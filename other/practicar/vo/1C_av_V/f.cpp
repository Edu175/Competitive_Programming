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
int divi(int a, int b){return mul(a,fpow(b,MOD-2));}
int main(){FIN;
	ll n,k,l; cin>>n>>k>>l;
	vector<vv> dp(n+3,vv(n+3));
	n=2*n;
	for(ll i=n-1;i>=0;i--)fore(c,0,n+1){
		auto &res=dp[i][c];
		// 0 es cerrar
		ll cant=n-i-c;
		if(cant%2)continue;
		assert(cant%2==0);
		ll c0=cant/2+c,c1=cant/2;
		ll p0=divi(c0,n-i),p1=sub(1,p0);
		p0=mul(p0,c); // ?
		res=0;
		ll go0=0,go1=0;
		if(p0){
			go0=mul((MOD+1)/2,add(c>=k,dp[i+1][c-1]));
		}
		if(p1){
			go1=mul((MOD+1)/2,add(c>=k,dp[i+1][c+1]));
		}
		res=add(mul(p0,go0),mul(p1,go1));
	}
	ll res=dp[0][0];
	res=mul(res,l);
	cout<<res<<"\n";
	return 0;
}
