#include <bits/stdc++.h> 
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define snd second 
#define fst first
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll) x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef long double ld;
typedef __int128 xl;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

const int LG = 19;
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
		int c=max(SZ(as)+SZ(bs)-1, 0ll), n=1;
		assert(c <= (1<<LG));
		u h=u(uu(-p)*-p%p), a=m(h, p/2+1), x, y;
		while(n<c) n*=2, h=red(p, m(h, a));
		fore(i,0,n){
			v[i]=i<SZ(as)?u(as[i]+p*(as[i]<0)):0,
			v[i+n]=i<SZ(bs)?u(bs[i]+p*(bs[i]<0)):0;

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
xl cv(xl a, xl m){
	if(a>m/2)a-=m;
	return a;
}
// vector<xl> conv_small(const poly &as, const poly &bs){
// 	static uint32_t v[2<<LG];
// 	static FFT<uint32_t, __uint64_t, 998244353,3> fft;
// 	poly res=fft.cv(as,bs,v);
// 	vector<xl> ans(SZ(res));
// 	fore(i,0,SZ(res))ans[i]=cv(res[i],998244353);
// 	cout<<"ans: ";for(auto i:ans)cout<<ll(i)<<" ";;cout<<"\n";
// 	return ans;
// }
vector<xl> conv_sunzi(const poly &v1, const poly &v2, xl m){
	const uint64_t inv=2703402103339935109ull,
		mod1= (1ull<<62)-(18ull<<32)+1,
		mod2= (1ull<<62)-(76ull<<32)+1;
	cerr<<"mod1 "<<mod1<<"\n";
	cerr<<"mod2 "<<mod2<<"\n";
	assert(mod1>mod2);
	static uint64_t v[2<<LG];
	static FFT<uint64_t, __uint128_t, mod1, 3> fft1;
	static FFT<uint64_t, __uint128_t, mod2, 17> fft2;
	auto as=fft1.cv(v1,v2,v),bs=fft2.cv(v1,v2,v);
	cout<<"as: ";for(auto i:as)cout<<i<<" ";;cout<<"\n";
	cout<<"bs: ";for(auto i:bs)cout<<i<<" ";;cout<<"\n";
	vector<xl> res(SZ(as));
	fore(i,0,SZ(as)){
		// auto d=(xl(5*xl(mod1)+as[i]-bs[i])*inv)%mod1;
		auto d=fft1.m(mod1+as[i]-bs[i],inv);
		d-=mod1*(d>=mod1);d%=m;
		
		res[i]=(bs[i]+mod2%m*d)%m;
		
		cerr
		
		// d-=mod1*(d>=mod1);
		// cerr<<(d>LLONG_MAX)<<" bool\n";
		// res[i]=(bs[i]+xl(mod2)*d);
	}
	return res;
}
vector<xl> multiply2(poly a, poly b){
	vector<xl> c(SZ(a)+SZ(b)-1);
	fore(i,0,SZ(a))fore(j,0,SZ(b))c[i+j]+=xl(a[i])*b[j];
	return c;
}
vector<xl> operator+(vector<xl> a, vector<xl> b){
	assert(SZ(a)==SZ(b));
	fore(i,0,SZ(a))a[i]+=b[i];
	return a;
}
// vector<xl> operator*(ll t, vector<xl> a){
// 	fore(i,0,SZ(a))a[i]*=t;
// 	return a;
// }
// const tf EPS = 1e-6;
// xl M=xl(1)<<20;
xl M=10000;
int main(){
	JET
	ll n; cin>>n;
	poly xs(n),ys(n);
	fore(i,0,n)cin>>xs[i]>>ys[i];
	auto b=ys; reverse(ALL(b));
	auto c1=conv_sunzi(xs,b,M);
	b=xs; reverse(ALL(b));
	auto c2=conv_sunzi(ys,b,M);
	auto c=c1+c2;
	vector<xl> coef(n);
	cout<<"c: ";
	fore(k,0,SZ(c)){
		cout<<(ll)c[k]<<" ";
		ll d=k-(n-1);
		if(d<0)d+=n;
		coef[d]+=c[k];
	}
	cout<<"\n";
	// assert(coef[0]<EPS);
	xl res=0;
	fore(k,1,n){
		res+=(n-k-1)*coef[k];
		// cout<<k<<": "<<coef[k]<<"\n";
	}
	auto cruz=[&](ll i, ll j){return xs[i]*ys[j]-ys[i]*xs[j];};
	// auto dbg=[&](){
	// 	cout<<"dbg\n";
	// 	fore(k,0,n){
	// 		tf res=0;
	// 		fore(i,0,n){
	// 			ll j=(i+k)%n;
	// 			res+=cruz(i,j);
	// 		}
	// 		cout<<k<<": "<<res<<" "<<coef[k]<<endl;
	// 		assert(abs(res-coef[k])<EPS);
	// 	}
	// };
	// dbg(); // ============================================
	xl tot=0;
	fore(i,0,n){
		ll j=(i+1)%n;
		tot+=cruz(i,j);
	}
	ld ans=ld(res)/tot;
	cout<<fixed<<setprecision(15)<<ans<<"\n";
	return 0;
}
