#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a, jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(x)  for(auto a:x){cout<<a<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll>  ii;




const int LG = 22;
typedef vector<ll> poly;
template<class u, class uu, u p, u root> 
struct FFT{
	u r[1+(2<<LG)];
	constexpr u m (u a, u b){
		uu k = uu(a)*b;
		#define op(g) g*(g*p+2)
		k += u(k) * (op(op(op(op(op(-p)))))) * uu(p);
		#undef op
		return u(k>>(8*sizeof(u)));
	}
	constexpr u red(u k, u a){return a-k*(a>=k);}
	FFT(){
		u k = r[2<<LG]= -p%p, b = root, e=p>>LG;
		for(;e;e/=2,b=m(b,b)) if(e&1) k=m(k,b);
		for(int i = (2<<LG)-1;i>=0;i--)r[i] = red(p,m(r[i+1],k)), i&(i-1)?0:k=m(k,k);
	}
	poly cv(const poly &as, const poly &bs, u *v){
		int c = max(SZ(as)+SZ(bs)-1,0ll),n=1;
		assert(c<=(1<<LG));
		u h = u(uu(-p)*-p%p), a = m(h,p/2+1),x ,y;
		while(n<c)n*= 2, h = red(p,m(h,a));
		fore(i,0,n){
			v[i] = i<SZ(as)?u(as[i]):0,
			v[i+n] = i<SZ(bs)?u(bs[i]):0;
		}
		for(auto s:{v,v+n})for(int j = n;j>=2;j--)for(int k=j&-j;k/=2;)fore(i,j-k,j){
			x=s[i], y = s[i-k];
			s[i-k] = red(2*p,x+y);
			s[i] = m(2*p+y-x, r[3*k-j+i]);
		}
		fore(i,0,n)v[i] = m(v[i],v[i+n]);
		fore(j,2,n+1)for(int k = 1;!(k&j);k*=2)fore(i,j-k,j){
			x=m(v[i],r[3*k+j-i]);
			y=red(2*p,v[i-k]);
			v[i-k]=x+y, v[i] = 2*p+y-x;
		}
		fore(i,0,c)v[i] = red(p,m(v[i],h));
		return poly(v,v+c);
	}
};

poly conv_small(const poly &as, const poly &bs){
	static uint32_t v[2<<LG];
	static FFT<uint32_t, uint64_t,998244353,3> fft;
	return fft.cv(as,bs,v);
}
const ll maxn=5e5+5;

int main(){
	JET
	
	ll n,k; cin>>n>>k;
	string s; cin>>s;
	vv a(n);
	fore(i,0,n) a[i]=s[i]-'0';

	ll del=0;
	fore(i,0,n) if(!a[i]){
		if(i)del+=a[i-1];
		if(i<n-1) del+=a[i+1];
	}
	vv f(n,del);
	fore(i,1,n+1){
		for(ll j=0; j<n; j+=i){
			if(j&&!a[j-1]) f[i-1]-=a[j];
			if(j&&!a[j]) f[i-1]-=a[j-1]; 
		}
	}
	
	vv N(n,0); fore(i,0,n) N[i]=!a[i];
	reverse(ALL(N));
	vv p=conv_small(a,N);
	// assert(SZ(p)==2*n-1);
	fore(i,0,n-1) f[i]+=p[n+i];
	reverse(ALL(N)); reverse(ALL(a));
	p=conv_small(a,N);
	fore(i,0,n-1) f[i]+=p[n+i];
	// show(f);
	sort(ALL(f));
	reverse(ALL(f));
	cout<<f[k-1]<<"\n";
	return 0;
}
// 7 
// 4 
// 7 
// 5 
// 5 
// 5
