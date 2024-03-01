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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		
	}
	return 0;
}

//me gustaria declararte mi amor pero solo se declarar variables

template<class x> ostream & operator<<(ostream & out, vector<x> v){
    out<<"{ ";
    for(auto y : v) out<<y<<" ";
    out<<"}";
    return out;
}

//PRAGMAS

//#pragma GCC optimize("Ofast") // may lead to precision errors

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
gedit A.cpp && gedit B.cpp && gedit C.cpp && gedit D.cpp && gedit E.cpp && gedit F.cpp && gedit G.cpp

// COMPILAR
g++ -O2 -std=c++17 -Wall -Wextra -g -D_GLIBCXX_DEBUG <file> -o a
//fast
g++ -O2 -std=c++17 -Wall -Wextra -g
//debug
g++ -O2 -std=c++17 -Wall -Wextra -g -D_GLIBCXX_DEBUG
//all warnings
g++ -O2 -std=c++17 -Wall -Wextra -g -D_GLIBCXX_DEBUG -Wshadow -Wconversion

//DEBUGGEAR CON GDB
// must have -g -D_GLIBCXX_DEBUG

gdb ./a
run <in
where

//TIPOS DE VARIABLES
short			//-3.2e4 a 3.2e4 // 2 bytes
int				//-2e9 a 2e9 // 4 bytes
unsigned int	//0 a 4e9
long long		//-9e18 a 9e18 // 8 bytes
__int128		// 1e38 // 16 bytes
float		//7 digits
double		//(recomendable) 15 digits
long double	//18 digits
__float128	//34 digits
bool	//1 o 0 // 1 byte

//TIPOS DE DATOS
queue<ll>q //FIFO
priority_queue<ll>pq //mayor a menor || priority_queue<ll,vector<ll>,comp>pq
deque<ll>dq //le entran por adelante y por atrás
stack<ll>sk //LIFO
auto p=lower_bo... //declarar puntero
p--,p++//mover puntero O(N)
bitset<n> b; // se pueden hacer operaciones de bits O(n/32) | O(n/64)
list<ll>l; // insert(iterator,element)//after iterator , erase(iterator) , pb, push_front
forward_list<ll>fl; // erase_after() , insert_after() , push_front //raro

//FUNCIONES
rotate(a.begin(),a.begin()+x,a.end()) //circular rotation x to the left
void rot(vector<ll>&a, ll x){rotate(a.begin(),a.begin()+x,a.end());}
b.count(); //pop_count de bitset
b._Find_first(); //first 1-bit (ctz)
b._Find_next(idx); //next 1-bit strictly after idx 
// ^^^^ WARNING undefined? for negative indices
v.resize(n);
to_string(x);
s.substr(l,n);// substring [l,l+n) // if no n: suffix [l,SZ(s))
stoll(s); //string to ll
getline(cin,s);cin.ignore();
//a=arreglo, n=tamaño de a, s=string, v=vector, st=set
lower_bound(a,a+n,x)//es un puntero, -a posición, *read only
lower_bound(ALL(v),x)//-v.begin()
st.lower_bound(x)
find(ALL(v),x)//O(n)
find(a,a+n,x)//O(n)
v.clear();
st.erase("x");
v.erase(v.begin()+i)//O(n)
count(ALL(v),x)//O(n)
s.erase(remove(ALL(s),'a'),s.end());
q.push(x)
q.front()
q.back();
q.pop();
sk.push(x)
sk.pop()
sk.top(); //sk.top()==pq.top()==q.front()
dq.pb(x)
dq.pop_back()
dq.push_front(x)
dq.pop_front()

assert(condition);
cout<<fixed<<setprecision(15)<<x<<"\n"; //imprimir con 15 digitos de presición 
// priority_queue with custom comparator cmp
priority_queue<ll,vector<ll>,function<bool(ll,ll)>>pq(cmp);

//MATH
gcd(x,y)//hace euclides por dentro

//binary gcd (already implemented in std::gcd but not in __gcd)
inline ll remtz(ll a){
	return a>>__builtin_ctz(a);
}
ll gcd_odd(ll a, ll b){
	while(a!=b){
		if(a<b)swap(a,b);
		a=remtz(a-b);
	}
	return a;
}
ll gcd(ll a, ll b){
	if(a==0)return b;
	if(b==0)return a;
	return gcd_odd(remtz(a),remtz(b))<<min(__builtin_ctz(a),__builtin_ctz(b));
}

//GEO
hypot(l,r);//return double
hypotf,fipotl//float,long double

struct pt{
	ll x,y;
	pt(ll x, ll y):x(x),y(y){}
	pt(){}
	pt operator-(pt p){return pt(x-p.x,y-p.y);}
	bool operator==(pt p){return (x==p.x&&y==p.y);}
	ll operator%(pt p){return x*p.y-y*p.x;}
	bool left(pt p, pt q){return (p-*this)%(q-*this)>0;}
};
pt.x,pt.y;

//BUSQUEDA BINARIA:
ll l=x,r=y;
while(l <= r) {
  m = (l+r)/2;
  if (can (m)) l=m+1;
  else r=m-1;
}
//Versión doubles
double l=x,r=y;
ll it;// it=techo log2((r-l)*presicion)
while(it--) {
  m = (l+r)/2;
  if (can (m)) l=m;
  else r=m;
}

