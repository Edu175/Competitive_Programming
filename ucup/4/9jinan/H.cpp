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
ll MOD;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	if(b<0)return 0;
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll N; cin>>N>>MOD;
		vv dp(N+1);
		dp[0]=1;
		fore(n,1,N+1){
			auto &res=dp[n];
			fore(a,0,n){
				ll b=n-1-a;
				if(!(a>b))continue;
				res=add(res,mul(dp[a],dp[b]));
			}
			 // el de iguales
			if((n-1)%2==0){
				ll a=(n-1)/2;
				ll cur=mul(dp[a],dp[a]);
				cur=add(cur,dp[a]);
				cur=mul(cur,(MOD+1)/2);
				res=add(res,cur);
			}
		}
		cout<<dp[N]<<"\n";
	}
	return 0;
}
