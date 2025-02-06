#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=5005,MAXS=100005;

vector<ll>g[MAXN];
ll c[MAXN];
ll vis[MAXN];
vector<vector<vector<ll>>>cmp;
ll bip=1,idx=0;
void dfs(ll x, ll w){
	c[x]=w;
	vis[x]=1;
	cmp[idx][w].pb(x);
	for(auto y:g[x]){
		if(!vis[y])dfs(y,w^1);
		else if(c[y]!=(w^1))bip=0;
	}
}
int main(){FIN;
	ll n,m; cin>>n>>m;
	vector<ll>sz(3);
	fore(i,0,3)cin>>sz[i];
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	vector<vector<ll>>a;
	fore(i,0,n){
		if(!vis[i]){
			cmp.pb({{},{}});
			dfs(i,0);
			a.pb({SZ(cmp[idx][0]),SZ(cmp[idx][1])});
			idx++;
		}
	}
	if(!bip){
		cout<<"NO\n";
		return 0;
	}
	bitset<MAXN> dp[idx+5];
	dp[idx][0]=1;
	for(ll i=idx-1;i>=0;i--){
		dp[i]=(dp[i+1]<<a[i][0])|(dp[i+1]<<a[i][1]);
	}
	if(!dp[0][sz[1]]){
		cout<<"NO\n";
		return 0;
	}
	ll res=sz[1];
	fore(i,0,idx){
		if(res>=a[i][0]&&dp[i+1][res-a[i][0]])res-=a[i][0];
		else if(res>=a[i][1]){
			res-=a[i][1];
			swap(cmp[i][0],cmp[i][1]);
		}
		else assert(0);
	}
	vector<ll>lab(n),us(n);
	fore(i,0,idx)for(auto x:cmp[i][0])lab[x]=2,us[x]=1;
	fore(i,0,n)if(!us[i]){
		if(sz[0])lab[i]=1,sz[0]--;
		else lab[i]=3;
	}
	cout<<"YES\n";
	fore(i,0,n)cout<<lab[i];;cout<<"\n";
	return 0;
}
