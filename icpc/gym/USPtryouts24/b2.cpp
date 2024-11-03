#include <bits/stdc++.h>
#define fore(i,a,b) for(int i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
typedef ll tf;
typedef vector<tf> poly;
const tf MOD=998244353, RT=998244350,MAXN=1<<19;

int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int pm(int a, ll b){
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
const ll MAXF=MAXN;
ll fc[MAXF],fci[MAXF];
void factos(){
	fc[0]=1;
	fore(i,1,MAXF)fc[i]=mul(fc[i-1],i);
	fci[MAXF-1]=pm(fc[MAXF-1],MOD-2);
	for(ll i=MAXF-2;i>=0;i--)fci[i]=mul(fci[i+1],(i+1));
}
ll nCr(ll n, ll k){ //must call factos before
	if(n<0||k<0||k>n)return 0;
	return mul(mul(fc[n],fci[k]),fci[n-k]);
}

ll addmod(ll a, ll b){return add(a,b);}
ll submod(ll a, ll b){return sub(a,b);}
ll mulmod(ll a, ll b){return mul(a,b);}
// typedef ll tf;
// typedef vector<tf> poly;
// const tf MOD=2305843009255636993,RT=5;
// FFT
// struct CD {
// 	double r,i;
// 	CD(double r=0, double i=0):r(r),i(i){}
// 	double real()const{return r;}
// 	void operator/=(const int c){r/=c, i/=c;}
// };
// CD operator*(const CD& a, const CD& b){
// 	return CD(a.r*b.r-a.i*b.i,a.r*b.i+a.i*b.r);}
// CD operator+(const CD& a, const CD& b){return CD(a.r+b.r,a.i+b.i);}
// CD operator-(const CD& a, const CD& b){return CD(a.r-b.r,a.i-b.i);}
// const double pi=acos(-1.0);
// NTT

struct CD {
	tf x;
	CD(tf x):x(x){}
	CD(){}
};
CD operator*(const CD& a, const CD& b){return CD(mulmod(a.x,b.x));}
CD operator+(const CD& a, const CD& b){return CD(addmod(a.x,b.x));}
CD operator-(const CD& a, const CD& b){return CD(submod(a.x,b.x));}
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
		// double z=2*pi/m*(inv?-1:1); // FFT
		// CD wi=CD(cos(z),sin(z)); // FFT
		CD wi=root(m,inv); // NTT
		for(int j=0;j<n;j+=m){
			CD w(1);
			for(int k=j,k2=j+m/2;k2<j+m;k++,k2++){
				CD u=a[k];CD v=a[k2]*w;a[k]=u+v;a[k2]=u-v;w=w*wi;
			}
		}
	}
	// if(inv)fore(i,0,n)a[i]/=n; // FFT
	if(inv){ // NTT
		CD z(pm(n,MOD-2)); // pm: modular exponentiation
		fore(i,0,n)a[i]=a[i]*z;
	}
}
poly multiply(poly& p1, poly& p2){
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
	// fore(i,0,n)res.pb((tf)floor(cp1[i].real()+0.5)); // FFT
	fore(i,0,n)res.pb(cp1[i].x); // NTT
	return res;
}

poly fpow(poly b, ll e, ll n){
	poly res={1};
	while(e){
		if(e&1)res=multiply(res,b);
		res.resize(n);
		b=multiply(b,b); e>>=1;
		b.resize(n);
		
	}
	return res;
}

int main(){
	JET
	factos();
	
	ll t; cin>>t;
	while(t--){
		ll n,m,h; cin>>n>>m>>h;
		vector<ll>p(h+1);
		fore(i,1,h+1)p[i]=1;
		p=fpow(p,m+1,n+5);
		for(auto i:p)cout<<i<<" ";;cout<<"\n";
		cout<<nCr(n,m)<<"\n";
		ll res=p[n+1];
		cout<<res<<"\n";
		
		res=mul(res,pm(nCr(n,m),MOD-2));
		cout<<res<<"\n";
		res=sub(1,res);
		cout<<res<<"\n";
	}
	return 0;
}