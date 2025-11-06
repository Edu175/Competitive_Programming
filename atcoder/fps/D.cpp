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
typedef ll tf;
// The maximum length of the resulting convolution vector is 2^LG
const int LG = 21;
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
	// cout<<"conv "<<SZ(as)<<" "<<SZ(bs)<<endl;
	static uint32_t v[2<<LG];
	static FFT<uint32_t, uint64_t, 998244353, 3> fft;
	return fft.cv(as, bs, v);
}

// For modular convolutions modulo a 62 bit prime.
poly conv_big(const poly &as, const poly &bs) {
	static uint64_t v[2<<LG];
	static FFT<uint64_t, __uint128_t, (1ull<<62)-(18ull<<32)+1, 3> fft;
	return fft.cv(as, bs, v);
}

// For modular convolutions modulo an arbitrary 32-bit modulus.
// Slightly slower than above versions, because it performs two calls to fft
poly conv_sunzi(const poly &v1, const poly &v2, ll m) {
	const uint64_t inv = 2703402103339935109ull,
		mod1 = (1ull<<62)-(18ull<<32)+1,
		mod2 = (1ull<<62)-(76ull<<32)+1;
	static uint64_t v[2<<LG];
	static FFT<uint64_t, __uint128_t, mod1, 3> fft1;
	static FFT<uint64_t, __uint128_t, mod2, 17> fft2;
	auto as=fft1.cv(v1, v2, v), bs=fft2.cv(v1, v2, v);
	fore(i,0,SZ(as)){
		auto d = fft1.m(mod1+as[i]-bs[i], inv);
		d -= mod1*(d >= mod1); d %= m;
		as[i] = (bs[i] + mod2%m*d)%m;
	}
	return as;
}
#define multiply conv_small

const ll MOD=(119<<23)+1,MAXF=1e6+5;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	if(b<0)return 0;
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}

int inv(int a){return fpow(a,MOD-2);}
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
// Polynomial division: O(n*log(n))
// Multi-point polynomial evaluation: O(n*log^2(n))
// Polynomial interpolation: O(n*log^2(n))
// Inverse: O(n*log(n))
// Log: O(n*log(n))
// Exp: O(n*log(n))

//Works with NTT. For FFT, just replace add,sub,mul,inv
poly add(poly &a, poly &b){
	int n=SZ(a),m=SZ(b);
	poly ans(max(n,m));
	fore(i,0,max(n,m)) ans[i]=add(i<SZ(a)?a[i]:0, i<SZ(b)?b[i]:0);
	while(SZ(ans)>1&&!ans.back())ans.pop_back();
	return ans;
}

// derivative of p
poly derivate(poly &p){
	poly ans(max(1, SZ(p)-1));
	fore(i,1,SZ(p)) ans[i-1]=mul(p[i],i);
	return ans;
}

// integral of p
poly integrate(poly &p){
	poly ans(SZ(p)+1);
	fore(i,0,SZ(p)) ans[i+1]=mul(p[i], inv(i+1));
	return ans;
}

// p % (x^n)
poly takemod(poly &p, int n){
	poly res=p;
	res.resize(min(SZ(res),n));
	while(SZ(res)>1&&res.back()==0) res.pop_back();
	return res;
}

// first d terms of 1/p
poly invert(poly &p, int d){
	assert(p[0]);
	poly res={inv(p[0])};
	int sz=1;
	while(sz<d){
		sz*=2;
		poly pre(p.begin(), p.begin()+min(SZ(p),sz));
		poly cur=multiply(res,pre);
		fore(i,0,SZ(cur)) cur[i]=sub(0,cur[i]);
		cur[0]=add(cur[0],2);
		res=multiply(res,cur);
		res=takemod(res,sz);
	}
	res.resize(d);
	return res;
}

// first d terms of log(p)
poly log(poly &p, int d){
	assert(p[0]==1);
	poly cur=takemod(p,d);
	poly a=invert(cur,d), b=derivate(cur);
	auto res=multiply(a,b);
	res=takemod(res,d-1);
	res=integrate(res);
	return res;
}

