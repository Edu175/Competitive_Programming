#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll n; cin>>n;
	vector<ll>a;
	fore(i,0,n){
		string s; cin>>s;
		a.pb(SZ(s));
	}
	vector<vector<ll>>dp(n+5,vector<ll>(2));
	dp[n][0]=dp[n][1]=0;
	for(ll i=n-1;i>=0;i--){
		ll hor=max(a[i],dp[i+1][0]);
		dp[i][1]=hor;
		dp[i][0]=min(dp[i+1][1],hor);
	}
	ll res=max(dp[0][0],(ll)1);
	cout<<res<<"\n";
	return 0;
}
