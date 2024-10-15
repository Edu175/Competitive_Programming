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

vector<ii> g[MAXN];

ll n;
vv dijkstra(ll s){
	vector<ll>d(n,-1);
	priority_queue<ii>pq;
	d[s]=0;
	pq.push({0,s});
	while(SZ(pq)){
		auto [dis,x]=pq.top(); pq.pop(); dis=-dis;
		if(d[x]<dis)continue;
		for(auto [y,w]:g[x]){
			ll nd=d[x]+w;
			if(d[y]==-1||nd<d[y]){
				d[y]=nd,pq.push({-nd,y});
			}
		}
	}
	return d;
}
const ll MAXM=MAXN;
vector<ii> f[MAXN]; // {node,edge}
ll lw[MAXN],dis[MAXN],art[MAXN],br[MAXM],vised[MAXM];
ll cnt_=0;
void dfs_(ll x){
	lw[x]=dis[x];
	for(auto [y,ed]:f[x])if(!vised[ed]){
		cnt_+=(x==0);
		vised[ed]=1;
		if(lw[y]==-1){ //tree edge
			dis[y]=dis[x]+1;
			dfs_(y);
			lw[x]=min(lw[x],lw[y]);
			art[x]|=(lw[y]>=dis[x]);
			br[ed]=(lw[y]>=dis[y]);
		}
		else lw[x]=min(lw[x],dis[y]); //back edge
	}
}
void dfs_init(ll n=0, ll m=0){
	mset(lw,-1); mset(art,0); mset(vised,0);
	//fore(i,0,n)lw[i]=-1,art[i]=0;
	//fore(i,0,m)vised[i]=0;
}
void dfs_tree(ll rt=0){
	if(lw[rt]!=-1)return;
	dis[rt]=0; cnt_=0;
	dfs_(rt);
	art[rt]=(cnt_>1);
}
int main(){FIN;
	ll m; cin>>n>>m;
	vector<pair<ii,ll>>ed;
	fore(i,0,m){
		ll u,v,w; cin>>u>>v>>w; u--,v--;
		g[u].pb({v,w});
		g[v].pb({u,w});
		ed.pb({{u,v},w});
	}
	auto l=dijkstra(0);
	auto r=dijkstra(n-1);
	vv esp(m),ans(m);
	ll dis=r[0];
	fore(i,0,m){
		auto [ar,w]=ed[i];
		auto [x,y]=ar;
		if(l[x]+w+r[y]==dis||l[y]+w+r[x]==dis){
			esp[i]=1;
			f[x].pb({y,i});
			f[y].pb({x,i});
		}
	}
	dfs_init();
	dfs_tree(0);
	fore(i,0,m){
		if(br[i])cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}
