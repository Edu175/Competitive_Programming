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
const ll MAXV=5050;
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n);
		ll g=0;
		fore(i,0,n)cin>>a[i],g=gcd(g,a[i]);
		ll cnt=count(ALL(a),g);
		if(cnt){
			cout<<n-cnt<<"\n";
			continue;
		}
		vector<vv> dp(n+3,vv(MAXV));
		fore(v,0,MAXV)dp[n][v]=n+5;
		dp[n][g]=0;
		for(ll i=n-1;i>=0;i--)fore(v,0,MAXV){
			auto &res=dp[i][v];
			res=min(dp[i+1][v],1+dp[i+1][gcd(v,a[i])]);
		}
		ll res=dp[0][0]-1+n-1;
		cout<<res<<"\n";
	}
	return 0;
}
