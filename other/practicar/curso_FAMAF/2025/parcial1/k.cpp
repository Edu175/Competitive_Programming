#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define forr(i,a,b) for(ll i=b-1,jet=a;i>=jet;--i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MOD=1e9+7;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k; k--;
		vector<vector<ll>> dp(n+1,vv(k+1));
		fore(t,0,k+1)dp[n][t]=1;
		fore(t,0,k+1)forr(i,0,n){
			auto &res=dp[i][t];
			res=dp[i+1][t];
			if(t>0)res=add(res,dp[n-i][t-1]);
		}
		cout<<dp[0][k]<<"\n";
	}
	return 0;
}