#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oii=b;i<oii;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" ";cout<<"\n"
using namespace std;
typedef int ll;
typedef pair<ll,ll> ii;
const ll MAXN=1005,MAXS=1e5+5,M=105;

ll n,k;
ll g[MAXN][MAXN];
ll a[MAXN];
ll vis[MAXN];
vector<vector<ll>>cmp; ll idx=0;
vector<ll>val;

void dfs(ll x){
	vis[x]=1; cmp[idx].pb(x);
	//cout<<x<<"\n";
	fore(y,0,n){
		//cout<<"   "<<y<<" "<<g[x][y]<<" "<<vis[y]<<"\n";
		if(g[x][y]&&!vis[y])dfs(y);
	}
}
ll dp[MAXN][MAXS];
vector<ll>ans;
void build(ll i, ll s){
	if(i==n)return;
	if(dp[i+1][s+val[i]]<dp[i+1][s])ans.pb(i),build(i+1,s+val[i]);
	else build(i+1,s);
}
int main(){FIN;
	ll m; cin>>n>>m;
	fore(i,0,n)fore(j,0,n)g[i][j]=1;
	ll sum=0;
	fore(i,0,n)cin>>a[i],sum+=a[i];
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		g[u][v]=0;
		g[v][u]=0;
	}
	/*fore(i,0,n){
		fore(j,0,n)cout<<g[i][j]<<" ";
		cout<<"\n";
	}*/
	fore(i,0,n){
		if(vis[i])continue;
		//cout<<"head "<<i<<":\n";
		cmp.pb({});
		dfs(i);
		idx++;
	}
	k=idx;
	val.resize(m);
	fore(i,0,k)for(auto x:cmp[i])val[i]+=a[x];
	//sub 1
	/*cout<<abs(val[0]-(sum-val[0]))<<"\n";
	for(auto i:cmp[0])cout<<i+1<<" ";
	cout<<"\n";*/
	for(ll i=k;i>=0;i--)fore(s,0,MAXS){
		ll &res=dp[i][s];
		if(i==k){res=abs(s-(sum-s));continue;}
		res=min(dp[i+1][s],dp[i+1][s+val[i]]);
	}
	cout<<dp[0][0]<<"\n";
	//build
	build(0,0);
	for(auto i:ans)for(auto j:cmp[i])cout<<j+1<<" ";
	cout<<"\n";
	return 0;
}
