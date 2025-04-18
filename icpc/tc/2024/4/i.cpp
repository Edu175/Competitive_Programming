#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {for(auto dkjgn:v)cout<<dkjgn<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=1ll<<20;
// MAXN must be power of 2 !!
// MOD-1 needs to be a multiple of MAXN !!
// big mod and primitive root for NTT:
typedef ll tf;
typedef vector<tf> poly;
const tf MOD=998244353,RT=3;
ll add(ll a, ll b){a+=b;if(a>=MOD)a-=MOD;return a;}
ll sub(ll a, ll b){a-=b;if(a<0)a+=MOD;return a;}
ll mul(ll a, ll b){return a*b%MOD;}
ll pm(ll b, ll e){
	ll ret=1;
	while(e){if(e&1)ret=mul(ret,b);e>>=1,b=mul(b,b);}
	return ret;
}
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
int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		string s; cin>>s;
		vector<ll>v(n);
		fore(i,0,n){
			if(s[i]=='?')v[i]=0;
			else if(s[i]=='V')v[i]=1;
			else v[i]=2;
		}
		auto rv=v; reverse(ALL(rv));
		// imp(v); imp(rv);
		vector<vector<ll>>a(4,vector<ll>(n,1)),b=a;
		fore(i,1,4)fore(j,0,n){
			a[i][j]=mul(a[i-1][j],v[j]);
			b[i][j]=mul(b[i-1][j],rv[j]);
		}
		poly t1=multiply(a[3],b[1]),t2=multiply(a[2],b[2]),t3=multiply(a[1],b[3]);
		// imp(t1); imp(t2); imp(t3);
		poly sum(n);
		fore(i,0,n){
			sum[i]=(t1[n-1+i]-2*t2[n-1+i]+t3[n-1+i]+3*MOD)%MOD;
		}
		// imp(sum)
		vector<ll>res;
		fore(d,1,n){
			ll flag=1;
			for(ll m=d;m<n;m+=d)flag&=!sum[m];
			if(flag)res.pb(d);
		}
		res.pb(n);
		cout<<SZ(res)<<"\n";
		for(auto i:res)cout<<i<<" ";
		cout<<"\n";
	}
	return 0;
}