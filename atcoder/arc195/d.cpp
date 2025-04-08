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
		vv a(n+1);
		fore(i,0,n)cin>>a[i];
		vector<vv> dp(n+1,vv(4));
		for(ll i=n-1;i>=0;i--)fore(mk,0,4){
			if(!i&&mk)continue;
			if(i==1&&(mk&2))continue;
			auto &res=dp[i][mk];
			ll bck=-1;
			if(i)bck=(mk&2?a[i-2]:a[i-1]);
			ll mki=mk<<1&3;
			ll go0=dp[i+1][mki]+(a[i]!=bck);
			ll go1=1+dp[i+1][mki|1]+(a[i+1]!=bck);
			res=go0;
			if(!(mk&1)&&i<n-1)res=min(res,go1);
			// cout<<i<<" "<<mk<<": "<<go0<<" "<<go1<<"\n";
		}
		cout<<dp[0][0]<<"\n";
	}
	return 0;
}
