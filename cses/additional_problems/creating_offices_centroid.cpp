#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef int ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

#pragma GCC optimize("O3,unroll-loops")
const ll MAXN=2e5+5;
// centroid go brr
 
vector<ll> g[MAXN];
bool tk[MAXN];
ll fat[MAXN];	// father in centroid decomposition 
ll szt[MAXN];	// size of subtree
ll tag[MAXN];	// tag[y]>=tag[x] for every y in x's subgraph (has to be conenected to x)
ll calcsz(ll x, ll f){
	szt[x]=1;
	for(auto y:g[x])if(y!=f&&!tk[y])szt[x]+=calcsz(y,x);
	return szt[x];
}
ll ccnt=0;
void cdfs(ll x=0,ll f=-1,ll sz=-1){	// O(nlogn)
	if(sz==-1)sz=calcsz(x,-1);
	for(auto y:g[x])if(!tk[y]&&szt[y]*2>=sz){
		szt[x]=0;cdfs(y,f,sz);return;
	}
	fat[x]=f; tk[x]=1; tag[x]=ccnt++;
	for(auto y:g[x])if(!tk[y])cdfs(y,x);
}
void centroid(){mset(tk,0);ccnt=0;cdfs();}
 
ll D[MAXN],fa[MAXN];
void dfs(ll x){
	for(auto y:g[x])if(y!=fa[x]){
		fa[y]=x;
		D[y]=D[x]+1;
		dfs(y);
	}
}
vv dis[MAXN];
void dfs1(ll rt, ll x, ll fa=-1, ll d=0){
	dis[x].pb(d);
	for(auto y:g[x])if(y!=fa&&tag[y]>=tag[rt])dfs1(rt,y,x,d+1);
}
ll md[MAXN];
ll mind(ll x){
	ll res=md[x];
	for(ll y=x,i=0;y!=-1;y=fat[y],i++)res=min(res,md[y]+dis[x][i]);
	return res;
}
void upd(ll x){
	for(ll y=x,i=0;y!=-1;y=fat[y],i++)md[y]=min(md[y],dis[x][i]);
}
ll nl[MAXN],orig[MAXN]; // nl for helping cache
ll cnt=0;
void cache(ll x, ll fa=-1){
	nl[x]=cnt;
	orig[cnt++]=x;
	for(auto y:g[x])if(y!=fa)cache(y,x);
}

int main(){FIN;
	ll n,k; cin>>n>>k;
	vector<ii>ed;
	fore(i,0,n-1){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
		ed.pb({u,v});
	}
	//
	cache(0);
	fore(i,0,n)g[i].clear();
	for(auto [x,y]:ed){
		ll u=nl[x],v=nl[y];
		g[u].pb(v);
		g[v].pb(u);
	}
	//
	D[0]=0; fa[0]=-1;
	// cerr<<"dfs\n";
	dfs(0);
	// cerr<<"centroid\n";
	centroid();
	vv pos(n);
	// cerr<<"reserve\n";
	fore(x,0,n){
		pos[tag[x]]=x,md[x]=k+5;
		// ll cnt=0;
		// for(ll y=x;y!=-1;y=fat[y],cnt++);
		// dis[x].reserve(cnt);
	}
	// cerr<<"dfs1\n";
	for(ll i=n-1;i>=0;i--){
		ll x=pos[i];
		dfs1(x,x);
	}
	vv deg(n); // pa abajo
	// cerr<<"problem\n";
	priority_queue<ii>pq;
	auto putif=[&](ll x){if(!deg[x])pq.push({D[x],x});};
	fore(x,0,n){
		deg[x]=SZ(g[x])-(fa[x]!=-1);
		putif(x);
	}
	vv bag,ans;
	while(SZ(pq)){
		auto [sdkj,x]=pq.top(); pq.pop();
		ll good=k<=mind(x);
		// cout<<x<<": "<<good<<"\n";
		if(good){
			ans.pb(x);
			upd(x);
		}
		if(fa[x]!=-1){
			deg[fa[x]]--;
			putif(fa[x]);
		}
	}
	cout<<SZ(ans)<<"\n";
	for(auto i:ans)cout<<orig[i]+1<<" ";;cout<<"\n";
	return 0;
}