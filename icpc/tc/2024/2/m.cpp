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

ll INF=1e15; // a constant > to any flow
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