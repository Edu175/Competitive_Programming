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

vector<ll> g[MAXN],g2[MAXN];set<ll> gst[MAXN];
ll n,n2,lw[MAXN],idx[MAXN],qidx,cmp[MAXN],qcmp;
stack<ll>st;

void tjn(ll u){
	lw[u]=idx[u]=++qidx;
	st.push(u); cmp[u]=-2;
	for(auto v:g[u]){
		if(!idx[v]||cmp[v]==-2){ //tree edge, back edge
			if(!idx[v])tjn(v);
			lw[u]=min(lw[u],lw[v]);
		}
		// else cross edge
	}
	if(lw[u]==idx[u]){
		ll x=u;
		do{x=st.top(),st.pop(),cmp[x]=qcmp;}
		while(x!=u);
		qcmp++;
	}
}
void scc(){
	//fore(i,0,n)idx[i]=0,cmp[i]=-1;//,g2[i].clear();gst[i].clear();
	//qidx=0; qcmp=0;
	mset(idx,0); // NO TEST CASES
	mset(cmp,-1);
	fore(i,0,n)if(!idx[i])tjn(i);
	fore(i,0,n)for(auto j:g[i])if(cmp[i]!=cmp[j])gst[cmp[i]].insert(cmp[j]);
	fore(i,0,n)for(auto j:gst[i])g2[i].pb(j);
	n2=qcmp;
}
bitset<MAXN> c[MAXN];
ll vis[MAXN];

void dfs(ll x){
	vis[x]=1;
	c[x][x]=1;
	for(auto y:g2[x]){
		if(!vis[y])dfs(y);
		c[x]|=c[y];
	}
}

int main(){FIN;
	ll m,q; cin>>n>>m>>q;
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
	}
	scc();
	fore(i,0,n2)if(!vis[i])dfs(i);
	while(q--){
		ll u,v; cin>>u>>v; u--,v--;
		u=cmp[u],v=cmp[v];
		if(c[u][v])cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
