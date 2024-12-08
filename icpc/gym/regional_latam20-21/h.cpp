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
ll go(string s){
	ll r=0;
	fore(i,0,SZ(s)){
		r*=10;
		r+=(s[i]-'0');
	}
	return r;
}

int main(){
	ET
	// ll s; cin>>s;
	// cout<<to_string(s)<<"\n";
	// return 0;
	ll n; cin>>n;
	Dinic di(n+10);
	di.add_edge(0,1,INF);
	di.add_edge(1,n+1,1);
	fore(i,0,n){
		string x; cin>>x;
		if(x=="*"){
			ll a; cin>>a; 
			if(a==1) a=n+1;
			di.add_edge(i+1,a,INF);
		}
		else{
			ll k=go(x);
			fore(i,0,k){
				ll a; cin>>a;
				if(a==1) a=n+1;
				di.add_edge(i+1,a,1);
			}
		}
	}
	ll res=di.max_flow(0,n+1);
	if(res<=0) cout<<"PINGO\n";
	if(res>=INF)cout<<"*\n";
	else cout<<res<<"\n";
	
}