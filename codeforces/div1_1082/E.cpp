#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {cout<<#v<<": "; for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MOD=(119<<23)+1;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	if(b<0)return 0;
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
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
// Replace with any NTT-friendly mod by doing:
// FFT<uint32_t, uint64_t, MOD, primitiveRoot(MOD)>
poly conv_small(const poly &as, const poly &bs) {
	static uint32_t v[2<<LG];
	static FFT<uint32_t, uint64_t, 998244353, 3> fft;
	return fft.cv(as, bs, v);
}

vv get(vv a){
	ll h=SZ(a)/2;
	vv l(a.begin(),a.begin()+h);
	vv r(a.begin()+h,a.end());
	reverse(ALL(l));
	auto p=conv_small(l,r);
	assert(SZ(p)==2*h-1);
	fore(i,h,2*h-1)p[i]=add(p[i],p[i-h]);
	p.erase(p.begin(),p.begin()+h-1);
	return p;
}
ll solve(string s){
	ll n=SZ(s),h=n/2;
	vv ca(n),cb(n),cc(n);
	fore(i,0,n){
		char ch=s[i];
		ca[i]=ch=='a'||ch=='?';
		cb[i]=ch=='b'||ch=='?';
		cc[i]=ch=='?';
	}
	auto Pa=get(ca);
	auto Pb=get(cb);
	auto Pc=get(cc);
	ll res=0;
	fore(k,0,h){
		if(Pa[k]+Pb[k]-Pc[k]!=h)continue;
		ll coef=fpow(2,Pc[k]);
		res=add(res,coef);
	}
	// cout<<"solve "<<s<<": "<<res<<"\n";
	return res;
}
string novo(string s, ll d){
	vector<set<ll>> r(d);
	fore(i,0,SZ(s))r[i%d].insert(s[i]);
	string ret;
	fore(i,0,d){
		auto &st=r[i];
		st.insert('?');
		if(SZ(st)==3)return "";
		ret.pb(*st.rbegin());
	}
	return ret;
}
const ll MAXV=4e5+5;
vv divs[MAXV];
int main(){FIN;
	fore(d,1,MAXV)for(ll i=d;i<MAXV;i+=d)divs[i].pb(d);
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n; ll h=n/2;
		string s; cin>>s;
		auto l=s.substr(0,h);
		auto r=s.substr(h,h);
		vv dp(h+1);
		ll ans=0;
		for(auto d:divs[h]){
			string t=novo(l,d)+novo(r,d);
			if(SZ(t)!=2*d)continue;
			auto &res=dp[d];
			res=solve(t);
			for(auto d2:divs[d])if(d2<d)res=sub(res,mul(dp[d2],d/d2));
			ans=add(ans,res);
			// cerr<<d<<": "<<res<<"\n";
		}
		cout<<ans<<"\n";
	}
	return 0;
}
