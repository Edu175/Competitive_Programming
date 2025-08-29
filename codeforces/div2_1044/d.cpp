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
		ll sum=0;
		fore(i,0,n)cin>>a[i],sum+=a[i];
		vv dp(n+5);
		a.pb(0);
		ll mx=0;
		for(ll i=n-1;i>=0;i--){
			dp[i]=mx-2+min(i+1,a[i+1]);
			dp[i]=max(dp[i],dp[i+1]-1);
			// cout<<"dp "<<i<<": "<<dp[i]<<"\n";
			ll j=i+1;
			if(j<n){
				ll cur=dp[j];
				mx=max(mx,cur);
				// cerr<<"cur "<<j<<": "<<cur<<"\n";
			}
		}
		ll res=sum-n-dp[0];
		cout<<res<<"\n";
	}
	return 0;
}
