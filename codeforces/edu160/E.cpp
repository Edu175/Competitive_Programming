#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

typedef ll tf;
typedef ll tc;
const tf INFFLOW=1e9;
const tc INFCOST=1e9;
struct MCF{
	int n;
	vector<tc> prio, pot; vector<tf> curflow; vector<int> prevedge,prevnode;
	priority_queue<pair<tc, int>, vector<pair<tc, int>>, greater<pair<tc, int>>> q;
	struct edge{int to, rev; tf f, cap; tc cost;};
	vector<vector<edge>> g;
	MCF(int n):n(n),prio(n),curflow(n),prevedge(n),prevnode(n),pot(n),g(n){}
	void add_edge(int s, int t, tf cap, tc cost) {
		g[s].pb((edge){t,SZ(g[t]),0,cap,cost});
		g[t].pb((edge){s,SZ(g[s])-1,0,0,-cost});
	}
	pair<tf,tc> get_flow(int s, int t) {
		tf flow=0; tc flowcost=0;
		while(1){
			q.push({0, s});
			fill(ALL(prio),INFCOST); 
			prio[s]=0; curflow[s]=INFFLOW;
			while(!q.empty()) {
				auto cur=q.top();
				tc d=cur.fst;
				int u=cur.snd;
				q.pop();
				if(d!=prio[u]) continue;
				for(int i=0; i<SZ(g[u]); ++i) {
					edge &e=g[u][i];
					int v=e.to;
					if(e.cap<=e.f) continue;
					tc nprio=prio[u]+e.cost+pot[u]-pot[v];
					if(prio[v]>nprio) {
						prio[v]=nprio;
						q.push({nprio, v});
						prevnode[v]=u; prevedge[v]=i;
						curflow[v]=min(curflow[u], e.cap-e.f);
					}
				}
			}
			if(prio[t]==INFCOST) break;
			fore(i,0,n) pot[i]+=prio[i];
			tf df=min(curflow[t], INFFLOW-flow);
			flow+=df;
			for(int v=t; v!=s; v=prevnode[v]) {
				edge &e=g[prevnode[v]][prevedge[v]];
				e.f+=df; g[v][e.rev].f-=df;
				flowcost+=df*e.cost;
			}
		}
		return {flow,flowcost};
	}
};

int main(){FIN;
	ll n,m; cin>>n>>m;
	ll h[n][m];
	ll sum=0;
	fore(i,0,n)fore(j,0,m){
		cin>>h[i][j];
		sum+=h[i][j];
	}
	vector<ll>a(n),b(m);
	fore(i,0,n)cin>>a[i];
	fore(j,0,m)cin>>b[j];
	ll s=n+m,t=n+m+1;
	MCF fl(n+m+2);
	fore(i,0,n)fl.add_edge(s,i,a[i],0);
	fore(j,0,m)fl.add_edge(n+j,t,b[j],0);
	fore(i,0,n)fore(j,0,m)fl.add_edge(i,n+j,1,(h[i][j]?-1:1));
	ll sa=0,sb=0;
	fore(i,0,n)sa+=a[i];
	fore(j,0,m)sb+=b[j];
	//cout<<sa<<" "<<sb<<"\n";
	ii res=fl.get_flow(s,t);
	//cout<<res.fst<<" "<<res.snd<<"\n";
	if(sa!=sb||res.fst!=sb)cout<<"-1\n";
	else cout<<sum+res.snd<<"\n";
	return 0;
}
