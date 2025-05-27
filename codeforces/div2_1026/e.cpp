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
#define impr(v) {for(auto i:v)cout<<i.fst<<","<<i.snd<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
// EULER WALK
// not tested
// returns edge indices
vector<ll> eulerWalk(vector<vector<ii>>& gr, ll nedges, ll src=0) {
	ll n = SZ(gr);
	vector<ll> D(n), its(n), eu(nedges), ret;
	vector<ii> s = {{src,-1}};
	D[src]++; // to allow Euler paths, not just cycles
	while (!s.empty()) {
		// imp(s);
		auto [x,e] = s.back(); 
		ll y, &it = its[x], end = SZ(gr[x]);
		if (it == end){ ret.pb(e); s.pop_back(); continue; }
		tie(y, e) = gr[x][it++];
		if (!eu[e]) {
			D[x]--, D[y]++;
			eu[e] = 1; s.pb({y,e});
		}}
	// imp(ret)
	ret.pop_back();
	reverse(ALL(ret));
	// imp(ret)
	// imp(D)
	for (ll x : D) if (x < 0 || SZ(ret) != nedges) return {};
	return ret;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll m; cin>>m;
		map<ll,ll>le,ri;
		auto get_idx=[&](ll v, map<ll,ll>&mp){
			if(mp.count(v))return mp[v];
			ll ret=SZ(mp);
			return mp[v]=ret;
		};
		vector<vector<ii>>gr(2*m);
		fore(i,0,m){
			ll u,v; cin>>u>>v;
			u=get_idx(u,le);
			v=get_idx(v,ri)+m;
			gr[u].pb({v,i});
			gr[v].pb({u,i});
		}
		ll src=0;
		fore(i,0,2*m){
			if(SZ(gr[i])&1)src=i;
			// cout<<i<<": "; impr(gr[i])
		}
		// cout<<"src "<<src<<"\n";
		auto r=eulerWalk(gr,m,src);
		if(!SZ(r))cout<<"NO\n";
		else {
			cout<<"YES\n";
			for(auto i:r)cout<<i+1<<" ";;cout<<"\n";
		}
	}
	return 0;
}
