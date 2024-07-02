#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MOD=998244353;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
struct tn{
	ll a,b,res;
};
string cv(tn h){return "["+to_string(h.a)+","+to_string(h.b)+"|"+to_string(h.res)+"]";}
struct tl{
	ll x,y;
	// bool operator==(tl b){return x==b.x&&y==b.y;}
};
// tn unit(ll v){return v;}
tn NEUT({0,0,0});
tl CLEAR({0,0});
tn oper(tn a, tn b){
	return tn({add(a.a,b.a),add(a.b,b.b),add(a.res,b.res)});
}
void acum(tl &a, tl v){ // accumulate lazy node
	a.x=add(a.x,v.x);
	a.y=add(a.y,v.y);
}
tn calc(ll s, ll e, tn h, tl v){ // calculate STree range, a=previous value
	// cout<<"calc "<<cv(h)<<" "<<v.x<<","<<v.y<<": ";
	
	// sumo x
	h.res=add(h.res,mul(h.b,v.x));
	h.a=add(h.a,mul(e-s,v.x));
	
	// sumo y
	h.res=add(h.res,mul(h.a,v.y));
	h.b=add(h.b,mul(e-s,v.y));
	
	// cout<<cv(h)<<"\n";
	return h;
} 

struct STree{
	vector<tn>st; vector<tl>lazy; ll n;
	STree(ll n):st(4*n+5,NEUT),lazy(4*n+5,CLEAR),n(n){
		//fore(i,0,n)upd(i,unit(0));
	}
	// void init(ll k, ll s, ll e, vector<ll>&a){
	// 	if(e-s==1)st[k]=unit(a[s]);
	// 	else {
	// 		ll m=(s+e)/2;
	// 		init(2*k,s,m,a); init(2*k+1,m,e,a);
	// 		st[k]=oper(st[2*k],st[2*k+1],k);
	// 	}
	// }
	void push(ll k, ll s, ll e){
		// if(lazy[k]==CLEAR)return;
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
	//void upd(ll p, tn v){upd(1,0,n,p,v);}
	tn query(ll a, ll b){return query(1,0,n,a,b);}
};

int main(){FIN;
	ll n,q; cin>>n>>q;
	vector<ll>a(n),b(n);
	fore(i,0,n)cin>>a[i],a[i]%=MOD;
	fore(i,0,n)cin>>b[i],b[i]%=MOD;
	STree st(n);
	fore(i,0,n){
		st.upd(i,i+1,tl({a[i]%MOD,b[i]%MOD}));
	}
	ll cnt=0;
	while(q--){
		ll ty,l,r; cin>>ty>>l>>r; l--;
		// cout<<cnt++<<": ";
		// fore(i,0,n)cout<<cv(st.query(i,i+1))<<" ";
		// cout<<"\n";
		if(ty==1){
			ll x; cin>>x; x%=MOD;
			st.upd(l,r,tl({x,0}));
		}
		else if(ty==2){
			ll x; cin>>x; x%=MOD;
			st.upd(l,r,tl({0,x}));
		}
		else {
			cout<<st.query(l,r).res<<"\n";
		}
		
	}
	return 0;
}
