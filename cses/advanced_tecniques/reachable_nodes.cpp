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
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
const ll MAXN=5e4;

bitset<MAXN> c[MAXN];
vector<ll> g[MAXN];
ll vis[MAXN];

void dfs(ll x){
	vis[x]=1;
	c[x][x]=1;
	for(auto y:g[x]){
		if(!vis[y])dfs(y);
		c[x]|=c[y];
	}
}

int main(){FIN;
	ll n,m; cin>>n>>m;
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
	}
	fore(i,0,n)if(!vis[i])dfs(i);
	fore(i,0,n)cout<<c[i].count()<<" ";
	cout<<"\n";
	return 0;
}
