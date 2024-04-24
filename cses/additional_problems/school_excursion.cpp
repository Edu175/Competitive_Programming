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
typedef int ll;
typedef pair<ll,ll> ii;
const ll MAXN=1e5+5;

vector<ll>g[MAXN];
ll vis[MAXN];
vector<ll>c;
void dfs(ll x){
	vis[x]=1;
	c.pb(x);
	for(auto y:g[x])if(!vis[y])dfs(y);
}

int main(){FIN;
	ll n,m; cin>>n>>m;
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	vector<ll>a;
	fore(i,0,n)if(!vis[i]){
		c.clear();
		dfs(i);
		a.pb(SZ(c));
	}
	vector<ll>b(n+1);
	for(auto i:a)b[i]++;
	fore(i,0,n+1)if(b[i]){
		ll x=min(b[i],((b[i]&1)?1:2)),y=(b[i]-x)/2;
		if(y)b[2*i]+=y;
		b[i]=x;
	}
	a.clear();
	fore(i,0,SZ(b))fore(j,0,b[i])a.pb(i);
	bitset<MAXN>dp;
	dp[0]=1;
	fore(i,0,SZ(a))dp|=dp<<a[i];
	//imp(a);
	fore(i,1,n+1)cout<<dp[i];;cout<<"\n";
	return 0;
}
