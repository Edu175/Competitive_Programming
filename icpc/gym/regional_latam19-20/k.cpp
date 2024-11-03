#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet; i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define ET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef __int128 ll;
typedef long long LL;
typedef pair<ll,ll> ii;
typedef vector <ll> vv;
const ll MAXN=1<<15;
typedef ll tf;
typedef vector<tf> poly;
typedef long double ld;
struct CD{
	ld r,i;
	CD(ld r=0, ld i=0): r(r), i(i) {}
	ld real()const{return r;}
	void operator/=(const int c){r/=c; i/=c;}
};
CD operator*(const CD& a, const CD& b){
	return CD(a.r*b.r-a.i*b.i,a.r*b.i+a.i*b.r);
}
CD operator+(const CD& a, const CD& b){
	return CD(a.r+b.r, a.i+b.i);
}
CD operator-(const CD& a, const CD& b){
	return CD(a.r-b.r, a.i-b.i);
}
const ld pi=acos(-1.0);
CD cp1[MAXN+9], cp2[MAXN+9];
int R[MAXN+9];
void dft(CD* a,int n, bool inv){
	fore(i,0,n)if(R[i]<i)swap(a[R[i]],a[i]);
	for(int m=2; m<=n; m*=2){
		ld z=2*pi/m*(inv?-1:1);
		CD wi=CD(cos(z),sin(z));
		for(int j=0; j<n; j+=m){
			CD w(1);
			for(int k=j, k2=j+m/2; k2<j+m; k++, k2++){
				CD u=a[k]; CD v=a[k2]*w; a[k]=u+v; a[k2]=u-v; w=w*wi;
			}
		}
	}
	if(inv) fore(i,0,n) a[i]/=n;
}
/*
ld flur(ld f_fft){
	f_fft+=0.5;
	return (f_fft<0.?-ceil(-f_fft):floor(f_fft));
}
*/
poly mulp(poly &p1, poly &p2){
	int n=SZ(p1)+SZ(p2)+1;
//	cout<<"p1: ";
//	fore(i,0,SZ(p1)) cout<<p1[i]<<" ";
//	cout<<"\n";
//	cout<<"p2: ";
//	fore(i,0,SZ(p2)) cout<<p2[i]<<" ";
//	cout<<"\n";
	int m=1,cnt=0;
	while(m<=n)m+=m,cnt++;
	fore(i,0,m){R[i]=0; fore(j,0,cnt)R[i]=(R[i]<<1)|((i>>j)&1);}
	fore(i,0,m) cp1[i]=0,cp2[i]=0;
	fore(i,0,SZ(p1)){cp1[i]=p1[i];}
	fore(i,0,SZ(p2)){cp2[i]=p2[i];}
	dft(cp1,m,false); dft(cp2,m,false);
	fore(i,0,m)cp1[i]=cp1[i]*cp2[i];
	dft(cp1,m,true);
	poly res;
	n-=2;
	fore(i,0,n){res.pb((tf)floor(cp1[i].real()+0.5));
	//cout<<res[i]<<" ";
	}
	//cout<<"\n";
	
	return res;
}
int main(){ET
	
	
	ll n;string s; cin>>s ; n=SZ(s);
	//if(s=="HHH") {cout<<"0\n"<<"1\n"; return 0;}
	poly res={(s[n-1]=='H'?1:-1)};
	fore(i,1,n){
		if(s[i-1]!=s[i]){
			poly k={-2*i-1,1};
			res=mulp(res,k);
		}
	}
	// fore(i,0,n){
	// 	ll x=1ll;
	// 	ll r=0;
	// 	fore(j,0,SZ(res)){
	// 		r+=res[j]*x;
	// 		x*=(2*(i+1));
	// 	}
	// 	cout<<"r "<<LL(r)<<" i "<<LL(i)<<"\n";
	// 	if(r*(s[i]=='H'?1:-1)<=0) {cout<<"pingo i="<<LL(i)<<"\n"; 
		
	// 	}
	// }
	cout<<LL(n)<<"\n";
	cout<<s<<"\n";
	assert(SZ(res));
	while(SZ(res)&&!res.back())res.pop_back();
	reverse(ALL(res));
	cout<<SZ(res)-1<<"\n";
	fore(i,0,SZ(res)){
		if(i)cout<<" ";
		cout<<LL(res[i]);
	}
	cout<<"\n";
	
//	if(!kk){ff++; kk=1ll<<ff;}
//}
}