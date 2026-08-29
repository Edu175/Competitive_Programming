#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){FIN;
	ll n,m; cin>>n>>m;
	vv g(n);
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		g[u]|=1ll<<v;
		g[v]|=1ll<<u;
	}
	ll N=1ll<<n;
	vv dp(N);
	dp[N-1]=0;
	for(ll mk=N-2;mk>=0;mk--){
		auto &res=dp[mk]; res=n+5;
		fore(x,0,n)if(mk>>x&1){
			res=min(res,1+dp[mk|g[x]]);
		}
	}
	vv isc(N);
	
	fore(mk,1,N){
		isc[mk]=1;
		fore(x,0,n)if(mk>>x&1){
			ll cur=(g[x]&mk)|(1ll<<x);
			if(cur!=mk)isc[mk]=0;
		}
	}
	
	ll res=n+5,wh=-1; // wh is a mk
	fore(x,0,n)assert(isc[1ll<<x]);
	fore(mk,0,N)if(isc[mk]){
		ll cur=dp[mk];
		if(cur<res)res=cur,wh=mk;
	}
	// cerr<<"res "<<res<<"\n";
	assert(wh!=-1);
	vv p;
	ll mk=wh;
	while(mk!=N-1){
		// cerr<<"mk "<<x<<"\n";
		fore(x,0,n)if(mk>>x&1){
			if(dp[mk]==1+dp[mk|g[x]]){
				p.pb(x),mk|=g[x];
				break;
			}
		}
	}
	assert(SZ(p)==res);
	cout<<SZ(p)<<"\n";
	for(auto i:p)cout<<i+1<<" ";;cout<<"\n";
	return 0;
}
