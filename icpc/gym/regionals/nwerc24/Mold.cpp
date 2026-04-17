#include <bits/stdc++.h> 
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define snd second 
#define fst first
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll) x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef __int128 xl;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

const ll K=19,maxn=1<<K;

typedef xl tf;
typedef long double cty;
typedef vector<tf> poly;
struct CD{
	cty r,i;
	CD(cty r=0., cty i=0.): r(r), i(i) {}
	cty real()const{return r;}
	void operator/=(const int c){r/=c,i/=c;}
};
CD operator*(const CD&a, const CD&b){
	return CD(a.r*b.r-a.i*b.i,a.r*b.i+a.i*b.r);
}
CD operator+(const CD&a, const CD&b){return CD(a.r+b.r,a.i+b.i);}
CD operator-(const CD&a, const CD&b){return CD(a.r-b.r,a.i-b.i);}
const cty pi=acosl(-1.0);

CD cp1[maxn+9],cp2[maxn+9];
int R[maxn+9];
void dft(CD *a, int n, bool inv){
	fore(i,0,n)if(R[i]<i)swap(a[R[i]],a[i]);
	for(int m=2; m<=n; m<<=1){
		cty z=2*pi/m*(inv?-1:1);
		CD wi=CD(cosl(z),sinl(z));
		for(int j=0; j<n; j+=m){
			CD w(1);
			for(int k=j,k2=j+m/2; k2<j+m;k++,k2++){
				CD u=a[k],v=a[k2]*w; a[k]=u+v,a[k2]=u-v, w=w*wi;
			}
		}
	}
	if(inv)fore(i,0,n)a[i]/=n;
}

poly multiply(vv p1, vv p2){
	int n=SZ(p1)+SZ(p2)+1;
	int m=1,cnt=0;
	while(m<=n)m<<=1,cnt++;
	fore(i,0,m){R[i]=0;fore(j,0,cnt)R[i]=(R[i]<<1)|((i>>j)&1);}
	fore(i,0,m) cp1[i]=0,cp2[i]=0;
	fore(i,0,SZ(p1))cp1[i]=p1[i];
	fore(i,0,SZ(p2))cp2[i]=p2[i];
	dft(cp1,m,false);dft(cp2,m,false);
	fore(i,0,m)cp1[i]=cp1[i]*cp2[i];
	dft(cp1,m,true);
	poly res;
	n-=2;
	fore(i,0,n) res.pb(floor(cp1[i].real()+0.5));
	return res;
}
poly multiply2(poly a, poly b){
	poly c(SZ(a)+SZ(b)-1);
	fore(i,0,SZ(a))fore(j,0,SZ(b))c[i+j]+=a[i]*b[j];
	return c;
}
poly operator+(poly a, poly b){
	assert(SZ(a)==SZ(b));
	fore(i,0,SZ(a))a[i]+=b[i];
	return a;
}
vector<ll> operator*(tf t, vector<ll> a){
	fore(i,0,SZ(a))a[i]*=t;
	return a;
}
// const tf EPS = 1e-6;
int main(){
	JET
	ll n; cin>>n;
	vv xs(n),ys(n);
	fore(i,0,n)cin>>xs[i]>>ys[i];
	auto b=ys; reverse(ALL(b)); b=(-1)*b;
	auto c1=multiply(xs,b);
	b=xs; reverse(ALL(b));
	auto c2=multiply(ys,b);
	auto c=c1+c2;
	vector<xl> coef(n);
	// cout<<"c: ";
	fore(k,0,SZ(c)){
		// cout<<c[k]<<" ";
		ll d=k-(n-1);
		if(d<0)d+=n;
		coef[d]+=c[k];
	}
	// cout<<"\n";
	// assert(coef[0]<EPS);
	tf res=0;
	fore(k,1,n){
		res+=xl(n-k-1)*coef[k];
		// cout<<k<<": "<<coef[k]<<"\n";
	}
	auto cruz=[&](ll i, ll j){return xs[i]*ys[j]-ys[i]*xs[j];};
	// auto dbg=[&](){
	// 	cout<<"dbg\n";
	// 	fore(k,0,n){
	// 		tf res=0;
	// 		fore(i,0,n){
	// 			ll j=(i+k)%n;
	// 			res+=cruz(i,j);
	// 		}
	// 		cout<<k<<": "<<res<<" "<<coef[k]<<endl;
	// 		assert(abs(res-coef[k])<EPS);
	// 	}
	// };
	// dbg(); // ============================================
	tf tot=0;
	fore(i,0,n){
		ll j=(i+1)%n;
		tot+=cruz(i,j);
	}
	typedef long double ld;
	ld ans=ld(res)/tot;
	// res/=tot;
	cout<<fixed<<setprecision(15)<<ans<<"\n";
	return 0;
}
