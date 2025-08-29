#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll mod=998244353;
const ll MOD=187645LL * mod;
void addig(auto &a, ll b){a+=b;if(a>=MOD)a-=MOD;}
ll add(ll a, ll b){addig(a,b);return a;}

int main(){
	JET
	ll n,m,k; cin>>n>>m>>k;
	vector<vv> g(n);
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	ll mxdis=n+5,mxday=mxdis/k+1;
	k++;
	vector<vector<vv>>dp(mxday+1,vector<vv>(k+1,vv(n))); // dia, resto, nodo
	dp[0][0][0]=1;
	fore(d,0,mxday)fore(r,0,k)fore(x,0,n){
		auto &now=dp[d][r][x];
		addig(dp[d+1][0][x],now);
		for(auto y:g[x])addig(dp[d][r+1][y],now);
		// cout<<d<<" "<<r<<" "<<x<<": "<<now<<"\n";
	}
	fore(d,0,mxday){
		ll cur=0;
		fore(r,0,k)addig(cur,dp[d][r][1]);
		if(cur!=0){
			cout<<cur%mod<<"\n";
			return 0;
		}
	}
	cout<<"0\n";
	return 0;
}