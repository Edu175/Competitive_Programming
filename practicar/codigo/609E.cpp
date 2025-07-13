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
const ll MAXN=2e5+5;

vector<ii> g[MAXN];
const ll K=18; //K such that 2^K>=n
ll F[K][MAXN],D[MAXN],V[K][MAXN];
void lca_dfs(ll x){
	for(auto [y,w]:g[x]){
		if(y==F[0][x])continue;
		F[0][y]=x;V[0][y]=w,D[y]=D[x]+1;lca_dfs(y);
	}
}
void lca_init(ll n){
	D[0]=0;F[0][0]=-1;
	lca_dfs(0);
	fore(k,1,K)fore(x,0,n){
		if(F[k-1][x]<0)F[k][x]=-1;
		else F[k][x]=F[k-1][F[k-1][x]],V[k][x]=max(V[k-1][x],V[k-1][F[k-1][x]]);
	}
}
ll query(ll x, ll y){
	if(D[x]<D[y])swap(x,y);
	ll res=-1;
	for(ll k=K-1;k>=0;k--)if(D[x]-(1ll<<k)>=D[y])res=max(res,V[k][x]), x=F[k][x];
	if(x==y)return res;
	for(ll k=K-1;k>=0;k--)if(F[k][x]!=F[k][y]){
		res=max({res,V[k][x],V[k][y]});
		x=F[k][x];
		y=F[k][y];
	}
	res=max({res,V[0][x],V[0][y]});
	return res;
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
int main(){FIN;
	ll n,m; cin>>n>>m;
	vector<array<ll,3>> ed;
	fore(i,0,m){
		ll u,v,w; cin>>u>>v>>w; u--,v--;
		ed.pb({w,u,v});
	}
	auto sed=ed;
	sort(ALL(sed));
	ll tot=0;
	uf_init();
	for(auto [w,u,v]:sed){
		if(uf_join(u,v)){
			tot+=w;
			g[u].pb({v,w});
			g[v].pb({u,w});
		}
	}
	lca_init(n);
	for(auto [w,u,v]:ed){
		ll c=query(u,v);
		ll res=tot;
		if(w>c)res+=w-c;
		cout<<res<<"\n";
	}
	return 0;
}