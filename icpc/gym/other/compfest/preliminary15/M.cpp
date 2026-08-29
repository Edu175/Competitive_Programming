#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define pb push_back
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MOD=(119<<23)+1;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int b, ll e){
	if(e<0)return 0;
	int r=1;
	for(;e;e>>=1,b=mul(b,b))if(e&1)r=mul(r,b);
	return r;
}
int inv(int a){return fpow(a,MOD-2);}

int main(){
	JET
	ll n; cin>>n;
	vv p(n);
	fore(i,0,n)cin>>p[i],p[i]=mul(p[i],inv(100));
	vector<ll> sums(n);
	vv dp(n+1); dp[0]=0; sums[0]=0;
	fore(i,0,n){
		auto &sum=sums[i]; sum=0;
		ll j; for(j=i-1;j>0&&p[j]!=p[i];j--);
		j=max(j,0ll);
		sum=sums[j];
		for(j++;j<=i;j++)sum=mul(add(sum,dp[j]),p[i]);
		auto &res=dp[i+1];
		res=mul(sub(dp[i],1),inv(sub(1,p[i])));
		res=sub(res,sum);
	}
	ll res=sub(0,dp[n]);
	cout<<res<<"\n";
	return 0;
}