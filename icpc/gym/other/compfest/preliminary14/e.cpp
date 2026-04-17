#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(v,a) memset((v),(a),sizeof(v))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef int ll;
typedef long long LL;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MOD=998244353,MAXN=2e5+5,MAXV=2e5+5;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(LL a, LL b){return a*b%MOD;}

vector<ll>g[MAXN]; ll n;
const ll K=19;
ll D[MAXN],P[MAXN];
vv ord;
void lca_dfs(ll x, ll fa){
	for(auto y:g[x])if(y!=fa){
		D[y]=D[x]+1;
		ord.pb(x);
		lca_dfs(y,x);
	}
	P[x]=SZ(ord);
	ord.pb(x);
}
ll oper(ll i, ll j){return D[i]<D[j]?i:j;}
// #define oper min
ll st[K][1ll<<K];
void st_init(vector<ll> &a){
	ll n=SZ(a);
	fore(i,0,n)st[0][i]=a[i];
	fore(k,1,K)fore(i,0,n-(1ll<<k)+1)
		st[k][i]=oper(st[k-1][i],st[k-1][i+(1ll<<(k-1))]);
}
ll st_query(int s, int e){
	int k=31-__builtin_clz(e-s);
	return oper(st[k][s],st[k][e-(1<<k)]);
}
// sparse table (K is 1 more)
void lca_init(){
	D[0]=0;
	lca_dfs(0,-1);
	st_init(ord);
}
ll lca(ll x, ll y){
	ll l=P[x],r=P[y];
	if(l>r)swap(l,r);
	return st_query(l,r+1);
}
ll vis_[MAXN],S[MAXN],E[MAXN];
ll cnt_=0;
void dfs_(ll x){
	vis_[x]=1;
	S[x]=cnt_++;
	for(auto y:g[x])if(!vis_[y])dfs_(y);
	E[x]=cnt_;
}
bool cmp(ll x, ll y){
	return S[x]<S[y];
}
void virtual_init(){
	cnt_=0;
	dfs_(0);
	fore(i,0,n)vis_[i]=0;
	lca_init();
}
vector<ll> t[MAXN]; // rooted tree
ll is[MAXN]; // is it a real tree node?
void make_tree(vector<ll>&v){
	// makes virtual tree t and adds virtual nodes to v
	// root is first node
	// sorts v in dfs order
	sort(ALL(v),cmp);
	for(auto i:v)is[i]=vis_[i]=1;
	fore(j,0,SZ(v)-1){
		ll a=lca(v[j],v[j+1]);
		if(!vis_[a])v.pb(a),vis_[a]=1;
	}
	sort(ALL(v),cmp);
	stack<ll>s;
	s.push(v[0]);
	fore(i,1,SZ(v)){
		while(!(S[s.top()]<=S[v[i]]&&S[v[i]]<E[s.top()]))s.pop();
		t[s.top()].pb(v[i]);
		s.push(v[i]);
	}
}
ll resi;
ll dp[MAXN];
void reset(vector<ll>&v){
	for(auto i:v){
		is[i]=vis_[i]=0;
		t[i].clear();
		dp[i]=0;
	}
	resi=0;
}
ll c[MAXN];
LL to2(LL n){return n*(n-1)/2;}
ll tot;
void dfs(ll x){
	c[x]=is[x];
	for(auto y:t[x]){
		dfs(y);
		c[x]+=c[y];
		ll b=c[y],a=tot-c[y],w=D[y]-D[x];
		resi=add(resi,mul((a*to2(b)+to2(a)*b)%MOD,w));
	}
}


int cr[MAXV];
short mu[MAXN] = {0,1};
ll sz[MAXN];
void cribonha(){
	mset(cr,-1);
	fore(i,2,MAXV)if(cr[i]<0)for(LL j=1ll*i*i;j<MAXV;j+=i)cr[j]=i;
}
ll ccnt=0,nl[MAXN];
void cache(ll x, ll fa){
	nl[x]=ccnt++;
	for(auto y:g[x])if(y!=fa)cache(y,x);
}
int main(){
    JET
	cribonha();
	cin>>n;
	vv a(n);
	vv nod[MAXV];
	fore(i,0,n){
		cin>>a[i];
		nod[a[i]].pb(i);
	}
	vector<ii>ed;
	fore(i,0,n-1){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
		ed.pb({u,v});
	}
	// cache(0,-1);
	// fore(i,0,n)g[i].clear();
	// for(auto [u,v]:ed){
	// 	u=nl[u];
	// 	v=nl[v];
	// 	g[u].pb(v);
	// 	g[v].pb(u);
	// }
	// fore(i,0,MAXV){
	// 	auto &v=nod[i];
	// 	auto vi=v; v.clear();
	// 	for(auto i:vi)v.pb(nl[i]);
	// }
	
	virtual_init();
	vv num(MAXV);
	ll res=0;
	fore(p,2,MAXV)if(cr[p]==-1){ // only primes
		vv v;
		for(ll m=p;m<MAXV;m+=p)for(auto i:nod[m])v.pb(i);
		tot=SZ(v);
		if(!tot)continue;
		make_tree(v);
		dfs(v[0]);
		res=add(res,resi);
		reset(v);
	}
	cout<<res<<"\n";
    return 0;
}