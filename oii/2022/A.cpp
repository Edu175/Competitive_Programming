#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oii=b;i<oii;i++)
#define SZ(x) ((int)x.size)
#define ALL(x) x.begin(),x.end
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" ";cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=1e5+5;

vector<ll>G[MAXN],g[MAXN]; //NORMAL, comprimido por color
set<ll> gst[MAXN];
ll C[MAXN],c[MAXN],w[MAXN],id[MAXN];
ll k=0;
ll vis[MAXN];
void dfs(ll x){
	vis[x]=1;
	id[x]=k;
	w[k]++;
	for(auto y:G[x])if(!vis[y]&&C[y]==C[x])dfs(y);
}
ll r1,r2,sz;
vector<ll>del;
void dfs2(ll x){
	sz+=w[x];
	vis[x]=1; del.pb(x);
	for(auto y:g[x])if(!vis[y]&&(c[y]==r1||c[y]==r2))dfs2(y);
}
int main(){FIN;
	ll n,m; cin>>n>>m;
	//G
	fore(i,0,n)cin>>C[i];
	ii ed[m];
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		G[u].pb(v);
		G[v].pb(u);
		ed[i]={u,v};
	}
	fore(x,0,n){
		if(vis[x])continue;
		c[k]=C[x];
		dfs(x);
		k++;
	}
	//g
	fore(i,0,m){ //with self loops not multi edges
		ll u=id[ed[i].fst],v=id[ed[i].snd];
		gst[u].insert(v);
		gst[v].insert(u);
	}
	map<ii,vector<ii>>can; //color, edge
	fore(u,0,k)for(auto v:gst[u]){
		g[u].pb(v);
		ii p={c[u],c[v]};
		if(p.fst>p.snd)swap(p.fst,p.snd);
		//if(u>v)swap(u,v);
		can[p].pb({u,v});
	}
	mset(vis,0);
	ll res=1;
	for(auto i:can){
		r1=i.fst.fst,r2=i.fst.snd;
		for(auto ar:i.snd){
			sz=0;
			ll x=ar.fst;
			if(vis[x])continue;
			dfs2(x);
			res=max(res,sz);
		}
		for(auto j:del)vis[j]=0;
		del.clear();
	}
	cout<<res<<"\n";
	return 0;
}

/*

g++ -O2 -std=c++17 -Wall -Wextra -g -D_GLIBCXX_DEBUG A.cpp -o a

*/
