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
const ll MAXN=2e5+5;

ll vis[MAXN],we[MAXN];

vector<ii> g[MAXN];

void dfs(ll x){
	vis[x]=1;
	for(auto [y,w]:g[x])if(!vis[y]){
		we[y]=we[x]^w;
		dfs(y);
	}
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		fore(i,0,n){
			g[i].clear();
			vis[i]=0;
			we[i]=0;
		}
		fore(i,0,m){
			ll u,v,w; cin>>u>>v>>w; u--,v--;
			g[u].pb({v,w});
			g[v].pb({u,w});
		}
		if(n&1){
			cout<<"-1\n";
			continue;
		}
		dfs(0);
		ll x=0;
		fore(i,0,n+1)x^=i;
		fore(i,0,n)x^=we[i];
		cout<<x<<"\n";
		
	}
	return 0;
}
