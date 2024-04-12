#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
const ll MAXN=20,INF=1e7;
ll g[MAXN];
ll dp[1ll<<MAXN];

ll ppc(ll x){return __builtin_popcountll(x);}

int main(){FIN;
	ll n,m; cin>>n>>m;
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		g[u]|=1ll<<v;
		g[v]|=1ll<<u;
	}
	dp[0]=0;
	fore(mk,1,1ll<<n){
		ll &res=dp[mk];
		res=INF;
		fore(i,0,n)if(mk&(1ll<<i)){
			ll pr=g[i]&mk;
			res=min(res,dp[mk^(1ll<<i)]+(ppc(g[i]^pr)-ppc(pr))*(n-ppc(mk)));
		}
	}
	ll res=dp[(1ll<<n)-1];
	cout<<res<<"\n";
	return 0;
}
