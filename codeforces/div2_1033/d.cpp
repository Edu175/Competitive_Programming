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
const ll MOD=1e9+7,MAXF=1e6+5;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	if(b<0)return 0;
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
// ll fc[MAXF],fci[MAXF];
// void factos(){
// 	fc[0]=1;
// 	fore(i,1,MAXF)fc[i]=mul(fc[i-1],i);
// 	fci[MAXF-1]=fpow(fc[MAXF-1],MOD-2);
// 	for(ll i=MAXF-2;i>=0;i--)fci[i]=mul(fci[i+1],(i+1));
// }
// ll nCr(ll n, ll k){ // must call factos before
// 	if(n<0||k<0||k>n)return 0;
// 	return mul(mul(fc[n],fci[k]),fci[n-k]);
// }
ll nCr(ll n, ll k){
	if(n<0||k<0||k>n)return 0;
	ll res=1;
	fore(i,0,k)res=mul(res,mul(n-i,fpow(i+1,MOD-2)));
	return res;
}
ll get(ll k, ll a){
	// smallest n s.t. ceil(n/k)>=a
	return add(sub(mul(a,k),k),1);
	// return a*k-k+1;
}
int main(){FIN;
	
	// factos();
	ll t; cin>>t;
	while(t--){
		ll a,b,k; cin>>a>>b>>k;
		ll n=get(k,a);
		ll m=get(mul(nCr(n,a),k),b);
		cout<<n<<" "<<m<<"\n";
	}
	return 0;
}
