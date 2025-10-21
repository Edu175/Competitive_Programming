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
const ll MAXN=2e5+5,MAXM=MAXN;
vector<ii> g[MAXN]; // {node,edge}
int lw[MAXN],D[MAXN];
bool vised[MAXM]; 

vv t[MAXN];
ll S[MAXN],E[MAXN],cnt=0;
vector<ll> down[MAXN],up[MAXN];

void dfs_(ll x){
	S[x]=cnt++;
	lw[x]=D[x];
	for(auto [y,i]:g[x])if(!vised[i]){
		vised[i]=1;
		if(lw[y]==-1){ // tree edge
			D[y]=D[x]+1;
			dfs_(y);
			lw[x]=min(lw[x],lw[y]);
			t[x].pb(y);
		}
		else {
			lw[x]=min(lw[x],D[y]);
			ll val=D[x]-D[y]+1;
			down[y].pb(val);
			up[x].pb(val);
		}
	}
	E[x]=cnt;
}
void dfs_tree(int n){
	mset(lw,-1), mset(vised,0);
	fore(i,0,n)if(lw[i]==-1)D[i]=0,dfs_(i);
}

const ll K=18; //K such that 2^K>=n
ll F[K][MAXN];
void lca_dfs(ll x){
	for(auto y:t[x]){
		if(y==F[0][x])continue;
		F[0][y]=x;D[y]=D[x]+1;lca_dfs(y);
	}
}
void lca_init(ll n){
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

ll ans[MAXN];
vector<ll> qsD[MAXN],qsU[MAXN];
ll sum0=0,sum1=0;
void dfs(ll x){
	for(auto y:t[x])dfs(y);
	// cout<<"dfs "<<x<<"\n";
	for(auto i:qsU[x])ans[i]+=sum0;
	for(auto v:up[x])sum0+=v;

	for(auto v:down[x])sum1+=v;
	for(auto i:qsD[x])ans[i]-=sum1;
}

int main(){FIN;
	ll n,m; cin>>n>>m;
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb({v,i});
		g[v].pb({u,i});
	}
	dfs_tree(n);
	lca_init(n);
	ll q; cin>>q;
	fore(i,0,q){
		ll x,y; cin>>x>>y; x--,y--;
		ll p=lca(x,y);
		qsD[x].pb(i);
		qsD[y].pb(i);
		qsU[p].pb(i);
	}
	// fore(x,0,n){
	// 	cout<<x<<": ";
	// 	for(auto y:t[x])cout<<y<<" ";
	// 	cout<<"| ";
	// 	for(auto [y,v]:ba[x])cout<<y<<","<<v<<" ";
	// 	cout<<"\n";
	// 	for(auto [y,i]:qs[x])cout<<y<<","<<i<<" ";
	// 	cout<<"qs\n";
	// }
	dfs(0);
	fore(i,0,q)cout<<ans[i]<<"\n";
	return 0;
}
