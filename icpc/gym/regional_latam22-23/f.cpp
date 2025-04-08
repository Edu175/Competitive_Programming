#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet; i++)
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
#define pb push_back
#define ET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ull R0=0x7e42ce82270a65b5;
const ull R1=0x4b489bc9a97a7ded;
const ull R2=0xaaeab0586d2aafaf;
ull falopa(ull x){
	x+=R0;
	x=(x^(x>>30))*R1;
	x=(x^(x>>27))*R2;
	return x^(x>>31);
}
const ll MAXN=105,INF=2*MAXN;
struct Dinic{
	int nodes,src,dst;
	vector<int> dist,q,work;
	struct edge{int to,rev; ll f,cap;};
	vector<vector<edge>> g;
	Dinic(int x):nodes(x),g(x),dist(x),q(x),work(x){}
	void add_edge(int s, int t, int cap){
		g[s].pb((edge){t,SZ(g[t]),0,cap});
		g[t].pb((edge){s,SZ(g[s])-1,0,0});
	}
	bool dinic_bfs(){
		fill(ALL(dist),-1); dist[src]=0;
		int qt=0;q[qt++]=src;
		for(int qh=0;qh<qt;qh++){
			int u=q[qh];
			fore(i,0,SZ(g[u])){
				edge &e=g[u][i]; int v=g[u][i].to;
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
		src=_src;
		dst=_dst;
		ll result=0;
		while(dinic_bfs()){
			fill(ALL(work),0);
			while(ll delta=dinic_dfs(src,INF))result+=delta;
		}
		return result;
	}
};
unordered_map<ull,bool> dp[MAXN];
ull hsh[MAXN];
ll sz0[MAXN],sz1[MAXN];
vv g0[MAXN],g1[MAXN];
// ll vec0[MAXN];
// ll vec1[MAXN];
bool f(ll x, ll u, ll fa0, ll fa1){
	if(sz0[x]<sz1[u])return 0;
	if(dp[x].count(hsh[u]))return dp[x][hsh[u]];
	auto &res=dp[x][hsh[u]];
	unordered_map<ull,ii>oc;
	ll q=0;
	for(auto v:g1[u])if(v!=fa1){
		auto &w=oc[hsh[v]];
		w.fst++,w.snd=v;
		q++;
	}
	
	ll nodes=SZ(oc)+SZ(g0[x]),s=nodes,t=nodes+1;
	Dinic fl(nodes+5);
	ll i=0;
	for(auto [dkfjh,par]:oc){
		auto [cant,v]=par;
		fl.add_edge(s,i,cant);
		// add de s a v con cant
		ll j=SZ(oc);
		for(auto y:g0[x])if(y!=fa0){
			ll hay=f(y,v,x,u);
			if(hay)fl.add_edge(i,j,INF);
			// add de v a y con inf
			j++;
		}
		i++;
	}
	ll j=SZ(oc);
	for(auto y:g0[x])if(y!=fa0){
		fl.add_edge(j,t,1);
		j++;
	}
	return res=fl.max_flow(s,t)==q;
	// check
}
void done(){
	cout<<"Y\n";
	exit(0);
}
ll fas[MAXN];
void dfs0(ll x, ll fa){
	sz0[x]=1;
	for(auto y:g0[x])if(y!=fa){
		dfs0(y,x);
		fas[y]=x;
		sz0[x]+=sz0[y];
	}
}
void dfs1(ll x, ll fa){
	sz1[x]=1; hsh[x]=0;
	for(auto y:g1[x])if(y!=fa){
		dfs1(y,x);
		sz1[x]+=sz1[y];
		hsh[x]+=hsh[y];
	}
	hsh[x]=falopa(hsh[x]);
}
ll n,m;
void doit(ll rt){
	dfs1(rt,-1);
	fore(x,0,n)if(f(x,rt,fas[x],-1))done();
}

int main(){
	ET
	cin>>n;
	fore(i,0,n-1){
		ll u,v; cin>>u>>v; u--,v--;
		g0[u].pb(v);
		g0[v].pb(u);
	}
	cin>>m;
	fore(i,0,m-1){
		ll u,v; cin>>u>>v; u--,v--;
		g1[u].pb(v);
		g1[v].pb(u);
	}
	dfs0(0,-1);
	fore(i,0,m)doit(i);
	cout<<"N\n";
}