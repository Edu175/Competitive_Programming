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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		
	}
	return 0;
}

// -------------------- CPP STUFF ----------------------------
// PRAGMAS
//#pragma GCC optimize("Ofast") // may lead to precision errors
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

// COMPILAR
g++ -O2 -std=c++17 -Wall -Wextra -g -D_GLIBCXX_DEBUG

// memoria (y tiempo) usada por un programa:
command time -v ./a // maxresident
// o
/usr/bin/time ./a

//INPUT OUTPUT POR ARCHIVO
#ifdef ONLINE_JUDGE
freopen("billboard.in","r",stdin);
freopen("billboard.out","w",stdout);
#endif
// or
ifstream cin;   cin.open("input.in", ios::in);
ofstream cout; cout.open("output.out", ios::out);

// LEER LINEA DE STRING
getline(cin,s);
cin.ignore();


// builtins
__builtin_popcountll(x); // contar bits prendidos de x
__builtin_clzll(x); // count leading zeros // 64-funcion: contar bits
__builtin_ctzll(x); // count trailing zeros // cantidad de factores 2

// CUSTOM COMPARATOR FOR SET/MAP/PQ
// with struct:
struct Cmp{
	bool operator()(const ii &a, const ii &b)const{
		return a.fst*b.snd<b.fst*a.snd;
	}
};
Cmp cmp; // for direct usage call cmp(a,b)

set<ii,Cmp> st;
map<ii,ll,Cmp> mp;
priority_queue<ii,vector<ii>,Cmp> pq; // dont forget to flip < if you want min-heap

// with lambda: (weird if you want to return it in a recursive function, just use the struct one)
auto cmp=[](const ii &a, const ii &b){
	return a.fst*b.snd<b.fst*a.snd;
};
set<ii,decltype(cmp)> st(cmp);
map<ii,ll,decltype(cmp)> mp(cmp);
priority_queue<ii,vector<ii>,decltype(cmp)> pq(cmp);

// RANDOM NUMBERS
random_device rd;
mt19937 rng(rd()); // mt19937_64 for long long
// use: rng() gives a random number
shuffle(ALL(a),rng); // instead of random_shuffle
// instead of rd() you can use any seed, or
// chrono::steady_clock::now().time_since_epoch().count()
// for time in miliseconds

//get k random DISTINCT integers from 1 to n (in O(k*log))
vv getDistinct(ll k, ll n){
	vv res;
	if(2*k<n){
		set<ll>st;
		while(SZ(st)<k)st.insert(rng()%n+1);
		for(auto i:st)res.pb(i);
		shuffle(ALL(res),rng);
	}
	else {
		vv v(n); iota(ALL(v),1); shuffle(ALL(v),rng);
		fore(i,0,k)res.pb(v[i]);
	}
	return res;
}

// LAMBDA RECURSIVA
function<void(ll)> dfs=... // un poco mas lento
auto dfs=[&](ll x, auto &&dfs){
	for(auto y:g[x])dfs(y,dfs);
};

// Generate all size-k bitmasks
ll mk=(1ll<<k)-1,r,c;
while(mk<=(1ll<<n)-(1ll<<(n-k))){
	// Code here
	if(!k)break;
	c=mk&-mk,r=mk+c,mk=r|(((r^mk)>>2)/c);
}

// NUMERIC LIMITS
// see more in std::numeric_limits
float		// 7 digits
double		// 15 digits // 53 bits de precision, 10 bits de exponente
long double	// 18 digits // 64 bits de precision, 14 bits de exponente
__float128	// 34 digits // 114 bits de precision, 14 bits de exponente


// DYNAMIC BITSET
// EN CODEFORCES SIGUE BUGEADO https://codeforces.com/blog/entry/129454
#include <tr2/dynamic_bitset>
using namespace tr2;
dynamic_bitset<> b; //template arguments: word type, allocator type
// uses find_first and find_next instead of _Find_first and _Find_next

//MY BITSET
typedef unsigned long long ull;
const ll W=64;
struct my_bitset{
	vector<ull>bs; int n;
	my_bitset(int n):bs((n+W)/W),n(n){}
	void flip(int p){bs[p/W]^=1ull<<(p%W);}
	int _Find_next(int p){ //exactly the same as original bitset
		++p;
		ll i=p/W;
		ull bl=bs[i];
		bl&=(~0ull)<<(p%W);
		if(bl)return i*W+__builtin_ctzl(bl);
		i++;
		for(;i<SZ(bs);i++){
			bl=bs[i];
			if(bl)return i*W+__builtin_ctzl(bl);
		}
		return n;
	}
};

//UNORDERED MAP, CUSTOM HASH (only useful because of hacks)
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
/*use
unordered_map<ll,int,custom_hash> um;
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
gp_hash_table<ll,int,custom_hash> ht;
gp_hash_table<ll,null_type,custom_hash> st; // for unordered set
*/

// IMPRIMIR CUALQUIER CONTAINER
// en c++20 es bastante mas corto pero no lo tengo :(
template <typename T, typename = void>
struct is_container : std::false_type {};
template <typename T>
struct is_container<T, std::void_t<decltype(std::declval<T>().begin())>> : std::true_type {};
template <typename T>
string cv(const T& x) {
    if constexpr (is_container<T>::value) {
        // std::cout << "This is a container.\n";
		string ret="{ ";
		for(auto i:x)ret+=cv(i)+" ";
		ret+="}";
		return ret;
    }
	else {
		// std::cout << "This is NOT a container.\n";
		return to_string(x);
	}
}
// uso: cout<<cv(vec)<<"\n";
// sirve tambien para containers de containers
// siempre y cuando exista to_string para el ultimo tipo

