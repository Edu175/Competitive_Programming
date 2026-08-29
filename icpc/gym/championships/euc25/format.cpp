#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(x) {for(auto y:x)cout<<y<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

int main(){
	JET
	ll n,m; cin>>n>>m;
	vector<ii> ed;
	vv vals;
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		ed.pb({u,v}); vals.pb(u); vals.pb(v);
	}
	sort(ALL(vals)); vals.resize(unique(ALL(vals))-vals.begin());
	auto get_idx=[&](ll x){return lower_bound(ALL(vals),x)-vals.begin();};
	for(auto [x,y]:ed)cout<<get_idx(x)+1<<" "<<get_idx(y)+1<<"\n";
	return 0;
}
