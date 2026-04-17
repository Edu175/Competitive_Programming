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
ll F[K][MAXN],D[MAXN];
void lca_dfs(ll x){
	for(auto y:g[x]){
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

ll dis(ll x, ll y){return D[x]+D[y]-2*D[lca(x,y)];}
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
	reverse(ALL(a));
	vv who(n,-1);
	set<ll> h[n];
	ll i=0;
	for(auto [lkassld,x,y]:a){
		if(who[x]!=-1){
			if(!h[who[x]].count(y))fail();
			continue;
		}
		auto &p=h[i];
		ll anc=lca(x,y);
		p={anc};
		fore(_,0,2)for(ll u=(_?x:y);u!=anc;u=F[0][u])p.insert(u);
		for(auto u:p){
			if(who[u]!=-1)fail();
			who[u]=i;
		}
		i++;
	}
	cout<<"Yes\n";
    return 0;
}