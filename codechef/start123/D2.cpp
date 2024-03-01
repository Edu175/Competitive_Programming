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
const ll MAXN=3e5+5;
vector<ll>g[MAXN]; ll n;
const ll K=20; //K such that 2^K>=n
ll F[K][MAXN],D[MAXN];
void lca_dfs(ll x){
	for(auto y:g[x]){
		if(y==F[0][x])continue;
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
ll father(ll v, ll x){ // v-ésimo padre de x
	for(ll k=K-1;k>=0;k--)if(v>=(1ll<<k)){
		x=F[k][x];
		v-=1ll<<k;
		if(x<0)break;
	}
	return x;
}
ll val[MAXN],dp[MAXN],lw[MAXN];
ll k;
void dfs1(ll x){
	lw[x]=x;
	if(x&&SZ(g[x])==1)lw[x]=max(father(k,x),(ll)0);
	for(auto y:g[x])if(y!=F[0][x]){
		dfs1(y);
		if(D[lw[y]]<D[lw[x]])lw[x]=lw[y];
	}
	ll v=val[x];
	val[lw[x]]+=v;
	val[x]-=v;
}
void dfs2(ll x){
	dp[x]=0;
	for(auto y:g[x])if(y!=F[0][x]){
		dfs2(y);
		dp[x]=max(dp[x],dp[y]);
	}
	dp[x]+=val[x];
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n>>k;
		fore(i,0,n+3){
			g[i].clear();
			val[i]=0;
		}
		fore(i,0,n-1){
			ll u,v; cin>>u>>v;
			u--,v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		lca_init();
		fore(i,1,n){
			if(SZ(g[i])==1){
				ll pa=max(father(k,i),(ll)0);
				val[pa]++;
			}
		}
		dfs1(0);
		//fore(i,0,n)cout<<val[i]<<" ";;cout<<"\n";
		dfs2(0);
		cout<<dp[0]<<"\n";
	}
	return 0;
}
