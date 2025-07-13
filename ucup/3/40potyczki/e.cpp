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
#define ppc __builtin_popcountll
int main(){FIN;
	ll n; cin>>n;
	vv a(n);
	fore(i,0,n)cin>>a[i];
	vv dp(n+5);
	vv suf(n+1);
	for(ll i=n-1;i>=0;i--){
		ll e=min(n,i+65);
		auto &res=dp[i];
		fore(j,i+1,e+1){
			if(j==n||ppc(a[i]^a[j])<=j-i)res=max(res,dp[j]);
		}
		res=max(res,suf[e]);
		res++; // yo
		suf[i]=max(suf[i+1],res);
		// cout<<i<<": "<<res<<"\n";
	}
	ll res=suf[0];
	res=n-res;
	cout<<res<<"\n";
	return 0;
}
