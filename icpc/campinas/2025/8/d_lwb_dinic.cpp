#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b;i<jet;i++)
#define pb push_back
#define snd second
#define fst first
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);
using namespace std;
typedef int ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
// TLE
#pragma GCC optimize("Ofast,O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
const ll INF=1e6;


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
int main(){
	JET
	map<ll,ll>xs,ys;
	ll n; cin>>n;
	ll N=2*n;
	vv g[N];
	vv col(N);
	ll cnt=0;
	map<ll,ll>id[N];
	fore(i,0,n){
		ll x,y; cin>>x>>y;
		if(!xs.count(x))xs[x]=cnt++;
		if(!ys.count(y))ys[y]=cnt,col[cnt++]=1;
		g[xs[x]].pb(ys[y]);
		g[ys[y]].pb(xs[x]);
		// cerr<<xs[x]<<" "<<ys[y]<<"\n";
		id[xs[x]][ys[y]]=i;
	}
	ll nodes=cnt;
	Dinic fl(nodes+10);
	ll s=nodes,t=nodes+1,s_=nodes+2,t_=nodes+3;
	fore(i,0,cnt)if(!col[i])for(auto j:g[i])fl.add_edge(i,j,1);
	ll acum=0;
	auto add_demand=[&](ll x, ll y, ll d, ll c){ // d <= c
		if(d)fl.add_edge(s_,y,d);
		// fl.add_edge(t,s,d);
		acum+=d;
		if(d)fl.add_edge(x,t_,d);
		if(c-d)fl.add_edge(x,y,c-d);
	};
	fore(x,0,cnt){
		ll m=SZ(g[x]);
		if(!col[x])add_demand(s,x,m/2,(m+1)/2);
		else add_demand(x,t,m/2,(m+1)/2);
	}
	if(acum)fl.add_edge(t,s,acum);
	ll res=fl.max_flow(s_,t_);
	vv ans(n);
	fore(x,0,cnt)if(!col[x]){
		for(auto e:fl.g[x])if(e.to<cnt){
			if(e.f==1)ans[id[x][e.to]]=1;
			// cout<<x<<" "<<e.to<<": "<<e.f<<" "<<e.cap<<"\n";
		}
	}
	auto check=[&](){
		fore(x,0,cnt){
			ll sum=0;
			for(auto y:g[x])sum+=ans[!col[x]?id[x][y]:id[y][x]];
			assert(abs(sum-(SZ(g[x])-sum))<=1);
		}
	};
	// fore(i,0,n)cerr<<"LF"[ans[i]];;cerr<<"\n";
	check();
	fore(i,0,n)cout<<"LF"[ans[i]];;cout<<"\n";
	return 0;
}