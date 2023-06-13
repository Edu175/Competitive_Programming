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
const ll MAXN=1e5+5,MAXQ=2e5+5,MAXM=2e5+5;

vector<ll>g[MAXN]; ll n;
const ll K=18;
//K such that 2^K>=n, log2 techo de n, ceil(log2(n))
ll F[K][MAXN],D[MAXN];//késimo padre de x, distancia a root
void lca_dfs(ll x){//padres 0 y distancia
	for(auto y:g[x]){
		if(y==F[0][x])continue;
		F[0][y]=x;D[y]=D[x]+1;lca_dfs(y);
	}
}
void lca_init(){//k padres
	D[0]=0;F[0][0]=-1;
	lca_dfs(0);
	fore(k,1,K)fore(x,0,n){
		if(F[k-1][x]<0)F[k][x]=-1;
		else F[k][x]=F[k-1][F[k-1][x]];
	}
}
ll lca(ll x,ll y){
	if(D[x]<D[y])swap(x,y);//x abajo
	for(ll k=K-1;k>=0;k--)if(D[x]-(1ll<<k)>=D[y])x=F[k][x];//level
	if(x==y)return x;
	for(ll k=K-1;k>=0;k--)if(F[k][x]!=F[k][y])x=F[k][x],y=F[k][y];//find lca
	return F[0][x];
}

int m,sq,nq; // sqrt(array size), #queries
struct qu{int l,r,id,lca;};
qu qs[MAXQ];
ll C[MAXN],S[MAXN],E[MAXN];
vector<ll>A; //tree in mod dfs order
void dfs_order(ll x, ll f){
	S[x]=SZ(A); A.pb(x);
	for(auto y:g[x])if(y!=f)dfs_order(y);
	E[x]=SZ(A); A.pb(x);
}
struct SRD{ // needs inverse
	ll n,sq; vector<ll>a,ran;
	SRD(ll n):n(n+5),sq(sqrt(n)+.5),a(n,0),ran(n/sq+5){}
	void upd(ll p, ll v){ // O(1)
		ran[p/sq]+=-a[p]+v; a[p]=v;
	}
	ll query(ll l, ll r){ // O(sqrt(n))
		assert(l<=r);
		ll res=0;
		if(l/sq==r/sq){
			fore(i,l,r)res+=a[i];
			return res;
		}
		fore(i,l,(l+sq-1)/sq*sq)res+=a[i];
		fore(i,r/sq*sq,r)res+=a[i];
		fore(i,(l+sq-1)/sq,r/sq)res+=ran[i];
		return res;
	}
};
ii ord[MAXM]; ll p[MAXM],v[MAXM],id[MAXM];
SRD sum,qan;
ll c[MAXN];
void ADD(ll x){ //CH add node x
	if(++c[p[x]]==1)sum.upd(id[p[x]],v[p[x]]),qan.upd(id[p[x]],1);
	
}
void REM(ll x){ //CH remove node x
	if(--c[p[x]]==0)sum.upd(id[p[x]],0),qan.upd(id[p[x]],0);
}
ll get_ans(ll lca, ll k){
	ADD(lca);
	ii tmp={k,-1};
	ll idx=lower_bound(ord,ord+m,tmp)-ord;
	ll res=sum.query(idx,m)
	REM(lca);
	return 
}
void init(){
	lca_init();
	A.clear();
	dfs_order(0,-1);
	fore(i,0,nq){
		ll u=qs[i].l,v=qs[i].r;
		if(S[u]>S[v])swap(u,v);
		qs[i].lca=lca(u,v); //CH add lca in struct qu
		qs[i].l=E[u],qs[i].r=E[v];
	}
	fore(i,0,m)ord[i]={v[i],i};
	sort(ord,ord+m);
	fore(i,0,m)id[ord[i].snd]=i;
	sum(m),qan(m);
}
void add(ll i){
	ll x=A[i];
	if(++C[x]==2)REM(x);
	else ADD(x);
}
void remove(ll i){
	ll x=A[i];
	if(--C[x]==1)ADD(x);
	else REM(x);
}
//CH get_ans(q.lca) in mos

ll ans[MAXQ]; // ans[i] = answer to ith query
bool qcomp(const qu &a, const qu &b){
    if(a.l/sq!=b.l/sq) return a.l<b.l;
    return (a.l/sq)&1?a.r<b.r:a.r>b.r;
}
void mos(){
	init();
    fore(i,0,nq)qs[i].id=i;
    sq=sqrt(SZ(a))+.5;
    sort(qs,qs+nq,qcomp);
    int l=0,r=0;
    fore(i,0,nq){
        qu q=qs[i];
        while(l>q.l)add(--l);
        while(r<q.r)add(r++);
        while(l<q.l)remove(l++);
        while(r>q.r)remove(--r);
        ans[q.id]=get_ans(q.lca);
    }
}

int main(){FIN;
	cin>>n>>m>>nq;
	fore(i,0,m)cin>>v[i];
	fore(i,0,n-1){
		ll u; cin>>u; u--;
		cin>>p[u]; p[u]--;
		g[u].pb(i+1);
		g[i+1].pb(u);
	}
	fore(i,0,nq)
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
