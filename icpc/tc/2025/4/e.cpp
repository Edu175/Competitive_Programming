#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll INF=1e18;
struct Dinic{
	int nodes,src,dst;
	vector<int> dist,q,work;
	struct edge{int to,rev; ll f,cap;};
	vector<vector<edge>> g;
	Dinic(int x): nodes(x), g(x),dist(x),q(x),work(x) {}
	void add_edge(int s, int t, ll cap){
		g[s].pb((edge){t,SZ(g[t]),0,cap});
		g[t].pb((edge){s,SZ(g[s])-1,0,0});
	}
	ii see_edge(int s, int pos){
		return (ii){g[s][pos].to,g[s][pos].f};
	}
	bool dinic_bfs(){
		fill(ALL(dist),-1); dist[src]=0;
		int qt=0; q[qt++]=src;
		for(int qh=0; qh<qt; qh++){
			int u=q[qh];
			fore(i,0,SZ(g[u])){
				edge &e=g[u][i]; int v=g[u][i].to;
				if(dist[v]<0&&e.f<e.cap) dist[v]=dist[u]+1,q[qt++]=v;
			}
		}
		return dist[dst]>=0;
	}
	ll dinic_dfs(int u, ll f){
		if(u==dst) return f;
		for(int &i=work[u]; i<SZ(g[u]); i++){
			edge &e=g[u][i];
			if(e.cap<=e.f)continue;
			int v=e.to;
			if(dist[v]==dist[u]+1){
				ll df=dinic_dfs(v,min(f,e.cap-e.f));
				if(df>0){e.f+= df; g[v][e.rev].f-=df; return df;}
			}
		}
		return 0;
	}
	ll max_flow(int _src, int _dst){
		src=_src, dst=_dst;
		ll result=0;
		while(dinic_bfs()){
			fill(ALL(work),0);
			while(ll delta=dinic_dfs(src,INF)) result+=delta;
		}
		return result;
	}
};


int main(){
	JET
	ll n,m; cin>>n>>m;
	vector<ii>ed;
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		ed.pb({u,v});
	}
	auto can=[&](ll k){
		ll nodes=n+m;
		Dinic fl(nodes+5);
		ll s=nodes,t=nodes+1;
		fore(i,0,n)fl.add_edge(i,t,k);
		fore(i,0,m){
			fl.add_edge(s,n+i,1);
			fl.add_edge(n+i,ed[i].fst,1);
			fl.add_edge(n+i,ed[i].snd,1);
		}
		return fl.max_flow(s,t)>=m;
	};
	auto papu=[&](ll k){
		ll nodes=n+m;
		Dinic fl(nodes+5);
		ll s=nodes,t=nodes+1;
		fore(i,0,n)fl.add_edge(i,t,k);
		fore(i,0,m){
			fl.add_edge(s,n+i,1);
			fl.add_edge(n+i,ed[i].fst,1);
			fl.add_edge(n+i,ed[i].snd,1);
		}
		fl.max_flow(s,t);
		vector<ii> rta;
		ll aux[2];
		fore(i,0,m){
			fore(_,0,2) {
				ii edi=fl.see_edge(n+i,1+_);
				aux[!(edi.snd==1)]=edi.fst;
				// cout<<edi.snd<<"ff\n";
			}
			rta.pb((ii){aux[0],aux[1]});
		}
		return rta;
	};
	ll l=0,r=m;
	while(l<=r){
		ll h=(l+r)/2;
		if(can(h))r=h-1;
		else l=h+1;
	}
	vector<ii> rta=papu(l);
	cout<<l<<"\n";
	for(auto [i,j]: rta){
		cout<<i+1<<" "<<j+1<<"\n";
	}
	return 0;
}