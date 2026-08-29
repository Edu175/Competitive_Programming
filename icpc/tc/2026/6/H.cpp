#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(a) {for(auto x:a)cout<<x<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll INF=1e18;

int main(){
	JET
	ll n,a,b,c; cin>>n>>a>>b>>c;
	vv dp(n+1,-INF); dp[0]=0;
	fore(i,1,n+1){
		auto &res=dp[i];
		if(a<=i)res=max(res,1+dp[i-a]);
		if(b<=i)res=max(res,1+dp[i-b]);
		if(c<=i)res=max(res,1+dp[i-c]);
	}
	cout<<dp[n]<<"\n";
	return 0;
}
