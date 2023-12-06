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
const ll MAXN=2e5+5;

const ll K=18; //K such that 2^K>=n
ll n; ll a[MAXN]; // USE THIS N !!!!!!
vector<ll> g[MAXN]; 

ll F[K][MAXN],D[MAXN];
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
	lca_dfs(0);
	fore(k,1,K)fore(x,0,n){
		if(F[k-1][x]<0){
			F[k][x]=-1;
		}
		else {
			F[k][x]=F[k-1][F[k-1][x]];
		}
	}
}
ll lca(ll x, ll y){
	if(D[x]<D[y])swap(x,y);//x abajo
	for(ll k=K-1;k>=0;k--)if(D[x]-(1ll<<k)>=D[y]){
		x=F[k][x];//level
	}
	if(x==y)return x;
	for(ll k=K-1;k>=0;k--)if(F[k][x]!=F[k][y]){
		x=F[k][x],y=F[k][y];//find lca
	}
	return F[0][x];
}

//bool operator[](ll x, ll j){return !!(x&(1ll<<j));}
//inline bool on(ll x, ll j){return (x&(1ll<<j))>0;}
struct matrix{
	vector<ll>x;
	ll m;
	matrix(): x(20),m(20){}
	bool add(ll v){
		if(v==0)return 0;
		//fore(j,0,m)if(on(v,j))v^=x[j];
		for(ll j=m-1;j>=0;j--)v=min(v,v^x[j]);
		if(v){x[31-__builtin_clz(v)]=v;return 1;}
		return 0;
	}
};

vector<ll> lst[MAXN];

void dfs(ll x, ll f){
	lst[x].pb(x);
	matrix mt;
	mt.add(a[x]);
	if(f!=-1){
		for(auto i:lst[f])if(mt.add(a[i]))lst[x].pb(i);
	}
	for(auto y:g[x])if(y!=f)dfs(y,x);
}

int main(){FIN;
	cin>>n;
	fore(i,0,n)cin>>a[i];
	fore(i,0,n-1){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(0,-1);
	lca_init();
	ll q; cin>>q;
	while(q--){
		ll x,y,k; cin>>x>>y>>k; x--,y--;
		ll p=lca(x,y);
		matrix mt;
		for(auto i:lst[x])if(D[i]>=D[p])mt.add(a[i]);
		for(auto i:lst[y])if(D[i]>=D[p])mt.add(a[i]);
		if(!mt.add(k))cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
