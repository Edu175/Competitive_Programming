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
const ll MOD=(119<<23)+1;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
#define addig(a,b) a=add(a,b)

int main(){FIN;
	ll n; cin>>n;
	vv a(n);
	ll sum=0;
	fore(i,0,n)cin>>a[i],sum+=a[i];
	vv dp(sum+1); dp[0]=1;
	fore(i,0,n){
		ll x=a[i];
		for(ll j=sum;j>=0;j--)if(j+x<=sum)addig(dp[j+x],dp[j]);
	}
	ll x=dp[sum/2];
	ll res=sub(mul(x,x),mul(2,x));
	if(sum&1)res=0;
	cout<<res<<"\n";
	return 0;
}
