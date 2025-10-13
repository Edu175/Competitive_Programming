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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		k=n*(n-1)/2-k;
		vector<ll> tri;
		fore(i,0,n+1)tri.pb(i*(i-1)/2);
		
		vv dp(n*n+5),to=dp;
		dp[0]=0;
		fore(k,1,n*n+5){
			auto &res=dp[k];
			res=1e18;
			fore(v,1,n+1)if(k-tri[v]>=0){
				ll cur=v+dp[k-tri[v]];
				res=min(res,cur);
				if(res==cur)to[k]=v;
			}
		}
		vv us;
		while(k>0){
			ll v=to[k];
			assert(v>0);
			us.pb(v);
			k-=tri[v];
		}
		// imp(us)
		ll cnt=n+1;
		vv res;
		for(auto z:us){
			fore(i,cnt-z,cnt)res.pb(i);
			cnt-=z;
		}
		while(SZ(res)<n)res.pb(--cnt);
		if(SZ(res)>n){
			cout<<"0\n";
		}
		else {
			imp(res)
		}
		// cout<<"\n";
	}
	return 0;
}
