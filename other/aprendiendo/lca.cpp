#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
const ll MAXN=2e5+5,K=18;
//K such that 2^K>=n, log2 techo de n, ceil(log2(n))
vector<ll> g[MAXN];
ll n;
ll F[K][MAXN],D[MAXN];
void lca_dfs(ll x){
	for(auto y:g[x]){
		if(F[0][x]==y)continue;
		F[0][y]=x;D[y]=D[x]+1;lca_dfs(y);
	}
}
void lca_init(){
	D[0]=0;F[0][0]=-1;
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

int main(){//FIN;
	cin>>n;
	fore(i,0,n-1){
		ll a,b; cin>>a>>b; a--,b--;
		g[a].pb(b); g[b].pb(a);
	}
	lca_init(); cout<<"init\n";
	while(1){ll a,b; cin>>a>>b; a--,b--; cout<<lca(a,b)+1<<endl;}
	return 0;
}