// -------------------- MATH ----------------------------
// COMBINATORIA
// MODULAR OPERATIONS
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	if(b<0)return 0;
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
ll fc[MAXF],fci[MAXF];
void factos(){
	fc[0]=1;
	fore(i,1,MAXF)fc[i]=mul(fc[i-1],i);
	fci[MAXF-1]=fpow(fc[MAXF-1],MOD-2);
	for(ll i=MAXF-2;i>=0;i--)fci[i]=mul(fci[i+1],(i+1));
}
ll nCr(ll n, ll k){ // must call factos before
	if(n<0||k<0||k>n)return 0;
	return mul(mul(fc[n],fci[k]),fci[n-k]);
}

// number of Regular Bracket Sequences of size n
ll rbs(ll n){
	return sub(nCr(n,n/2),nCr(n,n/2-1));
}

// STIRLING NUMBERS

// First kind (unsigned):
// s(n,k) = number of permutations with k cycles
// s(n,k) = s(n-1,k-1) + (n-1) * s(n-1,k)
ll usn(ll n, ll k){
	auto &res=mem[n][k];
	if(res!=-1)return res;
	if(k>n)return res=0;
	if(k==0)return res=n==0;
	return res=add(usn(n-1,k-1),mul(n-1,usn(n-1,k)));
}

// Second kind:
// S(n,k) = number of partitions of {1..n} into exactly k parts
// S(n,k) = S(n-1,k-1) + k * S(n-1,k)

// both can also be calculated in O(nlogn) for fixed k (with GF)

// BELL NUMBERS
// b_n = number of partitions of {1..n}
// b_n+1 = sum_{k=0}^{n} nCr(n,k) * b_k
// let B(x) be the EGF of b_n, B(x) = e^(e^x-1)


// offline queries of B(n,k)= sum_{i=1}^{k-1} nCr(n,i)
// no special cases, works for negatives (put k==0? return 1 in nCr, before everything, just in case)
// uses the fact that 2*B(n,k)=nCr(n,k-1)+B(n+1,k)
// for B(l,r,n) [l,r] :
// 2*B(l,r,n)=nCr(n,l)+nCr(n,r)-nCr(n+1,l)+B(l,r,n+1)
auto actu=[&](ll w, ll n, ll k){
	ll dl=k,dr=n;
	auto &l=par[w].fst;	// previous k
	auto &r=par[w].snd;	// previous n
	auto &cur=curs[w];	// previous ans
	while(l>dl){
		cur=sub(cur,nCr(r,--l));
	}
	while(r<dr){
		cur=add(cur,cur);
		cur=sub(cur,nCr(r,l-1));
		(r++);
	}
	while(l<dl){
		cur=add(cur,nCr(r,l++));
	}
	while(r>dr){
		(--r);
		cur=add(cur,nCr(r,l-1));
		cur=mul(cur,(MOD+1)/2);
	}
};


// NUMBER THEORY

// CRT in PYTHON
from sympy.ntheory.modular import crt
crt([99, 97, 95], [49, 76, 65])
# parameters: moduli, remainders
# returns: solution, modulus

// divisores and phi in VlogV time and memory
vector<ll> divs[MAXV];
void divisores(){
	fore(i,1,MAXV)for(int j=i;j<MAXV;j+=i)divs[j].pb(i);
}

ll phi[MAXV];
void phinit(){
	fore(i,1,MAXV){
		phi[i]+=i;
		for(int j=2*i;j<MAXV;j+=i)phi[j]-=phi[i];
	}
}
//O(√n) cada query
vector<ll> divs(ll x){
	vector<ll>res;
	for(int i=1; i*i<=x;i++){
		if(x%i==0)res.pb(i),res.pb(x/i);
		if(i*i==x)res.pop_back();
	}
	return res;
}

// MATRICES
// reduce in z_2
// dynamically add rows
const ll B=30;
struct matrix{
	vector<ll>x;
	matrix(): x(B){}
	bool add(ll v){
		if(v==0)return 0;
		for(ll j=B-1;j>=0;j--)v=min(v,v^x[j]);
		if(v){x[__lg(v)]=v;return 1;}
		return 0;
	}
};

// -------------------- GRAFOS ----------------------------
// version SMALL TO LARGE de union find O(nlogn)
vector<ll> comp[MAXN]; ll id[MAXN];
void uf_init(ll n){
	fore(i,0,n){
		comp[i]={i};
		id[i]=i;
	}
}
bool uf_join(ll a, ll b){
	a=id[a], b=id[b];
	if(a==b)return 0;
	if(SZ(comp[a])>SZ(comp[b]))swap(a,b);
	for(auto i:comp[a])comp[b].pb(i), id[i]=b;
	comp[a].clear();
	return 1;
}

