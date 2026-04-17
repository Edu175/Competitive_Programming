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
const ll MAXN=5005;


int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n);
		fore(i,0,n)cin>>a[i];
		vv xp(n+1);
		fore(i,1,n+1)xp[i]=xp[i-1]^a[i-1];
		map<ll,vv> mp;
		fore(i,0,SZ(xp))mp[xp[i]].pb(i);
		vv dp(n+1);
		for(ll i=n-1;i>=0;i--){
			auto &res=dp[i];
			res=dp[i+1];
			auto &v=mp[xp[i]];
			auto ptr=lower_bound(ALL(v),i);
			ptr++;
			if(ptr!=v.end()){
				res=max(res,1+dp[*ptr]);
			}
		}
		ll res=dp[0];
		res=n-res;
		cout<<res<<"\n";
	}
	return 0;
}
