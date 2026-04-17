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

vv dist(vv a){
	auto b=a; reverse(ALL(b));
	auto c=conv_small(a,b);
	ll n=SZ(a);
	// vv d;
	// fore(i,n-1,SZ(c))d.pb(c[i]);
	c.erase(c.begin(),c.begin()+n-1);
	return c;
}
vv operator-(vv a, vv b){
	vv c(max(SZ(a),SZ(b)));
	fore(i,0,SZ(c)){
		if(i<SZ(a))c[i]=a[i];
		if(i<SZ(b))c[i]=sub(c[i],b[i]);
	}
	return c;
}
vv get(vv a){
	ll n=SZ(a),h=n/2;
	vv l(a.begin(),a.begin()+h);
	vv r(a.begin()+h,a.end());
	vv pa=dist(a);
	vv pl=dist(l);
	vv pr=dist(r);
	// cerr<<"get ";
	// imp(a)
	// imp(l)
	// imp(r)
	// imp(pl)
	// imp(pr)
	// imp(pa)
	pa=pa-pl;
	pa=pa-pr;
	fore(j,0,5)pa.pb(0);
	// imp(pa)
	return pa;
}
const ll MAXV=4e5+5;
vv divs[MAXV];
int main(){FIN;
	fore(d,1,MAXV)for(ll i=d;i<MAXV;i+=d)divs[i].pb(d);
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n; ll h=n/2;
		string s; cin>>s;
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
		// imp(Pa)
		// imp(Pb)
		// imp(Pc)
		ll res=0;
		fore(k,0,h+1){
			if(Pa[k]+Pb[k]-Pc[k]!=k)continue;
			ll c=k+h;
			if(Pa[c]+Pb[c]-Pc[c]!=h-k)continue;
			ll coef=fpow(2,Pc[k]+Pc[c]);
			// cerr<<"good "<<k<<": "<<coef<<"\n";
			res=add(res,coef);
		}
		// cerr<<"res "<<res<<"\n";
		// auto Da=dist(ca);
		// auto Db=dist(cb);
		// auto Dc=dist(cc);
		ll sac=0;
		vector<vv> dp(h+1,vv(2));
		auto get=[&](ll d, string s){
			vector<set<ll>> r(d);
			fore(i,0,SZ(s))r[i%d].insert(s[i]);
			ll coef=1;
			fore(i,0,d){
				auto &st=r[i];
				st.erase('?');
				coef=mul(coef,2-SZ(st));
			}
			return coef;
		};
		for(auto d:divs[h])for(auto ig:{1,0}){
			auto &coef=dp[d][ig];
			if(ig)coef=get(d,s);
			else {
				auto l=s.substr(0,h);
				auto r=s.substr(h,h);
				coef=mul(get(d,l),get(d,r));
			}
			for(auto d2:divs[d])fore(j,ig,2)if(d2!=d||j!=ig){
				coef=sub(coef,dp[d2][j]);
			}
			ll cuan=h/d+ig;
			cuan--;
			ll cur=mul(coef,cuan);
			sac=add(sac,cur);
			cerr<<d<<" "<<ig<<": "<<cuan+1<<" "<<coef<<": "<<cur<<"\n";
		}
		res=sub(res,sac);
		cout<<res<<"\n";
	}
	return 0;
}
