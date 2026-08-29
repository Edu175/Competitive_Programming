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
template<class x> ostream & operator<<(ostream & out, vector<x> v){
    out<<"{ ";
    for(auto y : v) out<<y<<" ";
    out<<"}";
    return out;
}
#define ppc __builtin_popcountll

bool better(const vv &a, const vv &b){
	ll good=1;
	fore(i,0,SZ(a))good&=a[i]>=b[i];
	return good;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		vv a(n);
		fore(i,0,n)cin>>a[i];
		ll N=1ll<<n;
		vv sums(N); // max that is 0
		fore(mk,0,N){
			auto &sum=sums[mk];
			fore(i,0,n)if(!(mk>>i&1))sum=(sum+a[i]);
		}
		if(n==k){
			cout<<sums[0]<<"\n";
			continue;
		}
		#define GOOD(v,mk) (v.back()-v[0]<sums[mk])
		vector<vector<vv>> dp(N);
		ll res=0;
		fore(mk,0,N){
			auto &all=dp[mk];
			ll c=ppc(mk);
			if(c==k){
				vv v;
				fore(i,0,n)if(mk>>i&1)v.pb(a[i]);
				sort(ALL(v));
				// all.insert(v);
				if(1){
					// ll good=1;
					// for(auto u:all)if(better(u,v)){good=0;break;}
					if(!SZ(all))all.pb(v);
					else if(v>all[0])all[0]=(v);
				}
			}
			if(!SZ(all))continue;
			// cout<<mk<<": "; show(all)
			fore(i,0,n)if(!(mk>>i&1))for(auto v:all){
				ll mki=mk|(1<<i);
				v[0]+=a[i];
				sort(ALL(v));
				if(!1)continue;
				if(mki==N-1){
					assert(SZ(v)==1);
					// cerr<<v[0]-a[i]<<" "<<a[i]<<"\n";
					res=max(res,v.back());
				}
				else {
					v.resize(min(SZ(v),int(n-c-1)));
					// ll good=1;
					// for(auto u:dp[mki])if(better(u,v)){good=0;break;}
					if(!SZ(dp[mki]))dp[mki].pb(v);
					else if(v>dp[mki][0])dp[mki][0]=v;
				}
			}
		}
		cout<<res<<"\n";
	}
	return 0;
}
