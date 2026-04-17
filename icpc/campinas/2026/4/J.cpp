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

// For modular convolutions modulo 998244353.
poly conv_small(const poly &as, const poly &bs) {
	static uint32_t v[2<<LG];
	static FFT<uint32_t, uint64_t, 998244353, 3> fft;
	return fft.cv(as, bs, v);
}

const ll MAXN=2e5+5;

ll wh[MAXN],ans[MAXN];

void f(ll l, ll r, vv p){ // desired coef is p.back()
	ll c=r-l;
	if(SZ(p)>c+1)p.erase(p.begin(),p.end()-(c+1)); // use only the last c+1
	ll m=(l+r)/2;
	// cout<<"\nf "<<l<<","<<r<<" "<<m<<"\n";
	if(c>1)f(l,m,p);
	queue<vv> q;
	fore(i,l,m+1)q.push({wh[i],1});
	while(SZ(q)>1){
		auto x=q.front(); q.pop();
		auto y=q.front(); q.pop();
		q.push(conv_small(x,y));
	}
	ll k=SZ(p);
	p=conv_small(q.front(),p); q.pop();
	p.resize(k,0);
	// cout<<"m "<<m<<" p: "; imp(p)
	ans[m]=p.back();
	if(c>1)f(m+1,r,p);
}

int main(){FIN;
	ll n; cin>>n;
	vv a(n),oc(n);
	fore(i,0,n){
		cin>>a[i]; a[i]--;
		wh[i]=oc[a[i]]++;
	}
	// fore(i,0,n)cout<<wh[i]<<" ";;cout<<"\n";
	vv p(n+1);
	ll m; cin>>m;
	fore(i,0,m){
		ll x; cin>>x;
		p[n-x]=1;
	}
	// imp(p)
	f(0,n,p);
	fore(i,0,n)cout<<ans[i]<<" ";;cout<<"\n";
	return 0;
}