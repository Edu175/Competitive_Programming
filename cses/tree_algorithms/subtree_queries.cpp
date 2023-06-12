#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
const ll MAXN=2e5+5;

struct STree{
	ll n; vector<ll>t;
	STree(ll n):n(n),t(2*n+5,0){}
	void upd(ll p, ll v){
		for(p+=n,t[p]=v;p>1;p>>=1)t[p>>1]=t[p]+t[p^1];
	}
	ll query(ll l, ll r){
		ll res=0;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)res+=t[l++];
			if(r&1)res+=t[--r];
		}
		return res;
	}
};
ll a[MAXN];
vector<ll>g[MAXN];
ll s[MAXN],e[MAXN],c;
void dfs(ll x, ll f){
	s[x]=c++;
	for(auto y:g[x])if(y!=f)dfs(y,x);
	e[x]=c;
}

int main(){FIN;
	ll n,q; cin>>n>>q;
	fore(i,0,n)cin>>a[i];
	fore(i,0,n-1){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(0,-1);
	STree st(n);
	fore(i,0,n)st.upd(s[i],a[i]);//,cout<<i<<": "<<s[i]<<" "<<e[i]<<"\n";
	
	while(q--){
		ll t,x; cin>>t>>x; t--,x--;
		if(!t){
			ll v; cin>>v;
			st.upd(s[x],v);
			continue;
		}
		cout<<st.query(s[x],e[x])<<"\n";;
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
