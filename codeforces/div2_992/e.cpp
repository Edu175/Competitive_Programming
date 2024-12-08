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
typedef long double ld;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=2005;

vector<ll> g[MAXN];
ll fa[MAXN];
vv ord;
void dfs(ll x){
	for(auto y:g[x])if(y!=fa[x]){fa[y]=x;dfs(y);}
	ord.pb(x);
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,q; cin>>n>>q;
		fore(i,0,n){
			g[i].clear();
		}
		ord.clear();
		fore(i,0,n-1){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		fa[0]=0;
		dfs(0);
		reverse(ALL(ord));
		vector<vv>dp(n+3,vv(n+3));
		fore(p,0,n+1)for(auto x:ord)if(x){
			auto &res=dp[p][x];
			ll steps=2,sz=SZ(g[x]);
			if(!fa[x])steps=1;
			if(p)res=dp[p-1][fa[fa[x]]]+steps;
			ll c=0;
			c=dp[p][fa[fa[x]]]+steps+2*sz-2;
			if(!p||c<res)res=c;
		}
		while(q--){
			ll v,p; cin>>v>>p; v--;
			cout<<dp[p][fa[v]]+1<<"\n";
		}
	}
	return 0;
}
