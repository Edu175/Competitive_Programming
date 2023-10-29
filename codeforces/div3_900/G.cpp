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
const ll MAXN=2e5+5;


ll oper(ll a, ll b){return a|b;}
const ll K=18; //K such that 2^K>=n
ll n; ll a[MAXN]; // USE THIS N !!!!!!
vector<ll>g[MAXN]; 

ll F[K][MAXN],D[MAXN],V[K][MAXN];//késimo padre de x, distancia a root
void lca_dfs(ll x){//padres 0 y distancia
	for(auto y:g[x]){
		if(y==F[0][x])continue;
		F[0][y]=x;
		V[0][y]=a[y];
		D[y]=D[x]+1;
		lca_dfs(y);
	}
}
void lca_init(){//k padres
	D[0]=0;
	F[0][0]=-1;
	V[0][0]=a[0];
	lca_dfs(0);
	fore(k,1,K)fore(x,0,n){
		if(F[k-1][x]<0){
			F[k][x]=-1;
			V[k][x]=V[k-1][x];
		}
		else {
			F[k][x]=F[k-1][F[k-1][x]];
			V[k][x]=oper(V[k-1][x],V[k-1][F[k-1][x]]);
		}
	}
}
ii lca(ll x,ll y){
	if(D[x]<D[y])swap(x,y);//x abajo
	ll res=0;
	for(ll k=K-1;k>=0;k--)if(D[x]-(1ll<<k)>=D[y]){
		res=oper(res,V[k][x]);
		x=F[k][x];//level
	}
	if(x==y)return {x,oper(res,a[y])};
	for(ll k=K-1;k>=0;k--)if(F[k][x]!=F[k][y]){
		res=oper(res,V[k][x]);
		res=oper(res,V[k][y]);
		x=F[k][x],y=F[k][y];//find lca
	}
	res=oper(res,V[0][x]);
	res=oper(res,V[0][y]);
	res=oper(res,a[F[0][x]]);
	return {F[0][x],res};
}
//ll dis(ll x, ll y){return D[x]+D[y]-2*D[lca(x,y)];}
ll jump(ll x, ll v, ll p){
	for(ll k=K-1;k>=0;k--){
		//cout<<x<<" "<<k<<": "<<V[k][x]<<" "<<v<<"\n";
		if(x==-1)return -1;
		if(((v|V[k][x])^v)==0)x=F[k][x];
	}
	return x;
}
ll ppc(ll x){return __builtin_popcountll(x);}
ll f(ll x, ll y){return ppc(lca(x,y).snd);}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		fore(i,0,n){
			g[i].clear();
		}
		fore(i,0,n)cin>>a[i];
		fore(i,0,n-1){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		lca_init();
		/*fore(x,0,n){
			cout<<x<<": ";
			fore(k,0,K)cout<<F[k][x]<<","<<V[k][x]<<" ";
			cout<<"\n";
		}*/
		ll q; cin>>q;
		while(q--){
			ll x,y; cin>>x>>y; x--,y--;
			ll p=lca(x,y).fst,res=0;
			ll _x=x,_y=y;
			while(x!=-1&&D[x]>=D[p]){
				//cout<<x<<"x\n";
				res=max(res,f(_x,x)+f(x,_y));
				x=jump(x,lca(_x,x).snd,p);
			}
			
			while(y!=-1&&D[y]>=D[p]){
				//cout<<y<<"y\n";
				res=max(res,f(_x,y)+f(y,_y));
				y=jump(y,lca(_y,y).snd,p);
			}
			cout<<res<<" ";
			//cout<<"q\n";
		}
		cout<<"\n";
	}
	return 0;
}
