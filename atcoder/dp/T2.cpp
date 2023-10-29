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
const ll MAXN=3005,MOD=1e9+7;

ll dp[MAXN][MAXN];

int main(){FIN;
	ll n; cin>>n;
	string s; cin>>s; s.pb('<');
	dp[0][0]=1;
	fore(i,1,n+1){
		if(s[i-1]=='>'){
			dp[i][i]=0;
			for(ll j=i-1;j>=0;j--){
				dp[i][j]=(dp[i][j+1]+dp[i-1][j])%MOD;
			}
		}
		else {
			dp[i][0]=0;
			fore(j,1,i+1){
				dp[i][j]=(dp[i][j-1]+dp[i-1][j-1])%MOD;
			}
		}
	}
	ll res=dp[n][n];
	cout<<res<<"\n";
	return 0;
}
