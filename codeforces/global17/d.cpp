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
const ll MOD=1e9+7;

int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}

ll fac(ll n){return __builtin_ctzll(n);}
const ll B=35;
int main(){FIN;
	ll n; cin>>n;
	vv a(n);
	fore(i,0,n)cin>>a[i];
	vv b;
	fore(i,0,n)if(a[i]%2==0)b.pb(a[i]);
	ll res=mul(sub(fpow(2,n-SZ(b)),1),fpow(2,SZ(b)));
	a=b; n=SZ(a);
	// vector<vector<vector<vv>>>dp(n+3,vector<vv>(B,vv(2)));
	ll dp[n+3][B][2][2]; mset(dp,0);
	fore(i,0,B)dp[n][i][1][0]=1;
	for(ll i=n-1;i>=0;i--)fore(c,0,B)fore(did,0,2)fore(p,0,2){
		auto &res=dp[i][c][did][p];
		res=dp[i+1][c][did][p];
		ll q=fac(a[i]);
		if(q>=c)res=add(res,dp[i+1][c][did||q==c][p^(q==c)]);
	}
	ll sum=0;
	fore(i,0,B){
		sum=add(sum,dp[0][i][0][0]);
		// cout<<i<<": "<<dp[0][i][0][0]<<"\n";
	}
	// cout<<res<<" "<<sum<<"\n";
	cout<<add(res,sum)<<"\n";
	return 0;
}
