#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
const ll MOD=1e9+7,MAXF=2e5+5;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int b, ll e){
	ll r=1;
	while(e){
		if(e&1)r=mul(r,b);
		b=mul(b,b); e>>=1;
	}
	return r;
}
// charles-fft
/*
#define dforsn(i,s,n) for(int i=int(n)-1;i>=int(s);i--)
#define forsn(i,s,n) fore(i,0,n)
#define forn(i,n) forsn(i,0,n)
#define dforn(i,n) dforsn(i,0,n)
const int LG=18;

template<class u, class uu, u p, u root>
struct FFT {
	u r[1+(2<<LG)];
	constexpr u m(u a, u b){
		uu k=uu(a)*b;
		#define op(g) g*(g*p+2)
		k+=u(k)*(op(op(op(op(op(-p)))))) * uu(p);
		#undef op
		return u(k>>(8*sizeof(u)));
	}
	constexpr u red(u k, u a){return a-k*(a>=k);}
	FFT(){
		u k=r[2<<LG]=-p%p,b=root,e=p>>LG;
		for(; e; e/=2,b=m(b,b))if(e%2)k=m(k,b);
		dforn(i,2<<LG)r[i]=red(p,m(r[i+1],k)),i&(i-1)?0:k=m(k,k);
		assert(r[2]!=r[3]); assert(r[1]==r[2]);
		vv cv(const vv &as, const vv &bs, u *v){
			int c=max(SZ(as)+SZ(bs)-1,0),n=1;
			assert(c<=(1<<LG));
			u h=u(uu(-p)*-p%p),a=m(h,p/2+1),x,y;
			while(n<c)n<<=1,h=red(p,m(h,a));
			forn(i,n)
				v[i]=i<SZ(as)?u(as[i]):0,
				v[i+n]=i<SZ(bs)?u(bs[i]):0;
			for(auto s:{v,v+n})
			dforsn(j,2,n+1)for(int k=j&-j;k/=2;)forsn(i,j-k,j)
				x=s[i], y=s[i-k],
				s[i-k]=red(2*p,x+y),
				s[i]=m(2*p+y-x,r[3*k-j+i]);
			
			
			
			
			
			
			dforsn(j,2,n+1)for(int k=1;!(k&j);k*=2)
				
		}
	}
};
*/


vv multiply2(vv a, vv b){
	vv c(SZ(a)+SZ(b)-1);
	fore(i,0,SZ(a))fore(j,0,SZ(b))c[i+j]=add(c[i+j],mul(a[i],b[j]));
	return c;
}
ll fc[MAXF],fci[MAXF],med=(MOD+1)/2;
int main(){
	JET
	fc[0]=1;
	fore(i,1,MAXF)fc[i]=mul(fc[i-1],i);
	fci[MAXF-1]=fpow(fc[MAXF-1],MOD-2);
	for(ll i=MAXF-2;i>=0;i--)fci[i]=mul(fci[i+1],i+1);
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		vv p(n+1); p[0]=0; p[1]=1;
		fore(i,2,n+1)p[i]=med;
		if(m>n){cout<<"0\n";continue;}
		if(m==n){cout<<mul(fc[n-1],med);continue;}
		ll k=n-m,_k=k;
		vv r={1},b=p;
		while(k){
			if(k&1)r=multiply2(r,b);
			b=multiply2(b,b); k>>=1;
			b.resize(n+1);
		}
		// for(auto i:r)cout<<i<<" ";;cout<<"\n";
		ll res=mul(r[n],fc[n]);
		// cout<<n<<" "<<m<<" "<<_k<<": "<<r[n]<<" "<<fc[n]<<" "<<fci[_k]<<"\n";
		// cout<<res<<"\n";
		res=mul(res,fci[_k]);
		cout<<res<<"\n";
		
	}
	return 0;
}


// 3
// 4 2
// 4 3
// 5 3
// edu@edu-IdeaPad-3-14ITL6:~/Documents/ucup9qingdao$ ./a
// 0 0 1 1 250000003 
// 30
// 0 1 500000004 500000004 500000004 
// 12
// 0 0 1 1 250000003 500000005 
// 180
