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
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MOD=998244353,RT=3,MAXN=1ll<<19;
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
//const tf MOD=2305843009255636993,RT=5;
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
//	fore(i,0,n)res.pb((tf)floor(cp1[i].real()+0.5)); // FFT
	fore(i,0,n)res.pb(cp1[i].x); // NTT
	return res;
}

int main(){FIN;
	ll n; cin>>n;
	vector<ll>a(n);
	ll sum=0;
	fore(i,0,n)cin>>a[i],sum+=a[i];
	vector<poly>b(n);
	fore(i,0,n)b[i]={1,a[i]};
//	for(auto i:b)imp(i);
	while(SZ(b)>1){
		vector<poly>bi;
		fore(i,0,SZ(b)){
			if(i+1<SZ(b))bi.pb(multiply(b[i],b[i+1]));
			else bi.pb(b[i]);
			i++;
		}
		b=bi;
	}
//	imp(b[0]);
	b[0].pb(0);
	auto p=b[0];
//	imp(p)
	ll res=0,val=1,fac=1;
	fore(m,0,n+1){
		if(m)fac=mul(fac,m);
		p[m]=mul(mul(fac,val),p[m]);
		val=mul(val,pm(sum-m,MOD-2));
	}
//	imp(p)
	fore(m,0,n+1){
		ll resi=mul(m+1,sub(p[m],p[m+1]));
//		cout<<m<<": "<<m+1<<" * "<<sub(p[m],p[m+1])<<" = "<<resi<<"\n";
		res=add(res,resi);
		val=mul(val,pm(sum-m,MOD-2));
	}
	cout<<res<<"\n";
	return 0;
}
