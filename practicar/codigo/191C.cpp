#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
const ll MAXN=1e5+5,K=18;

vector<pair<ll,ll>>g[MAXN]; ll n;
ll c[MAXN],q=0,res[MAXN];

ll F[K][MAXN],D[MAXN];
void lca_dfs(ll x){
	for(auto i:g[x]){
		ll y=i.fst;
		if(y==F[0][x])continue;
		D[y]=D[x]+1; F[0][y]=x; lca_dfs(y);
	}
}
void lca_init(){
	D[0]=0; F[0][0]=-1; lca_dfs(0);
	fore(k,1,K)fore(x,0,n){
		if(F[k-1][x]==-1)F[k][x]=-1;
		else F[k][x]=F[k-1][F[k-1][x]];
	}
}
ll lca(ll x, ll y){
	if(D[x]<D[y])swap(x,y);
	for(ll k=K-1;k>=0;k--)if(D[x]-(1ll<<k)>=D[y])x=F[k][x];
	if(x==y)return x;
	for(ll k=K-1;k>=0;k--)if(F[k][x]!=F[k][y]){x=F[k][x],y=F[k][y];}
	return F[0][x];
}

void dfs(ll x){
	q+=c[x];
	//cout<<x<<": "<<q<<"\n";
	for(auto i:g[x]){
		ll y=i.fst, idx=i.snd;
		if(y==F[0][x])continue;
		res[idx]+=q;
		dfs(y);
		res[idx]-=q;
	}
}
int main(){FIN;
	cin>>n;
	fore(i,0,n-1){
		ll a,b; cin>>a>>b; a--,b--;
		g[a].pb({b,i});
		g[b].pb({a,i});
	}
	lca_init();
	ll k; cin>>k;
	fore(i,0,k){
		ll a,b; cin>>a>>b; a--,b--;
		c[a]--,c[b]--, c[lca(a,b)]+=2;
	}
	dfs(0);
	fore(i,0,n-1)cout<<res[i]<<" ";
	cout<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
