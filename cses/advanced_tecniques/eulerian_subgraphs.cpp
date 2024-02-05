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
typedef pair<ll,ll> ii;
const ll MOD=1e9+7,MAXN=1e5+5;

vector<ll> g[MAXN];
ll vis[MAXN];
void dfs(ll x){
	vis[x]=1;
	for(auto y:g[x])if(!vis[y])dfs(y);
}

int main(){FIN;
	ll n,m; cin>>n>>m;
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	ll q=0;
	fore(i,0,n)if(!vis[i]){q++,dfs(i);}
	ll res=1;
	fore(i,0,m-(n-q))res=2*res%MOD;
	cout<<res<<"\n";
	return 0;
}
