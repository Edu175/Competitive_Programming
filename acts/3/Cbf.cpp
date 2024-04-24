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

ll n;
ll a[MAXN];
vector<ii>g[MAXN];
const ll K=19; //K such that 2^K>=n
ll F[K][MAXN],D[MAXN],V[MAXN];
void lca_dfs(ll x){
	for(auto [y,w]:g[x]){
		if(y==F[0][x])continue;
		F[0][y]=x;D[y]=D[x]+1;V[y]=V[x]+w;lca_dfs(y);
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
ll dis(ll x, ll y){return V[x]+V[y]-2*V[lca(x,y)];}

vector<ll>dag[MAXN]; //O(n^2) edges
//vector<ll> g2[MAXN];set<ll> gst[MAXN];
ll n2,lw[MAXN],idx[MAXN],qidx,cmp[MAXN],qcmp;
stack<ll>st;

void tjn(ll u){
	lw[u]=idx[u]=++qidx;
	st.push(u); cmp[u]=-2;
	for(auto v:dag[u]){
		if(!idx[v]||cmp[v]==-2){ //tree edge, back edge
			if(!idx[v])tjn(v);
			lw[u]=min(lw[u],lw[v]);
		}
		// else cross edge
	}
	if(lw[u]==idx[u]){
		ll x=u;
		do{x=st.top(),st.pop(),cmp[x]=qcmp;}
		while(x!=u);
		qcmp++;
	}
}
void scc(){
	/*fore(i,0,n)idx[i]=0,cmp[i]=-1;//,g2[i].clear();gst[i].clear();
	qidx=0; qcmp=0;*/
	mset(idx,0); // NO TEST CASES
	mset(cmp,-1);
	fore(i,0,n)if(!idx[i])tjn(i);
	//fore(i,0,n)for(auto j:g[i])if(cmp[i]!=cmp[j])gst[cmp[i]].insert(cmp[j]);
	//fore(i,0,n)for(auto j:gst[i])g2[i].pb(j);
	n2=qcmp;
}

int main(){FIN;
	cin>>n;
	fore(i,0,n)cin>>a[i];
	fore(i,0,n-1){
		ll u,v,w; cin>>u>>v>>w; u--,v--;
		g[u].pb({v,w});
		g[v].pb({u,w});
	}
	lca_init();
	fore(i,0,n)fore(j,0,n)if(i!=j&&dis(i,j)<=a[i])dag[i].pb(j);
	scc();
	vector<ll>ind(n2);
	fore(x,0,n)for(auto y:dag[x])if(cmp[x]!=cmp[y])ind[cmp[y]]++;
	ll cnt=0;
	fore(x,0,n2)cnt+=!ind[x];
	cout<<cnt<<"\n";
	return 0;
}
