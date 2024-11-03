#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet =b;i<jet;i++)
#define pb push_back
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll INF=1e18;
// Min cut: nodes with dist>=0 vs nodes with dist<0
// Matching MVC: left nodes with dist<0 + right nodes with dist>0
struct Dinic{
	int nodes,src,dst;
	vector<int> dist,q,work;
	struct edge {int to,rev;ll f,cap;};
	vector<vector<edge>> g;
	Dinic(int x):nodes(x),g(x),dist(x),q(x),work(x){}
	void add_edge(int s, int t, ll cap){
		// if(cap<=0)return;
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

int main(){JET
	ll g,n,m; cin>>g>>n>>m;
	vv a(n),b(m),bas(g);
	fore(i,0,n)cin>>a[i];
	fore(i,0,g)cin>>bas[i];
	fore(i,0,m)cin>>b[i];
	fore(i,0,n){
		fore(j,0,g){
			ll v; cin>>v;
			a[i]-=bas[j]*v;
		}
	}
	ll s=n+m,t=s+1;
	Dinic fl(t+1);
	ll sum=0;
	// imp(a);
	fore(i,0,n)if(a[i]>=0)fl.add_edge(s,i,a[i]),sum+=a[i];
	fore(j,0,m)fl.add_edge(n+j,t,b[j]);
	fore(i,0,n){
		ll k; cin>>k;
		fore(_,0,k){
			ll j; cin>>j; j--;
			fl.add_edge(i,n+j,INF);
		}
	}
	ll cut=fl.max_flow(s,t);
	// cout<<sum<<" "<<cut<<"\n";
	ll res=sum-cut;
	cout<<res<<"\n";
    return 0;
}