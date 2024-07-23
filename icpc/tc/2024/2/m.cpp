#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

const ll INF= 1e15;
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
				if(dist[v]<0 && e.f<e.cap) dist[v]=dist[u]+1,q[qt++]=v;
			}
		}
		return dist[dst]>=0;
	}
	ll dinic_dfs(int u, ll f ){
		if(u==dst) return f;
		for(int &i=work[u];i<SZ(g[u]);i++){
			edge &e=g[u][i];
			if(e.cap<=e.f) continue;
			int v=e.to;
			if(dist[v]==dist[u]+1){
				ll df=dinic_dfs(v,min(f,e.cap-e.f));
				if(df>0){e.f+=df;g[v][e.rev].f-=df;return df;}
			}
		}
		return 0;
	}
	ll max_flow(int _src, int _dst){
		src=_src; dst=_dst;
		ll result=0;
		while(dinic_bfs()){
			fill(ALL(work),0);
			while(ll delta=dinic_dfs(src,INF))result+=delta;
			
		}
		return result;
	}
};


int main(){
	JET
	int t; cin>>t;
	while(t--){
		int n,m; cin>>n>>m;
		Dinic a(n+m+5);
		fore(i,1,m+1){
			a.add_edge(0,i,1);
		}
		fore(i,0,n){
			a.add_edge(m+1+i,n+m+3,(m+1)/2);
		}
		fore(i,0,m){
			int k; cin>>k;
			fore(j,0,k){
				int x; cin>>x;
				x--;
				a.add_edge(i+1,x+m+1,INF);
			}
		}
		ll rta=a.max_flow(0,n+m+3);
		
		if(rta!=m) cout<<"NO\n";
		else{
			cout<<"YES\n";
			fore(i,1,m+1){
				for(auto x : a.g[i]){
					if(x.f>0) cout<<x.to-m<<" ";
				}
				
			}
			cout<<"\n";
		}
		
		
	}
}