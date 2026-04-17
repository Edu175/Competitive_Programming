#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second 
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=1e3+5;

vector<int> g[MAXN];
int n,m;
int mat[MAXN]; bool vis[MAXN];
int match(int x){
	if(vis[x])return 0;
	vis[x]=true;
	for(auto y:g[x])if(mat[y]<0||match(mat[y])){mat[y]=x;return 1;}
	return 0;
}

ll mm(ll n){
	mset(mat,-1);
	ll res=0;
	fore(i,0,n)mset(vis,0),res+=match(i);
	return res;
}

ll c[MAXN];
void dfs(ll x, ll w){
	c[x]=w;
	for(auto y:g[x])if(c[y]==-1)dfs(y,w^1);
}
int main(){
	JET
	int t; cin>>t;
	while(t--){
		cin>>n>>m;
		fore(i,0,n)g[i].clear();
		vector<ii> ed;
		fore(i,0,m){
			ll u,v; cin>>u>>v; u--,v--;
			ed.pb({u,v});
			g[u].pb(v);
			g[v].pb(u);
		}
		vv h[2];
		mset(c,-1);
		fore(i,0,n)if(c[i]==-1)dfs(i,0);
		fore(i,0,n)h[c[i]].pb(i);
		vv id(n);
		fore(k,0,2)fore(i,0,SZ(h[k]))id[h[k][i]]=i;
		fore(i,0,n)g[i].clear();
		for(auto [x,y]:ed){
			if(c[x])swap(x,y);
			g[id[x]].pb(id[y]);
		}
		ll res=mm(SZ(h[0]));
		vv is(SZ(h[0]));
		fore(i,0,SZ(h[1])){
			if(mat[i]==-1)res++;
			else is[mat[i]]=1;
		}
		for(auto i:is)res+=!i;
		cout<<res<<"\n";
	}
	return 0;
}