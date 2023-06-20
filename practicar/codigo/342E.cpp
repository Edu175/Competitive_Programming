#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=2e5+5,K=18,INF=1e9;

vector<ll>g[MAXN]; ll n;
bool tk[MAXN];
ll fat[MAXN],szt[MAXN];
ll calcsz(ll x, ll f){
	szt[x]=1;
	for(auto y:g[x])if(!tk[y]&&y!=f)szt[x]+=calcsz(y,x);
	return szt[x];
}
void cdfs(ll x=0, ll f=-1, ll sz=-1){
	if(sz==-1)sz=calcsz(x,-1);
	for(auto y:g[x])if(!tk[y]&&szt[y]*2>=sz){
		szt[x]=0; cdfs(y,f,sz); return;
	}
	fat[x]=f; tk[x]=1;
	for(auto y:g[x])if(!tk[y])cdfs(y,x);
}
void centroid(){mset(tk,0);cdfs();}

ll F[K][MAXN],D[MAXN];//késimo padre de x, distancia a root
void lca_dfs(ll x){//padres 0 y distancia
	for(auto y:g[x]){
		if(y==F[0][x])continue;
		F[0][y]=x;D[y]=D[x]+1;lca_dfs(y);
	}
}
void lca_init(){//k padres
	D[0]=0;F[0][0]=-1;
	lca_dfs(0);
	fore(k,1,K)fore(x,0,n){
		if(F[k-1][x]<0)F[k][x]=-1;
		else F[k][x]=F[k-1][F[k-1][x]];
	}
}
ll lca(ll x,ll y){
	if(D[x]<D[y])swap(x,y);//x abajo
	for(ll k=K-1;k>=0;k--)if(D[x]-(1ll<<k)>=D[y])x=F[k][x];//level
	if(x==y)return x;
	for(ll k=K-1;k>=0;k--)if(F[k][x]!=F[k][y])x=F[k][x],y=F[k][y];//find lca
	return F[0][x];
}
ll dis(ll x, ll y){return D[x]+D[y]-2*D[lca(x,y)];}
ll w[MAXN];
int main(){FIN;
	ll q; cin>>n>>q;
	fore(i,0,n-1){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	lca_init();
	centroid();
	fore(i,0,n)w[i]=INF;
	for(ll y=0;y!=-1;y=fat[y])w[y]=min(w[y],dis(0,y));
	while(q--){
		ll t,x; cin>>t>>x; t--,x--;
		if(!t){ //upd
			for(ll y=x;y!=-1;y=fat[y])w[y]=min(w[y],dis(x,y));
		}
		else { //ask
			ll res=INF;
			for(ll y=x;y!=-1;y=fat[y])res=min(res,dis(x,y)+w[y]);
			cout<<res<<"\n";
		}
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
