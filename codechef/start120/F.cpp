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
const ll MAXN=5e5;
vector<ll>g[MAXN]; ll n;
const ll K=19; //K such that 2^K>=n
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
ll lca(ll x,ll y){
	if(D[x]<D[y])swap(x,y);
	for(ll k=K-1;k>=0;k--)if(D[x]-(1ll<<k)>=D[y])x=F[k][x];
	if(x==y)return x;
	for(ll k=K-1;k>=0;k--)if(F[k][x]!=F[k][y])x=F[k][x],y=F[k][y];
	return F[0][x];
}
ll father(ll v, ll x){ // v-ésimo padre de x
	//cout<<"padre "<<v<<" de "<<x<<" es ";
	for(ll k=K-1;k>=0;k--)if(v>=(1ll<<k)){
		//cout<<"avanzo "<<k<<": "<<x<<" --> "<<F[k][x]<<"\n";
		x=F[k][x];
		if(x<0)break;
		v-=1ll<<k;
	}
	//cout<<x<<"\n";
	return x;
}
vector<ll> t[MAXN];
ll a[MAXN];
ll sum=0;
void dfs(ll x, ll w){
	//cout<<"dfs "<<x<<" "<<w<<"\n";
	sum+=w*a[x];
	for(auto y:t[x])dfs(y,-w);
}
int main(){FIN;
	ll _; cin>>_;
	while(_--){
		ll k; cin>>n>>k;
		fore(i,0,n){
			g[i].clear();
			t[i].clear();
		}
		fore(i,0,n)cin>>a[i];
		fore(i,0,n-1){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		lca_init();
		vector<ll>roots;
		fore(i,0,n){
			ll p=father(k,i);
			if(p!=-1)t[p].pb(i);
			else roots.pb(i);
		}
		ll res=0;
		for(auto i:roots){
			//cout<<"root "<<i<<"\n";
			sum=0;
			dfs(i,1);
			res+=abs(sum);
			//cout<<"sum "<<sum<<"\n";
		}
		cout<<res<<"\n";
	}
	return 0;
}
