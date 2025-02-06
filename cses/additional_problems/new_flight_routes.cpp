#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto i:v)cout<<i<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=1e5+5;

vector<ll> g[MAXN]; set<ll> gst[MAXN];
ll n,n2,lw[MAXN],idx[MAXN],qidx,cmp[MAXN],qcmp;
stack<ll>st;

void tjn(ll u){
	lw[u]=idx[u]=++qidx;
	st.push(u); cmp[u]=-2;
	for(auto v:g[u]){
		if(!idx[v]||cmp[v]==-2){ // tree edge, back edge
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
	qidx=0; qcmp=0;
	mset(idx,0);
	mset(cmp,-1);
	fore(i,0,n)if(!idx[i])tjn(i);
	fore(i,0,n)for(auto j:g[i])if(cmp[i]!=cmp[j])gst[cmp[i]].insert(cmp[j]);
	fore(i,0,n)g[i].clear();
	n=qcmp;
	fore(i,0,n)for(auto j:gst[i])g[i].pb(j);
}

bitset<MAXN> to[MAXN],vis;

void dfs(ll x){
	vis[x]=1;
	to[x][x]=1;
	for(auto y:g[x]){
		if(!vis[y])dfs(y);
		to[x]|=to[y];
	}
}

int main(){FIN;
	ll m; cin>>n>>m;
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
	}
	scc(); // new graph on g
	if(n==1){cout<<"0\n";return 0;}
	
	return 0;
}
