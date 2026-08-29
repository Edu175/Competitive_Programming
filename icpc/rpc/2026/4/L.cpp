#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=3e5+5;
int n,rnk[MAXN],pre[MAXN],anc[MAXN],idom[MAXN],semi[MAXN],low[MAXN];
vector<ii> g[MAXN];
vector<int>rev[MAXN],dom[MAXN],ord;
void dfspre(int pos){
	rnk[pos]=SZ(ord); ord.pb(pos);
	for(auto [x,asd]:g[pos]){
		rev[x].pb(pos);
		if(rnk[x]==n) pre[x]=pos,dfspre(x);
	}
}
int eval(int v){
	if(anc[v]<n&&anc[anc[v]]<n){
		int x=eval(anc[v]);
		if(rnk[semi[low[v]]]>rnk[semi[x]]) low[v]=x;
		anc[v]=anc[anc[v]];
	}
	return low[v];
}
void dominators(int rt){
	fore(i,0,n){
		dom[i].clear(); rev[i].clear();
		rnk[i]=pre[i]=anc[i]=idom[i]=n;
		semi[i]=low[i]=i;
	}
	ord.clear(); dfspre(rt);
	for(int i=SZ(ord)-1;i;i--){
		int w=ord[i];
		for(int v:rev[w]){
			int u=eval(v);
			if(rnk[semi[w]]>rnk[semi[u]])semi[w]=semi[u];
		}
		dom[semi[w]].pb(w); anc[w]=pre[w];
		for(int v:dom[pre[w]]){
			int u=eval(v); idom[v]=(rnk[pre[w]]>rnk[semi[u]]?u:pre[w]);
		}
		dom[pre[w]].clear();
	}
	for(int w:ord) if(w!=rt&&idom[w]!=semi[w]) idom[w]=idom[idom[w]];
	fore(i,0,n) if(idom[i]==n)idom[i]=-1;
}
vv t[MAXN]; // el tree de dominator

vv bfs(ll s, vector<vector<ii>> &G){ // already puts in g
	vv d(n,-1);
	d[s]=0;
	queue<ll> q;
	q.push(s);
	while(SZ(q)){
		auto x=q.front(); q.pop();
		for(auto [y,i]:G[x]){
			if(d[y]==-1)q.push(y),d[y]=d[x]+1;
			if(d[y]==d[x]+1)g[x].pb({y,i});
		}
	}
	return d;
}

ll a[MAXN];
ll cant[MAXN];

void dfs(ll x){
	cant[x]=a[x];
	for(auto y:t[x]){
		dfs(y);
		cant[x]+=cant[y];
	}
}

int main(){FIN;
	ll m; cin>>n>>m;
	vector<vector<ii>> G(n); // statement's G
	fore(i,0,n)cin>>a[i];
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		G[u].pb({v,i});
		G[v].pb({u,i});
	}
	auto d=bfs(0,G);
	dominators(0);
	fore(i,0,n){
		ll fa=idom[i];
		if(fa!=-1)t[fa].pb(i);
	}
	dfs(0);
	vector<vv> ing(n);
	fore(x,0,n)for(auto [y,i]:g[x])ing[y].pb(i);
	vv ans(m);
	fore(x,0,n)if(SZ(ing[x])==1){
		ll ed=ing[x][0];
		ans[ed]=cant[x];
	}
	for(auto i:ans)cout<<i<<"\n";
	return 0;
}
