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
template<class x> ostream & operator<<(ostream & out, vector<x> v){
    out<<"{ ";
    for(auto y : v) out<<y<<" ";
    out<<"}";
    return out;
}

const ll MAXN=2e5+5;

vector<ll>g[MAXN]; ll n;
ll cnt=0;
vector<ll> dag[3*MAXN];
void add(ll x, ll y, ll t){
	if(!t)dag[x].pb(y); // down
	else dag[y].pb(x);  // up
}

const ll K=18; //K such that 2^K>=n
ll F[K][MAXN],D[MAXN];//késimo padre de x, distancia a root
ll nod[2][K][MAXN];
void lca_dfs(ll x){//padres 0 y distancia
	for(auto y:g[x]){
		if(y==F[0][x])continue;
		F[0][y]=x;D[y]=D[x]+1;lca_dfs(y);
	}
}
void lca_init(){//k padres
	D[0]=0;F[0][0]=-1;
	lca_dfs(0);
	fore
	fore(x,0,n)add(nod[0][0][x],x,1),add(nod[1][0][x],x,1);
	fore(k,1,K)fore(x,0,n){
		if(F[k-1][x]<0)F[k][x]=-1;
		else {
			F[k][x]=F[k-1][F[k-1][x]];
			nod[0]
		}
	}
}
ll lca(ll x,ll y){
	if(D[x]<D[y])swap(x,y);//x abajo
	for(ll k=K-1;k>=0;k--)if(D[x]-(1ll<<k)>=D[y])x=F[k][x];//level
	if(x==y)return x;
	for(ll k=K-1;k>=0;k--)if(F[k][x]!=F[k][y])x=F[k][x],y=F[k][y];//find lca
	return F[0][x];
}

ll father(ll v, ll x){ // v-ésimo padre de x
	for(ll k=K-1;k>=0;k--)if(v>=(1ll<<k)){
		x=F[k][x];
		v-=1ll<<k;
	}
	return x;
}
ll vis[MAXN*3];
ll flag=1;
vector<ll> ord;

void dfs(ll x){
	vis[x]=1;
	for(auto y:dag[x]){
		if(!vis[y])dfs(y);
		if(vis[y]==1)flag=0;
	}
	ord.pb(x);
	vis[x]=2;
}

int main(){FIN;
	ll q; cin>>n>>q;
	fore(i,0,n-1){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	cnt=n;
	lca_init();
	Rang st[2];
	while(q--){
		ll t,a,b,c; cin>>t>>a>>b>>c; t--,a--,b--,c--;
		query(a,b,c,st[t]);
	}
	fore(i,0,n)if(!vis[i])dfs(i);
	fore(i,0,3*n)
	if(!flag){
		cout<<"-1\n";
		return 0;
	}
	reverse(ALL(ord));
	vector<ll>res(n);
	ll asd=1;
	for(auto i:ord){
		if(i<n)res[i]=asd++;
	}
	imp(res);
	return 0;
}
