#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b; i<jet;i++)
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=3e6;

vii eulerWalk(vector<vector<ii>>& gr, ll nedges, ll src = 0) {
  ll n = SZ(gr);
  vi D(n), its(n), eu(nedges);
  vii ret, s = {{src, -1}};
  D[src]++;
  while (!s.empty()) {
    auto [x, e] = s.back();
    ll &it = its[x], end = SZ(gr[x]);
    if (it == end) {
      ret.pb({x, e});
      s.pop_back();
      continue;
    }
    ll y;
    tie(y, e) = gr[x][it++];
    if (!eu[e]) {
      D[x]--, D[y]++;
      eu[e] = 1; s.pb({y, e});
    }
  }
  for (ll x : D) if (x < 0 || SZ(ret) != nedges+1) return {};
  return {ret.rbegin(), ret.rend()};
}
 
 
bool can(ll m, const vector<ii>& edges) {
  ll n = edges.size();
 
  ll new_n = 1 << m;
  vector<ii> new_edges(n);
  fore(i, 0, n) {
    auto [u, v] = edges[i];
    new_edges[i] = {u & (new_n - 1), v & (new_n - 1)};
  }
 
  vector<vv> adj(new_n);
  for (auto [u, v] : new_edges) {
    adj[u].push_back(v), adj[v].push_back(u);
  }
 
  vector<bool> vis(new_n, false);
  vv s = {new_edges[0].first};
  vis[new_edges[0].first] = true;
  while (!s.empty()) {
    ll u = s.back();
    s.pop_back();
 
    for (ll v : adj[u]) {
      if (!vis[v]) {
        vis[v] = true;
        s.push_back(v);
      }
    }
  }
 
  fore(i, 0, new_n) {
    if (adj[i].size() > 0 && !vis[i]) {
      return false;
    }
  }
 
  vv deg(new_n);
  for (auto [u, v] : new_edges) {
    deg[u]++, deg[v]++;
  }
 
  fore(i, 0, new_n) {
    if (deg[i] % 2 != 0) {
      return false;
    }
  }
 
  return true;
}
struct trie{
	ll tr[MAXN][30]; ll qidx=0;
	ll add(ll x, char c){
		ll &res=tr[x][c];
		if(res!=-1)return res;
		return res=++qidx;
	}
};

int main(){JET
	
	return 0;
}