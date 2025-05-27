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
// this is my dinitz implementation based on
// https://codeforces.com/blog/entry/104960
// this should be O(n^2 m)

// (heavily influenced on what I remembered from el vasito)

ll INF=1e18; // a constant > to any flow
struct Dinic{
	int n;
	struct edge{int to,rev; ll f,cap; int idx;};
	vector<vector<edge>> g;
	vector<int> d,q,work;
	Dinic(int n):n(n),g(n),d(n),q(n),work(n){}
	void add_edge(int u, int v, ll cap, int idx){
		g[u].pb({v,SZ(g[v]),0,cap,idx});
		g[v].pb({u,SZ(g[u])-1,0,0,idx});
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
const ll MAXN=4005;
vector<ii> g[MAXN];
int main(){FIN;
	ll n1,n2,m; cin>>n1>>n2>>m;
	vv deg(n1+n2);
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb({v+n1,i});
		g[v+n1].pb({u,i});
		deg[u]++;
		deg[v+n1]++;
	}
	ll mn=deg[0];
	fore(i,0,n1+n2)mn=min(mn,deg[i]);
	fore(k,0,mn+1){
		ll nodes=n1+n2,s=nodes,t=s+1;
		Dinic fl(nodes+5);
		fore(x,0,n1){
			fl.add_edge(s,x,k,-1); // ojo
			for(auto [y,i]:g[x])fl.add_edge(x,y,1,i);
		}
		fore(y,n1,n1+n2)fl.add_edge(y,t,k,-1); // ojo
		vv used(m);
		ll flow=fl.max_flow(s,t);
		vv deg(n1+n2);
		fore(x,0,SZ(fl.g)){
			for(auto e:fl.g[x])if(e.idx!=-1&&e.f>0){
				used[e.idx]=1;
				deg[x]++;
				deg[e.to]++;
			}
		}
		fore(x,0,n1+n2){
			ll fal=k-deg[x];
			for(auto [y,i]:g[x])if(fal>0){
				if(!used[i]){
					used[i]=1,fal--;
					assert(deg[y]==k); // else flujo seria mas
				}
			}
		}
		cout<<count(ALL(used),1)<<" ";
		fore(i,0,m)if(used[i])cout<<i+1<<" ";
		cout<<"\n";
	}
	return 0;
}
