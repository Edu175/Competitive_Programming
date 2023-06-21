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
typedef pair<ll,ll> ii;
const ll MAXN=1e5+5,K=18,INF=1e10;

int uf[MAXN];
void uf_init(){mset(uf,-1);}
ll find(ll x){return uf[x]<0?x:uf[x]=find(uf[x]);}
bool join(ll x, ll y){
	x=find(x),y=find(y);
	if(x==y)return 0;
	if(uf[x]<uf[y])swap(x,y); //x chico
	uf[y]+=uf[x]; uf[x]=y;
	return 1;
}

ll n;
vector<ii> g[MAXN]; //MaxST
ll F[K][1ll<<K],D[MAXN],V[K][1ll<<K];
void lca_dfs(ll x){
	for(auto i:g[x])if(i.fst!=F[0][x]){
		ll y=i.fst;
		D[y]=D[x]+1; F[0][y]=x; V[0][y]=i.snd;
		lca_dfs(y);
	}
}
void lca_init(){
	mset(F,-1); D[0]=0;
	lca_dfs(0);
	fore(k,1,K)fore(i,0,n){
		if(F[k-1][i]<0)continue;
		F[k][i]=F[k-1][F[k-1][i]];
		V[k][i]=min(V[k-1][i],V[k-1][F[k-1][i]]);
	}
}
ii lca(ll x, ll y){ // {lca,ans}
	if(D[x]<D[y])swap(x,y);
	ll r=INF;
	//cout<<"lca\n";
	//cout<<x<<" "<<y<<": "<<r<<"\n";
	for(ll k=K-1;k>=0;k--)if(D[x]-(1ll<<k)>=D[y]){
		r=min(r,V[k][x]);
		x=F[k][x];
		//cout<<x<<" "<<y<<": "<<r<<"\n";
	}
	if(x==y)return {x,r};
	for(ll k=K-1;k>=0;k--)if(F[k][x]!=F[k][y]){
		r=min({r,V[k][x],V[k][y]});
		x=F[k][x];
		y=F[k][y];
		//cout<<x<<" "<<y<<": "<<r<<"\n";
	}
	r=min({r,V[0][x],V[0][y]});
	x=F[0][x]; y=F[0][y];
	//cout<<x<<" "<<y<<": "<<r<<"\n";
	return {x,r};
}
int main(){FIN;
	ll m; cin>>n>>m;
	vector<pair<ll,ii>>ed;
	fore(i,0,m){
		ll u,v,w; cin>>u>>v>>w; u--,v--;
		ed.pb({w,{u,v}});
	}
	sort(ALL(ed)); reverse(ALL(ed));
	uf_init();
	for(auto i:ed){
		ll w=i.fst,u=i.snd.fst,v=i.snd.snd;
		if(join(u,v))g[u].pb({v,w}),g[v].pb({u,w});
	}
	/*fore(x,0,n){
		cout<<x<<": ";
		for(auto i:g[x])cout<<i.fst<<","<<i.snd<<" ";
		cout<<"\n";
	}*/
	lca_init();
	/**fore(i,0,n){
		cout<<i<<": "<<D[i]<<"\n";
		fore(k,0,log2(n)+2)cout<<"  "<<k<<": "<<F[k][i]<<" "<<V[k][i]<<"\n";
	}*/
	ll q; cin>>q;
	while(q--){
		ll u,v; cin>>u>>v; u--,v--;
		cout<<lca(u,v).snd-1<<"\n";
	}
	return 0;
}
