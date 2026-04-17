#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {for(auto i:v)cout<<i<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
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

// Replace with any NTT-friendly mod by doing:
// FFT<uint32_t, uint64_t, MOD, primitiveRoot(MOD)>
poly conv_small(const poly &as, const poly &bs) {
	static uint32_t v[2<<LG];
	static FFT<uint32_t, uint64_t, 998244353, 3> fft;
	return fft.cv(as, bs, v);
}
const ll V=2.5e5+100;

vv calcDist(vv a, vv b){ // b ya reverseado
	// reverse(ALL(b));
	auto c=conv_small(a,b);
	reverse(ALL(c));
	c.erase(c.begin(),c.begin()+V-1);
	assert(SZ(c)==V);
	return c;
}


const ll B=9000;

int main(){
	JET
	ll n,q; cin>>n>>q;
	vv a(n),c(n);
	vector<vv> pos(n);
	fore(i,0,n){
		cin>>a[i]>>c[i];
		c[i]--;
		pos[c[i]].pb(i);
	}
	vv ms;
	ll m=n+1;
	while(1){
		ms.pb(m);
		if(m==1)break;
		m=(m+2)/3;
	}
	reverse(ALL(ms));
	ll z=SZ(ms);
	vector<vv> tots(z,vv(V));
	vv b(V);
	fore(i,0,n)b[a[i]]++;
	reverse(ALL(b));
	
	vv is(n);
	vector<vv> bc(n);
	fore(w,0,n)if(SZ(pos[w])>=B){
		is[w]=1;
		bc[w]=vv(V);
		for(auto i:pos[w])bc[w][a[i]]++;
		reverse(ALL(bc[w]));
	}
	
	ll small=0,big=0;
	fore(c,0,n)if(SZ(pos[c])){
		// cerr<<SZ(pos[c])<<"\n";
		(is[c]?big++:small++);
	}
	cerr<<"small "<<small<<"\n";
	cerr<<"big "<<big<<"\n";
	fore(wh,1,z){
		auto &tot=tots[wh];
		auto m=ms[wh];
		vv P(V);
		fore(i,1,m)P[a[i-1]]++;
		// cout<<"\n\nnuevo rango\n";
		// cout<<wh<<": "<<m<<":\n";
		tot=calcDist(P,b);

		// fore(d,0,28)cout<<tot[d]<<" ";;cout<<"\n";

		fore(c,0,n)if(SZ(pos[c])){
			auto &vec=pos[c];
			if(is[c]){
				vv p(V);
				for(auto i:vec){
					if(i+1>=m)break;
					p[a[i]]++;
				}
				auto re=calcDist(p,bc[c]);
				// cout<<"resto big "<<c<<": ";
				// fore(d,0,28)cout<<re[d]<<" ";;cout<<"\n";
				
				fore(i,0,V)tot[i]-=re[i];
			}
			else {
				fore(id0,0,SZ(vec)){
					if(vec[id0]+1>=m)break;
					fore(id1,0,SZ(vec)){
						ll i=vec[id0],j=vec[id1];
						ll d=a[j]-a[i];
						if(d<=0)continue;
						// cerr<<"resto small "<<c<<": "<<i<<" "<<j<<": "<<d<<"\n";
						tot[d]--;
					}
				}
			}
		}
		// fore(d,0,28)cout<<tot[d]<<" ";;cout<<"\n";
		// cout<<"\n";
	}
	
	while(q--){
		ll d; cin>>d;
		ll res=0;
		fore(wh,1,z){
			if(tots[wh][d]){
				res=ms[wh];
				break;
			}
		}
		double ans=res/2.;
		cout<<ans<<"\n";
	}
	
	return 0;
}