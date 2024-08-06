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
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

const ll M=55001;
int main(){FIN;
	vector<ll>fib={1,1};
	while(fib.back()<M)fib.pb(fib.back()+fib.end()[-2]);
	fib.pop_back();
	vector<ll>dp(M); dp[0]=0;
	ll mx=0;
	fore(i,1,M){
		dp[i]=i+1;
		for(auto v:fib)if(i>=v)dp[i]=min(dp[i],dp[i-v]+1);
		mx=max(mx,dp[i]);
	}
	fore(i,0,M)cout<<i<<": "<<dp[i]<<"\n";
	cout<<"max "<<mx<<"\n";
	return 0;
}