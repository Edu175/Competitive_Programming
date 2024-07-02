#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=1005,MOD=998244353,MAXF=MAXN;
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
ll n;
ll dp[28][MAXN];
ll a[29];
ll f(ll i, ll m){
	ll &res=dp[i][m];
	if(res!=-1)return res;
	if(m==0)return res=1;
	if(i==26)return res=0;
	res=0;
	fore(k,0,min(a[i],m)+1){
		res=add(res,mul(nCr(m,k),f(i+1,m-k)));
	}
	return res;
}

int main(){FIN;
	factos();
	cin>>n;
	fore(i,0,26)cin>>a[i];
	mset(dp,-1);
	ll res=0;
	fore(i,1,n+1)res=add(res,f(0,i));
	cout<<res<<"\n";
	return 0;
}
