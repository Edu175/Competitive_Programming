#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oii=b;i<oii;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto sdkfjg:v)cout<<sdkfjg<<" ";cout<<"\n";}
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=1005;
typedef bitset<MAXN> mask;

mask col[MAXN];
ll id[MAXN];
vector<ll> g[MAXN];
ll uf_find(ll x){return id[x]==x?x:id[x]=uf_find(id[x]);}
void add(ll x, ll y){
	g[x].pb(y); g[y].pb(x);
	ll px=uf_find(x),py=uf_find(y);
	if(px==py)return;
	col[px]|=col[py];
	id[py]=px;
}
vector<ll>c;
mask vis;

void dfs(ll x){
	vis[x]=1; c.pb(x);
	for(auto y:g[x])if(!vis[y])dfs(y);
}

void erase(ll x, ll y){
	g[x].erase(find(ALL(g[x]),y));
	g[y].erase(find(ALL(g[y]),x));
	ll px=uf_find(x);//,py=uf_find(y);
	vis.reset(); c.clear();
	dfs(x);
	if(vis[px]){
		vis.reset(); c.clear();
		swap(x,y);
		dfs(x);
	}
	if(vis[px])return;
	assert(!vis[y]);
	col[x]=col[px];
	for(auto i:c)id[i]=x;
	vis.reset(); c.clear();
	dfs(y);
	for(auto i:c)id[i]=px;
}


int main(){FIN;
	ll n,m; cin>>n>>m;
	vector<vector<ll>>is(n,vector<ll>(n));
	//init
	fore(i,0,n){
		col[i][i]=1;
		id[i]=i;
	}
	
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		if(u<v)swap(u,v);
		if(is[u][v])erase(u,v);
		else add(u,v);
		is[u][v]^=1;
	}
	fore(i,0,n)cout<<col[uf_find(i)].count()<<"\n";
	return 0;
}