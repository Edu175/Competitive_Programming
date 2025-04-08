#define forsn(i,s,n) for(int i = int(s);i<int(n);i++)
#define dforsn(i,s,n) for(int i = int(n)-1;i>=int(s);i--)
#define fore(i,s,n) forsn(i,s,n)
#define forn(i,n) forsn(i,0,n)
#define dforn(i,n) dforsn(i,0,n)
#define SZ(v) int(v.size())

// The maximum length of the resulting
// convolution vector is 2^LG
const int LG = 14;

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
		dforn(i, 2<<LG) r[i]=red(p, m(r[i+1], k)), i&(i-1)?0:k=m(k,k);
		assert(r[2] != r[3]); assert(r[1] == r[2]);
	}
	vector<ll> cv(const vector<ll> &as, const vector<ll> &bs, u *v) {
		int c=max(SZ(as)+SZ(bs)-1, 0), n=1;
		assert(c <= (1<<LG));
		u h=u(uu(-p)*-p%p), a=m(h, p/2+1), x, y;
		while(n<c) n*=2, h=red(p, m(h, a));
		forn(i, n)
			v[i] = i<SZ(as) ? u(as[i]) : 0,
			v[i+n] = i<SZ(bs) ? u(bs[i]) : 0;
		for(auto s:{v,v+n})
		dforsn(j, 2, n+1) for(int k=j&-j; k/=2;) forsn(i, j-k, j)
			x=s[i], y=s[i-k],
			s[i-k] = red(2*p, x+y),
			s[i] = m(2*p+y-x, r[3*k-j+i]);
		forn(i, n) v[i] = m(v[i], v[i+n]);
		forsn(j, 2, n+1) for(int k=1; !(k&j); k*=2) forsn(i, j-k, j)
			x = m(v[i], r[3*k+j-i]),
			y = red(2*p, v[i-k]),
			v[i-k]=x+y, v[i]=2*p+y-x;
		forn(i, c) v[i] = red(p, m(v[i], h));
		return vector<ll>(v, v+c);
	}
};

// For modular convolutions modulo 998244353:
vector<ll> conv_small(const vector<ll> &as, const vector<ll> &bs) {
	static uint32_t v[2<<LG];
	static FFT<uint32_t, uint64_t, 998244353, 3> fft;
	return fft.cv(as, bs, v);
}