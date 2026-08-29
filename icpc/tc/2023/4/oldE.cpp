#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll INF=1e18;
struct Dinic{
	struct edge {int to,rev;ll f,cap;};
	int nodes,src,dst; vector<int> dist,q,work; vector<vector<edge>> g;
	ll s,t,s_,t_;
	Dinic(int x):nodes(x),g(x),dist(x),q(x),work(x){
		s=nodes-4;
		t=nodes-3;
		s_=nodes-2;
		t_=nodes-1;
	}
	void add_edge(int s, int t, ll cap){
		g[s].pb((edge){t,SZ(g[t]),0,cap});
		g[t].pb((edge){s,SZ(g[s])-1,0,0});
	}
	bool dinic_bfs(){
		fill(ALL(dist),-1);dist[src]=0; int qt=0;q[qt++]=src;
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
			edge &e=g[u][i]; int v=e.to;
			if(e.cap<=e.f)continue;
			if(dist[v]==dist[u]+1){
				ll df=dinic_dfs(v,min(f,e.cap-e.f));
				if(df>0){e.f+=df;g[v][e.rev].f-=df;return df;}
			}
		}
		return 0;
	}
	ll max_flow(int _src, int _dst){
		src=_src;dst=_dst; ll result=0;
		while(dinic_bfs()){
			fill(ALL(work),0);
			while(ll delta=dinic_dfs(src,INF))result+=delta;
		}
		return result;
	}
	void add_demand(ll x, ll y, ll d, ll c){ // d <= c
		add_edge(s_,y,d);
		add_edge(t,s,d);
		add_edge(x,t_,d);
		add_edge(x,y,c-d);
	};
};
int main(){FIN;
	ll n; cin>>n;
	vector<ii> ed;
	fore(x,0,n){
		ll k; cin>>k;
		fore(_,0,k){
			ll y; cin>>y; y--;
			ed.pb({x,y});
		}
	}
	ll m=SZ(ed);
	auto can=[&](ll k){
		ll nodes=n,sp=nodes+1;
		Dinic fl(nodes+10);
		fore(x,0,n){
			fl.add_edge(sp,x,)
		}
	};
	ll l=-1,r=m+5
	
	return 0;
}
