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
const ll MOD=1e9+7;

int main(){FIN;
	ll n,k; cin>>n>>k;
	ll a[n];
	fore(i,0,n)cin>>a[i];
	ll dp[n+5][k+5];
	mset(dp,0);
	dp[0][0]=1;
	fore(i,0,n){
		ll sp[k+2];
		sp[0]=0;
		fore(j,1,k+2)sp[j]=sp[j-1]+dp[i][j-1]%MOD;
		fore(j,0,k+1){
			dp[i+1][j]=(sp[j+1]-(j-a[i]>=0?sp[j-a[i]]:0)+MOD)%MOD;
		}
	}
	cout<<dp[n][k]<<"\n";
	return 0;
}
