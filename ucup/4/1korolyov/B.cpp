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

const ll MAXN=1e5+5;

// The maximum length of the resulting convolution vector is 2^LG
const int LG = 18;
typedef vector<ll> poly;

template<class u, class uu, u p, u root>
struct FFT {
	u r[1+(2<<LG)];
	constexpr u m(u a, u b) {
		uu k = uu(a)*b;
		#define op(g) g*(g*p+2)
		k += u(k) * (op(op(op(op(op(-p)))))) * uu(p);
		#undef op
		return u(k>>(8*sizeof(u)));
	}
	constexpr u red(u k, u a){return a-k*(a>=k);}
	FFT() {
		u k=r[2<<LG]=-p%p, b=root, e=p>>LG;
		for(;e;e/=2,b=m(b,b)) if(e&1) k=m(k,b);
		for(int i=(2<<LG)-1;i>=0;i--) r[i]=red(p, m(r[i+1], k)), i&(i-1)?0:k=m(k,k);
	}
	poly cv(const poly &as, const poly &bs, u *v) {
		int c=max(SZ(as)+SZ(bs)-1, 0), n=1;
		assert(c <= (1<<LG));
		u h=u(uu(-p)*-p%p), a=m(h, p/2+1), x, y;
		while(n<c) n*=2, h=red(p, m(h, a));
		fore(i,0,n){
			v[i]=i<SZ(as)?u(as[i]):0,
			v[i+n]=i<SZ(bs)?u(bs[i]):0;

		}
		for(auto s:{v,v+n}) for(int j=n;j>=2;j--) for(int k=j&-j; k/=2;) fore(i,j-k,j){
			x=s[i], y=s[i-k];
			s[i-k] = red(2*p, x+y);
			s[i] = m(2*p+y-x, r[3*k-j+i]);
		}
		fore(i,0,n) v[i]=m(v[i], v[i+n]);
		fore(j,2,n+1) for(int k=1; !(k&j); k*=2) fore(i,j-k,j){
			x = m(v[i], r[3*k+j-i]);
			y = red(2*p, v[i-k]);
			v[i-k]=x+y, v[i]=2*p+y-x;
		}
		fore(i,0,c) v[i]=red(p, m(v[i], h));
		return poly(v, v+c);
	}
};

// For modular convolutions modulo 998244353.
// Replace with any NTT-friendly mod by doing:
// FFT<uint32_t, uint64_t, MOD, primitiveRoot(MOD)>
poly conv_small(const poly &as, const poly &bs) {
	static uint32_t v[2<<LG];
	static FFT<uint32_t, uint64_t, 998244353, 3> fft;
	return fft.cv(as, bs, v);
}
// MY
const ll MOD=998244353,MAXF=1e6+5;
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

// tag[y]>=tag[rt] for every y in rt's connected subgraph (unrooted subtree)
vector<int> g[MAXN];
int tag[MAXN]; // time of discovery of centroid
int fat[MAXN]; // father in centroid decomposition
int szt[MAXN]; // size of subtree
int calcsz(int x, int f){
	szt[x]=1;
	for(auto y:g[x])if(y!=f&&tag[y]<0)szt[x]+=calcsz(y,x);
	return szt[x];
}
int ccnt=0;
void cdfs(int x, int f, int sz=-1){ // O(nlogn)
	if(sz<0)sz=calcsz(x,-1);
	for(auto y:g[x])if(tag[y]<0&&szt[y]*2>=sz){
		szt[x]=0;cdfs(y,f,sz);return;
	}
	tag[x]=ccnt++; fat[x]=f;
	for(auto y:g[x])if(tag[y]<0)cdfs(y,x);
}
void centroid(){mset(tag,-1);ccnt=0;cdfs(0,-1);}


ll rt;
vv hist;
ll D[MAXN];
void dfs(ll x, ll fa){
	if(D[x]>=SZ(hist))hist.resize(D[x]+1);
	hist[D[x]]++;
	for(auto y:g[x])if(tag[y]>=tag[rt]&&y!=fa){
		D[y]=D[x]+1;
		dfs(y,x);
	}
}

vv operator+(vv &a, vv &b){
	vv c(max(SZ(a),SZ(b)));
	fore(i,0,SZ(a))c[i]=add(c[i],a[i]);
	fore(i,0,SZ(b))c[i]=add(c[i],b[i]);
	return c;
}

void cut(vv &p){
	while(SZ(p)&&!p.back())p.pop_back();
}

vv cp(MAXN);
ll n;
void doit(ll anc){
	vector<vv> ps={{1}}; // el anc
	rt=anc;
	for(auto y:g[anc])if(tag[y]>=tag[rt]){
		hist.clear();
		D[y]=1;
		dfs(y,anc);
		ps.pb(hist);
	}
	vv sum;
	for(auto i:ps)sum=sum+i;
	vv ret=conv_small(sum,sum);
	for(auto p:ps){
		vv sac=conv_small(p,p);
		fore(i,0,SZ(sac))ret[i]=sub(ret[i],sac[i]);
	}
	cut(ret);
	assert(SZ(ret)<=n);
	for(auto &i:ret)i=mul(i,(MOD+1)/2);
	fore(i,0,SZ(ret))if(ret[i])cp[i]=add(cp[i],ret[i]);
	// cout<<"doit "<<anc<<":\n";
	// for(auto i:ps)imp(i)
	// cout<<"=\n";
	// imp(ret)
	// cout<<"\n";
}

ll fac(ll n){return n<0?0:fc[n];}
ll faci(ll n){return n<0?0:fci[n];}

int main(){FIN;
	factos();
	cin>>n;
	fore(i,0,n-1){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	centroid();
	fore(x,0,n)doit(x);
	// fore(k,0,n+3)cout<<cp[k]<<" ";;cout<<"\n";
	
	// cout<<endl;
	assert(!cp[0]);
	
	vv pold(n+3),polkd(n+3);
	fore(i,0,SZ(pold))pold[i]=mul(cp[i],fac(n-i-1));
	fore(i,0,SZ(polkd))polkd[i]=faci(i);
	
	vv ret=conv_small(pold,polkd);
	
	fore(k,1,n+1){
		ll coef=mul(fac(k),faci(n-2-k));
		ll got=ret[k+1];
		ll res=mul(coef,got);
		cout<<res<<" ";
	}
	cout<<"\n";
	return 0;
}
