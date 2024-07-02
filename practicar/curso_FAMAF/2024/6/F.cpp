#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh.fst<<","<<gdljh.snd<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll B=20;
struct tn{
	vector<ii>q;
	tn():q(B,{0,0}){}
};
typedef ll tl; // lazy type
tn unit(ll v){
	tn r;
	fore(j,0,B){
		if(v>>j&1)r.q[j].snd++;
		else r.q[j].fst++;
	}
	return r;
}
ll unit(tn v){
	ll res=0;
	fore(j,0,B)res+=v.q[j].snd<<j;
	return res;
}
tn NEUT;
#define CLEAR 0 // cleared lazy node
tn oper(tn a, tn b){
	fore(j,0,B)a.q[j].fst+=b.q[j].fst,a.q[j].snd+=b.q[j].snd;
	return a;
}
void acum(tl &a, tl v){ // accumulate lazy node
	a^=v;
}
tn calc(ll s, ll e, tn a, tl v){ // calculate STree range, a=previous value
	// cout<<"calc "; imp(a.q);
	// cout<<v<<" --> ";
	fore(j,0,B)if(v>>j&1)swap(a.q[j].fst,a.q[j].snd);
	// imp(a.q);
	// cout<<"\n";
	return a;
} 

struct STree{
	vector<tn>st; vector<tl>lazy; ll n;
	STree(ll n):st(4*n+5,NEUT),lazy(4*n+5,CLEAR),n(n){
		//fore(i,0,n)upd(i,unit(0));
	}
	void init(ll k, ll s, ll e, vector<tn>&a){
		if(e-s==1)st[k]=a[s];
		else {
			ll m=(s+e)/2;
			init(2*k,s,m,a); init(2*k+1,m,e,a);
			st[k]=oper(st[2*k],st[2*k+1]);
		}
	}
	void push(ll k, ll s, ll e){
		if(lazy[k]==CLEAR)return;
		st[k]=calc(s,e,st[k],lazy[k]);
		if(e-s!=1){
			acum(lazy[2*k],lazy[k]);
			acum(lazy[2*k+1],lazy[k]);
		}
		lazy[k]=CLEAR;
	}
	void upd(ll k, ll s, ll e, ll a, ll b, tl v){ // range update
		push(k,s,e);
		if(e<=a||b<=s)return;
		if(a<=s&&e<=b){
			acum(lazy[k],v);
			push(k,s,e);
			return;
		}
		ll m=(s+e)/2;
		upd(2*k,s,m,a,b,v),upd(2*k+1,m,e,a,b,v);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	/*void upd(ll k, ll s, ll e, ll p, tn v){ // assign v to position p
		push(k,s,e);
		if(e<=p||p<s)return;
		if(e-s==1&&s==p){
			push(k,s,e);
			st[k]=v;
			return;
		}
		ll m=(s+e)/2;
		upd(2*k,s,m,p,v),upd(2*k+1,m,e,p,v);
		st[k]=oper(st[2*k],st[2*k+1]);
	}*/
	tn query(ll k, ll s, ll e, ll a, ll b){
		if(e<=a||b<=s)return NEUT;
		push(k,s,e);
		if(a<=s&&e<=b)return st[k];
		ll m=(s+e)/2;
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	void upd(ll a, ll b, tl v){upd(1,0,n,a,b,v);}
	// void upd(ll p, tn v){upd(1,0,n,p,v);}
	tn query(ll a, ll b){return query(1,0,n,a,b);}
	void init(vector<tn>&a){init(1,0,n,a);}
};
int main(){FIN;
	ll n; cin>>n;
	vector<ll>a(n);
	fore(i,0,n)cin>>a[i];
	STree st(n);
	vector<tn>ini(n);
	fore(i,0,n)ini[i]=unit(a[i]);
	st.init(ini);
	ll q; cin>>q;
	// ll Q=q;
	while(q--){
		// cout<<Q-q<<":\n";
		// fore(i,0,n)cout<<unit(st.query(i,i+1))<<" ";;cout<<"\n";
		ll ty; cin>>ty;
		if(ty==1){
			ll l,r; cin>>l>>r; l--;
			cout<<unit(st.query(l,r))<<"\n";
		}
		else {
			ll l,r,x; cin>>l>>r>>x; l--;
			st.upd(l,r,x);
		}
	}
	return 0;
}