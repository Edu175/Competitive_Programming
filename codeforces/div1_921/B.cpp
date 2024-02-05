#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

#pragma GCC optimize("Ofast") // may lead to precision errors

//#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#define bint __int128
const bint MOD=1000000000000000009LL;
bint fpow(bint b, bint e){
	if(e<0)return 0;
	bint ret=1;
	while(e){
		if(e&1)ret=ret*b%MOD;
		b=b*b%MOD,e>>=1;
	}
	return ret;
}
typedef bint tn; // node type
struct tl{
	bint s,m;
	bool operator==(tl b){return s==b.s&&m==b.m;}
};
tn unit(ll v){return v;}
#define NEUT 0
tl CLEAR=tl({0,1});
/*ll cut(ll a){
	if(a>=MOD)a-=MOD;
	return a;
}*/
tn oper(tn a, tn b){
	a+=b;
	if(a>=MOD)a-=MOD;
	return a;
}
void acum(tl &a, tl &v){ // accumulate lazy node
	a.s=(a.s*v.m+v.s)%MOD;
	a.m=a.m*v.m%MOD;
}
tn calc(ll s, ll e, tn a, tl v){ // calculate STree range, a=previous value
	return (a*v.m+(e-s)*v.s)%MOD;
} 

struct STree{
	vector<tn>st; vector<tl>lazy; ll n;
	STree(ll n):st(4*n+5,NEUT),lazy(4*n+5,CLEAR),n(n){
		//fore(i,0,n)upd(i,unit(0));
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
	void upd(ll k, ll s, ll e, ll p, tn v){ // assign v to position p
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
	}
	tn query(ll k, ll s, ll e, ll a, ll b){
		if(e<=a||b<=s)return NEUT;
		push(k,s,e);
		if(a<=s&&e<=b)return st[k];
		ll m=(s+e)/2;
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	void upd(ll a, ll b, tl v){if(a<b)upd(1,0,n,a,b,v);}
	void upd(ll p, tn v){upd(1,0,n,p,v);}
	tn query(ll a, ll b){return query(1,0,n,a,b);}
};

int main(){FIN;
	ll n,m,q; cin>>n>>m>>q;
	vector<ll>a(n);
	set<ll>h;
	vector<ll>X(m),V(m);
	fore(i,0,m)cin>>X[i],X[i]--;
	fore(i,0,m)cin>>V[i];
	fore(i,0,m)h.insert(X[i]),a[X[i]]=V[i];
	STree st(n);
	fore(i,0,n){
		if(a[i])continue;
		auto p=h.lower_bound(i);
		ll l=*prev(p),r=*p;
		st.upd(i,a[l]*(r-i));
		//cout<<i<<": "<<l<<" "<<r<<": "<<a[l]*(r-i)<<"\n";
	}
	while(q--){
		ll ty; cin>>ty;
		if(ty==1){
			ll x,v; cin>>x>>v; x--;
			auto p=h.lower_bound(x);
			ll l=*prev(p),r=*p;
			st.upd(l+1,x+1,tl{(MOD-a[l]*(r-x))%MOD,1});
			st.upd(x+1,r,{0,v*fpow(a[l],MOD-2)%MOD});
			a[x]=v;
			h.insert(x);
		}
		else {
			ll l,r; cin>>l>>r; l--;
			ll res=st.query(l,r);
			cout<<res<<"\n";
		}
		//fore(i,0,n)cout<<(ll)st.query(i,i+1)<<" ";;cout<<"\n";
	}
	return 0;
}
