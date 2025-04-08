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
const ll MOD=998244353;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	if(b<0)return 0;
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
const ll D=30;
ll A,B;
ll dp[D][16];
ll f(ll i, ll mk){
	auto &res=dp[i][mk];
	if(res!=-1)return res;
	res=0;
	fore(now,0,16){
		if(__builtin_popcount(now)&1)continue;
		ll b=now&1;
		ll a=now>>1&1;
		ll d=now>>2&1;
		ll c=now>>3&1;
		if(a>b&&(mk&1))continue;
		if(c>d&&((mk>>1)&1))continue;
		if((mk>>2&1)&&b>(A>>i&1))continue;
		if((mk>>3&1)&&d>(B>>i&1))continue;
		ll mki=mk;
		if()
		res=add(res,f(i-1,))
	}
}


int main(){FIN;
	ll t; cin>>t;
	while(t--){
		mset(dp,-1);
		
	}
	return 0;
}
