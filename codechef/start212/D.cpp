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
	if(b<0)return 0;
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
#define addig(a,b)a=add(a,b)
// el del mex
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		if(n==1){
			cout<<(k==1)<<"\n";
			continue;
		}
		k--; // mex 0
		vector<vv> dp(n+3,vv(n+3));
		dp[0][0]=1;
		fore(i,0,n)fore(c,0,n+1){
			auto &now=dp[i][c];
			if(!now)continue;
			addig(dp[i+1][c+1],mul(now,1+(i>0)));
			addig(dp[i+1][c],mul(now,max(i-1,0ll)));
		}
		ll res=dp[n][k];
		cout<<res<<"\n";
	}
	return 0;
}
