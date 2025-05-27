#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
// AC Download Speed https://cses.fi/paste/d7bb2e206ccf7bf7c78269/

// this is my dinitz implementation based on
// https://codeforces.com/blog/entry/104960
// this should be O(n^2 m)

// (heavily influenced on what I remembered from el vasito)

ll INF=1e18; // a constant > to any flow
struct Dinic{
	int n;
	struct edge{int to,rev; ll f,cap;};
	vector<vector<edge>> g;
	vector<int> d,q,work;
	Dinic(int n):n(n),g(n),d(n),q(n),work(n){}
	void add_edge(int u, int v, ll cap){
		g[u].pb({v,SZ(g[v]),0,cap});
		g[v].pb({u,SZ(g[u])-1,0,0});
	}
	int s,t;
	bool bfs(){
		fill(ALL(d),-1);
		int qt=0;
		d[s]=0; q[qt++]=s;
		for(int qh=0;qh<qt;qh++){
			auto x=q[qh];
			for(auto &e:g[x])if(e.f<e.cap&&d[e.to]==-1){
				d[e.to]=d[x]+1;
				q[qt++]=e.to;
			}
		}
		return d[t]!=-1;
	}
	ll dfs(int x, ll F){
		if(x==t)return F;
		ll _F=F;
		for(auto &i=work[x];i<SZ(g[x]);i++){
			auto &e=g[x][i];
			if(d[e.to]==d[x]+1&&e.f<e.cap){
				ll dF=dfs(e.to,min(F,e.cap-e.f));
				F-=dF;
				e.f+=dF; g[e.to][e.rev].f-=dF;
				if(!F)break;
			}
		}
		return _F-F;
	}
	ll max_flow(int _s, int _t){
		s=_s,t=_t;
		ll ret=0;
		while(bfs()){
			fill(ALL(work),0);
			ret+=dfs(s,INF);
		}
		return ret;
	}
};
int main(){FIN;
	int n,m; cin>>n>>m;
	Dinic fl(n);
	fore(i,0,m){
		int u,v; ll w; cin>>u>>v>>w; u--,v--;
		fl.add_edge(u,v,w);
	}
	cout<<fl.max_flow(0,n-1)<<"\n";
	return 0;
}