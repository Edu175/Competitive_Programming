#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(a){for(auto x:a)cout<<a<<" ";cout<<"\n"}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){
	JET
	ll n,k,m; cin>>n>>k>>m;
	vector<vector<vv>> gs(k,vector<vv>(n));
	fore(_,0,m){
		ll u,v,w; cin>>u>>v>>w; u--,v--,w--;
		gs[w][u].pb(v);
		gs[w][v].pb(u);
	}
	vector<vv> dp(k+1,vv(n));
	dp[0]=vv(n,1);
	fore(d,0,k){
		fore(x,0,n)if(dp[d][x])for(auto y:gs[d][x])dp[d+1][y]=1;
	}
	vv res;
	fore(x,0,n)if(dp[k][x])res.pb(x);
	cout<<SZ(res)<<"\n";
	for(auto x:res)cout<<x+1<<"\n";
	return 0;
}