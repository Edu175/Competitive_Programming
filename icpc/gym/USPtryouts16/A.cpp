#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define fore(i,a,b) for(ll i=a,aei=b;i<aei;++i)
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define imp(v) for(auto messi:v) cout << messi << " ";cout << "\n";
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef complex<ld> cc;

cc f(cc p, cc Tx, cc Ty, cc r0){
	cc a(real(p),0),b(0,imag(p));
	return a*Tx+b*Ty+r0;
}

int main(){FIN;
	ll h,w; cin>>h>>w;
	cc r[4];
	cout<<fixed<<setprecision(15);
	fore(i,0,4){
		ld a,b; cin>>a>>b;
		r[i]={a,b};
	}
	cc Tx=cc(w,0)/(r[1]-r[0]);
	cc Ty=cc(0,h)/(r[3]-r[0]);
	cc d0=r[1]-r[0]; d0/=abs(d0);
	cc d1=r[3]-r[0]; d1/=abs(d1);
	cc x=cc(real(r[0]),0)/(d0*Tx-cc(1));
	cc y=cc(0,imag(r[0]))/(d1*Ty-cc(1));
	cc p=x+y+r[0];
	cout<<real(p)<<" "<<imag(p)<<"\n";
	return 0;
}
