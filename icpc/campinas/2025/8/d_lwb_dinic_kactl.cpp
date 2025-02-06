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
// AC
#pragma GCC optimize("Ofast,O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
const ll INF=1e6;

/**
 * Author: chilli
 * Date: 2019-04-26
 * License: CC0
 * Source: https://cp-algorithms.com/graph/dinic.html
 * Description: Flow algorithm with complexity $O(VE\log U)$ where $U = \max |\text{cap}|$.
 * $O(\min(E^{1/2}, V^{2/3})E)$ if $U = 1$; $O(\sqrt{V}E)$ for bipartite matching.
 * Status: Tested on SPOJ FASTFLOW and SPOJ MATCHING, stress-tested
 */

struct Dinic {
	struct Edge {
		ll to, rev;
		ll c, oc;
		ll flow() { return max(oc - c, 0); } // if you need flows
	};
	vv lvl, ptr, q;
	vector<vector<Edge>> adj;
	Dinic(ll n) : lvl(n), ptr(n), q(n), adj(n) {}
	void addEdge(ll a, ll b, ll c, ll rcap = 0) {
		adj[a].pb({b, SZ(adj[b]), c, c});
		adj[b].pb({a, SZ(adj[a]) - 1, rcap, rcap});
	}
	ll dfs(ll v, ll t, ll f) {
		if (v == t || !f) return f;
		for (ll& i = ptr[v]; i < SZ(adj[v]); i++) {
			Edge& e = adj[v][i];
			if (lvl[e.to] == lvl[v] + 1)
				if (ll p = dfs(e.to, t, min(f, e.c))) {
					e.c -= p, adj[e.to][e.rev].c += p;
					return p;
				}
		}
		return 0;
	}
	ll calc(ll s, ll t) {
		ll flow = 0; q[0] = s;
		/*fore(L,0,31)*/ll L=30; do { // 'll L=30' maybe faster for random data
			lvl = ptr = vv(SZ(q));
			ll qi = 0, qe = lvl[s] = 1;
			while (qi < qe && !lvl[t]) {
				ll v = q[qi++];
				for (Edge e : adj[v])
					if (!lvl[e.to] && e.c >> (30 - L))
						q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
			}
			while (ll p = dfs(s, t, INF)) flow += p;
		} while (lvl[t]);
		return flow;
	}
	bool leftOfMinCut(ll a) { return lvl[a] != 0; }
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
	fore(i,0,cnt)if(!col[i])for(auto j:g[i])fl.addEdge(i,j,1);
	ll acum=0;
	auto add_demand=[&](ll x, ll y, ll d, ll c){ // d <= c
		if(d)fl.addEdge(s_,y,d);
		// fl.add_edge(t,s,d);
		acum+=d;
		if(d)fl.addEdge(x,t_,d);
		if(c-d)fl.addEdge(x,y,c-d);
	};
	fore(x,0,cnt){
		ll m=SZ(g[x]);
		if(!col[x])add_demand(s,x,m/2,(m+1)/2);
		else add_demand(x,t,m/2,(m+1)/2);
	}
	if(acum)fl.addEdge(t,s,acum);
	ll res=fl.calc(s_,t_);
	vv ans(n);
	fore(x,0,cnt)if(!col[x]){
		for(auto e:fl.adj[x])if(e.to<cnt){
			if(e.flow()==1)ans[id[x][e.to]]=1;
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