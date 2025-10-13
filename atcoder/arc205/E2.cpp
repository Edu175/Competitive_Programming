#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define LL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vv;
#pragma GCC optimize("Ofast") // may lead to precision errors
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
const int MOD=998244353,RT=3;
int fpow(ll a, ll b, ll MOD){
	if(b<0)return 0;
	ll r=1;
	while(b){if(b&1)r=r*a%MOD; b>>=1; a=a*a%MOD;}
	return r;
}
//returns x such that a^x = b (mod m) or -1 if inexistent
ll discrete_log(ll a,ll b) {
	const ll m=MOD;
	a%=m, b%=m;
    if(b == 1) return 0;
    int cnt=0;
    ll tmp=1;
    // for(int g=__gcd(a,m);g!=1;g=__gcd(a,m)) {
	// 	if(b%g) return -1;
    //     m/=g, b/=g;
    //     tmp = tmp*a/g%m;
    //     ++cnt;
    //     if(b == tmp) return cnt;
    // }
    gp_hash_table<ll,int> w;
    int s = ceil(sqrt(m));
    ll base = b;
    fore(i,0,s) {
		w[base] = i;
        base=base*a%m;
    }
    base=fpow(a,s,m);
    ll key=tmp;
    fore(i,1,s+2) {
		key=base*key%m;
        if(w.find(key)!=w.end()) return i*s-w[key]+cnt;
    }
    return -1;
}
const int K=20,POT=1<<K,B=5000;
ll dp[POT],val[POT];
void build(){
	// cerr<<"build: ";
	// fore(mk,0,POT)if(val[mk]!=1){
	// 	cout<<mk<<","<<val[mk]<<" ";
	// }
	// cout<<"\n";
	fore(mk,0,POT)dp[mk]=val[mk];
	fore(k,0,K)fore(mk,0,POT)if(mk&(1<<k)){
		dp[mk]+=dp[mk^(1<<k)];
	}
}

int cv(int x){
	assert(x);
	return discrete_log(RT,x);
}

int main(){FIN;
	fore(i,0,POT)val[i]=dp[i]=0;
	int n; cin>>n;
	vector<ii> bag;
	bag.reserve(B);
	ll hay0=0;
	fore(i,0,n){
		int v; cin>>v;
		hay0|=!v;
		if(hay0){
			// cerr<<" hay0!!\n";
			cout<<"0 ";
			continue;
		}
		int w=cv(v);
		// cerr<<v<<": "<<w<<"\n";
		if(SZ(bag)==B){
			for(auto i:bag)val[i.fst]+=i.snd;
			build();
			bag.clear();
		}
		bag.pb({v,w});
		ll res=dp[v];
		// cout<<v<<": dp="<<res<<": ";
		for(auto i:bag)if((i.fst|v)==v){
			res+=i.snd;
		}
		res=fpow(RT,res,MOD);
		cout<<res<<"\n";
		
	}
	return 0;
}
