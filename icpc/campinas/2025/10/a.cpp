#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define pb push_back
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define TUCUTUCUTUCUTUCU ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=2e4+5,MAXM=2*MAXN;

vector<ii> g[MAXN];
ll lw[MAXN],D[MAXN];
ll we[MAXM],vised[MAXM],br[MAXM];

void dfs(ll x){
	lw[x]=D[x];
	for(auto [y,i]:g[x])if(!vised[i]){
		vised[i]=1;
		if(lw[y]==-1){
			D[y]=D[x]+1;
			dfs(y);
			lw[x]=min(lw[x],lw[y]);
			br[i]=lw[y]>=D[y];
		}
		else lw[x]=min(lw[x],D[y]);
	}
}

vector<ii> t[MAXN];

ll n,diam;
ll dijkstra(ll s){
	priority_queue<ii>pq;
	vv d(n,0),fa(n,-1);
	d[s]=0; pq.push({0,s});
	while(SZ(pq)){
		auto [dis,x]=pq.top(); pq.pop(); dis=-dis;
		if(d[x]!=dis)continue;
		for(auto [y,w]:t[x])if(y!=fa[x]){
			auto nd=dis+w;
			if(fa[y]==-1||nd<d[y]){
				fa[y]=x; d[y]=nd;
				pq.push({-nd,y});
			}
		}
	}
	ll res=0;
	fore(i,0,n)res=min(res,d[i]);
	// cout<<"d: ";;fore(i,0,n)cout<<d[i]<<" ";;cout<<"\n";
	return res;
}

int main(){
	TUCUTUCUTUCUTUCU
	ll m; cin>>n>>m;
	vector<ii>ed;
	fore(i,0,m){
		ll u,v,w; cin>>u>>v>>w; u--,v--;
		we[i]=w;
		g[u].pb({v,i});
		g[v].pb({u,i});
		ed.pb({u,v});
	}
	mset(lw,-1);
	dfs(0);
	ll cost=0;
	fore(i,0,m){
		cost+=we[i];
		auto [x,y]=ed[i];
		// cout<<x<<","<<y<<": "<<br[i]<<" "<<we[i]<<"\n";
		if(br[i]){
			cost+=we[i];
			t[x].pb({y,-we[i]});
			t[y].pb({x,-we[i]});
		}
		else {
			t[x].pb({y,we[i]});
			t[y].pb({x,we[i]});
		}
	}
	ll best=dijkstra(0);
	// cout<<cost<<" "<<best<<"\n";
	ll res=cost+best;
	cout<<res<<"\n";
	return 0;
}
