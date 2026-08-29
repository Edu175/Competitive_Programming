#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {cerr<<#v<<": ";for(auto i:v)cerr<<i<<" "; cerr<<"\n";}
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

poly multiply(const poly &as, const poly &bs) {
	static uint32_t v[2<<LG];
	static FFT<uint32_t, uint64_t, 998244353, 3> fft;
	return fft.cv(as, bs, v);
}

const ll MOD=(119<<23)+1;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int b, ll e){
	if(e<0)return 0;
	int r=1;
	for(;e;e>>=1,b=mul(b,b))if(e&1)r=mul(r,b);
	return r;
}
ll inv(ll a){return fpow(a,MOD-2);}
poly add(poly a, poly b){
	int n=SZ(a),m=SZ(b);
	poly ans(max(n,m));
	fore(i,0,max(n,m)) ans[i]=add(i<SZ(a)?a[i]:0, i<SZ(b)?b[i]:0);
	while(SZ(ans)>1&&!ans.back())ans.pop_back();
	return ans;
}
poly derivate(poly &p){//derivative of p
	poly ans(max(1, SZ(p)-1));
	fore(i,1,SZ(p)) ans[i-1]=mul(p[i],i);
	return ans;
}
poly integrate(poly &p){
	poly ans(SZ(p)+1);//integral of p
	fore(i,0,SZ(p)) ans[i+1]=mul(p[i], inv(i+1));
	return ans;
}
poly takemod(poly &p, int n){
	poly res=p;//p % (x^n)
	res.resize(min(SZ(res),n));
	while(SZ(res)>1&&res.back()==0) res.pop_back();
	return res;
}
poly invert(poly &p, int d){
	assert(p[0]);//first d terms of 1/p
	poly res={inv(p[0])};
	int sz=1;
	while(sz<d){
		sz*=2;
		poly pre(p.begin(), p.begin()+min(SZ(p),sz));
		poly cur=multiply(res,pre);
		fore(i,0,SZ(cur)) cur[i]=sub(0,cur[i]);
		cur[0]=add(cur[0],2);
		res=multiply(res,cur);
		res=takemod(res,sz);
	}
	res.resize(d);
	return res;
}//O(n*log(n))
poly log(poly &p, int d){
	assert(p[0]==1);//first d terms of log(p)
	poly cur=takemod(p,d);
	poly a=invert(cur,d), b=derivate(cur);
	auto res=multiply(a,b);
	res=takemod(res,d-1);
	res=integrate(res);
	return res;
}//O(n*log(n))
poly exp(poly p, int d){
	assert(!p[0]);
	poly res={1};
	int sz=1;//first d terms of exp(p)
	while(sz<d){
		sz*=2; poly lg=log(res, sz), cur(sz);
		fore(i,0,sz) cur[i]=sub(i<SZ(p)?p[i]:0, i<SZ(lg)?lg[i]:0);
		cur[0]=add(cur[0],1);
		res=multiply(res,cur);
		res=takemod(res, sz);
	}
	res.resize(d);
	return res;
}//O(n*log(n))
poly neg(poly a){
	for(auto &i:a)i=sub(i,0);
	return a;
}
const ll MAXF=2e7+5;
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

ll m;
ll cu(ll k){
	return mul(fc[k*m],fpow(fci[m],k));
}

int main(){FIN;
	factos();
	ll n; cin>>n>>m;
	vv p(n+1);
	fore(k,0,n+1)p[k]=mul(cu(k),fci[k]);
	// show(p)
	// auto coefs=multiply(p,exp(neg(p),n+1));
	vv b=log(p,n+1);
	ll res=0;
	fore(k,1,n+1){
		ll cur=mul(fc[k],b[k]);
		ll coef=mul(nCr(n,k),cu(n-k));
		// cerr<<k<<": "<<cur<<" "<<coef<<": ";
		cur=mul(cur,coef);
		// cerr<<cur<<"\n";
		res=add(res,cur);
	}
	// cerr<<res<<" / "<<cu(n)<<"\n";
	res=mul(res,inv(cu(n)));
	cout<<res<<"\n";
	return 0;
}