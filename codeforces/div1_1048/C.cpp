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
#define forr(i,a,b) for(ll i=(b)-1,jet=a;i>=jet;i--)

// The maximum length of the resulting
// convolution vector is 2^LG
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
		int c=max(SZ(as)+SZ(bs)-1, 0), n=1;
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
typedef ll tf;
typedef vector<tf> poly;
const ll MOD=998244353;
int addm(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int subm(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mulm(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	if(b<0)return 0;
	int r=1;
	while(b){if(b&1)r=mulm(r,a); b>>=1; a=mulm(a,a);}
	return r;
}
int inv(ll x){return fpow(x,MOD-2);}

static uint32_t __v[2<<LG];
static FFT<uint32_t, uint64_t, 998244353, 3> fft;
poly multiply(const poly &as, const poly &bs) {
	return fft.cv(as, bs, __v);
}
poly takemod(poly &p, int n){
	poly res=p;
	res.resize(min(SZ(res),n));
	while(SZ(res)>1&&res.back()==0) res.pop_back();
	return res;
}
poly derivate(poly &p){
	poly ans(max(1, SZ(p)-1));
	fore(i,1,SZ(p)) ans[i-1]=mulm(p[i],i);
	return ans;
}
poly integrate(poly &p){
	poly ans(SZ(p)+1);
	fore(i,0,SZ(p)) ans[i+1]=mulm(p[i], inv(i+1));
	return ans;
}

poly invert(poly &p, int d){
	assert(p[0]);
	poly res={inv(p[0])};
	int sz=1;
	while(sz<d){
		sz*=2;
		poly pre(p.begin(), p.begin()+min(SZ(p),sz));
		poly cur=multiply(res,pre);
		fore(i,0,SZ(cur)) cur[i]=subm(0,cur[i]);
		cur[0]=addm(cur[0],2);
		res=multiply(res,cur);
		res=takemod(res,sz);
	}
	res.resize(d);
	return res;
}
poly log(poly &p, int d){
	assert(p[0]==1);
	poly cur=takemod(p,d);
	poly a=invert(cur,d), b=derivate(cur);
	auto res=multiply(a,b);
	res=takemod(res,d-1);
	res=integrate(res);
	return res;
}
poly exp(poly &p, int d){
	assert(!p[0]);
	poly res={1};
	int sz=1;
	while(sz<d){
		sz*=2;
		poly lg=log(res, sz), cur(sz);
		fore(i,0,sz) cur[i]=subm(i<SZ(p)?p[i]:0, i<SZ(lg)?lg[i]:0);
		cur[0]=addm(cur[0],1);
		res=multiply(res,cur);
		res=takemod(res, sz);
	}
	
	res.resize(d);
	return res;
}
const ll MAXF=2e5+5;
ll fc[MAXF],fci[MAXF],invf[MAXF];
void factos(){
	fc[0]=1;
	fore(i,1,MAXF)fc[i]=mulm(fc[i-1],i);
	fci[MAXF-1]=fpow(fc[MAXF-1],MOD-2);
	for(ll i=MAXF-2;i>=0;i--)fci[i]=mulm(fci[i+1],(i+1));
	fore(i,1,MAXF)invf[i]=mulm(fci[i],fc[i-1]);
}

bool mochila(ll l, ll r, vv &a){ // puedo formar alguno en [l,r) ?
	ll n=r; l=max(l,0ll);
	// cout<<"mochila "<<l<<","<<r<<": "; imp(a) 
	vv hist(n);
	for(auto i:a)if(i<n)hist[i]++;
	poly p(n);
	fore(i,0,n){
		ll c=hist[i];
		if(!c)continue;
		assert(i);
		fore(m,1,n){
			ll pos=m*i;
			if(pos>=n)break;
			ll term=mulm(c,invf[m]);
			p[pos]=((m+1)&1?subm:addm)(p[pos],term);
			// cerr<<i<<" "<<c<<": "<<term<<"\n";
		}
	}
	// imp(p) 
	p=exp(p,n);
	// imp(p) 
	fore(i,l,r)if(p[i])return 1;
	return 0;
}

int main(){FIN;
	factos();
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		vv d(n),ish(n,1);
		fore(i,1,n){
			ll p; cin>>p; p--;
			d[i]=d[p]+1;
			ish[p]=0;
		}
		vv hist(n);
		fore(i,0,n)hist[d[i]]++;
		ll mnd=n;
		fore(i,0,n)if(ish[i])mnd=min(mnd,d[i]);
		vv b;
		ll tot=0;
		fore(i,0,mnd+1)b.pb(hist[i]),tot+=hist[i];
		ll res=mnd+mochila(tot+k-n,k+1,b);
		cout<<res<<"\n";
	}
	return 0;
}
