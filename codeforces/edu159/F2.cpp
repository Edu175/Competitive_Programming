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
typedef int ll;
typedef pair<ll,ll> ii;

//bool operator[](ll x, ll j){return !!(x&(1ll<<j));}
bool on(ll x, ll j){return (x&(1ll<<j))>0;}
struct matrix{
	vector<ll>x;
	vector<ll>w;
	ll m;
	matrix(){}
	matrix(ll v): x(1,v),w(20,-1),m(20){
		if(v==0)x.clear();
		else w[__builtin_ctz(v)]=0;
	}
	void add(ll v){
		if(v==0)return;
		ll did=0;
		fore(j,0,m)if(on(v,j)){
			if(w[j]!=-1)v^=x[w[j]];
			else if(!did){
				w[j]=SZ(x);
				did=1;
			}
		}
		if(did)x.pb(v);
	}
};

typedef matrix node;
node oper(node a, node& b){
	for(auto i:b.x)a.add(i);
	return a;
}
const node NEUT=matrix(0);
const ll MAXN=2e5+5;

const ll K=18; //K such that 2^K>=n
ll n; ll a[MAXN]; // USE THIS N !!!!!!
vector<ll> g[MAXN]; 

ll F[K][MAXN],D[MAXN];
node V[K][MAXN];//késimo padre de x, distancia a root
void lca_dfs(ll x){//padres 0 y distancia
	for(auto y:g[x]){
		if(y==F[0][x])continue;
		F[0][y]=x;
		D[y]=D[x]+1;
		lca_dfs(y);
	}
}
void lca_init(){//k padres
	D[0]=0;
	F[0][0]=-1;
	fore(i,0,n)V[0][i]=node(a[i]);
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
pair<ll,node> lca(ll x, ll y){
	if(D[x]<D[y])swap(x,y);//x abajo
	node res=NEUT;
	for(ll k=K-1;k>=0;k--)if(D[x]-(1ll<<k)>=D[y]){
		res=oper(res,V[k][x]);
		x=F[k][x];//level
	}
	if(x==y)return {x,oper(res,V[0][y])};
	for(ll k=K-1;k>=0;k--)if(F[k][x]!=F[k][y]){
		res=oper(res,V[k][x]);
		res=oper(res,V[k][y]);
		x=F[k][x],y=F[k][y];//find lca
	}
	res=oper(res,V[0][x]);
	res=oper(res,V[0][y]);
	res=oper(res,V[0][F[0][x]]);
	return {F[0][x],res};
}

int main(){FIN;
	cin>>n;
	fore(i,0,n)cin>>a[i];
	fore(i,0,n-1){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	lca_init();
	ll q; cin>>q;
	while(q--){
		ll x,y,k; cin>>x>>y>>k; x--,y--;
		node mt=lca(x,y).snd;
		ll d=SZ(mt.x);
		mt.add(k);
		if(d==SZ(mt.x))cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
