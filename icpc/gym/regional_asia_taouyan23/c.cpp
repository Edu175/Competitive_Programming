#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
typedef ii tn; // {on,off}
typedef ll tl;
#define NEUT {0,0}
#define CLEAR 0
tn unit(ll v){
	ii a={0,0};
	if(v==1)a.fst++;
	if(v==0)a.snd++;
	return a;
}
tn oper(tn a, tn b){
	return {a.fst+b.fst,a.snd+b.snd};
}
void acum(tl &a, tl v){
	a^=v;
}
tn calc(tn a, tl v){
	if(v)a={a.snd,a.fst};
	return a;
}
struct STree{
	vector<tn>st; vector<tl>lazy; ll n;
	STree(ll n):st(4*n+5,NEUT),lazy(4*n+5,CLEAR),n(n){}
	void init(ll k, ll s, ll e, vector<tn> &a){
		if(e-s==1)st[k]=a[s];
		else {
			ll m=(s+e)/2;
			init(2*k,s,m,a);
			init(2*k+1,m,e,a);
			st[k]=oper(st[2*k],st[2*k+1]);
		}
	}
	void push(ll k, ll s, ll e){
		if(lazy[k]==CLEAR)return;
		st[k]=calc(st[k],lazy[k]);
		if(e-s!=1){
			acum(lazy[2*k],lazy[k]);
			acum(lazy[2*k+1],lazy[k]);
		}
		lazy[k]=CLEAR;
	}
	void upd(ll k, ll s, ll e, ll a, ll b, tl v){
		push(k,s,e);
		if(e<=a||b<=s)return;
		if(a<=s&&e<=b){
			acum(lazy[k],v);
			push(k,s,e);
			return;
		}
		ll m=(s+e)/2;
		upd(2*k,s,m,a,b,v);
		upd(2*k+1,m,e,a,b,v);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	tn query(ll k, ll s, ll e, ll a, ll b){
		if(e<=a||b<=s)return NEUT;
		push(k,s,e);
		if(a<=s&&e<=b)return st[k];
		ll m=(s+e)/2;
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	void upd(ll a, ll b, tl v){upd(1,0,n,a,b,v);}
	tn query(ll a, ll b){return query(1,0,n,a,b);}
	void init(vector<tn>&a){init(1,0,n,a);}
};
int main(){
	JET
	ll n,m; cin>>n>>m;
	ll sum=0;
	vector<tn>ini;
	fore(i,0,n){
		ll s,p; cin>>s>>p;
		ini.pb(unit(s));
		sum+=p;
	}
	STree st(n);
	st.init(ini);
	while(m--){
		char ty; cin>>ty;
		if(ty=='W'){
			ll l,r; cin>>l>>r; r++;
			st.upd(l,r,1);
		}
		else {
			ll v; cin>>v;
			auto rq=st.query(0,n);
			sum+=v*rq.fst;
		}
	}
	cout<<sum<<"\n";
	return 0;
}