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
		ll n; cin>>n;
		vv a(n);
		vector<vv> pos(n+1);
		vv wh(n);
		fore(i,0,n){
			cin>>a[i];
			wh[i]=SZ(pos[a[i]]);
			pos[a[i]].pb(i);
		}
		vv dp(n+1);
		for(ll i=n-1;i>=0;i--){
			auto &res=dp[i];
			res=dp[i+1];
			auto &vec=pos[a[i]];
			ll p=wh[i]+a[i]-1;
			// cout<<i<<": "<<a[i]<<": "<<wh[i]<<": "<<p<<"\n";
			if(p<SZ(vec)){
				res=max(res,a[i]+dp[vec[p]+1]);
			}
		}
		cout<<dp[0]<<"\n";
	}
	return 0;
}
