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

vector<ll> eulerWalk(vector<queue<ii>>& g, ll nedges, ll src=0) {
	ll n = SZ(g);
	vector<ll> D(n), its(n), eu(nedges), ret;
	vector<ii> s = {{src,-1}};
	D[src]++; // to allow Euler paths, not just cycles
	while (!s.empty()) {
		auto [x,e] = s.back(); 
		ll y;
		if (g[x].empty()){ ret.pb(e); s.pop_back(); continue; }
		tie(y, e) = g[x].front(); g[x].pop();
		if (!eu[e]) {
			D[x]--, D[y]++;
			eu[e] = 1; s.pb({y,e});
		}}
	ret.pop_back();
	reverse(ALL(ret));
	// for (ll x : D) if (x < 0 || SZ(ret) != nedges) return {};
	return ret;
}

void impQ(queue<ii> q){
	while(SZ(q)){
		auto [x,y]=q.front(); q.pop();
		cout<<x<<","<<y<<" ";
	}
	cout<<"\n";
}

int main(){FIN;
	ll t; cin>>t;
	fore(__,0,t){
		cout<<"Case #"<<__+1<<": ";
		ll n,m; cin>>n>>m;
		vector<queue<ii>> g(n);
		fore(i,0,m){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].push({v,i});
			g[v].push({u,i});
		}
		ll src=0;
		fore(x,0,n)if(SZ(g[x])&1)src=x;
		auto r=eulerWalk(g,m,src);
		imp(r)
		fore(x,0,n){
			impQ(g[x]);
		}
	}
	return 0;
}
