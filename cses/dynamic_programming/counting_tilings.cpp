#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MOD=1e9+7;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
const ll N=10,MAXN=15,MAXM=1005;
ll n,m;
ll dp[1ll<<N][MAXN*MAXM];
ll u;
ll f(ll mk, ll x){
	ll &res=dp[mk][x];
	if(res!=-1)return res;
	if(x>=n*m)return res=mk==u;
	res=f((mk<<1)&u,x+1);
	if(x%n&&!(mk&1))res=add(res,f(((mk<<1)|3)&u,x+1));
	if(!((mk>>(n-1))&1))res=f(((mk<<1)|1)&u,x+1);
	return res;
}
int main(){FIN;
	cin>>n>>m;
	u=(1ll<<n)-1;
	mset(dp,-1);
	cout<<f(u,0)<<"\n";
	return 0;
}

