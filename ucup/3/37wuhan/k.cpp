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
typedef ll tf;
typedef ll tc;
const tf INFFLOW=1e9;
const tc INFCOST=1e18;
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
// const ll C=50*1e8*  10+5;
const ll C=1e10;
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m; // n casinos
		vector<vv> a(n,vv(m));
		ll nodes=n+m,s=nodes,t=nodes+1,nadie=nodes+2,rew=nodes+3;
		vv tie(n),win(n),who(n,nadie),goes(n,nadie);
		fore(i,0,n){
			map<ll,ll>mp;
			fore(j,0,m)cin>>a[i][j],mp[a[i][j]]++;
			tie[i]=1; // doesnt matter actually
			vector<ii>h;
			fore(j,0,m){
				ll v=a[i][j];
				if(!v)continue;
				if(mp[v]==1)h.pb({v,j});
			}
			h.pb({-5,nadie});
			h.pb({-5,nadie});
			sort(ALL(h)); reverse(ALL(h));
			who[i]=h[0].snd;
			goes[i]=h[1].snd;
			if(who[i]!=nadie)tie[i]=h[0].fst;
			else assert(goes[i]==nadie); // no se va a usar
			win[i]=tie[i];
			while(mp.count(win[i]))win[i]++;
			// cout<<i<<": "<<tie[i]<<","<<win[i]<<" "<<who[i]<<" "<<goes[i]<<"\n";
		}
		vv hist(nodes+5);
		fore(i,0,n)hist[who[i]]++;
		MCF bst(0);
		ll hay=0,bcost=0;
		fore(k,0,n+5){
			MCF fl(nodes+5);
			// personas
			fore(i,0,m){
				fl.add_edge(s,i,hist[i],0);
				fl.add_edge(i,t,k,0);
			}
			fl.add_edge(s,nadie,hist[nadie],0);
			fl.add_edge(nadie,t,INFFLOW,0);
			// casinos
			fore(i,0,n){
				ll x=i+m;
				fl.add_edge(who[i],x,1,0);
				fl.add_edge(x,goes[i],1,tie[i]);
				fl.add_edge(x,t,1,win[i]);
				fl.add_edge(x,rew,1,win[i]-C);
			}
			// reward
			fl.add_edge(rew,t,k,0);
			
			auto [flow,cost]=fl.get_flow(s,t);
			cost+=k*C;
			// cout<<k<<":\n";
			// cout<<flow<<" "<<cost<<"\n";
			if(flow<n||cost >= C)continue;
			// cout<<"good\n";
			// cout<<endl;
			if(!hay||cost<bcost)bcost=cost,bst=fl,hay=1;
		}
		assert(hay);
		fore(i,0,n){
			ll x=i+m;
			vv cs;
			for(auto y:bst.g[x])if(y.f==1)cs.pb(y.cost);
			assert(SZ(cs)<=1);
			ll res=SZ(cs)?cs[0]:0;
			if(res<0)res+=C;
			cout<<res<<" ";
		}
		cout<<"\n";
		
	}
	return 0;
}
