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
const ll MAXN=505,MOD=1e9+7,MAXF=MAXN;
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
ll nCr(ll n, ll k){ //must call factorials before
	if(n<0||k<0||k>n)return 0;
	return mul(mul(fc[n],fci[k]),fci[n-k]);
}

ll dp[MAXN][MAXN];
char a[MAXN];
ll comb(ll a, ll b){
	return nCr(a+b,b);
}
ll f(ll l, ll r){
	ll &res=dp[l][r];
	if(res!=-1)return res;
	if(r-l==0)return res=1;
	if(r-l<=1)return res=0;
	res=0;
	fore(m,l+1,r)if(a[m]==a[l])res=add(res,
		mul(mul(f(l+1,m),f(m+1,r)),comb((m-l+1)/2,(r-(m+1))/2)));
	//cout<<"f "<<l<<","<<r<<" = "<<res<<"\n";
	return res;
}

int main(){FIN;
	factos();
	string s; cin>>s;
	ll n=SZ(s);
	fore(i,0,n)a[i]=s[i];
	mset(dp,-1);
	cout<<f(0,n)<<"\n";
	return 0;
}
