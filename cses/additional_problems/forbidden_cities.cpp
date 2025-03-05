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
const ll MAXN=1e5+5, MAXN2=2*MAXN;
vector<int> g[MAXN];int n;
struct edge {int u,v,comp;bool bridge;};
vector<edge> e;
void add_edge(int u, int v){
	g[u].pb(e.size());g[v].pb(e.size());
	e.pb((edge){u,v,-1,false});
}
int D[MAXN2],B[MAXN],T;
int nbc;  // number of biconnected components
int art[MAXN];  // articulation point iff !=0
stack<int> st;  // only for biconnected
void dfs(int u,int pe){
	B[u]=D[u]=T++;
	for(int ne:g[u])if(ne!=pe){
		int v=e[ne].u^e[ne].v^u;
		if(D[v]<0){
			st.push(ne);dfs(v,ne);
			if(B[v]>D[u])e[ne].bridge = true; // bridge
			if(B[v]>=D[u]){
				art[u]++; // articulation
				int last; // start biconnected
				do {
					last=st.top();st.pop();
					e[last].comp=nbc;
				} while(last!=ne);
				nbc++;    // end biconnected
			}
			B[u]=min(B[u],B[v]);
		}
		else if(D[v]<D[u])st.push(ne),B[u]=min(B[u],D[v]);
	}
}
void doit(){
	memset(D,-1,sizeof(D));memset(art,0,sizeof(art));
	nbc=T=0;
	fore(i,0,n)if(D[i]<0)dfs(i,-1),art[i]--;
}
vv t[MAXN2]; // tree node-bicomponent

const ll K=18; //K such that 2^K>=n
ll F[K][MAXN2];//,D[MAXN];
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
ll dis(ll x, ll y){return D[x]+D[y]-2*D[lca(x,y)];}

int main(){FIN;
	ll m,q; cin>>n>>m>>q;
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		add_edge(u,v);
	}
	doit();
	fore(x,0,n){
		set<ll>st;
		for(auto i:g[x]){
			ll y=n+e[i].comp;
			if(st.count(y))continue;
			st.insert(y);
			t[x].pb(y);
			t[y].pb(x);
		}
	}
	lca_init(n+nbc);
	while(q--){
		ll a,b,c; cin>>a>>b>>c; a--,b--,c--;
		if(dis(a,b)==dis(a,c)+dis(c,b))cout<<"NO\n";
		else cout<<"YES\n";
	}
	return 0;
}
