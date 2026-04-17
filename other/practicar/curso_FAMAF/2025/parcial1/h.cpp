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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		vv deg(n);
		fore(i,0,m){
			ll u,v; cin>>u>>v; u--,v--;
			deg[u]++,deg[v]++;
		}
		vv oc(n);
		vv vals;
		for(auto i:deg)if(i>1)oc[i]++,vals.pb(i);
		sort(ALL(vals));
		ll a=vals[0],b=vals.back();
		for(auto x:set({a,b})){
			oc[x]--;
			ll y=a^b^x;
			if(oc[y]==x)cout<<x<<" "<<y-1<<"\n";
			oc[x]++;
		}
	}
	return 0;
}