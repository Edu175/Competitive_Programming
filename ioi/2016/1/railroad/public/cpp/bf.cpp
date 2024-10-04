#include "railroad.h"
#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ioi=b;i<ioi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto dkfjhg:v)cout<<dkfjhg<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=2e5+5,INF=1e15;

long long plan_roller_coaster(std::vector<int> A, std::vector<int> B) {
    vector<ll>a,b;
	for(auto i:A)a.pb(i);
	for(auto i:B)b.pb(i);
	ll n=SZ(a);
	auto bin=[&](ll mk){
		string r;
		fore(i,0,n)r.pb('0'+(mk>>i&1));
		return r;
	};
	vector<vector<ll>>dp(1ll<<n,vector<ll>(n));
	fore(mk,1,1ll<<n)fore(x,0,n){
		ll &res=dp[mk][x];
		res=INF;
		// if(!mk){res=0;continue;}
		fore(y,0,n)if(mk>>y&1){
			res=min(res,max(b[x]-a[y],0ll)+dp[mk^(1ll<<y)][y]);
		}
		// cout<<bin(mk)<<" "<<x<<": "<<res<<"\n\n";
	}
	ll res=INF,u=(1ll<<n)-1;
	ll mk=u,x=0;
	fore(i,0,n){
		res=min(res,dp[u^(1ll<<i)][i]);
		if(dp[u^(1ll<<i)][i]==res)x=i,mk=u^(1ll<<i);
	}
	vector<ii>ret={{a[x],b[x]}};
	fore(_,0,n-1)fore(y,0,n)if(mk>>y&1){
		if(dp[mk][x]==max(b[x]-a[y],0ll)+dp[mk^(1ll<<y)][y]){
			
			mk^=1ll<<y;
			x=y;
			ret.pb({a[x],b[x]});
			break;
		}
	}
	// for(auto i:ret)cout<<i.fst<<","<<i.snd<<" ";;cout<<"\n";
    return res;
}
