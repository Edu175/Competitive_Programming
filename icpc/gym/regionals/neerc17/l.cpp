#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=1e5+5;
vector<ll>g[MAXN];
const ll K=17; //K such that 2^K>=n
ll F[K][MAXN],D[MAXN],S[MAXN],E[MAXN];
ll lcnt=0;
void lca_dfs(ll x){
	S[x]=lcnt++;
	for(auto y:g[x]){
		if(y==F[0][x])continue;
		F[0][y]=x;D[y]=D[x]+1;lca_dfs(y);
	}
	E[x]=lcnt;
}
void lca_init(ll n){
	lcnt=0;D[0]=0;F[0][0]=-1;
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

ll dis(ll x, ll y){return D[x]+D[y]-2*D[lca(x,y)];}
ll father(ll v, ll x){ // v-ésimo padre de x
	for(ll k=K-1;k>=0;k--)if(v>=(1ll<<k)){
		x=F[k][x];
		v-=1ll<<k;
		if(x<0)break;
	}
	return x;
}
ll go(ll x, ll y){
	assert(x!=y);
	if(S[x]<S[y]&&S[y]<E[x]){ // x anc of y
		return father(D[y]-D[x]-1,y);
	}
	return F[0][x];
}
void fail(){
	cout<<"No\n";
	exit(0);
}
int main(){
    JET
	ll n,m; cin>>n>>m;
	fore(i,0,n-1){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	lca_init(n);
	vector<array<ll,3>>a(m);
	fore(i,0,m){
		ll x,y; cin>>x>>y; x--,y--;
		a[i]={dis(x,y),x,y};
	}
	sort(ALL(a));
	vv w(n,-1);
	vv bad(n);
	ll i=0;
	for(auto [lkassld,x,y]:a){
		// cout<<x<<" "<<y<<": \n";
		ll _x=x;
		while(1){
			if(bad[x])fail();
			if(w[x]==-1)w[x]=i;
			else {
				ll idx=w[x];
				ll to=x^a[idx][1]^a[idx][2];
				if(dis(x,to)+dis(to,y)!=dis(x,y))fail();
				bad[x]=1;
				x=to;
			}
			bad[x]=1;
			if(x==y)break;
			x=go(x,y);
		}
		bad[_x]=bad[y]=0;
		w[_x]=w[y]=i;
		i++;
	}
	cout<<"Yes\n";
    return 0;
}