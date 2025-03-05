#include<bits/stdc++.h>
#define fore(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define TUCUTUCUTUCUTUCU ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
#define int ll
typedef ll tf;
typedef ll tc;
const tc INFCOST = numeric_limits<int>::max() / 4;
const tf INFFLOW=INFCOST;
ll cnt=0;
struct MCF{
	int n;
	vector<tc> prio, pot; vector<tf> curflow; vector<int>  prevedge,prevnode;
	priority_queue<pair<tc,int>,vector<pair<tc, int>>, greater<pair<tc, int>>> q;
	struct edge{int to, rev;tf f, cap;tc cost;};
	vector<vector<edge>> g;
	// MCF(int n) : n(n),prio(n),curflow(n),prevedge(n),prevnode(n),pot(n),g(n){}
	MCF(int n) : n(n),prio(n),pot(n),curflow(n),prevedge(n),prevnode(n),g(n){}
	
	void add_edge(int s, int t, tf cap, tc cost){
		assert(max(s,t)<n);
		g[s].pb((edge){t,SZ(g[t]),0,cap,cost});
		g[t].pb((edge){s,SZ(g[s])-1,0,0,-cost});
		
	}
	
	pair<tf,tc> get_flow(int s, int t){
		tf flow = 0; tc flowcost =0;
		while(1){
			q.push({0,s});
			fill(ALL(prio),INFCOST);
			prio[s]=0;curflow[s]=INFFLOW;
			while(!q.empty()){
				cnt++;
				auto cur = q.top();
				tc d = cur.fst;
				int u = cur.snd;
				q.pop();
				if(d!=prio[u]) continue;
				for(int i=0;i<SZ(g[u]);++i){
					edge &e = g[u][i];
					int v=e.to;
					if(e.cap<=e.f) continue;
					tc nprio = prio[u]+e.cost+pot[u]-pot[v];
					if(prio[v]>nprio){
						prio[v]=nprio;
						q.push({nprio,v});
						prevnode[v]=u; prevedge[v]=i;
						curflow[v]=min(curflow[u],e.cap-e.f);
					}
				}
			}
			if(prio[t]==INFCOST) break;
			fore(i,0,n) pot[i]+=prio[i];
			tf df = min(curflow[t],INFFLOW-flow);
			flow+=df;
			for(int v=t;v!=s;v=prevnode[v]){
				edge &e = g[prevnode[v]][prevedge[v]];
				e.f+=df; g[v][e.rev].f-=df;
				flowcost+=df*e.cost;
			}
			
		}
		return {flow,flowcost};
		
	}
};

ll n,m;
ll cv(ll i, ll j){return m*i+j;}
ll in(ll i, ll j){return cv(i,j)*2;}
ll out(ll i, ll j){return cv(i,j)*2+1;}

signed main(){
	TUCUTUCUTUCUTUCU
	cin>>n>>m;
	MCF fl(2*(n*m+5));
	fore(i,0,n)fore(j,0,m){
		ll x; cin>>x;
		ll fg=(i==0&&j==0)||(i==n-1&&j==m-1);
		if(i<n-1)fl.add_edge(out(i,j),in(i+1,j),2,0);
		if(j<m-1)fl.add_edge(out(i,j),in(i,j+1),2,0);
		if(!fg)fl.add_edge(in(i,j),out(i,j),1,-x);
	}
	ll s=out(0,0),t=in(n-1,m-1);
	auto [res,cost]=fl.get_flow(s,t);
	assert(res==2);
	cout<<-cost<<"\n";
	cerr<<cnt<<" cnt\n";
	return 0;
}