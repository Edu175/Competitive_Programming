#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
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
	while(b){
		if(b&1)r=mul(r,a);
		a=mul(a,a); b>>=1;
	}
	return r;
}
const ll MAXN=505,MAXF=MAXN*10;
ll fc[MAXF],fci[MAXF];
void factos(){
	fc[0]=1;
	fore(i,1,MAXF)fc[i]=mul(fc[i-1],i);
	fci[MAXF-1]=fpow(fc[MAXF-1],MOD-2);
	for(ll i=MAXF-2;i>=0;i--)fci[i]=mul(fci[i+1],i+1);
}
ll nCr(ll n, ll k){
	if(n<0||k<0||k>n)return 0;
	return mul(fc[n],mul(fci[k],fci[n-k]));
}
ll a[MAXN];
ll dp[MAXN][MAXN];

ll n;

ll f(ll i, ll z){
	// cout<<"pinga\n";
	auto &res=dp[i][z];
	// cout<<res<<" res first\n";
	if(res!=-1)return res;
	if(i==n)return res=1;
	// cout<<"pinga\n";
	res=0;
	fore(c,0,a[i]){
		fore(j,1,z+1){
			ll cantx=a[i]-c-1;
			ll canto=z-j;
			ll coef=nCr(cantx+canto,cantx);
			res=add(res,mul(coef,f(i+1,j+c)));
		}
	}
	// falta caso no p2, c=a[i]
	res=add(res,f(i+1,z+a[i]));
	return res;
}

int main(){
    JET
	mset(dp,-1);
	// fore(i,0,n+2)fore(j,0,MAXN)dp[i][j]=-1;
	factos();
	// cout<<nCr(5,2)<<" C(5,2)\n";
	cin>>n;
	fore(i,0,n)cin>>a[i];
	reverse(a,a+n);
	ll res=f(0,0);
	cout<<res<<"\n";
    return 0;
}

