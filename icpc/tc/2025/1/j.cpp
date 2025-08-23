#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define pb push_back
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MOD=998244353;
#define forr(i,a,b) for(ll i=(b)-1,jet=a;i>=jet;i--)
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
static uint32_t v[2<<LG];
static FFT<uint32_t, uint64_t, MOD, 3> fft;
vector<ll> conv_small(const vector<ll> &as, const vector<ll> &bs) {
	return fft.cv(as, bs, v);
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

vv get(vv a, ll mx){
	sort(ALL(a));
	ll q=0,n=SZ(a);
	queue<vv>ps;
	fore(i,0,n)if(a[i]<mx){
		q++;
		if(i==n-1||a[i]!=a[i+1]){
			vv p={1,2};
			if(q>=2)p.pb(1);
			ps.push(p);
			q=0;
		}
	}
	
	while(SZ(ps)>1){
		auto p=ps.front(); ps.pop();
		auto q=ps.front(); ps.pop();
		ps.push(conv_small(p,q));
	}
	
	return SZ(ps)?ps.front():vv(1,1);
}

int main(){
	JET
	ll n,k; cin>>n>>k;
	vv a(n);
	fore(i,0,n)cin>>a[i];
	vv b(k);
	fore(i,0,k)cin>>b[i];
	
	vector<vv> cants;
	fore(i,0,k)cants.pb(get(a,b[i]));
	
	auto query=[&](ll c, ll i){
		auto &p=cants[i];
		ll res=0<=c&&c<SZ(p)?p[c]:0;
		return res;
	};
	
	ll q; cin>>q;
	while(q--){
		ll h; cin>>h; h/=2;
		ll res=0;
		fore(i,0,k){
			ll c=h-b[i]-1;
			ll cur=query(c,i);
			res=add(res,cur);
		}
		cout<<res<<"\n";
	}
	return 0;
}