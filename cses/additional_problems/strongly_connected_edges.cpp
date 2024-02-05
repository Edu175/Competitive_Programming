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
const ll MAXN=1e5+5,MAXM=2*MAXN;
vector<ii> g[MAXN]; // {node,edge}
ll lw[MAXN],dis[MAXN]/*,art[MAXN]*/,br[MAXM],vised[MAXM];
//ll cnt=0;
vector<ii>edges;
void DFS(ll x){
	lw[x]=dis[x];
	for(auto [y,ed]:g[x])if(!vised[ed]){
		//cnt+=(x==0);
		vised[ed]=1;
		edges.pb({x,y});
		if(lw[y]==-1){ //tree edge
			dis[y]=dis[x]+1;
			DFS(y);
			lw[x]=min(lw[x],lw[y]);
			//art[x]|=(lw[y]>=dis[x]);
			br[ed]=(lw[y]>=dis[y]);
		}
		else lw[x]=min(lw[x],dis[y]); //back edge
	}
}
void dfs_tree(ll rt=0){
	mset(lw,-1); /*mset(art,0);*/ mset(br,0); mset(vised,0);
	dis[rt]=0; //cnt=0;
	DFS(rt);
	//art[rt]=(cnt>1);
}
int main(){FIN;
	ll n,m; cin>>n>>m;
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb({v,i});
		g[v].pb({u,i});
	}
	dfs_tree();
	ll res=1;
	fore(i,0,m)if(br[i])res=0;
	if(!res||SZ(edges)<m){
		cout<<"IMPOSSIBLE\n";
		return 0;
	}
	for(auto [x,y]:edges)cout<<x+1<<" "<<y+1<<"\n";
	return 0;
}
