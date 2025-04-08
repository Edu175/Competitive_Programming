// AC
#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<int> vv;
#define forsn(i,s,n) for(int i = int(s);i<int(n);i++)
#define dforsn(i,s,n) for(int i = int(n)-1;i>=int(s);i--)
#define forn(i,n) forsn(i,0,n)
#define dforn(i,n) dforsn(i,0,n)

// The maximum length of the resulting
// convolution vector is 2^LG
const int LG = 21;

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
const int MAXV=1e6+5;
bool good(vv a, ll k){
	// cout<<"good ";
	// for(auto i:a)cout<<i<<" ";;cout<<": ";
	vector<ll> c(MAXV);
	for(auto i:a)c[i]++;
	fore(i,0,MAXV)c[i]=min(c[i],3ll);
	ll ban=k%3==0&&k/3<MAXV?c[k/3]:0;
	fore(i,0,MAXV){
		ll j=k-2*i;
		if(j>=0&&j<MAXV)ban+=3*c[i]*(c[j]-(j==i)); 
	}
	auto d=conv_small(c,c);
	ll res=0;
	fore(i,0,MAXV){
		ll j=k-i;
		if(j>=0&&j<SZ(d))res+=c[i]*d[j];
	}
	res-=ban;
	// cout<<res<<"\n";
	return res>0;
}
bool good2(vv a, ll k){
	vv c(MAXV);
	for(auto i:a)c[i]++;
	fore(i,0,MAXV)if(c[i]){
		ll j=k-i;
		if(j>=0&&j<MAXV&&c[j]&&(i!=j||c[j]>1))return 1;
	}
	return 0;
}

int main(){FIN;
	int n,k; cin>>n>>k; ll _k=k;
	vv a(n);
	fore(i,0,n)cin>>a[i];
	if(!good(a,k)){
		cout<<"-1\n";
		return 0;
	}
	int l=0,r=n-1;
	while(l<=r){
		int m=(l+r)/2;
		vv b;
		fore(i,0,m+1)b.pb(a[i]);
		if(good(b,k))r=m-1;
		else l=m+1;
	}
	int e=l;
	k-=a[l];
	assert(k>0);
	l=0,r=e-1;
	while(l<=r){
		int m=(l+r)/2;
		vv b;
		fore(i,m,e)b.pb(a[i]);
		if(good2(b,k))l=m+1;
		else r=m-1;
	}
	int s=r;
	k-=a[s];
	assert(k>0);
	int m=-1;
	fore(i,s+1,e)if(a[i]==k)m=i;
	cout<<s+1<<" "<<m+1<<" "<<e+1<<"\n";
	// cout<<endl;
	assert(_k==a[s]+a[m]+a[e]);
	return 0;
}
