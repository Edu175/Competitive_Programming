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
const ll MAXN=1e5+5;
vector<ll>g[MAXN];
ll vis[MAXN];
vector<ll>p,cyc;
void doit(ll x){
	ll did=0;
	for(auto i:p){
		did|=i==x;
		if(did)cyc.pb(i);
	}
	cyc.pb(x);
}
void dfs(ll x, ll f=-1){
	if(SZ(cyc))return;
	vis[x]=1;
	p.pb(x);
	for(auto y:g[x])if(y!=f){
		if(SZ(cyc))return;
		if(!vis[y])dfs(y,x);
		else doit(y);
	}
	p.pop_back();
}

int main(){FIN;
	ll n,m; cin>>n>>m;
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	fore(i,0,n)if(!vis[i])dfs(i);
	if(!SZ(cyc))cout<<"IMPOSSIBLE\n";
	else {
		cout<<SZ(cyc)<<"\n";
		for(auto i:cyc)cout<<i+1<<" ";
		cout<<"\n";
	}
	return 0;
}
