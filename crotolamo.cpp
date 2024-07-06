#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

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

//INPUT OUTPUT POR ARCHIVO
#ifdef ONLINE_JUDGE
freopen("billboard.in","r",stdin);
freopen("billboard.out","w",stdout);
#endif
// or
ifstream cin;   cin.open("input.in", ios::in);
ofstream cout; cout.open("output.out", ios::out);

// LEER LINEA DE STRING
cin.ignore();
getline(cin,s);

// RANDOM NUMBERS
random_device rd;
mt19937 rng(rd()); // mt19937_64 for long long
// use: rng() gives a random number
shuffle(ALL(a),rng); // instead of random_shuffle
// instead of rd() you can use any seed, or
// chrono::steady_clock::now().time_since_epoch().count()
// for time in miliseconds

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
*/

// -------------------- MATH ----------------------------
// COMBINATORIA
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
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
ll nCr(ll n, ll k){ //must call factos before
	if(n<0||k<0||k>n)return 0;
	return mul(mul(fc[n],fci[k]),fci[n-k]);
}

// DIVISORES
// O(nlogn) memoria y tiempo
vector<ll> divs[MAXN];
void divisores(){
	fore(i,1,MAXN)for(int j=i;j<MAXN;j+=i)divs[j].pb(i);
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
		if(v){x[31-__builtin_clz(v)]=v;return 1;}
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
ll lw[MAXN],dis[MAXN],art[MAXN],br[MAXM],vised[MAXM];
ll cnt_=0;
void dfs_(ll x){
	lw[x]=dis[x];
	for(auto [y,ed]:g[x])if(!vised[ed]){
		cnt_+=(x==0);
		vised[ed]=1;
		if(lw[y]==-1){ //tree edge
			dis[y]=dis[x]+1;
			dfs_(y);
			lw[x]=min(lw[x],lw[y]);
			art[x]|=(lw[y]>=dis[x]);
			br[ed]=(lw[y]>=dis[y]);
		}
		else lw[x]=min(lw[x],dis[y]); //back edge
	}
}
void dfs_init(ll n=0, ll m=0){
	mset(lw,-1); mset(art,0); mset(vised,0);
	//fore(i,0,n)lw[i]=-1,art[i]=0;
	//fore(i,0,m)vised[i]=0;
}
void dfs_tree(ll rt=0){
	if(lw[rt]!=-1)return;
	dis[rt]=0; cnt_=0;
	dfs_(rt);
	art[rt]=(cnt_>1);
}
//uncomment for testcases

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
ll n;
vector<ii>g[MAXN]; // node, weight (1 if none)
struct node {
	ll dp,q;
	node():dp(0),q(0){}
	node(ll q):dp(0),q(q){}
};
node NEUT;
node leaf(ll x){
	return node(1);
}
node up(node x, ll w=1){
	x.dp+=x.q;
	return x;
}
node merge(node a, node b){
	a.q+=b.q;
	a.dp+=b.dp;
	return a;
}
node h[MAXN],ch[MAXN]; // hijo, complement hijo (SIN ARISTA PADRE)
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
}
void dfs2(ll x){
	fore(j,0,SZ(g[x])){
		auto [y,w]=g[x][j];
		if(y==fa[x])continue;
		ch[y]=merge(leaf(x),merge(pre[x][j],suf[x][j+1]));
		if(fa[x]!=-1)ch[y]=merge(ch[y],up(ch[x],wf[x]));
		dfs2(y);
	}
}
void reroot(ll rt=0){
	fa[rt]=-1,wf[rt]=0;
	dfs1(rt);
	fore(x,0,n){
		auto &p=pre[x];
		auto &s=suf[x];
		ll m=SZ(g[x]);
		p=s=vector<node>(m+1,NEUT);
		fore(j,1,m+1){
			auto [y,w]=g[x][j-1];
			p[j]=p[j-1];
			if(y!=fa[x])p[j]=merge(p[j],up(h[y],w));
		}
		for(ll j=m-1;j>=0;j--){
			auto [y,w]=g[x][j];
			s[j]=s[j+1];
			if(y!=fa[x])s[j]=merge(s[j],up(h[y],w));
		}
	}
	dfs2(rt);
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
vector<ll> t[MAXN];
ll is[MAXN]; // is it a real tree node?
void make_tree(vector<ll>&v){
//makes virtual tree t and adds virtual nodes to v
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
ll c[MAXN],dp[MAXN];
void reset(vector<ll>&v){
	for(auto i:v){
		is[i]=vis_[i]=0;
		t[i].clear();
		dp[i]=0;
	}
	resi=0;
}

// -------------------- DATA STRUCTURES ----------------------------
// SEGMENT TREE ITERATIVO (soporta operacion no conmutativa)
typedef ll node;
node oper(node a, node b){return a+b;}
#define NEUT 0
struct STree{
	int n; vector<node>t;
	STree(int n):n(n),t(2*n+5,NEUT){}
	void upd(int p, node v){
		for(p+=n,t[p]=v;p>1;p>>=1)p^=p&1,t[p>>1]=oper(t[p],t[p^1]);
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
	//init
	void init(vector<node>a){
		fore(i,0,SZ(a))t[n+i]=a[i];
		for(ll i=n-1;i>0;i--)t[i]=oper(t[2*i],t[2*i+1]);
	}

// para STree recursivo
	// BS on STree (put inside struct)
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

	// BS on STree desde el medio
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
// tn unit(ll v){return v;}
#define NEUT 0
#define CLEAR 0 // cleared lazy node
tn oper(tn a, tn b){
	return max(a,b);
}
void acum(tl &a, tl v){ // accumulate lazy node
	a+=v;
}
tn calc(ll s, ll e, tn a, tl v){ // calculate STree range, a=previous value
	a+=v;
	return a;
} 
struct STree{
	vector<tn>st; vector<tl>lazy; ll n;
	STree(ll n):st(4*n+5,NEUT),lazy(4*n+5,CLEAR),n(n){
		//fore(i,0,n)upd(i,unit(0));
	}
	void init(ll k, ll s, ll e, vector<tn>&a){
		if(e-s==1)st[k]=a[s];
		else {
			ll m=(s+e)/2;
			init(2*k,s,m,a); init(2*k+1,m,e,a);
			st[k]=oper(st[2*k],st[2*k+1]);
		}
	}
	void push(ll k, ll s, ll e){
		if(lazy[k]==CLEAR)return;
		st[k]=calc(s,e,st[k],lazy[k]);
		if(e-s!=1){
			acum(lazy[2*k],lazy[k]);
			acum(lazy[2*k+1],lazy[k]);
		}
		lazy[k]=CLEAR;
	}
	void upd(ll k, ll s, ll e, ll a, ll b, tl v){ // range update
		push(k,s,e);
		if(e<=a||b<=s)return;
		if(a<=s&&e<=b){
			acum(lazy[k],v);
			push(k,s,e);
			return;
		}
		ll m=(s+e)/2;
		upd(2*k,s,m,a,b,v),upd(2*k+1,m,e,a,b,v);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	tn query(ll k, ll s, ll e, ll a, ll b){
		if(e<=a||b<=s)return NEUT;
		push(k,s,e);
		if(a<=s&&e<=b)return st[k];
		ll m=(s+e)/2;
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	void upd(ll a, ll b, tl v){upd(1,0,n,a,b,v);}
	tn query(ll a, ll b){return query(1,0,n,a,b);}
	void init(vector<tn>&a){init(1,0,n,a);}
};
// may be useful
	void upd(ll k, ll s, ll e, ll p, tn v){ // assign v to position p
		push(k,s,e);
		if(e<=p||p<s)return;
		if(e-s==1&&s==p){
			push(k,s,e);
			st[k]=v;
			return;
		}
		ll m=(s+e)/2;
		upd(2*k,s,m,p,v),upd(2*k+1,m,e,p,v);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	void upd(ll p, tn v){upd(1,0,n,p,v);}

//  para PERSISTENT STree:
//*	if using as STree lazy creation change to
//	ks=(k?k: ... ); in upd
//	to avoid mle 
//
// for 2d static queries
typedef ii node;
node oper(node a, node b){return {a.fst+b.fst,a.snd+b.snd};}
node inv(node a, node b){return {a.fst-b.fst,a.snd-b.snd};}
	// (paste inside persistent)
	// n = 2nd coordinate
	vector<int>rts,keys;
	void init(vector<pair<ii,node>>a){
		// init 2d updates, (x,y) coords, value
		rts={0}; keys={}; // if 
		sort(ALL(a),[&](pair<ii,node>a, pair<ii,node> b){
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
	void add(ll x){
		dif+=x;
	}
};

// -------------------- MISCELLANEOUS ----------------------------
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