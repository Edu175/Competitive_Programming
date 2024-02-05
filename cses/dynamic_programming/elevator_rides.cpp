#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef int ll;
typedef pair<ll,ll> ii;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
const ll N=20;

ll can[1<<N];
ll dp[1<<N];

int main(){FIN;
	ll n,x; cin>>n>>x;
	vector<ll>a(n);
	fore(i,0,n)cin>>a[i];
	fore(mk,0,1ll<<n){
		ll sum=0;
		fore(i,0,n)if((mk>>i)&1)sum+=a[i];
		can[mk]=sum<=x;
	}
	dp[0]=0;
	fore(mk,1,1<<n){
		ll &res=dp[mk];
		ll x=1<<__builtin_ctz(mk);
		ll m=mk^x;
		res=dp[m]+1;
		for(ll sb=m;sb;sb=(sb-1)&m)if(can[sb^x])res=min(res,1+dp[m^sb]);
	}
	cout<<dp[(1ll<<n)-1]<<"\n";
	return 0;
}
