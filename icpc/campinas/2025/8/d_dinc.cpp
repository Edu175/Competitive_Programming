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
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll INF=1e15;
struct Dinic{
	int nodes, src,dst;
	vector<int> dist,q,work;
	struct edge{int to,rev; ll f,cap;int p;};
	vector<vector<edge>> g;
	Dinic(int x): nodes(x), g(x),dist(x),q(x),work(x){}
	void add_edge(int s, int t, ll cap, int p){
		g[s].pb((edge){t,SZ(g[t]),0,cap,p});
		g[t].pb((edge){s,SZ(g[s])-1,0,0,p});
	}
	bool dinic_bfs(){
		fill(ALL(dist),-1); dist[src]=0;
		int qt=0; q[qt++]=src;
		for(int qh=0; qh<qt; qh++){
			int u=q[qh];
			fore(i,0,SZ(g[u])){
				edge &e=g[u][i]; int v=g[u][i].to;
				if(e.p==1) continue;
				if(dist[v]<0&&e.f<e.cap)dist[v]=dist[u]+1,q[qt++]=v;
			}
		}
		return dist[dst]>=0;
	}
	bool dinic_bfs2(){
		fill(ALL(dist),-1); dist[src]=0;
		int qt=0; q[qt++]=src;
		for(int qh=0; qh<qt; qh++){
			int u=q[qh];
			fore(i,0,SZ(g[u])){
				edge &e=g[u][i]; int v=g[u][i].to;
				if(e.p==0) continue;
				
				// if(e.p==1) continue;
				if(dist[v]<0&&e.f<e.cap)dist[v]=dist[u]+1,q[qt++]=v;
			}
		}
		return dist[dst]>=0;
	}
	bool dinic_dfs(int u,ll f){
		if (u==dst )return f;
		for(int &i=work[u]; i<SZ(g[u]);i++){
			edge &e=g[u][i];
			if(e.cap<=e.f || e.p==1) continue;
			int v=e.to;
			if(dist[v]==dist[u]+1){
				ll df=dinic_dfs(v,min(f,e.cap-e.f));
				if(df>0){e.f+=df;g[v][e.rev].f-=df; return df;}
			}
		}
		return 0;
	}
	bool dinic_dfs2(int u,ll f){
		if (u==dst )return f;
		for(int &i=work[u]; i<SZ(g[u]);i++){
			edge &e=g[u][i];
			if(e.p==0) continue;
			
			if(e.cap<=e.f) continue;
			int v=e.to;
			if(dist[v]==dist[u]+1){
				ll df=dinic_dfs2(v,min(f,e.cap-e.f));
				if(df>0){e.f+=df;g[v][e.rev].f-=df; return df;}
			}
		}
		return 0;
	}
	ll max_flow(int _src,int _dst){
		src=_src; dst=_dst;
		ll result=0;
		int i=0;
		while(dinic_bfs()){
			fill(ALL(work),0);
			while(ll delta=dinic_dfs(src,INF))result+=delta;
			// cout<<i<<endl;
			// i++;
		}
		fore(i,0,6){
		for(auto x:g[i]){
			if(x.f>0){
				cout<<"manda "<<i<<" "<<x.to<<"\n";
			}
		}
		}
		while(dinic_bfs2()){
			fill(ALL(work),0);
			while(ll delta=dinic_dfs2(src,INF))result+=delta;
			// cout<<i<<endl;
			// i++;
		}
		return result;
	}
};
map<ii,ll> m;
map<ll,ll> LR;
map<ll,ll> AB;
map<ll,ll> RL;
map<ll,ll> BA;

int main(){
	JET
	ll n; cin>>n;
	Dinic D(2*n+3);
	ll lr=0,ab=n;
	ii p[n];
	fore(i,0,n){
		ll x,y;
		cin>>x>>y;x--,y--;
		m[{x,y}]=i;
		if(!LR.count(x)) {LR[x]=lr; RL[lr]=x; lr++;}
		if(!AB.count(y)) {AB[y]=ab; BA[ab]=y; ab++;}
		p[i]={x,y};
		D.add_edge(LR[x],AB[y],1,2);
	}
	for(auto [x,i]:LR){
	//	cout<<i<<"\n"; S
		cout<<i<<" "<<"\n";
		D.add_edge(2*n,i,(SZ(D.g[i]))/2,0);
		if(SZ(D.g[i])%2==1) D.add_edge(2*n,i,1,1);
	}
	for(auto [y,i]:AB){
		//cout<<i<<"\n"; T
		D.add_edge(i,2*n+1,(SZ(D.g[i]))/2,0);
		if(SZ(D.g[i])%2==0) D.add_edge(i,2*n+1,1,1);
	}
	D.max_flow(2*n,2*n+1);
	vector<ii> rec;
	fore(i,0,n){
		for(auto x:D.g[i]){
			if(x.f>0){
				rec.pb({i,x.to});
			}
		}
	}
//	for(auto jere:rec){cout<<RL[jere.fst]<<" "<<BA[jere.snd]<<"\n";}
	string res(n,'L');
	for(auto jere: rec){
		res[m[(ii){RL[jere.fst],BA[jere.snd]}]]='F';
	}
	cout<<res<<"\n";
	return 0;
}