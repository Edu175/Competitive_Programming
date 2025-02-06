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
ll m;
ll in(ll i, ll j){return 2*(m*i+j);}
ll out(ll i, ll j){return in(i,j)+1;}
void adj(ll i0, ll j0, ll i1, ll j1, MCF &f){
	f.add_edge(out(i0,j0),in(i1,j1),INFFLOW,0);
}
int main(){FIN;
	ll n,m,k; cin>>n>>m>>k;
	MCF f(3*n*m);
	ll a[n][m];
	fore(i,0,n)fore(j,0,m)cin>>a[i][j];
	fore(i,0,n){
		fore(j,0,m){
			if(i)adj(i,j,i-1,j,f);
			if(j)adj(i,j,i,j-1,f);
			if(i<n-1)adj(i,j,i+1,j,f);
			if(j<m-1)adj(i,j,i,j+1,f);
			f.add_edge(in(i,j),out(i,j),INFFLOW,a[i][j]);
		}
	}
	ll s=2*n*m+5,t=s+1;
	fore(_,0,k){
		ll i,j; cin>>i>>j; i--,j--;
		if(!_)f.add_edge(out(i,j),t,INFFLOW,0);
		f.add_edge(s,in(i,j),1,0);
	}
	ii res=f.get_flow(s,t);
	//assert(res.fst==k);
	cout<<res.fst<<"\n";
	cout<<res.snd<<"\n";
	return 0;
}
