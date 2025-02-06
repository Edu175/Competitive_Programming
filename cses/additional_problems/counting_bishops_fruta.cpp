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
const ll MAXN=505,MAXF=MAXN,MOD=1e9+7;
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
ll cuad(ll n, ll k){
	ll to=nCr(n,k);
	ll res=mul(mul(to,to),fc[k]);
	cout<<"cuad "<<n<<" "<<k<<": "<<res<<"\n";
	return res;
}

// incorrect, as events are not independent from one shape to another

ll dp[MAXN][MAXN]; // L shapes
ll f(ll n, ll k){
	auto &res=dp[n][k];
	if(res!=-1)return res;
	if(k>n*n)return res=0;
	res=cuad(n,k);
	fore(c,1,k+1){
		ll resi=mul(f(n-2+(n&1),c),f(n,k-c));
		res=sub(res,resi);
	}
	cout<<n<<" "<<k<<": "<<res<<"\n";
	return res;
}

ll even(ll n, ll k){
	vv dp(k+1);
	fore(c,0,k+1){
		auto &res=dp[c];
		res=cuad(n,k);
		fore(q,1,c){
			res=sub(res,mul(dp[q],dp[c-q]));
		}
		res=mul(res,(MOD+1)/2);
	}
	ll res=0;
	fore(c,0,k+1)res=add(res,mul(dp[c],dp[k-c]));
	return res;
}

int main(){FIN;
	factos();
	ll n,k; cin>>n>>k;
	if(!(n&1)){cout<<even(n,k)<<"\n";return 0;}
	mset(dp,-1);
	ll res=0;
	fore(c,0,k+1)res=add(res,mul(f(n,c),f(n-1,k-c)));
	cout<<res<<"\n";
	return 0;
}