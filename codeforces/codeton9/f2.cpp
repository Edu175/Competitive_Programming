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
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
const ll MAXN=1e5+5;
vector<ll> divs[MAXN];
void divisores(){
	fore(i,1,MAXN)for(int j=i;j<MAXN;j+=i)divs[j].pb(i);
}
// short mu[MAXN] = {0,1};
// void mobius(){
// 	fore(i,1,MAXN)if(mu[i])for(int j=i+i;j<MAXN;j+=i)mu[j]-=mu[i];
// }
// ll mo(ll v){ll ret=mu[v]; if(ret<0)ret+=MOD; return ret;}
// map<ii,ll> dp0[MAXN];
// ll cnt(ll m, ll g, ll g2){
// 	if(dp0[m].count({g,g2}))return dp0[m][{g,g2}];
// 	auto &res=dp0[m][{g,g2}];
// 	res=1;
// 	for(ll k=g2;k<m;k+=g2)res=add(res,mul(mo(k/g2),))
// }
// ll f(ll g, ll m){
// 	if(dp1[m].count(g))return dp1[m][g];
// 	auto &res=dp1[m][g];
// 	if(g==1)return res=1;
// 	res=0;
// 	for(auto g2:divs[g])if(g!=g2){
// 		res=add(res,mul(cnt(m,g,g2),mul(2,f(g2,))))
// 	}
// }
map<ll,ll> dp1[MAXN];
ll f(ll m, ll g){
	if(dp1[m].count(g))return dp1[m][g];
	auto &res=dp1[m][g];
	if(g==1)return res=1;
	res=0;
	for(auto g2:divs[g])if(g!=g2){
		res=add(res,mul(2,f(g2,gcd(g2,g))));
	}
	return res;
}
int main(){FIN;
	divisores();
	ll t; cin>>t;
	while(t--){
		ll m; cin>>m;
		ll res=0;
		fore(i,1,m+1)res=add(res,f(i,i));
		// res=mul(res,fpow(2,MOD-2));
		cout<<res<<"\n";
	}
	return 0;
}
