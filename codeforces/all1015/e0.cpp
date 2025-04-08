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
typedef int ll;
typedef long long LL;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
const ll MOD=1e9+7,MAXF=1e4+5;
#define forsn(i,s,n) for(int i = int(s);i<int(n);i++)
#define dforsn(i,s,n) for(int i = int(n)-1;i>=int(s);i--)
#define forn(i,n) forsn(i,0,n)
#define dforn(i,n) dforsn(i,0,n)
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
	vector<u> cv(const vector<u> &as, const vector<u> &bs, u *v) {
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
		return vector<u>(v, v+c);
	}
};

// For modular convolutions modulo 998244353:
vector<uint32_t> conv_small(const vector<uint32_t> &as, const vector<uint32_t> &bs) {
	static uint32_t v[2<<LG];
	static FFT<uint32_t, uint64_t, 65537, 3> fft;
	return fft.cv(as, bs, v);
}
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(LL a, LL b){return a*b%MOD;}
int fpow(int a, LL b){
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


int main(){FIN;
	factos();
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n),p(n);
		ll k=0;
		fore(i,0,n){
			cin>>a[i],k+=a[i]==-1;
			if(a[i]!=-1)p[a[i]]=i;
		}
		ll res=0;
		fore(x,1,n+1){ // aparecen [0,x)
			vv bl(n),lib(n); ll hay=0;
			fore(i,0,n)
				bl[i]=a[i]!=-1&&a[i]<x,lib[i]=a[i]==-1,hay+=bl[i];
			ll s=0,cnt=0;
			vector<uint32_t> l(k+1),r(k+1);
			fore(i,0,n+1){
				// )
				if(cnt==0)l[s]++;
				if(cnt==hay)r[s]++;
				if(i<n)s+=lib[i],cnt+=bl[i];
			}
			reverse(ALL(r));
			auto c=conv_small(l,r);
			c.resize(SZ(r)); reverse(ALL(c));
			ll resi=0;
			fore(z,0,SZ(c)){
				ll num=c[z];
				ll obj=x-hay;
				ll ceb=mul(nCr(k-obj,z-obj),mul(fc[z],fc[k-z]));
				// cout<<z<<" "<<obj<<": "<<num<<" "<<ceb<<": "<<mul(ceb,num)<<"\n";
				resi=add(resi,mul(ceb,num));
			}
			// cout<<x<<": "<<resi<<"\n";
			res=add(res,resi);
		}
		cout<<res<<"\n";
	}
	return 0;
}
