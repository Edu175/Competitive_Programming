#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b;i<jet;i++)
#define pb push_back
#define fst first
#define snd second 
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
// Min cut: nodes with dist>=0 vs nodes with dist<0
// Matching MVC: left nodes with dist<0 + right nodes with dist>0
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

const ll MAXN=505;
ll n,a,b,c,d;
ii p[MAXN],q[MAXN];
ll sq(ll n){return n*n;}
ll dis(ii a, ii b){
	return sq(a.fst-b.fst)+sq(a.snd-b.snd);
}
bool can(ll m){
	ll nodes=2*n+m;
	Dinic fl(nodes+5);
	fore(i,0,n){
		fl.add_edge(nodes,2*i,c);
		fl.add_edge(nodes,2*i+1,d);
		fore(j,0,m){
			if(dis(p[i],q[j])<=a)fl.add_edge(2*i,2*n+j,1);
			if(dis(p[i],q[j])<=b)fl.add_edge(2*i+1,2*n+j,1);
		}
	}
	fore(i,0,m)fl.add_edge(2*n+i,nodes+1,1);
	ll res=fl.max_flow(nodes,nodes+1);
	return res==m;
}

int main(){
	JET
	ll m; cin>>n>>m>>a>>b>>c>>d; c-=d; a*=a,b*=b;
	fore(i,0,n)cin>>p[i].fst>>p[i].snd;
	fore(i,0,m)cin>>q[i].fst>>q[i].snd;
	ll l=0,r=m;
	while(l<=r){
		ll m=(l+r)/2;
		if(can(m))l=m+1;
		else r=m-1;
	}
	if(l==m+1)l=-1;
	cout<<l<<"\n";
}