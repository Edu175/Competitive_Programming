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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		vector<ll>a(n);
		fore(i,0,n)cin>>a[i];
		vector<vector<ll>>dp(n+20,vector<ll>(k+5));
		for(ll i=n-1;i>=0;i--)fore(c,0,k+1){
			ll &res=dp[i][c];
			res=dp[i+1][c]+a[i];
			fore(j,0,c+1){
				if(i+j>=n)break;
				res=min({res,a[i]*(j+1)+dp[i+j+1][c-j],a[i+j]*j+dp[i+j][c-j]});
			}
		}
		cout<<dp[0][k]<<"\n";
	}
	return 0;
}
