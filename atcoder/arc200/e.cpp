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
#define DBG(x)cerr<<#x<<": "<<x<<"\n";
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
ll nCr(ll n, ll k){
	if(n<0||k<0||n<k)return 0;
	ll res=1;
	fore(i,0,k)res=mul(res,mul(n-i,fpow(i+1,MOD-2)));
	return res;
}
ll cont(ll n, ll k){ // contar secuencias de tamaño n con exactamente k números distintos
	ll res=0;
	fore(c,1,k+1){
		ll term=mul(nCr(k,c),fpow(c,n));
		res=(c%2==k%2?add:sub)(res,term);
	}
	return res;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		ll romb=mul(mul(nCr(m,2),fpow(2,m-2)),cont(n,4));
		ll est=mul(fpow(2,m),fpow(m+1,n));
		ll dob=mul(mul(fpow(2,m),nCr(m,2)),(MOD+1)/2);
		dob=mul(dob,cont(n,2));
		ll ari=mul(mul(mul(fpow(2,m),m),(MOD+1)/2),cont(n,2));
		ll uno=mul(m,fpow(2,m));
		ll esp=mul(mul(2,mul(nCr(m,3),fpow(2,m-3))),cont(n,4));
		// DBG(romb)
		// DBG(est)
		// DBG(dob)
		// DBG(ari)
		// DBG(uno)
		// DBG(esp)
		ll res=add(romb,sub(est,add(dob,add(uno,ari))));
		res=add(res,esp);
		cout<<res<<"\n";
	}
	return 0;
}
