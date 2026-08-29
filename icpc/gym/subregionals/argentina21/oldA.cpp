#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define forr(i,a,b) for(ll i=(b)-1,jet=a;i>=jet;--i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {cout<<#v<<": ";for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
// #pragma GCC optimize("Ofast") // may lead to precision errors
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

// The maximum length of the resulting convolution vector is 2^LG
const int LG = 14;
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
const ll MOD=1e9+7;
poly multiply1(const poly &v1, const poly &v2) { // modulo MOD
	const uint64_t inv = 2703402103339935109ull,
	mod1 = (1ull<<62)-(18ull<<32)+1,
	mod2 = (1ull<<62)-(76ull<<32)+1;
	static uint64_t v[2<<LG];
	static FFT<uint64_t, __uint128_t, mod1, 3> fft1;
	static FFT<uint64_t, __uint128_t, mod2, 17> fft2;
	auto as=fft1.cv(v1, v2, v), bs=fft2.cv(v1, v2, v);
	fore(i,0,SZ(as)){
		auto d = fft1.m(mod1+as[i]-bs[i], inv);
		d -= mod1*(d >= mod1); d %= MOD;
		as[i] = (bs[i] + mod2%MOD*d)%MOD;
	}
	return as;
}
poly multiply2(const poly &v1, const poly &v2){
	poly ans(SZ(v1)+SZ(v2)-1);
	fore(i,0,SZ(v1))fore(j,0,SZ(v2))ans[i+j]=(ans[i+j]+v1[i]*v2[j])%MOD;
	return ans;
}
const ll MAGIC=1e4;

poly multiply(const poly &v1, const poly &v2){
	if(ll(SZ(v1))*SZ(v2)<MAGIC) return multiply2(v1,v2);
	return multiply1(v1,v2);
}


int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	if(b<0)return 0;
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
const ll MAXF=5005;
ll fc[MAXF],fci[MAXF];
void factos(){
	fc[0]=1;
	fore(i,1,MAXF)fc[i]=mul(fc[i-1],i);
	fci[MAXF-1]=fpow(fc[MAXF-1],MOD-2);
	for(ll i=MAXF-2;i>=0;i--)fci[i]=mul(fci[i+1],(i+1));
}

int main(){FIN;
	factos();
	ll n,R; cin>>n>>R;
	vv a(n);
	fore(i,0,n)cin>>a[i],a[i]=R-a[i]+1; // r[i] = [0,a[i])
	for(ll i=n-2;i>=0;i--)a[i]=min(a[i],a[i+1]);
	if(a[0]<0){
		cout<<"0\n";
		return 0;
	}
	auto vals=a; vals.resize(unique(ALL(vals))-vals.begin());
	ll m=SZ(vals);
	vv d(m); fore(i,0,SZ(d))d[i]=vals[i]-(!i?0:vals[i-1]);
	// show(a);
	// show(d);
	vector<vv> dp(2,vv(n+1));
	dp[m&1][n]=1;
	forr(v,0,m){
		auto &ac=dp[v&1];
		auto &otr=dp[(v+1)&1];
		ll l=n;
		fore(i,0,n)if(a[i]>=vals[v]){l=i;break;}
		vv c(n-l+1);
		c[0]=1;
		fore(i,1,SZ(c))c[i]=mul(d[v]+i-1,c[i-1]);
		fore(i,0,SZ(c))c[i]=mul(c[i],fci[i]);
		// show(c)
		reverse(ALL(c));
		
		ll s=n;
		fore(i,0,n+1)if(otr[i]){s=i;break;}
		vv pol(otr.begin()+s,otr.end());
		
		// cerr<<"l "<<l<<"\n";
		auto got=multiply(c,pol);
		// show(got)
		ac=vv(n+1);
		fore(i,l,n+1)ac[i]=got[SZ(c)-1-s+i];
		// cout<<v<<": ";
		// show(ac)
	}
	cout<<dp[0][0]<<"\n";
	return 0;
}
