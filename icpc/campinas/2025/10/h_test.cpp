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

#include<bits/extc++.h>
const int INF = numeric_limits<int>::max() / 4;

struct MCMF {
  struct edge {
    int from, to, rev, cap, flow, cost;
  };
  int N;
  vector<vector<edge>> ed;
  vector<int> seen, dist, pi;
  vector<edge *> par;
 
  MCMF(int N) : N(N), ed(N), seen(N), dist(N), pi(N), par(N) {}
 
  void addEdge(int from, int to, int cap, int cost) {
    if (from == to) return;
    ed[from].push_back(edge{from, to, SZ(ed[to]), cap, 0, cost});
    ed[to].push_back(edge{to, from, SZ(ed[from]) - 1, 0, 0, -cost});
  }
 
  void path(int s) {
    fill(ALL(seen), 0);
    fill(ALL(dist), INF);
    dist[s] = 0;
    int di;
 
    __gnu_pbds::priority_queue<ii> q;
    vector<decltype(q)::point_iterator> its(N);
    q.push({0, s});
 
    while (!q.empty()) {
      s = q.top().second;
      q.pop();
      seen[s] = 1;
      di = dist[s] + pi[s];
      for (edge &e : ed[s])
        if (!seen[e.to]) {
          int val = di - pi[e.to] + e.cost;
          if (e.cap - e.flow > 0 && val < dist[e.to]) {
            dist[e.to] = val;
            par[e.to] = &e;
            if (its[e.to] == q.end())
              its[e.to] = q.push({-dist[e.to], e.to});
            else
              q.modify(its[e.to], {-dist[e.to], e.to});
          }
        }
    }
    fore(i, 0, N) pi[i] = min(pi[i] + dist[i], INF);
  }
 
  ii maxflow(int s, int t) {
    int totflow = 0;
    int totcost = 0;
    while (path(s), seen[t]) {
      int fl = 2;
      for (edge *x = par[t]; x; x = par[x->from]) fl = min(fl, x->cap - x->flow);
 
      totflow += fl;
      for (edge *x = par[t]; x; x = par[x->from]) {
        x->flow += fl;
        ed[x->to][x->rev].flow -= fl;
      }
    }
    fore(i, 0, N) for (edge &e : ed[i]) totcost += e.cost * e.flow;
    return {totflow, totcost / 2};
  }
 
  void setpi(int s) {
    fill(ALL(pi), INF);
    pi[s] = 0;
    int it = N, ch = 1, v;
    while (ch-- && it--)
      fore(i, 0, N) if (pi[i] != INF) for (edge &e : ed[i]) if (e.cap) if ((v = pi[i] + e.cost) < pi[e.to]) pi[e.to] = v,
                                                                                                           ch = 1;
    assert(it >= 0);
  }
};
ll n,m;
ll cv(ll i, ll j){return m*i+j;}
ll in(ll i, ll j){return cv(i,j)*2;}
ll out(ll i, ll j){return cv(i,j)*2+1;}

int main(){
	TUCUTUCUTUCUTUCU
	cin>>n>>m;
	MCMF fl(2*(n*m+5));
	fore(i,0,n)fore(j,0,m){
		ll x; cin>>x;
		ll fg=(i==0&&j==0)||(i==n-1&&j==m-1);
		if(i<n-1)fl.addEdge(out(i,j),in(i+1,j),2,0);
		if(j<m-1)fl.addEdge(out(i,j),in(i,j+1),2,0);
		if(!fg)fl.addEdge(in(i,j),out(i,j),1,-x);
	}
	ll s=out(0,0),t=in(n-1,m-1);
	fl.setpi(s); // q pija es esto
	auto [res,cost]=fl.maxflow(s,t);
	assert(res==2);
	cout<<-cost<<"\n";
	return 0;
}