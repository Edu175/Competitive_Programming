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
const ll INF=1e16;
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		vv a(n);
		fore(i,0,n)cin>>a[i];
		vector<vector<ii>> g(n);
		fore(i,0,m){
			ll u,v,w; cin>>u>>v>>w; u--,v--;
			g[u].pb({v,w});
		}
		auto get=[&](ll m){
			vv dp(n);
			dp[n-1]=m;
			for(ll i=n-2;i>=0;i--){
				auto &res=dp[i];
				res=-INF;
				for(auto [y,w]:g[i])
					if(dp[y]>=w)res=max(res,dp[y]);
				res-=a[i];
			}
			return dp[0];
		};
		ll l=0,r=INF;
		while(l<=r){
			ll m=(l+r)/2;
			if(get(m)>=0)l=m+1;
			else r=m-1;
		}
		cout<<l<<"\n";
	}
	return 0;
}