// PRIM
ll is[MAXN];
ll prim(){
	ll res=0,q=n;
	priority_queue<pair<ll,pair<ll,ll>>>pq; // edge {1,0}
	for(auto i:g[0])pq.push({-i.snd,{0,i.fst}});
	is[0]=1; q--;
	while(SZ(pq)&&q){
		ll w=-pq.top().fst,u=pq.top().snd.fst,v=pq.top().snd.snd;
		pq.pop();
		if(is[u]&&is[v])continue;
		is[v]=1; q--;
		for(auto i:g[0])pq.push({-i.snd,{v,i.fst}});
		res+=w; //add edge
	}
	return res;
}

//DFS TREE (articulation points and bridges)
vector<ii> g[MAXN]; // {node,edge}
int lw[MAXN],D[MAXN],art[MAXN]; // articulation point iff !=0
bool br[MAXM],vised[MAXM]; 
void dfs_(ll x){
	lw[x]=D[x];
	for(auto [y,i]:g[x])if(!vised[i]){
		vised[i]=1;
		if(lw[y]==-1){ // tree edge
			D[y]=D[x]+1;
			dfs_(y);
			lw[x]=min(lw[x],lw[y]);
			art[x]+=(lw[y]>=D[x]);
			br[i]=(lw[y]>=D[y]);
		}
		else lw[x]=min(lw[x],D[y]),br[i]=0; // back edge
	}
}
void dfs_tree(int n, int m=0){
	if(!m)mset(lw,-1), mset(art,0), mset(vised,0);
	else { // multiple testcases
		fore(i,0,n)lw[i]=-1,art[i]=0;
		fore(i,0,m)vised[i]=0;
	}
	fore(i,0,n)if(lw[i]==-1)D[i]=0,dfs_(i),art[i]--;
}

// EULER WALK
// returns edge indices
vector<ll> eulerWalk(vector<vector<ii>>& gr, ll nedges, ll src=0) {
	ll n = SZ(gr);
	vector<ll> D(n), its(n), eu(nedges), ret;
	vector<ii> s = {{src,-1}};
	D[src]++; // to allow Euler paths, not just cycles
	while (!s.empty()) {
		auto [x,e] = s.back(); 
		ll y, &it = its[x], end = SZ(gr[x]);
		if (it == end){ ret.pb(e); s.pop_back(); continue; }
		tie(y, e) = gr[x][it++];
		if (!eu[e]) {
			D[x]--, D[y]++;
			eu[e] = 1; s.pb({y,e});
		}}
	ret.pop_back();
	reverse(ALL(ret));
	for (ll x : D) if (x < 0 || SZ(ret) != nedges) return {};
	return ret;
}

// DINIC
// this is my dinitz implementation based on
// https://codeforces.com/blog/entry/104960
// this should be O(n^2 m)

// almost the same as el vasito's, only dfs is different
// time is also similar

ll INF=1e18; // a constant > to any flow
struct Dinic{
	int n;
	struct edge{int to,rev; ll f,cap;};
	vector<vector<edge>> g;
	vector<int> d,q,work;
	Dinic(int n):n(n),g(n),d(n),q(n),work(n){}
	void add_edge(int u, int v, ll cap){
		g[u].pb({v,SZ(g[v]),0,cap});
		g[v].pb({u,SZ(g[u])-1,0,0});
	}
	int s,t;
	bool bfs(){
		fill(ALL(d),-1);
		int qt=0;
		d[s]=0; q[qt++]=s;
		for(int qh=0;qh<qt;qh++){
			auto x=q[qh];
			for(auto &e:g[x])if(e.f<e.cap&&d[e.to]==-1){
				d[e.to]=d[x]+1;
				q[qt++]=e.to;
			}
		}
		return d[t]!=-1;
	}
	ll dfs(int x, ll F){
		if(x==t)return F;
		ll _F=F;
		for(auto &i=work[x];i<SZ(g[x]);i++){
			auto &e=g[x][i];
			if(d[e.to]==d[x]+1&&e.f<e.cap){
				ll dF=dfs(e.to,min(F,e.cap-e.f));
				F-=dF;
				e.f+=dF; g[e.to][e.rev].f-=dF;
				if(!F)break;
			}
		}
		return _F-F;
	}
	ll max_flow(int _s, int _t){
		s=_s,t=_t;
		ll ret=0;
		while(bfs()){
			fill(ALL(work),0);
			ret+=dfs(s,INF);
		}
		return ret;
	}
};

// -------------------- TREES ----------------------------
// LCA
// normal en el vasito
ll dis(ll x, ll y){return D[x]+D[y]-2*D[lca(x,y)];} // distancia
ll father(ll v, ll x){ // v-esimo padre de x
	for(ll k=K-1;k>=0;k--)if(v>=(1ll<<k)){
		x=F[k][x];
		v-=1ll<<k;
		if(x<0)break;
	}
	return x;
}

// O(1) query with O(n sqrt(n)) preprocessing
const ll B=316; // sqrt(MAXN)
ll F[B+5][MAXN];
ll Fb[MAXN/B+5][MAXN];

void sqrt_init(){
	fore(x,0,n)F[0][x]=x,Fb[0][x]=x;
	fore(k,1,B+1)fore(x,0,n){
		F[k][x]=F[k-1][F[1][x]];
	}
	fore(i,1,n/B+1)fore(x,0,n){
		Fb[i][x]=Fb[i-1][F[B][x]];
	}
}
ll father(ll k, ll x){ // k-esimo padre de x
	x=Fb[k/B][x];
	k%=B;
	x=F[k][x];
	return x;
}

