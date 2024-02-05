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
const ll K=18; //K such that 2^K>=n
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

ll dis(ll x, ll y){return D[x]+D[y]-2*D[lca(x,y)];}

ll h[MAXN];
vector<ll>v;
void dfs1(ll x){
	/*if(SZ(g[x])==0)*/h[x]=0;
	for(auto y:g[x]){
		dfs1(y);
		h[x]=max(h[x],h[y]+1);
	}
}
bool cmp(ll a, ll b){return h[a]<h[b];};
void dfs2(ll x){
	if(SZ(g[x])==0)v.pb(x);
	for(auto y:g[x]){
		dfs2(y);
	}
}
int main(){FIN;
	ll k; cin>>n>>k;
	fore(i,1,n){
		ll p; cin>>p; p--;
		g[p].pb(i);
	}
	lca_init();
	dfs1(0);
	fore(i,0,n)sort(ALL(g[i]),cmp);
	dfs2(0);
	ll res=D[v[0]];
	vector<ll>add;
	fore(i,0,SZ(v)-1){
		ll dst=dis(v[i],v[i+1]);
		res+=dst;
		add.pb(-dst+D[v[i+1]]);
	}
	sort(ALL(add));
	fore(i,0,min(k,(ll)SZ(add))){
		if(add[i]<0)res+=add[i];
	}
	cout<<res<<"\n";
	return 0;
}
