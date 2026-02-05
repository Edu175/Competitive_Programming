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
const ll INF=1e18;

// assuming all same parity r's have the same sequence of adds
// except for l=r when ans=0

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n);
		fore(i,0,n)cin>>a[i];
		vector<vector<vv>> dp(n+1,vector<vv>(3,vv(2)));
		vector<vv> cant(n+1,vv(2));
		for(ll i=n-1;i>=0;i--)cant[i]=cant[i+1],cant[i][i&1]++;
		ll ans=0;
		for(ll i=n-1;i>=0;i--){
			vv best(2,INF);
			fore(now,0,3){
				auto &res=dp[i][now];
				res={INF,INF};
				fore(od,0,2){
					fore(prox,0,3){
						if(i==n-1||a[i]+now!=a[i+1]+prox){
							res[od]=min(res[od],dp[i+1][prox][od]);
						}
					}
					res[od]+=cant[i+1][od]*now;
					best[od]=min(best[od],res[od]);
				}
				res[i&1]+=now;
			}
			// cout<<i<<": "<<best[0]<<" "<<best[1]<<"\n";
			ans+=best[0]+best[1];
		}
		cout<<ans<<"\n";
	}
	return 0;
}
