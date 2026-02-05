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
const ll MAXF=2e7+5;
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
vv multiply(vv a, vv b){
	vv c(SZ(a)+SZ(b)-1);
	fore(i,0,SZ(a))fore(j,0,SZ(b))c[i+j]=add(c[i+j],mul(a[i],b[j]));
	return c;
}
int main(){FIN;
	factos();
	ll n,m; cin>>n>>m;
	// vv p(n+1); iota(ALL(p),0);
	// vv r={1};
	// fore(_,0,m)r=multiply(r,p);
	// imp(r)
	// fore(s,0,n+1){
	// 	ll coef=nCr(s+m-1,2*m-1);
	// 	cout<<coef<<" ";
	// }
	// cout<<"\n";
	ll res=0;
	fore(s,0,n+1){
		ll c=n-s;
		if((c&1)||c<0)continue;
		c/=2;
		ll cur=mul(fpow(2,m),nCr(c+m-1,m-1));
		cur=mul(cur,nCr(s+m-1,2*m-1));
		res=add(res,cur);
	}
	cout<<res<<"\n";
	return 0;
}
