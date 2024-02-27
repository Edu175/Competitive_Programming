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
const ll MAXN=1e5+5;

vector<ll> g[MAXN];
ll vis[MAXN];
vector<ll>ord;
ll cnt=0;
void dfs(ll x){
	vis[x]=1;
	sort(ALL(g[x]));
	for(auto y:g[x])if(!vis[y])dfs(y);
	ord.pb(x);
}

int main(){FIN;
	ll n,m; cin>>n>>m;
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		g[v].pb(u);
	}
	fore(i,0,n)if(!vis[i])dfs(i);
	for(auto i:ord)cout<<i+1<<" ";;cout<<"\n";
	return 0;
}
