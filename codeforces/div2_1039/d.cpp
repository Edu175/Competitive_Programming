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
		ll n; cin>>n;
		vv a(n);
		fore(i,0,n)cin>>a[i];
		a.pb(0);
		vv dp(n+1);
		ll sum=0;
		for(ll i=n-1;i>=0;i--){
			if(a[i]>a[i+1])dp[i]=dp[i+1]+n-i;
			else dp[i]=dp[i+1]+1;
			sum+=dp[i];
		}
		cout<<sum<<"\n";
	}
	return 0;
}
