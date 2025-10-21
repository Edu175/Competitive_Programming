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

ll cnt=0;

ll wh[MAXN],fa[MAXN],val[MAXN];

vector<ii> tr;

void dfs_(ll x){
	lw[x]=D[x];
	for(auto [y,i]:g[x])if(!vised[i]){
		vised[i]=1;
		if(lw[y]==-1){ // tree edge
			D[y]=D[x]+1;
			fa[y]=x;
			dfs_(y);
			lw[x]=min(lw[x],lw[y]);
			tr.pb({x,y});
		}
		else {
			lw[x]=min(lw[x],D[y]);
			ll v=D[x]-D[y]+1;
			for(ll i=fa[x];i!=y;i=fa[i])wh[i]=cnt;
			val[cnt]=v;
			cnt++;
		}
	}
}
void dfs_tree(int n){
	mset(lw,-1), mset(vised,0);
	mset(wh,-1);
	fa[0]=-1;
	D[0]=0,dfs_(0);
	fore(i,0,n)if(wh[i]==-1){
		wh[i]=cnt;
		val[cnt]=0;
		cnt++;
	}
}

const ll K=18; //K such that 2^K>=n
ll F[K][MAXN];
ll V[MAXN];
vv t[MAXN];

void lca_dfs(ll x){
	V[x]+=val[x];
	for(auto y:t[x]){
		F[0][y]=x;
		V[y]=V[x];
		D[y]=D[x]+1;
		lca_dfs(y);
	}
}
void lca_init(ll n){
	ll rt=wh[0];
	V[rt]=0;F[0][rt]=-1,D[rt]=0;
	lca_dfs(rt);
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

int main(){FIN;
	ll n,m; cin>>n>>m;
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb({v,i});
		g[v].pb({u,i});
	}
	dfs_tree(n);
	for(auto [x,y]:tr){
		x=wh[x]; y=wh[y];
		if(x==y)continue;
		t[x].pb(y);
	}
	lca_init(cnt);
	// fore(x,0,n){
	// 	cout<<x<<": "<<wh[x]<<"\n";
	// }
	// fore(x,0,cnt)cout<<val[x]<<" ";;cout<<"\n";
	// fore(x,0,cnt)cout<<V[x]<<" ";;cout<<"\n";
	// fore(x,0,cnt){
	// 	cout<<x<<": ";
	// 	imp(t[x])
	// }
	// cerr<<"queries\n";
	ll q; cin>>q;
	fore(i,0,q){
		ll x,y; cin>>x>>y; x--,y--;
		x=wh[x]; y=wh[y];
		ll p=lca(x,y);
		// cout<<x<<","<<y<<" "<<p<<": ";
		ll res=V[x]+V[y]-2*V[p]+val[p];
		cout<<res<<"\n";
	}
	return 0;
}
