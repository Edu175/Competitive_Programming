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
const ll MAXN=2e5+5;

ll n;
vector<pair<ll,ll>>g[MAXN];

bool tk[MAXN];
ll fat[MAXN];	// father in centroid decomposition 
ll szt[MAXN];	// size of subtree

ll calcsz(ll x, ll f){
	szt[x]=1;
	for(auto y:g[x])if(y.fst!=f&&!tk[y.fst])szt[x]+=calcsz(y.fst,x);
	return szt[x];
}
void cdfs(ll x=0,ll f=-1,ll sz=-1){	// O(nlogn)
	if(sz==-1)sz=calcsz(x,-1);
	for(auto y:g[x])if(!tk[y.fst]&&szt[y.fst]*2>=sz){
		szt[x]=0;cdfs(y.fst,f,sz);return;
	}
	fat[x]=f; tk[x]=1;
	for(auto y:g[x])if(!tk[y.fst])cdfs(y.fst,x);
}
void centroid(){mset(tk,0);cdfs();}

const ll K=18;
//K such that 2^K>=n, log2 techo de n, ceil(log2(n))
ll F[K][MAXN],D[MAXN];//késimo padre de x, distancia a root
ll sp[MAXN];
void lca_dfs(ll x){//padres 0 y distancia
	for(auto y:g[x]){
		if(y.fst==F[0][x])continue;
		F[0][y.fst]=x;D[y.fst]=D[x]+1; sp[y.fst]=sp[x]+y.snd;lca_dfs(y.fst);
	}
}
void lca_init(){//k padres
	D[0]=0;F[0][0]=-1,sp[0]=0;
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
ll disp(ll x, ll y){return sp[x]+sp[y]-2*sp[lca(x,y)];}
ll dis(ll x, ll y){return D[x]+D[y]-2*D[lca(x,y)];}

vector<pair<ll,ll>> b[MAXN];
int main(){FIN;
	cin>>n;
	ll sum=0;
	fore(i,0,n-1){
		ll u,v,w; cin>>u>>v>>w; u--,v--;
		g[u].pb({v,w});
		g[v].pb({u,w});
		sum+=w;
	}
	centroid();
	lca_init();
	fore(x,0,n){	//upd
		//if(SZ(g[x])>1)continue;
		for(ll y=x; y!=-1;y=fat[y]){
			b[y].pb({disp(x,y),x});
		}
	}
	fore(i,0,n)sort(ALL(b[i])),reverse(ALL(b[i]));
	ll res=0;
	fore(x,0,n){
		if(!SZ(b[x]))continue;
		ll c=b[x][0].snd,d=-1;
		for(auto i:b[x]){
			if(dis(c,i.snd)==dis(c,x)+dis(x,i.snd)){
				d=i.snd;
				break;
			}
		}
		/*cout<<x<<": ";
		for(auto i:b[x])cout<<i.fst<<","<<i.snd<<" ";
		cout<<": "<<c<<" "<<d<<"\n";*/
		if(d!=-1)res=max(res,disp(c,x)+disp(x,d));
	}
	cout<<2*sum-res<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
