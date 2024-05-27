#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
// Min cut: nodes with dist>=0 vs nodes with dist<0
// Matching MVC: left nodes with dist<0 + right nodes with dist>0
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


vector<int> kmppre(string& t){ // r[i]: longest border of t[0,i)
	vector<int> r(t.size()+1);r[0]=-1;
	int j=-1;
	fore(i,0,t.size()){
		while(j>=0&&t[i]!=t[j])j=r[j];
		r[i+1]=++j;
	}
	return r;
}
bool is_sub(string &a, string &b){ // <=
	auto c=b+"$"+a;
	auto r=kmppre(c);
	fore(i,SZ(b),SZ(r))if(r[i]==SZ(b))return 1;
	return 0;
}

const ll MAXN=105;
ll n;
ll g[MAXN][MAXN];

int main(){FIN;
	cin>>n;
	vector<string> s(n);
	vector<ll>a(n);
	fore(i,0,n)cin>>s[i];
	fore(i,0,n)cin>>a[i];
	map<string,ll>mp;
	fore(i,0,n)mp[s[i]]=max(mp[s[i]],a[i]);
	vector<string>s_;
	vector<ll>a_;
	for(auto i:mp)s_.pb(i.fst),a_.pb(i.snd);
	a=a_;s=s_;
	n=SZ(s);

	ll sum=0;
	fore(i,0,n)sum+=a[i];
	fore(i,0,n)fore(j,0,n)if(i!=j)g[i][j]=is_sub(s[i],s[j]);

	Dinic fl(2*n+5);
	ll so=2*n,ti=2*n+1;
	fore(i,0,n)fl.add_edge(so,i,a[i]),fl.add_edge(n+i,ti,a[i]);
	fore(i,0,n)fore(j,0,n)if(g[i][j])fl.add_edge(i,n+j,INF);
	ll res=fl.max_flow(so,ti);
//	cout<<res<<"\n";
	res=sum-res;
	cout<<res<<"\n";
	return 0;
}
