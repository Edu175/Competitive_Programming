#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ioi=b;i<ioi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto kjfg:v)cout<<kjfg<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=1505;
ll n;
ll vis[MAXN],g[MAXN][MAXN];
void dfs(ll x){
	vis[x]=1;
	fore(y,0,n)if(g[x][y]&&!vis[y])dfs(y);
}
void initialize(int N){
	n=N;
	fore(i,0,n)fore(j,0,n)if(i!=j)g[i][j]=1;
}
int hasEdge(int u, int v){
	ll x=u,y=v;
	g[x][y]=g[y][x]=0;
	fore(i,0,n)vis[i]=0;
	dfs(x);
	if(vis[y])return 0;
	g[x][y]=g[y][x]=1;
	return 1;
}

