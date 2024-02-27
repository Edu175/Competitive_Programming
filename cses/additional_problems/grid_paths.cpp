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
const ll MAXF=3e6+5,MOD=1e9+7,MAXN=3005;
ll fpow(ll b, ll e){
	if(e<0)return 0;
	ll ret=1;
	while(e){
		if(e&1)ret=ret*b%MOD;
		b=b*b%MOD,e>>=1;
	}
	return ret;
}

ll fc[MAXF],fci[MAXF];
void factorials(){
	fc[0]=1;
	fore(i,1,MAXF)fc[i]=fc[i-1]*i%MOD;
	fci[MAXF-1]=fpow(fc[MAXF-1],MOD-2);
	for(ll i=MAXF-2;i>=0;i--)fci[i]=fci[i+1]*(i+1)%MOD;
}
ll nCr(ll n, ll k){ //must call factorials before
	if(n<0||k<0||k>n)return 0;
	return fc[n]*fci[k]%MOD*fci[n-k]%MOD;
}
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
ii a[MAXN];
ll dp[MAXN];
ll cam(ll i, ll j){
	ll x=a[j].fst-a[i].fst,y=a[j].snd-a[i].snd;
	return nCr(x+y,x);
}
ll n;
ll f(ll i){
	ll &res=dp[i];
	if(res!=-1)return res;
	res=cam(i,n+1);
	fore(j,1,n+1)if(i!=j)
		res=sub(res,mul(cam(i,j),f(j)));
	return res;
}
int main(){FIN;
	factorials();
	ll m; cin>>m>>n;
	fore(i,1,n+1)cin>>a[i].fst>>a[i].snd,a[i].fst--,a[i].snd--;
	a[n+1]={m-1,m-1};
	a[0]={0,0};
	mset(dp,-1);
	cout<<f(0)<<"\n";
	return 0;
}

