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
ll nCr(ll n, ll k){ // must call factos before
	if(n<0||k<0||k>n)return 0;
	ll res=1;
	fore(i,0,k)res=mul(res,mul(n-i,fpow(i+1,MOD-2)));
	return res;
}
ll sq(ll n){return mul(n,n);}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll k,n,m; cin>>k>>n>>m;
		ll good=mul(sq(nCr(n-2*k+2,2)),sq(nCr(m-2*k+2,2)));
		ll bad=mul(nCr(n-2*k+3,4),nCr(m-2*k+3,4));
		bad=mul(bad,2);
		ll res=sub(good,bad);
		cout<<res<<"\n";
	}
	return 0;
}
