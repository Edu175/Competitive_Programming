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
const ll MOD=1e9+7,MAXF=10005;
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
int main(){FIN;
	factos();
	ll t; cin>>t;
	while(t--){
		ll n,c,m; cin>>n>>c>>m;
		ll asd;; fore(i,0,m)cin>>asd;
		vector<vv>dp(n+3,vv(m+3));
		dp[n][m]=1;
		for(ll p=n-1;p>=0;p--)fore(z,0,m+1){
			auto &res=dp[p][z];
			fore(t,0,c+1){
				ll resi=0;
				if(z+t<=m)resi=mul(nCr(c,t),dp[p+1][z+t]);
				res=add(res,resi);
			}
			// cout<<p<<" "<<z<<": "<<res<<"\n";
		}
		cout<<dp[1][c]<<"\n";
	}
	return 0;
}
