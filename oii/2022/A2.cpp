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
ll C[MAXN],c[MAXN],w[MAXN],id[MAXN];
ll k=0;
ll vis[MAXN];
void dfs(ll x){
	vis[x]=1;
	id[x]=k;
	w[k]++;
	for(auto y:G[x])if(!vis[y]&&C[y]==C[x])dfs(y);
}

set<ii>st;
bool is(ll x, ll y){ //anti self-loops and multi-edges
	if(x==y)return 1;
	if(x>y)swap(x,y);
	if(st.count({x,y}))return 1;
	st.insert({x,y});
	return 0;
}
ll r1,r2,sz;
void dfs2(ll x){
	//cout<<"dfs2 "<<x<<endl;
	sz+=w[x];
	for(auto y:g[x])if((c[y]==r1||c[y]==r2)&&!is(x,y))dfs2(y);
}
int main(){FIN;
	ll n,m; cin>>n>>m;
	if(n<=2000)return 0;
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
	//cout<<"g"<<endl;
	fore(i,0,m){ //contains self loops (prob) and multi edges
		ll u=id[ed[i].fst],v=id[ed[i].snd];
		g[u].pb(v);
		g[v].pb(u);
		ed[i]={u,v};
	}
	ll res=1;
	//cout<<"res"<<endl;
	fore(i,0,m){
		ll x=ed[i].fst;
		sz=0;
		r1=c[ed[i].fst],r2=c[ed[i].snd];
		dfs2(x);
		res=max(res,sz);
	}
	cout<<res<<"\n";
	return 0;
}

/*

g++ -O2 -std=c++17 -Wall -Wextra -g -D_GLIBCXX_DEBUG A.cpp -o a

*/
