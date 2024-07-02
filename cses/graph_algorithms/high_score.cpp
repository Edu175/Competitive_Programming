#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=2505,INF=1e15;

vector<ii> g[MAXN],t[MAXN];
ll vis[MAXN];
void dfs(ll x, ll w){
	// cout<<"dfs "<<x<<" "<<w<<"\n";
	vis[x]|=w;
	for(auto [y,fgdfh]:(w==1?g:t)[x]){
		if(!(vis[y]&w))dfs(y,w);
	}
}

int main(){FIN;
	ll n,m; cin>>n>>m;
	fore(i,0,m){
		ll u,v,w; cin>>u>>v>>w; u--,v--;
		g[u].pb({v,w});
		t[v].pb({u,w});
	}
	vector<vector<ll>>dp(2*n+5,vector<ll>(n,-INF));
	dp[0][0]=0;
	fore(i,1,2*n+5){
		fore(x,0,n){
			for(auto [y,w]:g[x])
				dp[i][y]=max(dp[i][y],dp[i-1][x]+w);
		}
		// cout<<i<<": "; imp(dp[i]);
	}
	vector<ll>res(n,-INF),ans(n,-INF),bad(n);
	fore(x,0,n){
		fore(i,0,n)res[x]=max(res[x],dp[i][x]);
		fore(i,n,2*n+5)ans[x]=max(ans[x],dp[i][x]);
	}
	fore(x,0,n)bad[x]=ans[x]>res[x];
	dfs(0,1); dfs(n-1,2);
	ll flag=1;
	fore(x,0,n)if(bad[x]&&vis[x]==3)flag=0;
	// fore(i,0,n)cout<<bad[i]<<" ";;cout<<"\n";
	// fore(i,0,n)cout<<vis[i]<<" ";;cout<<"\n";
	if(!flag)cout<<"-1\n";
	else cout<<res[n-1]<<"\n";
	return 0;
}
