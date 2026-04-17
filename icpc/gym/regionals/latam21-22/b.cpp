#include <bits/stdc++.h>
#define  fore(i,a,b) for(ll i=a, jet=b; i<jet; i++)
#define pb push_back
#define fst first 
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define ET ios::sync_with_stdio(0);cout.tie(0);cin.tie(0);
#define imp(v) {cout<<#v<<": ";for(auto i:v)cout<<i<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
// lpm ahora tengo que codear fft
const ll MAXN=1<<19;
typedef ll tf;
typedef vector<tf> poly;
struct CD{
	ld r,i;
	CD(ld r=0, ld i=0):r(r),i(i){}
	ld real()const{return r;}
	void operator/=(const int c){r/=c,i/=c;}
};
CD operator*(const CD& a, const CD& b){
	return CD(a.r*b.r-a.i*b.i,a.r*b.i+a.i*b.r);}
CD operator+(const CD& a, const CD& b){return CD(a.r+b.r,a.i+b.i);}
CD operator-(const CD& a, const CD& b){return CD(a.r-b.r,a.i-b.i);}
const ld pi=acosl(-1.0);

CD cp1[MAXN+9],cp2[MAXN+9];
int R[MAXN+9];
void dft(CD* a, int n, bool inv){
	fore(i,0,n)if(R[i]<i)swap(a[R[i]],a[i]);
	for(int m=2;m<=n;m*=2){
		ld z=2*pi/m*(inv?-1:1);
		CD wi=CD(cos(z),sin(z));
		for(int j=0;j<n;j+=m){
			CD w(1);
			for(int k=j,k2=j+m/2;k2<j+m;k++,k2++){
				CD u=a[k]; CD v=a[k2]*w; a[k]=u+v;a[k2]=u-v;w=w*wi;
			}
		}
	}
	if(inv)fore(i,0,n)a[i]/=n;
}
poly multiply(poly& p1, poly& p2){
	int n=SZ(p1)+SZ(p2)+1;
	int m=1,cnt=0;
	while(m<=n)m+=m,cnt++;
	fore(i,0,m){R[i]=0;fore(j,0,cnt)R[i]=(R[i]<<1)|((i>>j)&1);}
	fore(i,0,m)cp1[i]=0,cp2[i]=0;
	fore(i,0,SZ(p1))cp1[i]=p1[i];
	fore(i,0,SZ(p2))cp2[i]=p2[i];
	dft(cp1,m,false),dft(cp2,m,false);
	fore(i,0,m)cp1[i]=cp1[i]*cp2[i];
	dft(cp1,m,true);
	poly res;
	n-=2;
	fore(i,0,n)res.pb((tf)floor(cp1[i].real()+0.5));
	return res;
}

vv solve(vv a, vv b){
	ll n=SZ(a);
	sort(ALL(a));
	sort(ALL(b));
	// cout<<"solve\n";
	// imp(a)
	// imp(b)
	vv c,d,fij;
	fore(i,0,n){
		if(a[i]*b[i]<0)c.pb(abs(a[i])),d.pb(abs(b[i]));
		else fij.pb(a[i]*b[i]);
	}
	sort(ALL(fij)); reverse(ALL(fij));
	sort(ALL(c)); sort(ALL(d));
	auto e=multiply(c,d);
	ll m=SZ(fij);
	vv ret(n);
	ll sum=0;
	fore(i,0,m)sum+=fij[i],ret[i]=sum;
	// imp(fij)
	// cout<<sum<<" sum\n";
	// imp(e);
	fore(i,0,n-m){
		auto &res=ret[m+i];
		res=sum;
		res-=e[i];
	}
	return ret;
}

int main(){
	ET
	ll n; cin>>n;
	vv a(n),b(n);
	fore(i,0,n)cin>>a[i];
	fore(i,0,n)cin>>b[i];
	auto mx=solve(a,b);
	fore(i,0,n)b[i]=-b[i];
	auto mn=solve(a,b);
	fore(k,0,n){
		cout<<-mn[k]<<" "<<mx[k]<<"\n";
	}
}