#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oii=b;i<oii;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
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
void dfs2(ll x){
	sz+=w[x];
	vis[x]=1;
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
	vector<pair<ii,ll>>can;
	fore(i,0,m){ //contains self loops (prob) and multi edges
		ll u=id[ed[i].fst],v=id[ed[i].snd];
		ed[i]={u,v};
		//if(u>v)swap(u,v);
		ii p={c[u],c[v]};
		if(p.fst>p.snd)swap(p.fst,p.snd);
		can.pb({p,i});
	}
	sort(ALL(can));
	ll res=1;
	mset(vis,0);
	vector<ll>nodes;
	fore(i,0,SZ(can)){
		ll ix=can[i].snd,u=ed[ix].fst,v=ed[ix].snd;
		nodes.pb(u),nodes.pb(v);
		h[u].pb(v);
		h[v].pb(u);
		if(i==SZ(can)-1||can[i].fst!=can[i+1].fst){ //answer on colors i]
			for(auto x:nodes){
				if(vis[x])continue;
				sz=0;
				dfs2(x);
				res=max(res,sz);
			}
			for(auto x:nodes){
				h[x].clear();
				vis[x]=0;
			}
			nodes.clear();
		}
	}
	cout<<res<<"\n";
	return 0;
}

/*

g++ -O2 -std=c++17 -Wall -Wextra -g -D_GLIBCXX_DEBUG A.cpp -o a

*/
