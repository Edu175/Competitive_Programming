#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef int ll;
typedef pair<ll,ll> ii;
const ll MAXN=1e5+5, INF=1e9;

ll a[MAXN];
ll dp[MAXN][5];

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n)cin>>a[i];
		dp[n][0]=0;
		fore(i,1,4)dp[n][i]=-INF;
		for(ll i=n-1;i>=0;i--)fore(c,0,4){
			ll &res=dp[i][c];
			//res=dp[i+1][3];
			if(c==0){
				res=0;
				continue;
			}
			res=max(dp[i+1][c]-1,dp[i+1][c-1]+a[i]-1);
			//cout<<i<<" "<<c<<": "<<res<<"\n";
		}
		ll res=0;
		fore(i,0,n)res=max(res,dp[i][3]);
		cout<<res+1<<"\n";
	}
	return 0;
}
