#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
#define impinv(v) {for(auto gdljh:v)cout<<fpow(gdljh,MOD-2)<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
const ll MAXV=2e6+5,MOD=998244353,RT=5,MAXN=1ll<<18,MAXF=MAXV;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int pm(int a, ll b){
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}

// MAXN must be power of 2 !!
// MOD-1 needs to be a multiple of MAXN !!
// big mod and primitive root for NTT:
typedef ll tf;
typedef vector<tf> poly;
// FFT
//struct CD {
//	double r,i;
//	CD(double r=0, double i=0):r(r),i(i){}
//	double real()const{return r;}
//	void operator/=(const int c){r/=c, i/=c;}
//};
//CD operator*(const CD& a, const CD& b){
//	return CD(a.r*b.r-a.i*b.i,a.r*b.i+a.i*b.r);}
//CD operator+(const CD& a, const CD& b){return CD(a.r+b.r,a.i+b.i);}
//CD operator-(const CD& a, const CD& b){return CD(a.r-b.r,a.i-b.i);}
//const double pi=acos(-1.0);
// NTT

struct CD {
	tf x;
	CD(tf x):x(x){}
	CD(){}
};
CD operator*(const CD& a, const CD& b){return CD(mul(a.x,b.x));}
CD operator+(const CD& a, const CD& b){return CD(add(a.x,b.x));}
CD operator-(const CD& a, const CD& b){return CD(sub(a.x,b.x));}
vector<tf> rts(MAXN+9,-1);
CD root(int n, bool inv){
	tf r=rts[n]<0?rts[n]=pm(RT,(MOD-1)/n):rts[n];
	return CD(inv?pm(r,MOD-2):r);
}

CD cp1[MAXN+9],cp2[MAXN+9];
int R[MAXN+9];
void dft(CD* a, int n, bool inv){
	fore(i,0,n)if(R[i]<i)swap(a[R[i]],a[i]);
	for(int m=2;m<=n;m*=2){
//		double z=2*pi/m*(inv?-1:1); // FFT
//		CD wi=CD(cos(z),sin(z)); // FFT
		 CD wi=root(m,inv); // NTT
		for(int j=0;j<n;j+=m){
			CD w(1);
			for(int k=j,k2=j+m/2;k2<j+m;k++,k2++){
				CD u=a[k];CD v=a[k2]*w;a[k]=u+v;a[k2]=u-v;w=w*wi;
			}
		}
	}
//	if(inv)fore(i,0,n)a[i]/=n; // FFT
	if(inv){ // NTT
		CD z(pm(n,MOD-2)); // pm: modular exponentiation
		fore(i,0,n)a[i]=a[i]*z;
	}
}
poly multiply(poly &p1, poly &p2){
	int n=p1.size()+p2.size()+1;
	int m=1,cnt=0;
	while(m<=n)m+=m,cnt++;
	fore(i,0,m){R[i]=0;fore(j,0,cnt)R[i]=(R[i]<<1)|((i>>j)&1);}
	fore(i,0,m)cp1[i]=0,cp2[i]=0;
	fore(i,0,p1.size())cp1[i]=p1[i];
	fore(i,0,p2.size())cp2[i]=p2[i];
	dft(cp1,m,false);dft(cp2,m,false);
	fore(i,0,m)cp1[i]=cp1[i]*cp2[i];
	dft(cp1,m,true);
	poly res;
	n-=2;
//	fore(i,0,n)res.pb((tf)floor(cp1[i].real()+0.5)); // FFT
	fore(i,0,n)res.pb(cp1[i].x); // NTT
	return res;
}
//ll inverse[MAXV];
vector<ll>a;
poly f(int l, int r){
	if(r-l==1){
		vector<ll>v(2);
		v[1]=pm(a[l],MOD-2);//inverse[a[l]];
		v[0]=sub(1,v[1]);
		return v;
	}
	int m=(l+r)/2;
	auto s=f(l,m),e=f(m,r);
	return multiply(s,e);
}

bitset<MAXV>cr;

int main(){FIN;
	cr[0]=cr[1]=1;
	fore(i,2,MAXV)if(!cr[i])for(ll j=1ll*i*i;j<MAXV;j+=i)cr[j]=1;
//	ll fc[MAXF],fci[MAXF];
//	fc[0]=1;
//	fore(i,1,MAXF)fc[i]=mul(fc[i-1],i);
//	fci[MAXF-1]=pm(fc[MAXF-1],MOD-2);
//	for(int i=MAXF-2;i>=0;i--)fci[i]=mul(fci[i+1],(i+1));
//	fore(i,1,MAXV)inverse[i]=mul(fci[i],fc[i-1]);
//	cout<<inverse[2]<<"\n";
	ll t,k; cin>>t>>k; k--;
	if(t==2){
		if(k==0)cout<<pm(2,MOD-2)<<"\n";
		else cout<<"0\n";
		return 0;
	}
	fore(i,2,t)if(!cr[i])a.pb(i);
//	random_shuffle(ALL(a));
//	cout<<SZ(a)<<"\n";
	auto p=f(0,SZ(a));
//	imp(a);
//	impinv(p);
	ll res=0;
	if(k<SZ(p))res=p[k];
	res=mul(res,pm(t,MOD-2));
	cout<<res<<"\n";
	return 0;
}
