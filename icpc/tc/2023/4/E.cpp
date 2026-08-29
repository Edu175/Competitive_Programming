#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
/**
 * Author: Stanford
 * Date: Unknown
 * Source: Stanford Notebook
 * Description: Min-cost max-flow.
 *  If costs can be negative, call setpi before maxflow, but note that negative cost cycles are not supported.
 *  To obtain the actual flow, look at positive values only.
 * Status: Tested on kattis:mincostmaxflow, stress-tested against another implementation
 * Time: $O(F E \log(V))$ where F is max flow. $O(VE)$ for setpi.
 */

#include <bits/extc++.h> /// include-line, keep-include

const ll INF = numeric_limits<ll>::max() / 4;

struct MCMF {
	struct edge {
		int from, to, rev;
		ll cap, cost, flow;
	};
	int N;
	vector<vector<edge>> ed;
	vv seen;
	vector<ll> dist, pi;
	vector<edge*> par;

	MCMF(int N) : N(N), ed(N), seen(N), dist(N), pi(N), par(N) {}

	void add_edge(int from, int to, ll cap, ll cost) {
		if (from == to) return;
		ed[from].push_back(edge{ from,to,SZ(ed[to]),cap,cost,0 });
		ed[to].push_back(edge{ to,from,SZ(ed[from])-1,0,-cost,0 });
	}

	void path(int s) {
		fill(ALL(seen), 0);
		fill(ALL(dist), INF);
		dist[s] = 0; ll di;

		__gnu_pbds::priority_queue<pair<ll, int>> q;
		vector<decltype(q)::point_iterator> its(N);
		q.push({ 0, s });

		while (!q.empty()) {
			s = q.top().second; q.pop();
			seen[s] = 1; di = dist[s] + pi[s];
			for (edge& e : ed[s]) if (!seen[e.to]) {
				ll val = di - pi[e.to] + e.cost;
				if (e.cap - e.flow > 0 && val < dist[e.to]) {
					dist[e.to] = val;
					par[e.to] = &e;
					if (its[e.to] == q.end())
						its[e.to] = q.push({ -dist[e.to], e.to });
					else
						q.modify(its[e.to], { -dist[e.to], e.to });
				}
			}
		}
		fore(i,0,N) pi[i] = min(pi[i] + dist[i], INF);
	}

	pair<ll, ll> maxflow(int s, int t) {
		ll totflow = 0, totcost = 0;
		while (path(s), seen[t]) {
			ll fl = INF;
			for (edge* x = par[t]; x; x = par[x->from])
				fl = min(fl, x->cap - x->flow);

			totflow += fl;
			for (edge* x = par[t]; x; x = par[x->from]) {
				x->flow += fl;
				ed[x->to][x->rev].flow -= fl;
			}
		}
		fore(i,0,N) for(edge& e : ed[i]) totcost += e.cost * e.flow;
		return {totflow, totcost/2};
	}

	// If some costs can be negative, cALL this before maxflow:
	void setpi(int s) { // (otherwise, leave this out)
		fill(ALL(pi), INF); pi[s] = 0;
		int it = N, ch = 1; ll v;
		while (ch-- && it--)
			fore(i,0,N) if (pi[i] != INF)
			  for (edge& e : ed[i]) if (e.cap)
				  if ((v = pi[i] + e.cost) < pi[e.to])
					  pi[e.to] = v, ch = 1;
		assert(it >= 0); // negative cost cycle
	}
};
int main(){FIN;
	#ifdef ONLINE_JUDGE
	freopen("inspection.in","r",stdin);
	freopen("inspection.out","w",stdout);
	#endif
	ll n; cin>>n;
	vector<ii> ed;
	fore(x,0,n){
		ll k; cin>>k;
		fore(_,0,k){
			ll y; cin>>y; y--;
			ed.pb({x,y});
		}
	}
	ll m=SZ(ed);
	ll nodes=n,s=nodes,sp=nodes+1,t=nodes+2;
	MCMF fl(nodes+5);
	fl.add_edge(s,sp,m,0);
	fl.add_edge(sp,t,INF,-1);
	ll C=1e5;
	fore(x,0,n){
		fl.add_edge(sp,x,INF,0);
		fl.add_edge(x,t,INF,0);
	}
	for(auto [x,y]:ed){
		fl.add_edge(x,y,1,-C);
		fl.add_edge(x,y,INF,0);
	}
	fl.setpi(s);
	auto [flow,cost]=fl.maxflow(s,t);
	ll res=m+cost%C;
	// cerr<<"res "<<res<<"\n";
	// cerr<<"s "<<s<<"\n";
	// cerr<<"sp "<<sp<<"\n";
	// cerr<<"t "<<t<<"\n";
	vector<vv> ps;
	while(SZ(ps)<res){
		vv p;
		for(ll x=sp;x!=t;){
			ll wh=-1;
			// cerr<<"x "<<x<<"\n";
			// for(auto e:fl.g[x])if(e.cap>0){
			// 	cerr<<e.to<<","<<e.f<<"/"<<e.cap<<" ";
			// }
			// cerr<<"\n";
			for(auto &e:fl.ed[x])if(e.cap>0&&e.flow>0){
				wh=e.to,e.flow--;
				break;
			}
			x=wh;
			p.pb(x);
		}
		// cerr<<"path "; show(p)
		assert(p.back()==t);
		p.pop_back();
		if(SZ(p))ps.pb(p);
	}
	cout<<SZ(ps)<<"\n";
	for(auto p:ps){
		for(auto i:p)cout<<i+1<<" ";;cout<<"\n";
	}
	return 0;
}
