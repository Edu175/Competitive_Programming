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

#define NEUT 0
#define CLEAR 0 // cleared lazy node
ll oper(ll a, ll b){return a+b;}
void acum(pair<ll,ll> &a, pair<ll,ll> v){
	if(!v.snd)a.fst+=v.fst;
	else a.fst=v.fst,a.snd=v.snd;
} // accumulate lazy node
ll calc(ll s, ll e, ll a, ll v, ll t){
	if(!t)return a+(e-s)*v;
	else return (e-s)*v;
} // calculate STree range, a=previous value

struct STree{
	vector<ll>st; vector<pair<ll,ll>>lazy; ll n;
	STree(ll n):st(4*n+5,NEUT),lazy(4*n+5,{CLEAR,0}),n(n){}
	void push(ll k, ll s, ll e){
		if(lazy[k].fst==CLEAR)return;
		st[k]=calc(s,e,st[k],lazy[k].fst,lazy[k].snd);
		if(e-s!=1){
			acum(lazy[2*k],lazy[k]);
			acum(lazy[2*k+1],lazy[k]);
		}
		lazy[k]={CLEAR,0};
	}
	void upd(ll k, ll s, ll e, ll a, ll b, ll v, ll t){
		push(k,s,e);
		if(e<=a||b<=s)return;
		if(a<=s&&e<=b){
			acum(lazy[k],{v,t});
			push(k,s,e);
			return;
		}
		ll m=(s+e)/2;
		upd(2*k,s,m,a,b,v,t),upd(2*k+1,m,e,a,b,v,t);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	ll query(ll k, ll s, ll e, ll a, ll b){
		if(e<=a||b<=s)return NEUT;
		push(k,s,e);
		if(a<=s&&e<=b)return st[k];
		ll m=(s+e)/2;
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	void upd(ll a, ll b, ll v, ll t){upd(1,0,n,a,b,v,t);}
	ll query(ll a, ll b){return query(1,0,n,a,b);}
};

int main(){FIN;
	ll n,q; cin>>n>>q;
	ll a[n];
	fore(i,0,n)cin>>a[i];
	STree st(n);
	fore(i,0,n)st.upd(i,i+1,a[i],1);
	while(q--){
		ll ty,a,b; cin>>ty>>a>>b; ty--,a--;
		if(ty==2){
			cout<<st.query(a,b)<<"\n";
		}
		else {
			ll x; cin>>x;
			st.upd(a,b,x,ty);
		}
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
