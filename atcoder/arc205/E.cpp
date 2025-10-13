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
typedef int ll;
typedef long long LL;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
// #pragma GCC optimize("Ofast") // may lead to precision errors
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
const ll K=20,POT=1<<K,B=5000;
const LL MOD=998244353;
LL dp[POT],val[POT];

#define mulig(a,b) a=(a)*(b)%MOD;
void build(){
	// cerr<<"build: ";
	// fore(mk,0,POT)if(val[mk]!=1){
	// 	cout<<mk<<","<<val[mk]<<" ";
	// }
	// cout<<"\n";
	fore(mk,0,POT)dp[mk]=val[mk];
	fore(k,0,K)fore(_mk,0,POT/2){
		ll pre=(_mk>>k)<<(k+1);
		ll mk=_mk|pre|(1<<k);
		mulig(dp[mk],dp[mk^(1<<k)]);
	}
}


int main(){FIN;
	fore(i,0,POT)val[i]=dp[i]=1;
	ll n; cin>>n;
	vector<LL> bag;
	bag.reserve(B);
	fore(i,0,n){
		ll v; cin>>v;
		if(SZ(bag)==B){
			for(auto i:bag)mulig(val[i],i);
			build();
			bag.clear();
		}
		bag.pb(v);
		LL res=dp[v];
		// cout<<v<<": dp="<<res<<": ";
		for(auto i:bag)if((i|v)==v){
			mulig(res,i);
		}
		cout<<res<<"\n";
		
	}
	return 0;
}
