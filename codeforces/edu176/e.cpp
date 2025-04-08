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
const ll D=31;
ll A,B;
ll dp[D][2][2][2][2];
ll f(ll i, ll d0, ll d1, ll d2, ll d3){
	if(i==-1)return !d0&&!d1&&!d2&&!d3;
	auto &res=dp[i][d0][d1][d2][d3];
	if(res!=-1)return res;
	
	res=0;
	fore(now,0,16){
		if(__builtin_popcount(now)&1)continue;
		bool b=now&1;
		bool a=now>>1&1;
		bool d=now>>2&1;
		bool c=now>>3&1;
		if(a>b&&d0)continue;
		if(c>d&&d1)continue;
		bool Ai=(A>>i&1);
		bool Bi=(B>>i&1);
		if(d2&&b>Ai)continue;
		if(d3&&d>Bi)continue;
		res=add(res,f(i-1,d0&&a==b,d1&&c==d,d2&&b==Ai,d3&&d==Bi));
	}
	return res;
}

ll to2(ll n){return n*(n-1)/2%MOD;}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		cin>>A>>B; A++,B++;
		ll res=mul(A,B);
		ll combA=sub(fpow(2,n),2);
		ll combB=sub(fpow(2,m),2);
		res=add(res,mul(A,mul(to2(B),combB)));
		res=add(res,mul(B,mul(to2(A),combA)));
		mset(dp,-1);
		ll num=f(D-1,1,1,1,1);
		res=add(res,mul(mul(combA,combB),num));
		cout<<res<<"\n";
	}
	return 0;
}
