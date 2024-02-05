#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MOD=1e9+7;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
const ll MAXN=1005;
ll dp[MAXN][MAXN];
int main(){FIN;
	ll n; cin>>n;
	char a[n][n];
	fore(i,0,n)fore(j,0,n)cin>>a[i][j];
	for(ll i=n;i>=0;i--)for(ll j=n;j>=0;j--){
		ll &res=dp[i][j];
		res=0;
		if(a[i][j]=='*'||i==n||j==n)continue;
		if(i==n-1&&j==n-1){res=1;continue;}
		res=add(dp[i+1][j],dp[i][j+1]);
	}
	cout<<dp[0][0]<<"\n";
	return 0;
}

