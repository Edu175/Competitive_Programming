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
const ll MOD=1e9+7;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	if(b<0)return 0;
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}

// ll fn(ll n){return n*(n-1)/2%MOD;} // )
#define bint __int128
ll fn(bint n){
	return bint(n*(n-1)/2)%MOD;
} // )
const ll MX=1e18;
ll f(ll a, ll n, ll d, ll k){
	if(n==0)return 0;
	if(k==0){
		a%=MOD; d%=MOD;
		ll res=add(mul(a,n%MOD),mul(d,fn(n)));
		return res;
	}
	if(d%2==0){
		if(a&1)	return f(3*a+1,n,3*d,k-1);
				return f(a/2,  n,d/2,k-1);
	}
	return 	add(f(a, (n+1)/2,2*d,k),
				f(a+d, n/2,  2*d,k));
}

int main(){FIN;
	ll n,k; cin>>n>>k;
	cout<<f(1,n,1,k)<<"\n";
	return 0;
}
