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
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=3005;
vector<ll>g[MAXN];
const ll K=12; //K such that 2^K>=n
ll F[K][MAXN],D[MAXN],S[MAXN],E[MAXN];
ll lcnt=0;
void lca_dfs(ll x){
	S[x]=lcnt++;
	for(auto y:g[x]){
		if(y==F[0][x])continue;
		F[0][y]=x;D[y]=D[x]+1;lca_dfs(y);
	}
	E[x]=lcnt;
}
void lca_init(ll n){
	lcnt=0;D[0]=0;F[0][0]=-1;
	lca_dfs(0);
	fore(k,1,K)fore(x,0,n){
		if(F[k-1][x]<0)F[k][x]=-1;
		else F[k][x]=F[k-1][F[k-1][x]];
	}
}
ll lca(ll x,ll y){
	if(D[x]<D[y])swap(x,y);
	for(ll k=K-1;k>=0;k--)if(D[x]-(1ll<<k)>=D[y])x=F[k][x];
	if(x==y)return x;
	for(ll k=K-1;k>=0;k--)if(F[k][x]!=F[k][y])x=F[k][x],y=F[k][y];
	return F[0][x];
}
 
ll dis(ll x, ll y){return D[x]+D[y]-2*D[lca(x,y)];}
ll father(ll v, ll x){ // v-ésimo padre de x
	for(ll k=K-1;k>=0;k--)if(v>=(1ll<<k)){
		x=F[k][x];
		v-=1ll<<k;
		if(x<0)break;
	}
	return x;
}
ll go(ll x, ll y){
	assert(x!=y);
	if(S[x]<S[y]&&S[y]<E[x]){ // x anc of y
		return father(D[y]-D[x]-1,y);
	}
	return F[0][x];
}
int uf[MAXN];
void uf_init(){mset(uf,-1);}
int uf_find(int x){return uf[x]<0?x:uf[x]=uf_find(uf[x]);}
bool uf_join(int x, int y){
	x=uf_find(x);y=uf_find(y);
	if(x==y)return false;
	if(uf[x]>uf[y])swap(x,y); // y -> x
	uf[x]+=uf[y];uf[y]=x;
	return true;
}
ll vis[MAXN][MAXN];
void f(ll x, ll y){
	if(vis[x][y])return;
	vis[x][y]=1;
	uf_join(x,y);
	if(x==y)return;
	if(dis(x,y)==1)return;
	ll xp=go(x,y),yp=go(y,x);
	f(xp,yp);
}
// ll vis2[MAXN][MAXN];
void dfs(ll x, ll y, ll xp, ll yp){
	if(uf_find(x)!=uf_find(y))return;
	if(vis[x][y])return;
	vis[x][y]=1;
	for(auto i:g[x])if(i!=xp)for(auto j:g[y])if(j!=yp)dfs(i,j,x,y);
}
int main(){FIN;
	uf_init();
	ll n; cin>>n;
	fore(i,0,n-1){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	lca_init(n);
	fore(i,0,n)fore(j,0,n){
		char c;
		cin>>c;
		if(c=='1')f(i,j);
	}
	mset(vis,0);
	fore(i,0,n){
		dfs(i,i,-1,-1);
		for(auto j:g[i])dfs(i,j,j,i);
	}
	ll res=0;
	fore(i,0,n)fore(j,0,n)res+=vis[i][j];
	cout<<res<<"\n";
	return 0;
}
