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
const ll MOD=998244353,MAXF=2e5+5;
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
ll rbs(ll n){ // number of Regular Bracket Sequences
	// such that saldo is positive
	if(n&1)return 0;
	if(n==0)return 1;
	n-=2;
	return sub(nCr(n,n/2),nCr(n,n/2-1));
}
ll tab(ll n, ll m){
	return nCr(n+m-2,n-1);
}
ll tabrayas(ll n, ll m){
	return tab(n+1,m+1);
}
int main(){FIN;
	factos();
	ll n,m; cin>>n>>m;
	ll res=0;
	vector<ll> coef(n+m+5);
	fore(d,0,n+m+5){
		
	}
	fore(k,0,n+m){
		ll resi=0;
		if(k==0){
			resi=tabrayas(n,m);
		}
		else {
			ll l=rbs(k),r=tabrayas(n-k/2,m-k/2),c=nCr(n+m-1,k);
			resi=mul(mul(l,r),c);
			cout<<k<<": "<<l<<" "<<r<<" "<<c<<": "<<resi<<"\n";
		}
		res=add(res,resi);
	}
	cout<<res<<"\n";
	return 0;
}
