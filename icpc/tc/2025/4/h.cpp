#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define forr(i,a,b) for(ll i=(b)-1,jet=a;i>=jet;i--)
#define fst first
#define snd second
#define pb push_back
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MOD=998244353;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	if(b<0)return 0;
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}

// CHARLES-FFT

const int LG = 19;

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
	constexpr u red(u k, u a) { return a-k*(a>=k); }
	FFT() {
		u k = r[2<<LG] = -p%p, b=root, e = p>>LG;
		for(; e; e/=2, b=m(b,b)) if(e%2) k=m(k, b);
		forr(i, 0, 2<<LG) r[i]=red(p, m(r[i+1], k)), i&(i-1)?0:k=m(k,k);
		assert(r[2] != r[3]); assert(r[1] == r[2]);
	}
	vector<ll> cv(const vector<ll> &as, const vector<ll> &bs, u *v) {
		int c=max(SZ(as)+SZ(bs)-1, 0ll), n=1;
		assert(c <= (1<<LG));
		u h=u(uu(-p)*-p%p), a=m(h, p/2+1), x, y;
		while(n<c) n*=2, h=red(p, m(h, a));
		fore(i, 0, n)
			v[i] = i<SZ(as) ? u(as[i]) : 0,
			v[i+n] = i<SZ(bs) ? u(bs[i]) : 0;
		for(auto s:{v,v+n})
		forr(j, 2, n+1) for(int k=j&-j; k/=2;) fore(i, j-k, j)
			x=s[i], y=s[i-k],
			s[i-k] = red(2*p, x+y),
			s[i] = m(2*p+y-x, r[3*k-j+i]);
		fore(i, 0, n) v[i] = m(v[i], v[i+n]);
		fore(j, 2, n+1) for(int k=1; !(k&j); k*=2) fore(i, j-k, j)
			x = m(v[i], r[3*k+j-i]),
			y = red(2*p, v[i-k]),
			v[i-k]=x+y, v[i]=2*p+y-x;
		fore(i, 0, c) v[i] = red(p, m(v[i], h));
		return vector<ll>(v, v+c);
	}
};

// For modular convolutions modulo 998244353:
vector<ll> conv_small(const vector<ll> &as, const vector<ll> &bs) {
	static uint32_t v[2<<LG];
	static FFT<uint32_t, uint64_t, 998244353, 3> fft;
	return fft.cv(as, bs, v);
}

// For modular convolutions modulo a 62 bit prime:
vector<ll> conv_big(const vector<ll> &as, const vector<ll> &bs) {
	static uint64_t v[2<<LG];
	static FFT<uint64_t, __uint128_t, (1ull<<62)-(18ull<<32)+1, 3> fft;
	return fft.cv(as, bs, v);
}

// For modular convolutions modulo an arbitrary 32-bit modulus:
vector<ll> conv_sunzi(const vector<ll> &v1, const vector<ll> &v2, ll m) {
	const uint64_t inv = 2703402103339935109ull,
		mod1 = (1ull<<62)-(18ull<<32)+1,
		mod2 = (1ull<<62)-(76ull<<32)+1;
	static_assert(__uint128_t(inv)*mod2%mod1 == (-mod1)%mod1);
	static uint64_t v[2<<LG];
	static FFT<uint64_t, __uint128_t, mod1, 3> fft1;
	static FFT<uint64_t, __uint128_t, mod2, 17> fft2;
	auto as=fft1.cv(v1, v2, v), bs=fft2.cv(v1, v2, v);
	fore(i, 0, SZ(as)) {
		auto d = fft1.m(mod1+as[i]-bs[i], inv);
		d -= mod1*(d >= mod1); d %= m;
		as[i] = (bs[i] + mod2%m*d)%m;
	}
	return as;
}

int main(){
	JET
	ll n; cin>>n;
	vv z(n);
	fore(i,1,n){
		ll u,v; cin>>u>>v; u--,v--;
		z[u]++,z[v]++;
		z[i]--; // saco el padre de i
	}
	vector<vv>ps;
	fore(i,0,n)ps.pb({1,z[i]});
	
	while(SZ(ps)>1){
		vector<vv> psi;
		for(ll i=0;i<SZ(ps);i+=2){
			psi.pb(i==SZ(ps)-1?ps[i]:conv_small(ps[i],ps[i+1]));
		}
		swap(ps,psi);
	}
	auto p=ps[0];
	
	ll res=0;
	vv fc(n+1,1);
	fore(i,1,n+1)fc[i]=mul(i,fc[i-1]);
	fore(k,0,n){
		ll term=mul(fc[n-k],p[k]);
		res=(k&1?sub:add)(res,term);
	}
	cout<<res<<"\n";
	return 0;
}