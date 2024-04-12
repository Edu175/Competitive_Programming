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

vector<ll>g[MAXN]; ll n;
const ll K=18;
ll F[K][MAXN],D[MAXN];

void lca_dfs(ll x){
	for(auto y:g[x])if(F[0][x]!=y){
		F[0][y]=x;
		D[y]=D[x]+1;
		lca_dfs(y);
	}
}

void lca_init(){
	D[0]=0; F[0][0]=n; F[0][n]=n; D[n]=-1;
	lca_dfs(0);
	fore(k,1,K)fore(x,0,n+1)F[k][x]=F[k-1][F[k-1][x]];
}
ll lca(ll x, ll y){
	if(D[x]<D[y])swap(x,y);
	for(ll k=K-1;k>=0;k--)if(D[x]-(1ll<<k)>=D[y])x=F[k][x];
	if(x==y)return x;
	for(ll k=K-1;k>=0;k--)if(F[k][x]!=F[k][y]){
		x=F[k][x];
		y=F[k][y];
	}
	return F[0][x];
}
ll bef[MAXN],aft[MAXN],q=0,p[MAXN];
void dfs(ll x){
	q+=bef[x];
	p[x]+=q;
	q+=aft[x];
	//cout<<"dfs "<<x<<" ("<<F[0][x]<<")"<<endl;
	for(auto y:g[x])if(F[0][x]!=y){
		dfs(y);
	}
	p[x]-=q;
}

int main(){FIN;
	ll q; cin>>n>>q;
	fore(i,0,n-1){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	lca_init();
	while(q--){
		ll x,y; cin>>x>>y; x--,y--;
		auto v=lca(x,y);
		bef[v]+=2;
		aft[x]--;
		aft[y]--;
		p[v]--;
	}
	dfs(0);
	fore(i,0,n)cout<<p[i]<<" ";;cout<<"\n";
	return 0;
}