do{
	
}
while(next_permutation(ALL(a)));

//CODE JAM
	ll te=t;
	while(t--){
		cout<<"Case #"<<te-t<<": ";

//INPUT OUTPUT POR ARCHIVO
	ifstream cin;   cin.open("input.in", ios::in);
	ofstream cout; cout.open("output.out", ios::out);
	
//HACKER CUP
	ll t; cin>>t;
	fore(_,0,t){
		cout<<"Case #"<<_+1<<": ";
		
		
__builtin_popcountll(x); //contar bits 1 de x
__builtin_clzll(x); // count leading zeros // 64-funcion contar bits
__builtin_ctzll(x); // count trailing zeros // cantidad de factores 2

//FLOOR SQRT
ll fqrt(ll x){ //if ceil change to r*r<x and return r
	ll r=sqrt(x)-3;
	for(;r<0||r*r<=x;r++)if(r<0)continue;
	return r-1;
}

//FAST POW y NUMEROS COMBINATORIOS
ll fpow(ll b, ll e){
	if(e<0)return 0;
	ll ret=1;
	while(e){
		if(e&1)ret=ret*b%MOD;
		b=b*b%MOD,e>>=1;
	}
	return ret;
}

ll fc[MAXF],fci[MAXF];
void factorials(){
	fc[0]=1;
	fore(i,1,MAXF)fc[i]=fc[i-1]*i%MOD;
	fci[MAXF-1]=fpow(fc[MAXF-1],MOD-2);
	for(ll i=MAXF-2;i>=0;i--)fci[i]=fci[i+1]*(i+1)%MOD;
}
ll nCr(ll n, ll k){ //must call factorials before
	if(n<0||k<0||k>n)return 0;
	return fc[n]*fci[k]%MOD*fci[n-k]%MOD;
}
//MODULAR OPERATIONS
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
//bolitas en cajitas
ll ceb(ll c, ll b){return nCr(c+b-1,c-1);}

//Divisores
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

//FACTORIZACION EN PRIMOS
vector<pair<ll,ll>> fact(ll x){
	vector<pair<ll,ll>>v;
	for(ll i=2; i*i<=x; i++){
		ll count=0;
		while(x%i==0){
			count++;
			x/=i;
		}
		if(count)v.pb({i,count});
	}
	if(x>1)v.pb({x,1});
	return v;
}

//CRIBA
int cr[MAXV]; // -1 if prime, some not trivial divisor if not	O(nloglog(n))
void init_sieve(){
	memset(cr,-1,sizeof(cr));
	fore(i,2,MAXV)if(cr[i]<0)for(ll j=1ll*i*i;j<MAXV;j+=i)cr[j]=i;
}
map<int,int> fact(int n){  // must call init_cribe before		O(log(n))
	map<int,int> res;
	while(cr[n]>=0)res[cr[n]]++,n/=cr[n];
	if(n>1)res[n]++;
	return res;
}

//UNION FIND Y KRUSKAL
int uf[MAXN];
void uf_init(){memset(uf,-1,sizeof(uf));}
int uf_find(int x){return uf[x]<0?x:uf[x]=uf_find(uf[x]);}
bool uf_join(int x, int y){
	x=uf_find(x);y=uf_find(y);
	if(x==y)return false;
	if(uf[x]>uf[y])swap(x,y); // y -> x
	uf[x]+=uf[y];uf[y]=x;
	return true;
}
//version SMALL TO LARGE
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

vector<pair<ll,pair<ll,ll>>>es; //edges(cost,(u,v))
ll kruskal(ll n){
	sort(ALL(es)); uf_init(n);
	ll res=0;
	for(auto i:es){
		ll a=i.snd.fst, b=i.snd.snd, w=i.fst;
		if(uf_join(a,b))res+=w;
	}
	return res;
}

//PRIM
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
//DIJKSTRA  O(N + MlogM)
vector<ii> g[MAXN];//g[u]={cost,v}
ll d[MAXN];
void dijkstra(ll x){
	mset(d,-1);//flag value
	d[x]=0;
	priority_queue<ii,vector<ii>,greater<ii>> q;//ascending order {cost,u}
	q.push({0,x});
	while(SZ(q)){
		x=q.top().snd;auto c=q.top().fst;
		q.pop();
		if(d[x]!=c)continue;//if changed
		for(auto i:g[x]){
			ll y=i.fst,c=i.snd;
			if(d[y]==-1||d[x]+c<d[y]){
				d[y]=d[x]+c;
				q.push({d[y],y});
			}
		}
	}
}

//FLOYD WARSHALL
void floyd(){//O(n^3)
	//setear g[i][i]=0 y INF a aristas no existentes
	//se pisan los valores en la matriz de adyacencia
	fore(k,0,n)fore(i,0,n)if(g[i][k]!=INF)fore(j,0,n)if(g[k][j]!=INF)
		g[i][j]=min(g[i][j],g[i][k]+g[k][j]),//or if(d==f||newPath<d)for flag value
		g[j][i]=g[i][j];//not directed
}

//TOPOSORT
vector<ll> g[MAXN];
ll vis[MAXN];
bool esDAG=1;
vector<ll>ord;
void dfs(ll x){
	vis[x]=1;
	for(auto i:g[x]){
		if(vis[i]!=2){
			if(vis[i]==1){
				esDAG=0;
				vis[i]=2;
				break;
			}
			else dfs(i);
		}
	}
	vis[x]=2;
	ord.pb(x);
}
reverse(ALL(ord));

//LCA
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
ll father(ll v, ll x){ // v-ésimo padre de x
	for(ll k=K-1;k>=0;k--)if(v>=(1ll<<k)){
		x=F[k][x];
		v-=1ll<<k;
		if(x<0)break;
	}
	return x;
}

// queries de caminos
typedef ll node;
#define NEUT 0
node oper(node a, node b){return a|b;}

const ll K=18; //K such that 2^K>=n
ll n; ll a[MAXN]; // USE THIS N !!!!!!
vector<ll> g[MAXN]; 

ll F[K][MAXN],D[MAXN];
node V[K][MAXN];//késimo padre de x, distancia a root
void lca_dfs(ll x){//padres 0 y distancia
	for(auto y:g[x]){
		if(y==F[0][x])continue;
		F[0][y]=x;
		D[y]=D[x]+1;
		lca_dfs(y);
	}
}
void lca_init(){//k padres
	D[0]=0;
	F[0][0]=-1;
	fore(i,0,n)V[0][i]=node(a[i]);
	lca_dfs(0);
	fore(k,1,K)fore(x,0,n){
		if(F[k-1][x]<0){
			F[k][x]=-1;
			V[k][x]=V[k-1][x];
		}
		else {
			F[k][x]=F[k-1][F[k-1][x]];
			V[k][x]=oper(V[k-1][x],V[k-1][F[k-1][x]]);
		}
	}
}
pair<ll,node> lca(ll x, ll y){
	if(D[x]<D[y])swap(x,y);//x abajo
	node res=NEUT;
	for(ll k=K-1;k>=0;k--)if(D[x]-(1ll<<k)>=D[y]){
		res=oper(res,V[k][x]);
		x=F[k][x];//level
	}
	if(x==y)return {x,oper(res,V[0][y])};
	for(ll k=K-1;k>=0;k--)if(F[k][x]!=F[k][y]){
		res=oper(res,V[k][x]);
		res=oper(res,V[k][y]);
		x=F[k][x],y=F[k][y];//find lca
	}
	res=oper(res,V[0][x]);
	res=oper(res,V[0][y]);
	res=oper(res,V[0][F[0][x]]);
	return {F[0][x],res};
}

// oper no conmutativa (NO CHEQUEADO)
typedef ll node;
//struct node{};
#define oper min
#define NEUT INF
vector<ii>g[MAXN]; ll n;
ll F[K][1ll<<K],D[MAXN];
node V[K][1ll<<K];
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
		V[k][i]=oper(V[k-1][i],V[k-1][F[k-1][i]]);
	}
}
pair<ll,node> lca(ll x, ll y){ // {lca,ans}
	node l=NEUT,r=NEUT;
	if(D[x]>D[y]){
		for(ll k=K-1;k>=0;k--)if(D[x]-(1ll<<k)>=D[y]){
			l=oper(l,V[k][x]); x=F[k][x];
		}
	}
	else {
		for(ll k=K-1;k>=0;k--)if(D[y]-(1ll<<k)>=D[x]){
			r=oper(r,V[k][y]); y=F[k][y];
		}
	}
	if(x==y)return {x,oper(l,rev(r))};
	for(ll k=K-1;k>=0;k--)if(F[k][x]!=F[k][y]){
		l=oper(l,V[k][x]); x=F[k][x];
		r=oper(r,V[k][y]); y=F[k][y];
	}
	l=oper(l,V[0][x]); x=F[0][x];
	r=oper(r,V[0][y]); y=F[0][y];
	return {x,oper(l,rev(r))};
}