//TRIE
ll tr[MAXN][30], qidx=0; //MAXN = MAX NODES
ll add(ll x, char h){
	ll &res=tr[x][h-'a'];
	if(res)return res;
	else return res=++qidx;
}

//REROOTING
// (without inverse)
// didn't test final, but it's often unnecesary
vector<ii> g[MAXN]; // node, weight (1 if none)
struct node {
	ll res,mx;
	node():res(0),mx(0){}
};
node NEUT;
node leaf(ll x){
	return NEUT;
}
node merge(node a, node b){
	a.res=max({a.res,b.res,a.mx+b.mx});
	a.mx=max(a.mx,b.mx);
	return a;
}
void final(node &v, ll x){}
node up(node x, ll w=1){
	x.mx+=w;
	x.res=max(x.res,x.mx);
	return x;
}


node h[MAXN],ch[MAXN]; // hijo, complement hijo (SIN ARISTA PADRE)
node tot[MAXN]; // total
vector<node> pre[MAXN],suf[MAXN];
ll wf[MAXN],fa[MAXN]; // weight father, father
void dfs1(ll x){
	h[x]=leaf(x);
	for(auto [y,w]:g[x])if(y!=fa[x]){
		wf[y]=w;
		fa[y]=x;
		dfs1(y);
		h[x]=merge(h[x],up(h[y],w));
	}
	final(h[x],x);
}
void dfs2(ll x){
	fore(j,0,SZ(g[x])){
		auto [y,w]=g[x][j];
		if(y==fa[x])continue;
		ch[y]=merge(leaf(x),merge(pre[x][j],suf[x][j+1]));
		if(fa[x]!=-1)ch[y]=merge(ch[y],up(ch[x],wf[x]));
		final(ch[y],x);
		dfs2(y);
	}
}
void reroot(ll n){
	ll rt=0;
	fa[rt]=-1,wf[rt]=0;
	dfs1(rt);
	fore(x,0,n){
		ll m=SZ(g[x]);
		auto doit=[&](vector<node> &p){
			p=vector<node>(m+1,NEUT);
			fore(j,1,m+1){
				auto [y,w]=g[x][j-1];
				p[j]=p[j-1];
				if(y!=fa[x])p[j]=merge(p[j],up(h[y],w));
			}
		};
		doit(pre[x]); reverse(ALL(g[x]));
		doit(suf[x]); reverse(ALL(g[x]));
		reverse(ALL(suf[x]));
	}
	dfs2(rt);
	fore(x,0,n){
		tot[x]=h[x];
		if(fa[x]!=-1)tot[x]=merge(tot[x],up(ch[x],wf[x])),final(tot[x],x);
		else assert(x==rt),tot[x]=h[x];
		// you may want to treat the root specially
		// if that is the case, remember to recalculate tot[rt]
	}
}

// (with inverse)
//example: tree hashing
vector<ll> g[MAXN];
typedef ull node;
node h[MAXN],ch[MAXN],tot[MAXN];
node NEUT=0;
node merge(node a, node b){
	return a+b;
}
node sub(node a, node b){
	return a-b;
}
node up(node a){
	return splitmix64(a);
}
void dfs1(ll x, ll f=-1){
	h[x]=NEUT;
	for(auto y:g[x])if(y!=f){
		dfs1(y,x);
		h[x]=merge(h[x],up(h[y]));
	}
}
void dfs2(ll x, ll f=-1){
	tot[x]=merge(tot[x],h[x]);
	for(auto y:g[x])if(y!=f){
		ch[y]=up(merge(ch[x],sub(h[x],up(h[y]))));
		tot[y]=ch[y];
		dfs2(y,x);
	}
}
void reroot(ll rt=0){
	dfs1(rt);
	ch[rt]=NEUT;
	tot[rt]=NEUT;
	dfs2(rt);
}

//VIRTUAL TREES
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

// "binary lifting" with O(n) preprocessing
// (only for trees, I think)
// not tested
ll D[MAXN],F[MAXN],jump[MAXN]; // Depth, Father
ii V[MAXN],val[MAXN]; // V = Father value, val = jump value
void makeLeaf(ll x, ll p, ii _val){
	F[x]=p;
	V[x]=_val;
	D[x]=D[p]+1;
	if(D[p]-D[jump[p]]==D[jump[p]]-D[jump[jump[p]]]){
		jump[x]=jump[jump[p]];
		val[x]=oper(V[x],oper(val[p],val[jump[p]]));
	}
	else jump[x]=p,val[x]=V[x];
}
D[n]=0;
F[n]=-1; jump[n]=n;
void go(ll &x, ll &z){
	auto can=[&](ll* to, ii* v)->bool{ // if can, jump
		if(z<v[x].fst&&to[x]<n){
			z+=v[x].snd;
			x=to[x];
			return 1;
		}
		return 0;
	};
	while(can(jump,val)||can(F,V));
	// last jump
	if((pot>=s[x]||z<s[x])&&a[x]==n)z+=v[x],x=a[x];
	else z+=s[x],x=w[x];
}

