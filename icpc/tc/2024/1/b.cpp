#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (ll)x.size()
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll INF=1e18;

struct Dinic{
	int nodes,src,dst;
	vector<int> dist,q,work;
	struct edge {int to,rev;ll f,cap;};
	vector<vector<edge>> g;
	Dinic(int x):nodes(x),g(x),dist(x),q(x),work(x){}
	void add_edge(int s, int t, ll cap){
		g[s].pb((edge){t,SZ(g[t]),0,cap});
		g[t].pb((edge){s,SZ(g[s])-1,0,0});
	}
	bool dinic_bfs(){
		fill(ALL(dist),-1);dist[src]=0;
		int qt=0;q[qt++]=src;
		for(int qh=0;qh<qt;qh++){
			int u=q[qh];
			fore(i,0,SZ(g[u])){
				edge &e=g[u][i];int v=g[u][i].to;
				if(dist[v]<0&&e.f<e.cap)dist[v]=dist[u]+1,q[qt++]=v;
			}
		}
		return dist[dst]>=0;
	}
	ll dinic_dfs(int u, ll f){
		if(u==dst)return f;
		for(int &i=work[u];i<SZ(g[u]);i++){
			edge &e=g[u][i];
			if(e.cap<=e.f)continue;
			int v=e.to;
			if(dist[v]==dist[u]+1){
				ll df=dinic_dfs(v,min(f,e.cap-e.f));
				if(df>0){e.f+=df;g[v][e.rev].f-=df;return df;}
			}
		}
		return 0;
	}
	ll max_flow(int _src, int _dst){
		src=_src;dst=_dst;
		ll result=0;
		while(dinic_bfs()){
			fill(ALL(work),0);
			while(ll delta=dinic_dfs(src,INF))result+=delta;
		}
		return result;
	}
};
const ll MAXN=1e5+5,MAXS=11;
vector<ii> g[MAXN];
ll d[MAXS][MAXN];
void dijkstra(ll wh, ll s){
	d[wh][s]=0;
	priority_queue<ii>pq;
	pq.push({0,s});
	while(SZ(pq)){
		auto [dis,x]=pq.top(); pq.pop();
		dis=-dis;
		if(d[wh][x]<dis)continue;
		for(auto [y,w]:g[x]){
			ll nd=dis+w;
			if(d[wh][y]==-1||nd<d[wh][y])d[wh][y]=nd,pq.push({-nd,y});
		}
	}
	
}
ll n,s;
ll a[MAXN];
ll p[MAXS],c[MAXS],sum;
bool can(ll x){
	ll pot=1ll<<s;
	vector<ll>as(pot);
	fore(i,0,n){
		ll mk=0;
		fore(j,0,s)if(d[j][i]<=x)mk|=1ll<<j;
		as[mk]+=a[i];
	}
	ll m=pot+s+3;
	Dinic fl(m);
	ll so=pot+s,ti=pot+s+1;
	fore(i,0,pot)fl.add_edge(so,i,as[i]);
	fore(mk,0,pot){
		fore(j,0,s)if(mk>>j&1)fl.add_edge(mk,pot+j,INF);
	}
	fore(i,0,s)fl.add_edge(pot+i,ti,c[i]);
	ll mx=fl.max_flow(so,ti);
	return mx==sum;
}

int main(){JET
	ll m; cin>>n>>m>>s;
	fore(i,0,n)cin>>a[i],sum+=a[i];
	fore(i,0,m){
		ll u,v,w; cin>>u>>v>>w; u--,v--;
		g[u].pb({v,w});
		g[v].pb({u,w});
	}
	fore(i,0,s)cin>>p[i]>>c[i],p[i]--;
	mset(d,-1);
	fore(i,0,s)dijkstra(i,p[i]);
	ll l=0,r=1e15;
	while(l<=r){
		ll m=(l+r)/2;
		if(can(m))r=m-1;
		else l=m+1;
	}
	cout<<l<<"\n";
}