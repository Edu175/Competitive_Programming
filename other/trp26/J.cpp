#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){FIN;
	ll n; cin>>n;
	vv a(n+1); // 1-index
	fore(i,1,n+1)cin>>a[i];
	vector<vv> dp(n+2,vv(n+2,1));
	for(ll l=n;l>=1;l--)fore(r,l,n+1){
		auto &res=dp[l][r];
		res=n+5;
		if(a[l]==a[r])res=dp[l+1][r-1];
		fore(m,l,r){
			ll cur=dp[l][m]+dp[m+1][r];
			res=min(res,cur);
		}
		// cerr<<l<<","<<r<<": "<<res<<"\n";
	}
	cout<<dp[1][n]<<"\n";
	return 0;
}
