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

vector<ll>g[MAXN];
ll C[MAXN],c[MAXN],w[MAXN],id[MAXN];
ll k=0;
ll vis[MAXN];
void dfs(ll x){
	vis[x]=1;
	id[x]=k;
	w[k]++;
	for(auto y:g[x])if(!vis[y]&&C[y]==C[x])dfs(y);
}
ll sz;
vector<ll> h[MAXN];
//vector<ll>del;
void dfs2(ll x){
	sz+=w[x];
	vis[x]=1; //del.pb(x);
	for(auto y:h[x])if(!vis[y])dfs2(y);
}
int main(){FIN;
	ll n,m; cin>>n>>m;
	fore(i,0,n)cin>>C[i],C[i]--;
	ii ed[m];
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
		ed[i]={u,v};
	}
	fore(x,0,n){
		if(vis[x])continue;
		c[k]=C[x];
		dfs(x);
		k++;
	}
	//vector<ll>col[n];
	//fore(i,0,k)col[c[i]].pb(i);
	map<ll,vector<ii>>can; //color, edge
	//set<ii>multi;
	fore(i,0,m){ //contains self loops (prob) and multi edges
		ll u=id[ed[i].fst],v=id[ed[i].snd];
		//if(u>v)swap(u,v);
		//if(multi.count({u,v}))continue;
		//multi.insert({u,v});
		ii p={c[u],c[v]};
		if(p.fst>p.snd)swap(p.fst,p.snd);
		ll k=n*p.fst+p.snd;
		can[k].pb({u,v});
	}
	ll res=1;
	mset(vis,0);
	ll nodes[2*n+5];
	for(auto i:can){
		ll idx=0;
		//for(auto j:col[i.fst.fst])nodes.pb(j);
		//for(auto j:col[i.fst.snd])nodes.pb(j);
		for(auto ar:i.snd){
			//if(nodes.count(ar.fst)&&nodes.count(ar.snd))continue;
			//nodes.pb(ar.fst),nodes.pb(ar.snd);
			nodes[idx++]=ar.fst; nodes[idx++]=ar.snd;
			h[ar.fst].pb(ar.snd);
			h[ar.snd].pb(ar.fst);
		}
		fore(i,0,idx){
			ll x=nodes[i];
			if(vis[x])continue;
			sz=0;
			dfs2(x);
			res=max(res,sz);
		}
		fore(i,0,idx){
			ll x=nodes[i];
			if(vis[x])h[x].clear();
			vis[x]=0;
		}
	}
	cout<<res<<"\n";
	return 0;
}

/*

g++ -O2 -std=c++17 -Wall -Wextra -g -D_GLIBCXX_DEBUG A.cpp -o a

*/
