#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll INF=1e16;
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		vector<ll>a(n);
		map<ll,ll>mp;
		fore(i,0,n)cin>>a[i],mp[a[i]]^=1;
		ll did=0;
		map<ll,vector<ll>>r;
		for(auto i:mp)if(i.snd)r[i.fst%k].pb(i.fst);
		ll res=0;
		for(auto [i,v]:r){
			ll m=SZ(v);
			for(auto &i:v)i/=k;
			vector<vector<ll>>dp(m+2,vector<ll>(2));
			dp[m][m&1]=0;
			dp[m][(m+1)&1]=INF;
			for(ll i=m-1;i>=0;i--)fore(d,0,2){
				ll &res=dp[i][d];
				if(d){
					if(i==m-1)res=INF;
					else res=v[i+1]-v[i]+dp[i+2][d];
				}
				else {
					res=dp[i+1][1];
					if(i<m-1)res=min(res,v[i+1]-v[i]+dp[i+2][d]);
				}
			}
			res+=dp[0][0];
			did+=m&1;
		}
		if((n&1)!=did)res=-1;
		cout<<res<<"\n";
	}
	return 0;
}
