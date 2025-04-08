#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const int MOD=1e9+7;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int main(){FIN;
	int n,m; cin>>n>>m;
	int g[n][n]; mset(g,0);
	fore(i,0,m){
		int x,y; cin>>x>>y; x--,y--;
		g[x][y]++;
	}
	int dp[1<<n][n]; mset(dp,0);
	int all=(1<<n)-1,last=all^(1<<(n-1));
	dp[last][n-1]=1;
	for(int mk=last-1;mk>=0;mk--)fore(x,0,n)if(!(mk>>x&1)){
		auto &res=dp[mk][x];
		int nxt=mk|(1<<x);
		fore(y,0,n)if(!(mk>>y&1))res=add(res,mul(g[x][y],dp[nxt][y]));
	}
	cout<<dp[0][0]<<"\n";
	return 0;
}