// first d terms of exp(p)
poly exp(poly &p, int d){
	assert(!p[0]);
	poly res={1};
	int sz=1;
	while(sz<d){
		sz*=2;
		poly lg=log(res, sz), cur(sz);
		fore(i,0,sz) cur[i]=sub(i<SZ(p)?p[i]:0, i<SZ(lg)?lg[i]:0);
		cur[0]=add(cur[0],1);
		res=multiply(res,cur);
		res=takemod(res, sz);
	}
	
	res.resize(d);
	return res;
}

pair<poly,poly> divslow(poly &a, poly &b){ // O(n*m + logMOD)
	poly q,r=a;
	tf inve=inv(b.back());
	while(SZ(r)>=SZ(b)){
		q.pb(mul(r.back(),inve));
		if(q.back()) fore(i,0,SZ(b)){
			r[SZ(r)-i-1]=sub(r[SZ(r)-i-1],mul(q.back(),b[SZ(b)-i-1]));
		}
		r.pop_back();
	}
	reverse(ALL(q));
	return {q,r};
}

pair<poly,poly> divide(poly &a, poly &b){	//returns {quotient,remainder}
	int m=SZ(a),n=SZ(b),MAGIC=750;
	if(m<n) return {{0},a};
	if(min(m-n,n)<MAGIC)return divslow(a,b);
	poly ap=a; reverse(ALL(ap));
	poly bp=b; reverse(ALL(bp));
	bp=invert(bp,m-n+1);
	poly q=multiply(ap,bp);
	q.resize(SZ(q)+m-n-SZ(q)+1,0);
	reverse(ALL(q));
	poly bq=multiply(b,q);
	fore(i,0,SZ(bq)) bq[i]=sub(0,bq[i]);
	poly r=add(a,bq);
	return {q,r};
}

vector<poly> tree;

void filltree(vector<tf> &x){
	int k=SZ(x);
	tree.resize(2*k);
	fore(i,k,2*k) tree[i]={sub(0,x[i-k]),1};
	for(int i=k-1;i;i--) tree[i]=multiply(tree[2*i],tree[2*i+1]);
}

vector<tf> evaluate(poly &a, vector<tf> &x){
	filltree(x);
	int k=SZ(x);
	vector<poly> ans(2*k);
	ans[1]=divide(a,tree[1]).snd;
	fore(i,2,2*k) ans[i]=divide(ans[i>>1],tree[i]).snd;
	vector<tf> r; fore(i,0,k) r.pb(ans[i+k][0]);
	return r;
}

poly interpolate(vector<tf> &x, vector<tf> &y){
	filltree(x);
	poly p=derivate(tree[1]);
	int k=SZ(y);
	vector<tf> d=evaluate(p,x);
	vector<poly> intree(2*k);
	fore(i,k,2*k) intree[i]={mul(y[i-k],inv(d[i-k]))};
	for(int i=k-1;i;i--){
		poly p1=multiply(tree[2*i],intree[2*i+1]);
		poly p2=multiply(tree[2*i+1],intree[2*i]);
		intree[i]=add(p1,p2);
	}
	return intree[1];
}

poly fpow(poly a, ll b, ll n){
	poly r={1};
	while(b){
		// cerr<<"r\n";
		if(b&1)r=multiply(r,a);
		// cerr<<"a\n";
		b>>=1; a=multiply(a,a);
		a=takemod(a,n);
		assert(SZ(a)<=n);
		r=takemod(r,n);
	}
	return r;
}

ll stars(ll n, ll k){ // stars and balls, n bolitas, k cajitas,
	return nCr(n+k-1,n);
}

int main(){FIN;
	factos();
	ll n,m; cin>>n>>m;
	ll res=0;
	fore(c,n-1,n+1){
		ll q=m-c;
		if(q<0)continue;
		q/=2;
		ll cur=stars(q,n+1);
		res=add(res,cur);
	}
	res=mul(res,fc[n]);
	cout<<res<<"\n";
	return 0;
}
