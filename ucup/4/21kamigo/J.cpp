#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

int MOD;
const int MAXN=1e6+20;

int addmod(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int submod(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mulmod(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	int r=1;
	while(b){if(b&1)r=mulmod(r,a); b>>=1; a=mulmod(a,a);}
	return r;
}
int inv(int a){
	return fpow(a,MOD-2);
}

int f[MAXN],invv[MAXN],invf[MAXN];
int cmb(int n, int k){return n<k?0:mulmod(f[n],mulmod(invf[k],invf[n-k]));}
void init_facs(){	//call before using cmb!!
	invv[1]=1; fore(i,2,MAXN) invv[i]=mulmod(submod(0,MOD/i),invv[MOD%i]);
	f[0]=invf[0]=1;
	fore(i,1,MAXN) f[i]=mulmod(f[i-1],i), invf[i]=mulmod(invf[i-1],invv[i]);
}

// The maximum length of the resulting convolution vector is 2^LG
const int LG = 20;
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

// For modular convolutions modulo an arbitrary 32-bit modulus.
// Slightly slower than above versions, because it performs two calls to fft
poly multiply(const poly &v1, const poly &v2, ll m=MOD) {
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

poly get(vector<int> &a, int l, int r){
	if(l+1==r) return {submod(0,a[l]), 1};
	int m=(l+r)/2;
	poly aa=get(a,l,m);
	poly b=get(a,m,r);
	return multiply(aa,b);
}


// Assuming your convolution function is available in your environment:
// vector<int> conv_sunzi(const vector<int>& p, const vector<int>& q);

// Standard modular exponentiation
long long power(long long base, long long exp, int mod) {
    long long res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

// Finds a primitive root modulo P in O(sqrt(P) + log P)
int get_primitive_root(int p) {
    if (p == 2) return 1;
    int phi = p - 1, n = phi;
    vector<int> fact;
    
    // Factorize P - 1
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            fact.push_back(i);
            while (n % i == 0) n /= i;
        }
    }
    if (n > 1) fact.push_back(n);

    // Test candidates
    for (int res = 2; res <= p; ++res) {
        bool ok = true;
        for (int factor : fact) {
            if (power(res, phi / factor, p) == 1) {
                ok = false;
                break;
            }
        }
        if (ok) return res;
    }
    return -1;
}

// Evaluates C(x) = for all x from 0 to P-1
vector<int> multi_evaluate(int P, const vector<ll>& C) {
    // C holds standard coefficients: C[0] + C[1]*x + ...

    // ---------------------------------------------------------
    // STEP 2: Bluestein's Algorithm / Chirp-Z Transform
    // ---------------------------------------------------------
    int g = get_primitive_root(P);
    int inv_g = power(g, P - 2, P);
    int N = C.size() - 1; // Degree of polynomial

    vector<ll> A_prime(N + 1, 0);
    vector<ll> B(N + P, 0); 

    // Build A' array (reversed A)
    for (int i = 0; i <= N; ++i) {
        long long exp = (1LL * i * (i - 1) / 2) % (P - 1);
        int inv_g_pow = power(inv_g, exp, P);
        A_prime[N - i] = (1LL * C[i] * inv_g_pow) % P;
    }

    // Build B array
    for (int j = 0; j <= N + P - 2; ++j) {
        long long exp = (1LL * j * (j - 1) / 2) % (P - 1);
        B[j] = power(g, exp, P);
    }

    // Single convolution to process all evaluations simultaneously
    vector<ll> poly_C = multiply(A_prime, B);

    // ---------------------------------------------------------
    // STEP 3: Map results back to answers array
    // ---------------------------------------------------------
    vector<int> ans(P, 0);
    ans[0] = C[0]; // F(0) is simply the constant term

    int g_pow_k = 1; // Represents x = g^k
    for (int k = 0; k <= P - 2; ++k) {
        long long exp = (1LL * k * (k - 1) / 2) % (P - 1);
        int inv_g_pow = power(inv_g, exp, P);
        
        int val = 0;
        if (N + k < (int)poly_C.size()) {
            val = poly_C[N + k];
        }
        val = (1LL * val * inv_g_pow) % P; // Multiply by g^(-binom(k, 2))
        
        ans[g_pow_k] = (val % P + P) % P;
        
        g_pow_k = (1LL * g_pow_k * g) % P; // Move to next primitive root power
    }

    return ans;
}


int main(){FIN;
	int n,pp; cin>>n>>pp;
	MOD=pp;
	init_facs();

	vector<int> a(n);
	fore(i,0,n) cin>>a[i];

	auto den=get(a,0,n);

	vector<int> res(MOD);

	int m=0;
	for(auto x:a) m=max(x,m);

	vector<int> xx(MOD-m);
	fore(i,0,MOD-m) xx[i]=m+i;

	auto yy=multi_evaluate(pp,den);

	res[m]=1;
	fore(i,0,n) res[m]=mulmod(res[m], cmb(m, a[i]));

	fore(i,m+1,MOD){
		res[i]=mulmod(mulmod(fpow(i,n), res[i-1]), inv(yy[i]));
	}

	poly asd(MOD);
	fore(i,0,MOD) asd[i]=mulmod(fpow(MOD-1, i), invf[i]);

	poly asd2(MOD);
	fore(i,0,MOD) asd2[i]=mulmod(res[i], invf[i]);
	poly vv=multiply(asd,asd2);

	fore(i,0,SZ(vv)) vv[i]=mulmod(vv[i], f[i]);

	int ans=0;
	fore(i,0,SZ(vv)) ans=addmod(ans, vv[i]);

	cout<<ans<<"\n";
}
