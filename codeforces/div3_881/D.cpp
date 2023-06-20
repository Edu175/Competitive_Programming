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
const ll MAXN=2e5+5;

vector<ll>g[MAXN];
ll h[MAXN];
void dfs(ll x, ll f){
	for(auto y:g[x])if(y!=f){
		dfs(y,x);
		h[x]+=h[y];
	}
	if(x!=0&&SZ(g[x])==1)h[x]=1;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n){
			g[i].clear();
			h[i]=0;
		}
		fore(i,0,n-1){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		dfs(0,-1);
		ll q; cin>>q;
		while(q--){
			ll x,y; cin>>x>>y; x--,y--;
			cout<<h[x]*h[y]<<"\n";
		}
	}
	return 0;
}
