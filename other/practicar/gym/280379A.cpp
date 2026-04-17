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
template<class x> ostream & operator<<(ostream & out, vector<x> v){
    out<<"{ ";
    for(auto y : v) out<<y<<" ";
    out<<"}";
    return out;
}
// The maximum length of the resulting convolution vector is 2^LG
const int LG = 12;
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
ll MOD,m;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}

void takemod(vv &a){ // mod x^m-1
	if(SZ(a)>m){
		vv c(m);
		fore(i,0,SZ(a))c[i%m]=add(c[i%m],a[i]);
		a=c;
	}
	while(SZ(a)>1&&!a.back())a.pop_back();
}
vv add(vv a, vv b){
	vv c(max(SZ(a),SZ(b)));
	fore(i,0,SZ(a))c[i]=add(c[i],a[i]);
	fore(i,0,SZ(b))c[i]=add(c[i],b[i]);
	takemod(c);
	return c;
}
vv mul(vv a, vv b){
	// vv c(SZ(a)+SZ(b)-1);
	// fore(i,0,SZ(a))fore(j,0,SZ(b))c[i+j]=add(c[i+j],mul(a[i],b[j]));
	vv c=conv_sunzi(a,b,MOD);
	takemod(c);
	return c;
}

vv fpow(vv a, ll b){
	if(b<0)return {0};
	vv r={1};
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}

ll fpow(ll a, ll b){
	if(b<0)return 0;
	ll r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
int main(){FIN;
	ll n,r; cin>>n>>m>>r>>MOD;
	vv coef(m-r+1); coef[m-r]=1;
	vv rhs={1,1};
	rhs=fpow(rhs,n);
	vv res=mul(coef,rhs);
	cerr<<res<<": ";
	cout<<mul(res[0],m)<<"\n";
	ll rt=258648936;
	ll num=0,pot=1;
	fore(i,0,m){
		if(i<SZ(res))num=add(num,mul(pot,res[i]));
		pot=mul(pot,rt);
	}
	cerr<<pot<<": "<<num<<"\n";
	return 0;
}