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
const ll MAXN=1e6+5,MOD=998244353;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
int mu[MAXN] = {0,1};
void mobius(){
	fore(i,1,MAXN)if(mu[i])for(int j=i+i;j<MAXN;j+=i)mu[j]-=mu[i];
}
vector<ll> divs[MAXN]; // saque el 1 !!!
void divisores(){
	fore(i,2,MAXN)for(int j=i;j<MAXN;j+=i)divs[j].pb(i);
}
int main(){FIN;
	mobius();
	divisores();
	ll n; cin>>n;
	vv a(n);
	fore(i,0,n)cin>>a[i];
	fore(i,0,MAXN){
		mu[i]=sub(0,mu[i]);
	}
	vv val(MAXN);
	ll ans=0;
	for(ll i=n-1;i>=0;i--){
		ll res=0;
		if(i==n-1)res=1;
		for(auto d:divs[a[i]]){
			res=add(res,mul(mu[d],val[d]));
			// cout<<"d "<<d<<": "<<val[d]<<" * "<<mu[d]<<"\n";
		}
		for(auto d:divs[a[i]])val[d]=add(val[d],res);
		ans=res;
		// cout<<i<<" "<<a[i]<<": "<<res<<"\n";
	}
	cout<<ans<<"\n";
	return 0;
}
