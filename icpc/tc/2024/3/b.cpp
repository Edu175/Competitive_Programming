#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {cout<<#v<<": ";for(auto ldfkj:v)cout<<ldfkj<<" ";cout<<"\n";}
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
	struct edge {int to,rev,idx;ll f,cap;};
	vector<vector<edge>> g;
	Dinic(int x):nodes(x),g(x),dist(x),q(x),work(x){}
	void add_edge(int s, int t, ll cap, int idx=-1){
		g[s].pb((edge){t,SZ(g[t]),idx,0,cap});
		g[t].pb((edge){s,SZ(g[s])-1,idx,0,0});
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
	ll n1,n2,m,q; cin>>n1>>n2>>m>>q;
	Dinic fl(n1+n2+5);
	ll s=n1+n2,t=s+1;
	fore(i,0,n1)fl.add_edge(s,i,1);
	fore(i,0,n2)fl.add_edge(i+n1,t,1);
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--; v+=n1;
		fl.add_edge(u,v,1,i);
	}
	vector<ll>vc; // node
	vector<ll>mat(n1+n2+5,-1);
	ll mm=fl.max_flow(s,t);
	ll sum=0;
	fore(x,0,n1){
		if(fl.dist[x]<0){
			ll idx=-1;
			for(auto y:fl.g[x])if(y.f==1)idx=y.idx;
			vc.pb(x); mat[x]=idx; sum+=idx+1;
		}
	}
	fore(x,n1,n1+n2){
		if(fl.dist[x]>0){
			ll idx=-1;
			for(auto y:fl.g[x])if(y.f==-1)idx=y.idx;
			vc.pb(x); mat[x]=idx; sum+=idx+1;
		}
	}
	// imp(vc); imp(mat);
	while(q--){
		ll ty; cin>>ty;
		if(ty==1){
			ll x=vc.back(); vc.pop_back();
			ll idx=mat[x];
			sum-=idx+1;
			cout<<"1\n";
			if(x<n1)cout<<x+1<<"\n";
			else cout<<-(x-n1+1)<<"\n";
			cout<<sum<<endl;
		}
		else {
			cout<<SZ(vc)<<"\n";
			for(auto x:vc)cout<<mat[x]+1<<" ";
			cout<<endl;
		}
	}
	return 0;
}