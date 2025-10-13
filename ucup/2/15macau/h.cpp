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
const ll MOD=998244353,MAXF=1e6+5;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	if(b<0)return 0;
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
ll nCr(ll n, ll k){ // must call factos before
	if(n<0||k<0||k>n)return 0;
	return mul(mul(fc[n],fci[k]),fci[n-k]);
}

const ll MAXN=1e5+5;
vv dpg[MAXN],dpf[MAXN];
ll D[MAXN],fa[MAXN];
vv g[MAXN];

ll f(ll x, ll lib);
ll ge(ll x, ll lib);

ll ge(ll x, ll lib){
	auto &res=dpg[x][lib];
	if(res!=-1)return res;
	
	ll m=SZ(g[x]);
	ll mx=D[x]+2;
	vector<vv> dp(2,vv(mx));
	dp[m&1][0]=1;
	for(ll i=m-1;i>=0;i--)fore(z,0,mx){
		auto &res=dp[i&1][z];
		res=0;
		fore(c,0,z+1){
			ll cur=mul(f(g[x][i],c),dp[(i+1)&1][z-c]);
			res=add(res,cur);
		}
	}
	fore(i,0,mx)dpg[x][i]=dp[0][i];
	
	assert(res!=-1);
	return res;
}
ll f(ll x, ll lib){
	auto &res=dpf[x][lib];
	if(res!=-1)return res;
	lib++;
	res=0;
	fore(z,0,lib+1){
		ll term=mul(fci[z],ge(x,lib-z));
		res=add(res,term);
	}
	return res;
}

int main(){FIN;
	factos();
	ll n; cin>>n;
	fore(i,1,n){
		cin>>fa[i],fa[i]--;
		g[fa[i]].pb(i);
		D[i]=D[fa[i]]+1;
	}
	fore(i,0,n){
		dpg[i]=dpf[i]=vv(D[i]+2,-1);
	}
	ll res=f(0,0);
	res=mul(res,fc[n]);
	cout<<res<<"\n";
	return 0;
}
