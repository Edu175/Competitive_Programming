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
const ll MAXV=1e5+5,MOD=998244353;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(ll a, ll b, ll m=MOD){
	if(b<0)return 0;
	ll r=1;
	while(b){if(b&1)r=r*a%m; b>>=1; a=a*a%m;}
	return r;
}
ll mem[MAXV];
ll ord(ll m){ // ord_m(10), (0 if m==1)
	if(m==1)return 0;
	auto &res=mem[m];
	if(res!=-1)return res;
	res=0;
	ll x=1;
	do{
		x=x*10%m;
		res++;
	}while(x!=1);
	return res;
}
ll get(ll a, ll b){
	// cerr<<a<<" "<<b<<": ";
	ll res=SZ(to_string(a/b));
	a%=b;
	while(a&&gcd(b/gcd(a,b),10)!=1){
		a=a*10%b;
		res++;
	}
	if(a){
		res+=ord(b/gcd(a,b));
	}
	// cerr<<res<<"\n";
	return res;
}
int main(){FIN;
	mset(mem,-1);
	ll n; cin>>n;
	vv a(n);
	fore(i,0,n)cin>>a[i];
	ll res=0;
	fore(i,0,n)fore(j,0,n)res+=get(a[i],a[j]);
	cerr<<res<<"\n";
	res%=MOD;
	res=mul(res,fpow(mul(n,n),MOD-2));
	cout<<res<<"\n";
	return 0;
}