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
const ll MAXN=1e5+5,MAXM=105;

ll dp[MAXN][MAXM];

int main(){FIN;
	ll n,m; cin>>n>>m;
	vector<ll>a(n);
	fore(i,0,n)cin>>a[i];
	fore(i,0,n)dp[i][m+1]=dp[i][0]=0;
	for(ll i=n-1;i>=0;i--)fore(v,1,m+1){
		ll &res=dp[i][v];
		if(a[i]&&v!=a[i]){res=0;continue;}
		if(i==n-1){res=1;continue;}
		res=add(dp[i+1][v-1],add(dp[i+1][v],dp[i+1][v+1]));
	}
	ll res=dp[0][a[0]];
	if(a[0]==0)fore(v,1,m+1)res=add(res,dp[0][v]);
	cout<<res<<"\n";
	return 0;
}
