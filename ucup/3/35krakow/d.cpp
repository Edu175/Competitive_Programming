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
ll inv(ll n){return fpow(n,MOD-2);}
int main(){FIN;
	
	ll N=1e6+5;
	// ll N=10;
	vv hs(N);
	
	fore(n,2,N){
		hs[n]=add(hs[n-1],inv(n));
	}
	
	ll __t; cin>>__t;
	while(__t--){
		ll n; cin>>n;
		ll h=hs[n];
		ll res=sub(h,1);
		res=add(res,inv(n));
		res=add(res,mul(inv(n),h));
		
		// darlo vueltinha
		res=sub(n,res);
		cout<<res<<"\n";
	}
	return 0;
}
