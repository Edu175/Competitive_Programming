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

bool is_p(ll n){
	if(n==0)return 0;
	for(ll i=2;i*i<=n;i++)if(n%i==0)return 0;
	return 1;
}

const ll MAXN=205;
vv g[MAXN];
ll vis[MAXN];
vv c;
void dfs(ll x){
	c.pb(x);
	vis[x]=1;
	for(auto y:g[x])if(!vis[y])dfs(y);
}

int main(){FIN;
	ll n; cin>>n;
	vv a(n);
	vector<vv> b(2);
	fore(i,0,n)cin>>a[i],b[a[i]&1].pb(i);
	ll nodes=n,s=nodes+1,t=nodes+2;
	Dinic fl(nodes+5);
	for(auto i:b[0]){
		fl.add_edge(s,i,2);
		for(auto j:b[1])if(is_p(a[i]+a[j]))fl.add_edge(i,j,1);
	}
	for(auto i:b[1])fl.add_edge(i,t,2);
	ll mx=fl.max_flow(s,t);
	if(mx!=n){
		cout<<"Impossible\n";
		return 0;
	}
	fore(x,0,n){
		for(auto e:fl.g[x])if(e.to<n){
			if(e.f==1){
				ll y=e.to;
				g[x].pb(y);
				g[y].pb(x);
			}
		}
	}
	vector<vv> ans;
	fore(i,0,n)if(!vis[i]){
		c.clear();
		dfs(i);
		ans.pb(c);
	}
	cout<<SZ(ans)<<"\n";
	for(auto v:ans){
		cout<<SZ(v)<<" ";
		for(auto i:v)cout<<i+1<<" ";
		cout<<"\n";
	}
	return 0;
}