// -------------------- DATA STRUCTURES ----------------------
// SEGMENT TREE ITERATIVO (soporta operacion no conmutativa)
typedef ll node;
node oper(node a, node b){return a+b;}
#define NEUT 0
struct STree{
	int n; vector<node>t;
	STree(int n):n(n),t(2*n+5,NEUT){}
	void upd(int p, node v){
		for(p+=n,t[p]=oper(t[p],v);p>1;p>>=1)p^=p&1,t[p>>1]=oper(t[p],t[p^1]);
	}
	node query(int l, int r){
		node izq=NEUT,der=NEUT;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)izq=oper(izq,t[l++]);
			if(r&1)der=oper(t[--r],der);
		}
		return oper(izq,der);
	}
};
	// init (put inside struct)
	void init(vector<node>a){
		fore(i,0,n)t[n+i]=a[i];
		for(ll i=n-1;i>0;i--)t[i]=oper(t[2*i],t[2*i+1]);
	}

// para STree recursivo
	// descenso en STree (put inside struct)
	ll find(ll k, ll s, ll e, ll x){
		if(s+1==e){
			if(st[k]>=x)return s;
			return n; //o s+1?
		}
		ll m=(s+e)/2;
		if(st[2*k]>=x)return find(2*k,s,m,x);
		return find(2*k+1,m,e,x-st[2*k]);
	}
	ll find(ll x){return find(1,0,n,x);} //lowerbound on sum prefixes

	
	// descenso en STree desde el medio
	
	// cosas a cambiar:
	// si quiero la primera posicion en la cual
	// se cumple una proposicion,
	// solo tengo que cambiar la definicion de bad
	// si quiero la ultima posicion, reversea el stree
	int find(int k, int s, int e, int a, int b, int j){
		// ejemplo: primera pos en la cual el bit j esta apagado 
		if(e<=a||b<=s) return b; // b es que no lo encontre
		// push(k,s,e); // para lazy
		int m = (s+e)/2;
		bool bad=(st[k].fst>>j&1); // bad es que no lo va a encontrar en este subarbol
		if(bad&&(a<=s&&e<=b))return b;
		if(e-s==1)return s;
		int res=find(2*k,s,m,a,b,j);
		if(res==b)res=find(2*k+1,m,e,a,b,j);
		return res; // cuando lo encuentra devuelve algo en [a,b)
	}
	int find(int a, int b, int j){return find(1,0,n,a,b,j);}

	
	// otra version:
	// Ej: primer <= a la izquierda
	vector<ll>st;int n; vector<int>ss,es,pos;
	STree(int n): st(4*n+5,NEUT), n(n), ss(4*n+5),es(4*n+5), pos(n+5) {}
	void init(int k, int s, int e, vector<ll> &a){
		ss[k]=s,es[k]=e;
		if(s+1==e){st[k]=a[s];pos[s]=k;return;}
		int m=(s+e)/2;
		init(2*k,s,m,a);init(2*k+1,m,e,a);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	ll find(ll k, ll s, ll e, ll x){
		if(s+1==e){
			if(st[k]<=x)return s;
			return -1; //o s-1?
		}
		ll m=(s+e)/2;
		if(st[2*k+1]<=x)return find(2*k+1,m,e,x);
		return find(2*k,s,m,x);
	}
	ll find(ll p){ //primer <= a la izquierda
		ll k=pos[p],x=st[k];
		while(k>1){
			if((k&1)&&st[k^1]<=x)return find(k^1,ss[k^1],es[k^1],x);
			k/=2;
		}
		return -1;
	}

// SEGMENT TREE LAZY
typedef ll tn; // node type
typedef ll tl; // lazy type
#define NEUT 0
#define CLEAR 0 // cleared lazy node
tn oper(tn a, tn b){
	return max(a,b);
}
void acum(tl &a, tl v){ // accumulate lazy node
	a+=v;
}
tn calc(int s, int e, tn a, tl v){ // calculate STree range, a=previous value
	assert(s|e|1); // useless, it's only to avoid compiler warning
	a+=v;
	return a;
} 
struct STree{
	vector<tn>st; vector<tl>lazy; int n;
	STree(int n):st(4*n+5,NEUT),lazy(4*n+5,CLEAR),n(n){}
	void init(int k, int s, int e, vector<tn>&a){
		if(e-s==1)st[k]=a[s];
		else {
			int m=(s+e)/2;
			init(2*k,s,m,a); init(2*k+1,m,e,a);
			st[k]=oper(st[2*k],st[2*k+1]);
		}
	}
	void push(int k, int s, int e){
		if(lazy[k]==CLEAR)return;
		st[k]=calc(s,e,st[k],lazy[k]);
		if(e-s!=1){
			acum(lazy[2*k],lazy[k]);
			acum(lazy[2*k+1],lazy[k]);
		}
		lazy[k]=CLEAR;
	}
	void upd(int k, int s, int e, int a, int b, tl v){ // range update
		push(k,s,e);
		if(e<=a||b<=s)return;
		if(a<=s&&e<=b){
			acum(lazy[k],v);
			push(k,s,e);
			return;
		}
		int m=(s+e)/2;
		upd(2*k,s,m,a,b,v),upd(2*k+1,m,e,a,b,v);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	tn query(int k, int s, int e, int a, int b){
		if(e<=a||b<=s)return NEUT;
		push(k,s,e);
		if(a<=s&&e<=b)return st[k];
		int m=(s+e)/2;
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	void upd(int a, int b, tl v){upd(1,0,n,a,b,v);}
	tn query(int a, int b){return query(1,0,n,a,b);}
	void init(vector<tn>&a){init(1,0,n,a);}
};
// may be useful
	void upd(int k, int s, int e, int p, tn v){ // assign v to position p
		push(k,s,e);
		if(e<=p||p<s)return;
		if(e-s==1&&s==p){
			push(k,s,e);
			st[k]=v;
			return;
		}
		int m=(s+e)/2;
		upd(2*k,s,m,p,v),upd(2*k+1,m,e,p,v);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	void upd(int p, tn v){upd(1,0,n,p,v);}

//  para PERSISTENT STree:
//*	if using as STree lazy creation change to
//	ks=(k?k: ... ); in upd
//	to avoid mle 

// for 2d static queries
// O(p logn) where p = number of points
typedef pair<ll,ll> node;
node oper(node a, node b){return {a.fst+b.fst,a.snd+b.snd};}
node inv(node a, node b){return {a.fst-b.fst,a.snd-b.snd};}
	// (paste inside persistent)
	// n = 2nd coordinate
	// IF ONLY COPYING THIS CHANGE TO oper= IN LEAF UPDATE (acummulate, instead of assign)
	vector<int>rts,keys;
	typedef pair<pair<ll,ll>,node> dat;
	void init(vector<dat>a){
		// init 2d updates, (x,y) coords, value
		rts={0}; keys={};
		sort(ALL(a),[&](const dat &a, const dat &b){
			return a.fst.fst<b.fst.fst;});
		for(auto [pa,v]:a){
			auto [x,y]=pa;
			keys.pb(x);
			rts.pb(upd(y,v));
		}
	}
	node get(ll i, ll j0, ll j1){ // get rectangle [0,i) [j0,j1)
		ll p=lower_bound(ALL(keys),i)-keys.begin();
		return query(rts[p],j0,j1);
	}
	node get(ll i0, ll i1, ll j0, ll j1){
		// get rectangle [i0,i1) [j0,j1) with inverse operation
		return inv(get(i1,j0,j1),get(i0,j0,j1));
	}

// para FENWICK TREE
ii find(ll x){ // upperbound on prefix sums], (pos,remainder)
	ll p=0;    // change 19 to floor(log2(MAXN))
	for(ll k=19;k>=0;k--)if(ft[p+(1ll<<k)]<=x){
		p+=1ll<<k;
		x-=ft[p];
	}
	return {p,x};
}

// PARTIAL SUMS 2D
fore(i,1,n+1)fore(j,1,n+1)sp[i][j]=a[i-1][j-1]+sp[i][j-1];
fore(i,1,n+1)fore(j,1,n+1)sp[i][j]+=sp[i-1][j];

// IN K-DIMENSIONS     (sum of smaller elements in any direction)
// store initial values
// for dimension d in range(k): for all elements mk in order:
// 	  sp[mk]+=sp[mk-1 en d] //anterior en dimension d
// example (k bit dimensions):
fore(mk,0,1ll<<k)sp[mk]=a[mk];
fore(d,0,k)fore(mk,0,1ll<<k){
	if(mk&(1ll<<d))sp[mk]+=sp[mk^(1ll<<d)];
}

//MERGE SORT TREE LAZY CREATION
// uses indexed_set with pair. point update, rectangle query
ll qidx=0;
struct MSTree{ //lazy creation
	vector<indexed_set>mst; vector<ll> L,R; ll n;
	MSTree (ll n):mst(1),L(1,-1),R(1,-1),n(n){}
	MSTree(){}
	ll new_node(){
		ll ks=SZ(L);
		mst.pb({});
		L.pb(-1),R.pb(-1);
		return ks;
	}
	void upd(ll k, ll s, ll e, ll i, ll j, ll v){
		if(v==1)mst[k].insert({j,qidx++});
		if(v==-1)
			mst[k].erase(mst[k].find_by_order(mst[k].order_of_key({j,-1})));
		if(s+1==e)return;
		ll m=(s+e)/2;
		if(i<m){
			if(L[k]==-1){ll ls=new_node(); L[k]=ls;}
			upd(L[k],s,m,i,j,v);
		}
		else {
			if(R[k]==-1){ll rs=new_node(); R[k]=rs;}
			upd(R[k],m,e,i,j,v);
		}
	}
	ll query(ll k, ll s, ll e, ll i0, ll i1, ll j0, ll j1){
		if(k==-1||i1<=s||e<=i0)return 0;
		if(i0<=s&&e<=i1){
			return mst[k].order_of_key({j1,-1})-mst[k].order_of_key({j0,-1});
		}
		ll m=(s+e)/2;
		return query(L[k],s,m,i0,i1,j0,j1)+query(R[k],m,e,i0,i1,j0,j1);
	}
	void upd(ll i, ll j, ll v){upd(0,0,n,i,j,v);}
	ll query(ll i0, ll i1, ll j0, ll j1){return query(0,0,n,i0,i1,j0,j1);}
};

//MIN-QUEUE (O(n))
struct MinQ{
	deque<ii>q; ll dif=0;
	MinQ(){}
	void push(ll x){
		ll cnt=1;
		x-=dif;
		while(SZ(q)&&x<=q.back().fst)cnt+=q.back().snd,q.pop_back();
		q.pb({x,cnt});
	}
	void pop(){
		if(!SZ(q))return;
		if(q.front().snd>1)q.front().snd--;
		else q.pop_front();
	}
	ll query(){
		if(!SZ(q))return INF;
		return q.front().fst+dif;
	}
	void add(ll x){dif+=x;}
};


// ------------------------------STRINGS-------------------------
// compare substrings with suffix array
string S;
vector<int>sa,lcp,pos;
void SA_compare_init(string &_s){
	S=_s;
	sa=constructSA(S);
	lcp=computeLCP(S,sa);
	pos.resize(SZ(sa));
	fore(i,0,SZ(sa))pos[sa[i]]=i;
	st_init(lcp);
}
ll get_lcp(ll i, ll j){
	if(i==j)return SZ(S)-1-i;
	ll l=pos[i],r=pos[j];
	if(l>r)swap(l,r);
	return st_query(l+1,r+1);
}

ll compare(ii a, ii b){
	auto [i,i1]=a; auto [j,j1]=b; i1-=i,j1-=j;
	ll k=get_lcp(i,j);
	if(k>=i1&&k>=j1){
		if(i1==j1)return 0;
		return i1<j1?-1:1;
	}
	if(k>=i1)return -1;
	if(k>=j1)return 1;
	return S[i+k]<S[j+k]?-1:1;
}

// ------------------------ FLOW ------------------------------

// FLOW WITH DEMANDS

// add edge (x,y) with capacity c and demand d
// where s_ and t_ are the new source and sink
// only checks if demands are satisfied
// doesn't guarantee max flow

// to optimize constant you can merge all t,s edges
// and only add an edge when cap is non-zero

auto add_demand=[&](ll x, ll y, ll d, ll c){ // d <= c
	fl.add_edge(s_,y,d);
	fl.add_edge(t,s,d);
	fl.add_edge(x,t_,d);
	fl.add_edge(x,y,c-d);
};


// ------------------ MISCELLANEOUS --------------------------
//MOS ON TREE 
//needs lca // (CH = change)
ll C[MAXN],S[MAXN],E[MAXN],P[MAXN];
vector<ll>A; //tree in mod dfs order
void dfs_order(ll x){
	P[x]=			//CH answer on node x
	S[x]=SZ(A); A.pb(x);
	for(auto y:g[x])dfs_order(y);
	E[x]=SZ(A); A.pb(x);
}
void ADD(ll x){ //CH add node x
	
}
void REM(ll x){ //CH remove node x
	
}
ll get_ans(ll x){ //CH add P[x]
	ADD(P[x]);
	REM(P[x]);
	return P[x]+
}
void init(){
	lca_init();
	A.clear();
	dfs_order(0);
	fore(i,0,nq){
		ll u=qs[i].l,v=qs[i].r;
		if(S[u]>S[v])swap(u,v);
		qs[i].lca=lca(u,v); //CH add lca in struct qu
		qs[i].l=E[u],qs[i].r=E[v];
	}
	//CH init
	
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
//CH get_ans(q.lca) and n with SZ(A) in mos

//SQRT DECOMPOSITION BLOCKS STRUCTURES
#define BLOCKSZ sqrt(N)
struct BL{ //2d queries (static, n points, coordinates up to n)
	//query O(sqrt(n)), memory O(nsqrt(n)))
	ll r,n,q; vector<vector<int>>sp; vector<ll>a;
	//r=block size, q=number of blocks
	BL(ll N):r(BLOCKSZ),n((N+r-1)/r*r),q(n/r),sp(q,vector<int>(n+5)),a(n,n){}
	BL(){}
	void init(vector<ll>&_a){
		fore(i,0,SZ(_a))a[i]=_a[i];
		fore(i,0,q){
			vector<ll>b(n+1);
			fore(j,0,r)b[a[r*i+j]]++;
			fore(j,1,n+2)sp[i][j]=sp[i][j-1]+b[j-1];
		}
	}
	ll query(ll i0, ll i1, ll j0, ll j1){
		ll res=0;
		ll s=i0,e=min(i1,i0/r*r+r);
		fore(i,s,e)res+=(j0<=a[i]&&a[i]<j1);
		if(i0/r==i1/r)return res;
		fore(i,i0/r+1,i1/r)res+=sp[i][j1]-sp[i][j0];
		s=i1/r*r,e=i1;
		fore(i,s,e)res+=(j0<=a[i]&&a[i]<j1);
		return res;
	}
};

ll find(ll i0, ll i1, ll j0, ll j1, ll k){ //whatever, specific on problem
	// kesimo (i) punto en rectangulo
	if(k>=query(i0,i1,j0,j1))return -1;
	ll s=i0,e=min(i1,i0/r*r+r);
	fore(i,s,e)if(j0<=a[i]&&a[i]<j1){
		if(k==0)return i;
		k--;
	}
	ll bp=-1;
	fore(i,i0/r+1,i1/r){
		ll c=sp[i][j1]-sp[i][j0];
		if(k-c<0){
			bp=i;
			break;
		}
		k-=c;
	}
	s=i1/r*r,e=i1;
	if(bp!=-1)s=bp*r,e=s+r;
	fore(i,s,e)if(j0<=a[i]&&a[i]<j1){
		if(k==0)return i;
		k--;
	}
	assert(0);
}

#define BLOCKSZ sqrt(n)+5
struct BH{ //Blocks Histogram
	//upd O(1), query O(sqrt(n)), memory O(nsqrt(n)))
	ll n,r,q; vector<vector<int>>h; vector<ll>a,sz;
	//r=block size, q=number of blocks
	BH(ll n):n(n),r(BLOCKSZ),q((n+r-1)/r),h(q,vector<int>(n+5)),a(n),sz(q,r){
		if(n%r)sz[q-1]=n%r;
		//fore(i,0,n)sz[i/r]++;
		fore(i,0,q)h[i][0]=sz[i];
	}
	BH(){}
	void upd(ll p, ll v){ //v<n+5
		//if(a[p]==n)return; //specific on problem
		ll bp=p/r;
		h[bp][a[p]]--;
		a[p]=v;
		h[bp][a[p]]++;
	}
	ll query(ll x){ //whatever, specific on problem
		ll bp=-1;
		fore(i,0,q)if(h[i][n]+h[i][x]<sz[i]){
			bp=i;
			break;
		}
		if(bp==-1)return -1;
		fore(i,0,r){
			ll pos=r*bp+i;
			if(a[pos]!=n&&a[pos]!=x)return pos;
		}
		assert(0);//no llega
	}
};
// generic
void upd(ll i0, ll i1, ll v){
	#define SINGLE(s,e) fore(i,s,e)a[i]=max(a[i],v)
	SINGLE(i0,min(i1,i0/r*r+r));
	if(i0/r==i1/r)return res;
	fore(i,i0/r+1,i1/r)val[i]=max(val[i],v); //blocks
	SINGLE(i1/r*r,i1);
}

// DIVIDE AND CONQUER DP OPTIMIZATION
// sets dp[i]=min(f(i,j)) for all j, given that arg dp[i] <= arg dp[i+1]	O(nlogn)
void dnc(ll l, ll r, ll s, ll e){ // all [,)
	if(r-l<=0)return;
	ll m=(l+r)/2;
	ll opt=s;
	ll &res=dp[m];
	fore(j,s,e)if(f(m,j)<res)opt=j,resi=f(m,j);
	if(r-l>1)dnc(l,m,s,opt+1),dnc(m+1,r,opt,e);
}

// 1D1D dp optimization
// technically it's only the part inside aliens, but all problems I saw that required 1D1D also needed aliens (only 3, I'll change it when I encounter a counterexample)

ii dp[MAXN];
ll lam;
ii cost(ll l, ll r){ // monge inequality must hold (only for this function)
	ll now=sqrtl((r-l)*(sp[r]-sp[l]));
	ii ret={now+dp[r].fst+lam,dp[r].snd+1};
	return ret;
}

ii aliens(ll _lam){
	lam=_lam;
	deque<ii>dq; dq.pb({n-1,n});
	for(ll j=n-1;j>=0;j--){ // info hasta (j
		auto opt=dq.back().snd;
		assert(dq.back().fst==j);
		dp[j]=cost(j,opt);
		if(!j)break;
		dq.pop_back();
		if(!SZ(dq)||dq.back().fst<j-1)dq.pb({j-1,opt});
		ll s=0;
		while(SZ(dq)){
			auto [i,opt]=dq.front();
			if(cost(i,j)<cost(i,opt))s=i,dq.pop_front();
			else break;
		}
		if(!SZ(dq)){assert(s==j-1);dq.pb({s,j});continue;}
		ll l=s,r=dq.front().fst-1;
		while(l<=r){
			ll m=(l+r)/2;
			if(cost(m,j)<cost(m,dq.front().snd))l=m+1;
			else r=m-1;
		}
		if(r>=0)dq.push_front({r,j});
	}
	return dp[0];
}

//SIMULATED ANNEALING
// answer only (no reconstuction required)
// for reconstruction also store the best state
ll r=0; // current answer, modify in ch
void ch(int i){ //change to a neighbour (could be erase/insert i or swap i,j)
	
}
double t=1e9; //temperature, 1e9 or 1e5
ll SA(){
	srand(175);
	fore(i,0,n)if(rand()&1)ch(i); //random state
	ll best=r;
	while(clock()<=1.99*CLOCKS_PER_SEC){ //time limit 2sec
		ll old=r;
		int i=rand()%n;
		ch(i);
		best=min(best,r);
		if(! (r<old||exp((old-r)/t)*RAND_MAX>=rand()) )ch(i);
		t*=0.99999;
	}
	//cerr<<t<<"\n";
	return best;
}

// cache relabeling
// helpful to reduce constant when the slow part is a dfs
// you can generalize this for other problems
// for centroid is roughly a x2 speedup
ll nl[MAXN],orig[MAXN]; // new label for helping cache
ll cnt=0;
void cache(ll x, ll fa=-1){
	nl[x]=cnt;
	orig[cnt++]=x;
	for(auto y:g[x])if(y!=fa)cache(y,x);
}
// inside main (store edges in ed in the same order as inserted)
cache(0);
fore(i,0,n)g[i].clear();
for(auto [x,y]:ed){
	ll u=nl[x],v=nl[y];
	g[u].pb(v);
	g[v].pb(u);
}