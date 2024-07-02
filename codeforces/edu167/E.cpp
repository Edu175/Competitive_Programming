#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MOD=998244353;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int main(){FIN;
	ll n,k; cin>>n>>k;
	vector<vector<ll>>dp(n+5,vector<ll>(2));
	dp[n][1]=1;
	// fore(i,0,n+1)cout<<dp[i][1]<<" ";;cout<<"\n";
	fore(__,0,k){
		ll s=0,_=__&1;
		auto get=[&](ll i){
			int tmp=(__==k-1?dp[i][_]:0);
			return add(tmp,dp[i][_^1]);
		};
		for(ll i=n;i>=0;i--){
			dp[i][_]=add(get(i+1),s);
			if(i==0||i==n-2)dp[i][_]=add(dp[i][_],get(i+2));
			s=add(s,get(i+2));
		}
		// fore(i,0,n+1)cout<<dp[i][_]<<" ";;cout<<"\n";
	}
	cout<<dp[0][(k&1)^1]<<"\n";
	return 0;
}