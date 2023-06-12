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
const ll MAXN=1e5+5;

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

ll c[MAXN],a[MAXN],s[MAXN],e[MAXN],q[MAXN],res=0;
pair<ll,ll>p[MAXN];
vector<ll>b;
void dfs(ll x){
	s[x]=SZ(b); b.pb(x);
	q[x]+=a[x]*a[x];
	for(auto y:g[x])q[y]=q[x],dfs(y);
	e[x]=SZ(b); b.pb(x);
}
int sq,nq; // array size, sqrt(array size), #queries
struct qu{int l,r,id,lca;};
qu qs[MAXN];
void init(){
	fore(i,0,n)p[i]={1,0};
}
void ADD(ll x){
	if(p[D[x]].snd++)res-=p[D[x]].fst;
	p[D[x]].fst*=a[x];
	res+=p[D[x]].fst;
}
void REM(ll x){
	res-=p[D[x]].fst;
	p[D[x]].fst/=a[x];
	if(--p[D[x]].snd)res+=p[D[x]].fst;
}
void add(ll i){
	ll x=b[i];
	if(++c[x]==2)REM(x);
	else ADD(x);
}
void remove(ll i){
	ll x=b[i];
	if(--c[x]==1)ADD(x);
	else REM(x);
}
ll get_ans(ll P){
	return res+q[P];
}
ll ans[MAXN]; // ans[i] = answer to ith query
bool qcomp(const qu &a, const qu &b){
    if(a.l/sq!=b.l/sq) return a.l<b.l;
    return (a.l/sq)&1?a.r<b.r:a.r>b.r;
}
void mos(){
	init();
    fore(i,0,nq)qs[i].id=i;
    sq=sqrt(2*n)+.5;
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
	cin>>n>>nq;
	fore(i,0,n)cin>>a[i];
	fore(i,0,n-1){
		ll x; cin>>x; x--;
		g[x].pb(i+1);
	}
	lca_init();
	dfs(0);
	fore(i,0,nq){
		ll x,y; cin>>x>>y; x--,y--;
		if(s[y]<s[x])swap(x,y);
		qs[i].l=e[x],qs[i].r=e[y];
		qs[i].lca=lca(x,y);
	}
	mos();
	fore(i,0,nq)cout<<ans[i]<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
