#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oii=b;i<oii;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {cout<<"{ ";for(auto sdkfjg:v)cout<<sdkfjg<<" ";cout<<"} ";}
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=2e5+5;

ll n,k;
vector<ll>dp[MAXN]; ll id[MAXN];
ll res=0;
void join(ll x, ll y){
	ll _x=x,_y=y;
	x=id[x],y=id[y];
	while(x==y);
	if(SZ(dp[x])<SZ(dp[y]))swap(x,y);
	ll n=SZ(dp[x]),m=SZ(dp[y]);
	ll resi=0;
	fore(i,0,m){
		ll b=k-i;
		if(b>=0&&b<n)resi+=dp[x][n-1-b]*dp[y][m-1-i];
	}
	fore(i,0,m){
		dp[x][n-1-i]+=dp[y][m-1-i];
	}
	dp[y].clear();
	id[_x]=id[_y]=x;
	res+=resi;
}

vector<ll> g[MAXN]; ll fa[MAXN];
vector<ll>ord;

void dfs(ll x){
	for(auto y:g[x])if(y!=fa[x]){
		fa[y]=x;
		dfs(y);
	}
	ord.pb(x);
}

int main(){FIN;
	cin>>n>>k; 
	fore(i,0,n-1){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	fa[0]=-1;
	dfs(0);
	fore(i,0,n)id[i]=i,dp[i]={1};
	for(auto x:ord){
		for(auto y:g[x])if(y!=fa[x])join(x,y);
		dp[id[x]].pb(0);
	}
	cout<<res<<"\n";
	return 0;
}