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
const ll MAXN=1e5+5,MAXM=2e5+5;

vector<ii> g[MAXN],t[MAXN];
ll es[MAXM],deg[MAXN],vis[MAXN];
void dfs1(ll x){
	vis[x]=1;
	for(auto [y,i]:g[x])if(!vis[y]){
		t[x].pb({y,i});
		dfs1(y);
	}
}
ll c=0;
void dfs2(ll x){
	vis[x]=1;
	c^=deg[x];
	for(auto [y,i]:t[x]){
		es[i]^=c;
		dfs2(y);
		es[i]^=c;
	}
}
int main(){FIN;
	ll n,m; cin>>n>>m;
	vector<ii>ed;
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb({v,i});
		g[v].pb({u,i});
		deg[u]^=1;
		ed.pb({u,v});
	}
	fore(i,0,n)if(!vis[i])dfs1(i);
	mset(vis,0);
	ll flag=1;
	fore(i,0,n)if(!vis[i]){
		c=0;
		dfs2(i);
		if(c)flag=0;
	}
	if(!flag){
		cout<<"IMPOSSIBLE\n";
		return 0;
	}
	fore(i,0,m){
		if(es[i])swap(ed[i].fst,ed[i].snd);
		cout<<ed[i].fst+1<<" "<<ed[i].snd+1<<"\n";
	}
	return 0;
}
