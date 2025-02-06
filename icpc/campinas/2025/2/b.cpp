#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b; i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MOD=1e9+7;

ll add(ll a, ll b){a+=b;if(a>=MOD)a-=MOD;return a;}
ll sub(ll a, ll b){a-=b;if(a<MOD)a+=MOD;return a;}
ll mul(ll a, ll b){return a*b%MOD;}
void sumale(ll &a, ll b){a=add(a,b);}

int main(){
	JET
	ll n,m; cin>>n>>m;
	vector<vector<vv>> dp(n+5,vector<vv>(n+5,vv(2)));
	dp[0][0][1]=1;
	// cout<<m<<" m\n";
	fore(i,1,n+1)fore(k,0,i+1){
		auto &res0=dp[i][k][0];
		auto &res1=dp[i][k][1];
		fore(fg,0,2)if(k-fg>=0&&m-k>=0)sumale(res0,mul(dp[i-1][k-fg][fg],m-k+fg));
		fore(fg,0,2)sumale(res1,mul(dp[i-1][k][fg],k));
		// cout<<i<<" "<<k<<": "<<res0<<" "<<res1<<"\n";
	}
	ll res=0;
	fore(k,0,n+3)res=add(res,dp[n][k][1]);
	cout<<res<<"\n";
	return 0;
}