#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

// assuming misma fila, completo mismo color
// puede ser que distintas filas tengan distinto color
// lo primero ya es suficiente
// dado un rango de igual color, es facil obtener el costo en O(1)
// dnc dp?
// o stree dp <-----
// stree de colores

#define NEUT 0
#define CLEAR 0 // cleared lazy node
ll oper(ll a, ll b){
	return max(a,b);
}
void acum(ll &a, ll v){ // accumulate lazy node
	a=max(a,v);
}
ll calc(ll s, ll e, ll a, ll v){ // calculate STree range, a=previous value
	assert(s|e|1);
	return max(a,v);
} 

struct STree{
	vector<ll>st,lazy; ll n;
	STree(ll n):st(4*n+5,NEUT),lazy(4*n+5,CLEAR),n(n){}
	void push(ll k, ll s, ll e){
		if(lazy[k]==CLEAR)return;
		st[k]=calc(s,e,st[k],lazy[k]);
		if(e-s!=1){
			acum(lazy[2*k],lazy[k]);
			acum(lazy[2*k+1],lazy[k]);
		}
		lazy[k]=CLEAR;
	}
	void upd(ll k, ll s, ll e, ll a, ll b, ll v){
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
	void upd(ll k, ll s, ll e, ll p, ll v){ // sum v to position p
		push(k,s,e);
		if(e<=p||p<s)return;
		if(e-s==1&&s==p){
			push(k,s,e);
			st[k]+=v;
			return;
		}
		ll m=(s+e)/2;
		upd(2*k,s,m,p,v),upd(2*k+1,m,e,p,v);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	ll query(ll k, ll s, ll e, ll a, ll b){
		if(e<=a||b<=s)return NEUT;
		push(k,s,e);
		if(a<=s&&e<=b)return st[k];
		ll m=(s+e)/2;
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	void upd(ll p, ll v){upd(1,0,n,p,v);}
	void upd(ll a, ll b, ll v){upd(1,0,n,a,b,v);}
	ll query(ll a, ll b){return query(1,0,n,a,b);}
};

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m,k; cin>>n>>m>>k;
		map<ll,ll> val[n];
		vv me(n);
		map<ll,ll> c[2];
		ll fij=0;
		fore(i,0,n){
			c[i&1].clear();
			fore(j,0,m){
				ll u; cin>>u; u--;
				if(u==-2)me[i]++;
				else {
					fij+=c[(i+1)&1][u];
					c[i&1][u]++;
					if(i)val[i-1][u]++;
					if(i<n-1)val[i+1][u]++;
				}
			}
		}
		// cout<<fij<<" fij\n";
		fore(i,0,n-1)fij+=me[i]*me[i+1];
		// cout<<fij<<" fij\n";
		STree st(k);
		vv dp(n);
		for(ll i=n-1;i>=0;i--){
			for(auto [u,c]:val[i])st.upd(u,c*me[i]);
			dp[i]=st.query(0,k);
			if(i)dp[i]-=me[i]*me[i-1];
			st.upd(0,k,dp[i]);
		}
		ll res=fij+dp[0];
		cout<<res<<"\n";
	}
	return 0;
}
