#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=2e5+5;

ll dp[MAXN],maxp[MAXN];

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n+3){
			dp[i]=0;
			maxp[i]=0;
		}
		ll a[n];
		fore(i,0,n)cin>>a[i],a[i]--;
		dp[n]=0;
		for(ll i=n-1;i>=0;i--){
			ll &res=dp[i];
			res=max(maxp[a[i]]-i,dp[i+1]);
			//cout<<i<<": "<<maxp[a[i]]<<"-"<<i<<","<<dp[i+1]<<": "<<res<<"\n";
			maxp[a[i]]=max(maxp[a[i]],dp[i+1]+i+1);
		}
		cout<<dp[0]<<"\n";
	}
	return 0;
}
