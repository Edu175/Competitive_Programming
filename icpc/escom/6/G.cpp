#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MOD=1e9+7,MAXF=2e7+5;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int b, ll e){
	if(e<0)return 0;
	int r=1;
	for(;e;e>>=1,b=mul(b,b))if(e&1)r=mul(r,b);
	return r;
}
int fc[MAXF],fci[MAXF];
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
ll inv(ll a){return mul(fci[a],fc[a-1]);} // 0<a<MAXN
ll cat(ll n, ll k){
	if(k>n||k<0||n<0)return 0;
	ll coef=mul(k,inv(2*n-k));
	return mul(coef,nCr(2*n-k,n));
}

int main(){FIN;
	factos();
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		if(k==1){
			cout<<"1\n";
			continue;
		}
		ll res=0,pot=fpow(k-1,n);
		fore(q,1,n+1){
			pot=mul(pot,mul(k,inv(k-1)));
			ll cur=mul(cat(n,q),pot);
			// cerr<<q<<": "<<pot<<" "<<cat(n,q)<<": "<<cur<<"\n";
			res=add(res,cur);
		}
		cout<<res<<"\n";
	}
	return 0;
}
