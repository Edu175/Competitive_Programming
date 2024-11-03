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
const ll MOD=1e9+7,MAXF=1e6;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
ll fc[MAXF],fci[MAXF];
void factos(){
	fc[0]=1;
	fore(i,1,MAXF)fc[i]=mul(fc[i-1],i);
	fci[MAXF-1]=fpow(fc[MAXF-1],MOD-2);
	for(ll i=MAXF-2;i>=0;i--)fci[i]=mul(fci[i+1],(i+1));
}
ll nCr(ll n, ll k){ //must call factos before
	if(n<0||k<0||k>n)return 0;
	return mul(mul(fc[n],fci[k]),fci[n-k]);
}
ll mem[MAXF];
ll tree(ll n){ // rooted
	ll &res=mem[n];
	if(res!=-1)return res;
	if(n<=1)return res=1;
	return res=fpow(n,n-1);
}
const ll MAXN=5005;
ll dp[MAXN][MAXN];
ll dp2[MAXN][MAXN];
ll inv(ll n){
	assert(n>0);
	return mul(fci[n],fc[n-1]);
}
ll fun(ll z, ll n){ // do * 1/z in first call
	ll &res=dp2[z][n];
	if(res!=-1)return res;
	if(z==0)return res=n==0;
	res=0;
	fore(m,1,n+1){
		ll coef=mul(tree(m),nCr(n,m));
		res=add(res,mul(coef,fun(z-1,n-m)));
	}
	// cout<<"fun "<<z<<" "<<n<<": "<<res<<"\n";
	return res;
}

ll tot(ll n){ // # of fun graphs connected
	ll res=0;
	fore(z,1,n+1)res=add(res,mul(inv(z),fun(z,n)));
	return res;
}
// oeis of that ^
// a(n) = Sum_{k=1..n} n!*n^(n-k-1) / (n-k)!

int main(){FIN;
	factos();
	mset(dp,-1); mset(dp2,-1); mset(mem,-1);
	ll n; cin>>n;
	fore(i,0,n+1)cout<<tot(i)<<" ";;cout<<"\n";
	return 0;
}