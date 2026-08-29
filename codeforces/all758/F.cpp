#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define forr(i,a,b) for(ll i=(b)-1,jet=a;i>=jet;--i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MOD=998244353;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int b, ll e){
	if(e<0)return 0;
	int r=1;
	for(;e;e>>=1,b=mul(b,b))if(e&1)r=mul(r,b);
	return r;
}

const ll MAXN=2005;
ll dp[2][101][MAXN];
vv b;
ll k;
ll tra(ll i, ll v){
	v=v-b[i];
	if(abs(v)>k)return -1;
	return v+k;
}
void push(ll i, ll v, ll l, ll val){
	v=tra(i,v);
	if(v==-1||l<0)return;
	dp[i&1][v][l]=add(dp[i&1][v][l],val);
}
int main(){FIN;
	ll n,k; cin>>n>>k;
	b=vv(n+1);
	fore(i,1,n+1)cin>>b[i];
	dp[0][tra(0,0)][0]=1;
	// lib are > mex
	fore(i,0,n)fore(mex,b[i]-k,b[i]+k+1)forr(lib,0,n+1){
		auto &now=dp[i&1][tra(i,mex)][lib];
		if(!now)continue;
		
		push(i+1,)
		
		now=0;
	}
	return 0;
}
