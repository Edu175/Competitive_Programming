#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet; i++)
#define pb push_back
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) int(x.size())
#define ET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
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

int main(){
	ET;
	ll n; cin>>n;
	ll nodes=n;
	Dinic fl(nodes+5);
	fl.add_edge(nodes,0,INF);
	auto add=[&](ll s, ll t, ll cap){
		fl.add_edge(s,!t?nodes+1:t,cap);
	};
	fore(i,0,n){
		string s; cin>>s;
		if(s=="*"){
			ll y; cin>>y; y--;
			add(i,y,INF);
		}
		else {
			ll m=stoll(s);
			fore(_,0,m){
				ll y; cin>>y; y--;
				add(i,y,1);
			}
		}
	}
	ll res=fl.max_flow(nodes,nodes+1);
	if(res<INF)cout<<res+1<<"\n";
	else cout<<"*\n";
}