//DATA STRUCTURES

//SEGMENT TREE
#define oper min
#define NEUT INF
struct STree{
	vector<ll>st;int n;
	STree(int n): st(4*n+5,NEUT), n(n) {}
	void init(int k, int s, int e, vector<ll> &a){
		if(s+1==e){st[k]=a[s];return;}
		int m=(s+e)/2;
		init(2*k,s,m,a);init(2*k+1,m,e,a);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	void upd(int k, int s, int e, int p, ll v){
		if(s+1==e){st[k]=v;return;}
		int m=(s+e)/2;
		if(p<m)upd(2*k,s,m,p,v);
		else upd(2*k+1,m,e,p,v);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	ll query(int k, int s, int e, int a, int b){
		if(s>=b||e<=a)return NEUT;
		if(a<=s&&e<=b)return st[k];
		int m=(s+e)/2;
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	void init(vector<ll> &a){init(1,0,n,a);}
	void upd(int p, ll v){upd(1,0,n,p,v);}
	ll query(int a, int b){return query(1,0,n,a,b);}
};// uso: STree name(n);name.init(a);name.upd(i,v);name.query(s,e);	

//BS on STree (put inside struct)
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

//STree ITERATIVO
typedef ll node;
node oper(node a, node b){return a+b;}
#define NEUT 0
struct STree{
	int n; vector<node>t;
	STree(int n):n(n),t(2*n+5,NEUT){}
	void upd(int p, node v){
		for(p+=n,t[p]=v;p>1;p>>=1)t[p>>1]=oper(t[p],t[p^1]);
	}
	node query(int l, int r){
		node res=NEUT;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)res=oper(res,t[l++]);
			if(r&1)res=oper(res,t[--r]);
		}
		return res;
	}
};

//init
void init(vector<ll>&a){
	assert(SZ(a)>=n);
	fore(i,0,n)t[i+n]=a[i];
	for(int s=1<<(32-__builtin_clz(n)),e=2*n;s>1;s>>=1,e=s<<1){
		for(int i=s;i<e;i+=2)t[i>>1]=oper(t[i],t[i^1]);
	}
}
//custom (soporta opers no conmutativas :D)
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
void init(vector<ll>&a){
	assert(SZ(a)>=n);
	fore(i,0,n)t[i+n]=node(a[i]);
	for(int s=1<<(32-__builtin_clz(n)),e=2*n;s>1;s>>=1,e=s<<1){
		for(int i=s;i<e;i+=2)t[i>>1]=oper(t[i],t[i^1]);
	}
}

// LAZY
#define NEUT 0
#define CLEAR 0 // cleared lazy node
ll oper(ll a, ll b){
	return a+b;
}
void acum(ll &a, ll v){ // accumulate lazy node
	a+=v;
}
ll calc(ll s, ll e, ll a, ll v){ // calculate STree range, a=previous value
	return a+(e-s)*v;
} 

struct STree{
	vector<ll>st,lazy; ll n;
	STree(ll n):st(4*n+5,NEUT),lazy(4*n+5,CLEAR),n(n){}
	void push(ll k, ll s, ll e){
		if(lazy[k]==CLEAR)return;
		st[k]=calc(s,e,st[k],lazy[k]);
		if(e-s!=1){
			acum(lazy[2*k],lazy[k]);
			acum(lazy[2*k+1],lazy[k]);
		}
		lazy[k]=CLEAR;
	}
	void upd(ll k, ll s, ll e, ll a, ll b, ll v){
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
	ll query(ll k, ll s, ll e, ll a, ll b){
		if(e<=a||b<=s)return NEUT;
		push(k,s,e);
		if(a<=s&&e<=b)return st[k];
		ll m=(s+e)/2;
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	void upd(ll a, ll b, ll v){upd(1,0,n,a,b,v);}
	ll query(ll a, ll b){return query(1,0,n,a,b);}
};

//custom (with normal single update)

typedef ll tn; // node type
typedef ll tl; // lazy type
tn unit(ll v){return v;}
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
	void init(ll k, ll s, ll e, vector<ll>&a){
		if(e-s==1)st[k]=unit(a[s]);
		else {
			ll m=(s+e)/2;
			init(2*k,s,m,a); init(2*k+1,m,e,a);
			st[k]=oper(st[2*k],st[2*k+1],k);
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
	tn query(ll k, ll s, ll e, ll a, ll b){
		if(e<=a||b<=s)return NEUT;
		push(k,s,e);
		if(a<=s&&e<=b)return st[k];
		ll m=(s+e)/2;
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	void upd(ll a, ll b, tl v){upd(1,0,n,a,b,v);}
	void upd(ll p, tn v){upd(1,0,n,p,v);}
	tn query(ll a, ll b){return query(1,0,n,a,b);}
};
//PERSISTENTE
struct STree{ //persistent
	vector<int>st,L,R; ll n,rt;
	STree(ll n): st(1,NEUT),L(1,0),R(1,0),n(n),rt(0){}
	ll new_node(ll v,ll l, ll r){
		ll ks=SZ(st);
		st.pb(v),L.pb(l),R.pb(r);
		return ks;
	}
	ll upd(ll k, ll s, ll e, ll p, ll v){
		ll ks=new_node(st[k],L[k],R[k]);
		if(s+1==e){st[ks]=v;return ks;}
		ll m=(s+e)/2,ps;
		if(p<m)ps=upd(L[ks],s,m,p,v),L[ks]=ps;
		else ps=upd(R[ks],m,e,p,v),R[ks]=ps;
		st[ks]=oper(st[L[ks]],st[R[ks]]);
		return ks;
	}
	ll query(ll k, ll s, ll e, ll a, ll b){
		if(a<=s&&e<=b)return st[k];
		if(e<=a||b<=s)return NEUT;
		ll m=(s+e)/2;
		return oper(query(L[k],s,m,a,b),query(R[k],m,e,a,b));
	}
	ll upd(ll k, ll p, ll v){return rt=upd(k,0,n,p,v);} // update on root k (first root is 0)
	ll upd(ll p, ll v){return upd(rt,p,v);} // update on last root
	ll query(ll k, ll a, ll b){return query(k,0,n,a,b);}
};

//FENWICK TREE
int ft[MAXN+1]; // for more dimensions, make ft multi-dimensional
void upd(int i0, int v){ // add v to i0th element (0-based)
	// add extra fors for more dimensions
	for(int i=i0+1;i<=MAXN;i+=i&-i)ft[i]+=v;
}
int get(int i0){ // get sum of range [0,i0)
	int r=0;
	// add extra fors for more dimensions
	for(int i=i0;i;i-=i&-i)r+=ft[i];
	return r;
}
int get_sum(int i0, int i1){ // get sum of range [i0,i1) (0-based)
	return get(i1)-get(i0);
}

struct FTree{
	vector<ll>ft; ll n;
	FTree(ll n):ft(n+5,0),n(n+5){}
	void upd(ll i0, ll v){
		for(ll i=i0+1;i<=n;i+=i&-i)ft[i]+=v;
	}
	ll get_sum(ll i0){
		ll res=0;
		for(ll i=i0;i>0;i-=i&-i)res+=ft[i];
		return res;
	}
	ll query(ll a, ll b){
		return get_sum(b)-get_sum(a);
	}
};

//2d
int ft[MAXN+1][MAXN+1];
void upd(int i0, int j0, int v){
	for(int i=i0+1;i<=MAXN;i+=i&-i)
	for(int j=j0+1;j<=MAXN;j+=j&-j)
		ft[i][j]+=v;
}
int get(int i0, int j0){
	int r=0;
	for(int i=i0;i;i-=i&-i)
	for(int j=j0;j;j-=j&-j)
		r+=ft[i][j];
	return r;
}
int get_sum(int i0, int j0, int i1, int j1){
	return get(i1,j1)-get(i1,j0)-get(i0,j1)+get(i0,j0);
}

//SPARSE TABLE
const ll K=18;//K such that 2^k>n
#define oper min
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
// might be better for multiple testcases
struct ST{
	ll n,K; vector<vector<ll>>st;
	ST(ll n):n(n),K(64-__builtin_clzll(n)),st(K,vector<ll>(1<<K)){}
	void init(vector<ll>& a){
		fore(i,0,n)st[0][i]=a[i];
		fore(k,1,K)fore(i,0,n-(1<<k)+1)
			st[k][i]=oper(st[k-1][i],st[k-1][i+(1<<(k-1))]);
	}
	ll query(ll s, ll e){
		ll k=63-__builtin_clzll(e-s);
	return oper(st[k][s],st[k][e-(1<<k)]);
	}
};

//PARTIAL SUMS 2D
fore(i,1,n+1)fore(j,1,n+1)sp[i][j]=a[i-1][j-1]+sp[i][j-1];
fore(i,1,n+1)fore(j,1,n+1)sp[i][j]+=sp[i-1][j];

//IN K-DIMENSIONS
//store initial values
//for dimension d in range(k): for all elements mk in order:
//	sp[mk]+=sp[mk-1 en d] //anterior en dimension d
//example (k bit dimensions):
fore(mk,0,1ll<<k)sp[mk]=a[mk];
fore(d,0,k)fore(mk,0,1ll<<k){
	if(mk&(1ll<<d))sp[mk]+=sp[mk^(1ll<<d)];
}

// Iterate over non empty subsets of bitmask
for(int s=m;s;s=(s-1)&m) // Decreasing order
for (int s=0;s=s-m&m;) 	 // Increasing order

//HASHING
#define bint __int128
struct Hash{
	bint MOD=212345678987654321LL,P=1777771,PI=106955741089659571LL;
	//P[5]={1444441,1777771,1234567,1242421,1010003};
	vector<bint>pi,h;//,pt;
	Hash(string& s){
		assert((P*PI)%MOD==1);
		pi.resize(SZ(s)+1),h.resize(SZ(s)+1);//,pt.resize(SZ(s)+1);
		pi[0]=1,h[0]=0;//,pt[0]=1;
		bint p=1;
		fore(i,1,SZ(s)+1){
			h[i]=(h[i-1]+s[i-1]*p)%MOD;
			pi[i]=(pi[i-1]*PI)%MOD;
			p=(p*P)%MOD;
			//pt[i]=p;
		}
	}
	ll get(ll s, ll e){
		return ((h[e]-h[s]+MOD)*pi[s])%MOD;
	}
};
/*ll con(ll h1, ll m, ll h2){
	return (h1+(bint(h2)*bint(pt[m]))%MOD)%MOD;
}*/
//for concatenation

//RANDOM
srand((ll)&n);//not assigned variable n
rand()%m;
random_shuffle(ALL(v));

ll rnd(){ // [0,2³⁰) in cf
	return ((1ll*rand())<<15)+rand();
}

//generate random tree O(n²)
vector<ll>a={0};
vector<ll>vis(n);
vis[0]=1;
vector<ii>ed;
fore(i,0,n-1){
	ll p=rand()%(n-1-i);
	fore(j,0,n){
		if(vis[j])continue;
		if(!p){
			ed.pb({a[rand()%SZ(a)],j});
			vis[j]=1;
			a.pb(j);
		}
		p--;
	}
}
//uniform distribution, mersenne twister
random_device rd;
mt19937 rng(rd());
uniform_int_distribution<int>dis(0,1000000000);
cout<<dis(rng)<<"\n"; //uniform
cout<<rng()<<"\n"; //range int

//UNORDERED MAP, CUSTOM HASH
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

//EXTENDED SET
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree
<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
indexed_set;
// find_by_order(i) -> iterator to ith element
// order_of_key(k) -> position (int) of lower_bound of k
//less_equal for repeated elements (erase only with pointer)


// find by order of STree version
// BS on SegTree for O(log) (find on SegTree recursivo)
ll pos(STree &st, ll p){ // log(n)**2, last element = p // upper bound -1
	ll l=0,r=st.n;
	while(l<=r){
		ll m=(l+r)/2;
		if(st.query(0,m)<p+1)l=m+1;
		else r=m-1;
	}
	return r;
}

//MATCHING EN GRAFO BIPARTITO
ll n,m;
vector<ll>g[MAXN]; // [0,n)->[0,m)
bool vis[MAXN];
ll mat[MAXN];
bool match(ll x){
	if(vis[x])return 0;
	vis[x]=1;
	for(auto i:g[x])if(mat[i]==-1||match(mat[i])){mat[i]=x; return 1;}
	return 0;
}
vector<ii> max_matching(){
	mset(mat,-1);
	vector<ii> res;
	fore(x,0,n)mset(vis,0),match(x);
	fore(i,0,m)if(mat[i]!=-1)res.pb({mat[i],i});
	return res;
}

//TARJAN
vector<ll> g[MAXN];//,g2[MAXN];set<ll> gst[MAXN];
ll n,n2,lw[MAXN],idx[MAXN],qidx,cmp[MAXN],qcmp;
stack<ll>st;

void tjn(ll u){
	lw[u]=idx[u]=++qidx;
	st.push(u); cmp[u]=-2;
	for(auto v:g[u]){
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
	fore(i,0,n)idx[i]=0,cmp[i]=-1;//,g2[i].clear();gst[i].clear();
	qidx=0; qcmp=0;
	/*mset(idx,0); // NO TEST CASES
	mset(cmp,-1);*/
	fore(i,0,n)if(!idx[i])tjn(i);
	//fore(i,0,n)for(auto j:g[i])if(cmp[i]!=cmp[j])gst[cmp[i]].insert(cmp[j]);
	//fore(i,0,n)for(auto j:gst[i])g2[i].pb(j);
	n2=qcmp;
}

//CENTROID DECOMPOSITION
bool tk[MAXN];
ll fat[MAXN];	// father in centroid decomposition 
ll szt[MAXN];	// size of subtree

ll calcsz(ll x, ll f){
	szt[x]=1;
	for(auto y:g[x])if(y!=f&&!tk[y])szt[x]+=calcsz(y,x);
	return szt[x];
}
void cdfs(ll x=0,ll f=-1,ll sz=-1){	// O(nlogn)
	if(sz==-1)sz=calcsz(x,-1);
	for(auto y:g[x])if(!tk[y]&&szt[y]*2>=sz){
		szt[x]=0;cdfs(y,f,sz);return;
	}
	fat[x]=f; tk[x]=1;
	for(auto y:g[x])if(!tk[y])cdfs(y,x);
}
void centroid(){mset(tk,0);cdfs();}

//TRIE
ll tr[MAXN][30], qidx=0; //MAXN = MAX NODES
ll add(ll x, char h){
	ll &res=tr[x][h-'a'];
	if(res)return res;
	else return res=++qidx;
}

//REROOTING
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


// (without inverse)
struct node{
	//element (if ll typedef)
	node(){}
};
#define NEUT
node merge(node a, node b){
	//merge subtree a and b
}
void level_up(node &x){// add edge
	//climb a level in tree
}

node h[MAXN],ch[MAXN]; //hijos, complement hijos
vector<node>pre[MAXN],suf[MAXN];//	[0,i)  ,  [i,n)
ll f[MAXN];
void subtree(ll x){
	for(auto y:g[x]){
		if(y==f[x])continue;
		f[y]=x;
		subtree(y);
		h[x]=merge(h[x],h[y]);
	}
	level_up(h[x]);
}
void father_subtree(ll x){
	fore(i,0,SZ(g[x])){
		ll y=g[x][i];
		if(y==f[x])continue;
		ch[y]=merge(merge(pre[x][i],suf[x][i+1]),ch[x]);
		level_up(ch[y]);
		father_subtree(y);
	}
}
void rerooting(ll n){
	fore(i,0,n){// clear if testcases
		h[i]=NEUT, ch[i]=NEUT; // MUST
		pre[i].clear();
		suf[i].clear();
	}
	subtree(0);
	fore(x,0,n){
		suf[x].resize(SZ(g[x])+1,NEUT);
		pre[x].resize(SZ(g[x])+1,NEUT);
		fore(i,1,SZ(g[x])+1){			
			ll y=g[x][i-1];
			if(y==f[x])pre[x][i]=pre[x][i-1];
			else pre[x][i]=merge(pre[x][i-1],h[y]);
		}
		for(ll i=SZ(g[x])-1;i>=0;i--){
			ll y=g[x][i];
			if(y==f[x])suf[x][i]=suf[x][i+1];
			else suf[x][i]=merge(suf[x][i+1],h[y]);
		}
	}
	father_subtree(0);
	// stores subtree in h and complement in ch
}

//SQRT DECOMPOSITION

//MOS
int n,sq,nq; // array size, sqrt(array size), #queries
struct qu{int l,r,id;};
qu qs[MAXN];
void init(){
	
}
void add(ll i){
	
}
void remove(ll i){
	
}
ll get_ans(){
	
}
ll ans[MAXN]; // ans[i] = answer to ith query
bool qcomp(const qu &a, const qu &b){
    if(a.l/sq!=b.l/sq) return a.l<b.l;
    return (a.l/sq)&1?a.r<b.r:a.r>b.r;
}
void mos(){
	init();
    fore(i,0,nq)qs[i].id=i;
    sq=sqrt(n)+.5;
    sort(qs,qs+nq,qcomp);
    int l=0,r=0;
    fore(i,0,nq){
        qu q=qs[i];
        while(l>q.l)add(--l);
        while(r<q.r)add(r++);
        while(l<q.l)remove(l++);
        while(r>q.r)remove(--r);
        ans[q.id]=get_ans();
    }
}
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

//BLOCKS STRUCTURES
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
};

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

//HLD

vector<int> g[MAXN];
int wg[MAXN],dad[MAXN],dep[MAXN]; // weight,father,depth
void dfs1(int x){
	wg[x]=1;
	for(int y:g[x])if(y!=dad[x]){
		dad[y]=x;dep[y]=dep[x]+1;dfs1(y);
		wg[x]+=wg[y];
	}
}
int curpos,pos[MAXN],head[MAXN];
void hld(int x, int c){
	if(c<0)c=x;
	pos[x]=curpos++;head[x]=c;
	int mx=-1;
	for(int y:g[x])if(y!=dad[x]&&(mx<0||wg[mx]<wg[y]))mx=y;
	if(mx>=0)hld(mx,c);
	for(int y:g[x])if(y!=mx&&y!=dad[x])hld(y,-1);
}
void hld_init(){dad[0]=-1;dep[0]=0;dfs1(0);curpos=0;hld(0,-1);}
int query(int x, int y, STree& rmq){
	int r=NEUT;
	while(head[x]!=head[y]){
		if(dep[head[x]]>dep[head[y]])swap(x,y);
		r=oper(r,rmq.query(pos[head[y]],pos[y]+1));
		y=dad[head[y]];
	}
	if(dep[x]>dep[y])swap(x,y); // now x is lca
	r=oper(r,rmq.query(pos[x],pos[y]+1));	// *
	return r;
}
// for updating: rmq.upd(pos[x],v);
// queries on edges: - assign values of edges to "child" node
//                   - change pos[x] to pos[x]+1 in query (line *)
//commutative support (needs <= O(log²) rev): (change only query)
node query(int x, int y, STree& rmq){
	node l=NEUT,r=NEUT;
	while(head[x]!=head[y]){
		if(dep[head[x]]>dep[head[y]]){
			l=oper(rmq.query(pos[head[x]],pos[x]+1),l);
			x=dad[head[x]];
		}
		else {
			r=oper(rmq.query(pos[head[y]],pos[y]+1),r);
			y=dad[head[y]];
		}
	}
	if(dep[x]>dep[y]){
		l=oper(rmq.query(pos[y],pos[x]+1),l);
	}
	else {
		r=oper(rmq.query(pos[x],pos[y]+1),r);	// *
	}
	return oper(rev(l),r);
}

//MOBIUS
short mu[MAXN] = {0,1};
void mobius(){
	fore(i,1,MAXN)if(mu[i])for(int j=i+i;j<MAXN;j+=i)mu[j]-=mu[i];
}

//MATRICES

//fast exponentiation
typedef vector<vector<ll>> Matrix;
Matrix ones(ll n){
	Matrix r(n,vector<ll>(n));
	fore(i,0,n)r[i][i]=1;
	return r;
}
Matrix operator*(Matrix a, Matrix b){	//no conmutativa
	ll n=SZ(a),m=SZ(b[0]),z=SZ(a[0]);
	Matrix r(n,vector<ll>(m));
	fore(i,0,n)fore(j,0,m)fore(k,0,z)r[i][j]=(r[i][j]+a[i][k]*b[k][j])%MOD;
	return r;
}
Matrix be(Matrix b, ll e){	//b tiene que ser cuadrada
	Matrix r=ones(SZ(b));
	while(e){if(e&1ll)r=r*b; b=b*b; e/=2;}
	return r;
}

//reduce in z_2
bool on(ll x, ll j){return (x&(1ll<<j))>0;}
void reduce(vector<ll> &x){ // z_2
	ll n=SZ(x),m=20;
	ll i=0,j=0;
	while(i<n&&j<m){
		if(!on(x[i],j)){
			fore(k,i+1,n)if(on(x[k],j)){
				swap(x[i],x[k]);
				break;
			}
		}
		if(!on(x[i],j)){j++;continue;}
		fore(k,i+1,n)if(on(x[k],j))x[k]^=x[i];
		i++,j++;
	}
	x.resize(i); //optional
}
//dynamically add rows
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
//add identity row with fixed height
bool on(ll x, ll j){return (x&(1ll<<j))>0;}
struct matrix{ // z_2
	vector<ll>x;
	ll m,d;
	matrix(){}
	matrix(ll v): x(20),m(20),d(0){
		if(v)x[__builtin_ctz(v)]=v,d++;
	}
	void add(ll v){
		if(v==0)return;
		ll w=-1;
		fore(j,0,m)if(on(v,j)){
			if(x[j])v^=x[j];
			else if(w==-1)w=j;
		}
		if(w!=-1)d++,x[w]=v;
	}
};

//CONVEX HULL TRICK
//(min, increasing insert coefficents, non increasing queries, online) 
//for maximum just change the sign of lines
ll idiv(ll a, ll b){ //int division
	if((a<0)^(b<0))return (a+b-1)/b; //ceil
	return a/b; //floor
}
struct ln{
	ll a,b;
	ln(ll a, ll b):a(a),b(b){}
	ll eq(ll x){return a*x+b;}
	pair<ll,ll> operator%(ln l){
		ll x=idiv(b-l.b,l.a-a);
		return {x,eq(x)};
	}
};
deque<ln>cht;
ll query(ll x){
	ln l=cht.back(); cht.pop_back();
	while(SZ(cht)&&l.eq(x)>=cht.back().eq(x))l=cht.back(),cht.pop_back();
	cht.pb(l);
	return cht.back().eq(x);
}
void insert(ln l){
	if(!SZ(cht)){
		cht.pb(l);
		return;
	}
	ln m=cht.front(); cht.pop_front();
	while(SZ(cht)&&((l%m).fst>(m%cht.front()).fst||l%m==m%cht.front()))
		m=cht.front(),cht.pop_front();
	cht.push_front(m), cht.push_front(l);
}

//FIRST SMALLER ELEMENT
vector<ll> fse(vector<ll>a, ll r=0){ //index of first smaller element to the left (-1 if none)
//for bigger change for condition, for right reverse a, then le, and indexes (n-1-x)
	ll n=SZ(a);
	if(r)reverse(ALL(a));
	vector<ll>le(n,-1);
	fore(i,0,n)for(le[i]=i-1;le[i]!=-1&&a[le[i]]>=a[i];le[i]=le[le[i]]);
	if(r){
		reverse(ALL(le));
		for(auto &i:le)i=n-1-i;
	}
	return le;
}

// DIVIDE AND CONQUER OPTIMIZATION
// sets dp[i]=min(f(i,j)) for all j, given that arg dp[i] <= arg dp[i+1]	O(nlogn)
void dnc(ll l, ll r, ll s, ll e){ // all [,)
	if(r-l<=0)return;
	ll m=(l+r)/2;
	ll opt=s;
	ll &res=dp[m];
	fore(j,s,e)if(f(m,j)<res)opt=j,resi=f(m,j);
	if(r-l>1)dnc(l,m,s,opt+1),dnc(m+1,r,opt,e);
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

//decompose range in O(log) subranges
vector<ll> dag[3*MAXN];
void add(ll x, ll y, ll t){
	if(!t)dag[x].pb(y); // down
	else dag[y].pb(x);  // up
}
ll cnt=0;
struct Rang{
	ll n,t; vector<ll>k;
	Rang(){}
	Rang(ll n, ll t):n(n),t(t),k(2*n+5){
		fore(i,0,n){
			k[i]=cnt++;
			k[i+n]=i;
		}
		fore(i,1,n){
			add(k[i],k[2*i],t);
			add(k[i],k[2*i+1],t);
		}
	}
	void query(ll l, ll r, ll c){
		for(l+=n,r+=n;l<r;l/=2,r/=2){
			if(l&1)add(c,k[l++],t);
			if(r&1)add(c,k[--r],t);
		}
	}
};

//EULERIAN PATH
//undirected
queue<ii> g[MAXN]; // graph with node, edge index
ii a[MAXM]; // array with m edges
ll vis[MAXM];
ll R[MAXM];
ll go(ll idx){
	ll x=a[idx].snd;
	while(SZ(g[x])){
		auto [y,i]=g[x].front(); g[x].pop();
		if(vis[i])continue;
		if(a[i].snd!=y)swap(a[i].fst,a[i].snd);
		R[idx]=i;
		vis[i]=1;
		return go(i);
	}
	return idx;
}
vector<ll> euler_path(ll s){
	ll flag=1;
	//ll cnt=0;
	//fore(i,0,n)cnt+=SZ(g[i])&1);
	//if(cnt!=0&&cnt!=2)flag=0; // condition for circuit/path
	ll idx=m;
	a[m]={-1,s}; // start
	a[m+1]={-1,-1}; // end
	R[m]=m+1;
	vis[idx]=1;
	while(idx!=m+1){
		ll rs=R[idx],e=go(idx);
		if(e==idx)idx=R[idx];
		else R[e]=rs;
	}
	fore(i,0,n)if(SZ(g[i]))flag=0;
	idx=m;
	vector<ll>res;
	while(idx!=m+1){
		if(SZ(res)&&a[idx].fst!=res.back())flag=0; // generic condition
		res.pb(a[idx].snd),idx=R[idx];
	}
	if(!flag)return {};
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

//SIMULATED ANNEALING
//For example, see https://codeforces.com/contest/1556/submission/244884389
//Tutorial blog: https://codeforces.com/blog/entry/94437
typedef vector<ll> node;
int value(node a){ //valor a minimizar
	
}
node vecino(node a){ //estado vecino, diametro del grafo chico <=50 o por ahi
	
}
node random_state(){ //random initial state
	
}
/*double temp(double p){
	
}*/
double P(ll old, ll now, double t){
	if(now<old)return 1.0;
	return exp((old-now)/t);
}
double t=1e5; //temperature, 1e9 or 1e5
node SA(){
	ll seed; srand((ll)&seed);
	node s=random_state();
	node best=s;
	//ll steps=0;
	while(clock()/(double)CLOCKS_PER_SEC<=1.99){ //time limit 2sec
		//double t=temp((clock()/(double)CLOCKS_PER_SEC)/1.99);
		node next=vecino(s);
		if(value(s)<value(best))best=s;
		if(P(value(s),value(next),t)>=(double)rand()/RAND_MAX)s=next;
		t*=0.99999;
		//steps++;
	}
	//cout<<"total steps "<<steps<<"\n";
	return best;
}
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
