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
const ll INF=1e15;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m,k; cin>>n>>m>>k;
		vector<vv>a(n,vv(m));
		fore(i,0,n)fore(j,0,m)cin>>a[i][j];
		vector<vector<vv>>dp(n+3,vector<vv>(m+3,vv(m,INF)));
		dp[n][m-1][0]=0;
		for(ll i=n-1;i>=0;i--)for(ll j=m-1;j>=0;j--){
			ll mn=INF;
			fore(d,0,m)mn=min(mn,dp[i+1][j][d]+k*d);
			fore(d,0,m){
				auto &res=dp[i][j][d];
				res=a[i][(j+d)%m];
				res+=min(dp[i][j+1][d],mn);
				// cout<<i<<" "<<j<<" "<<d<<": "<<res<<"\n";
			}
		}
		ll res=INF;
		fore(d,0,m)res=min(res,dp[0][0][d]+k*d);
		cout<<res<<"\n";
	}
	return 0;
}
