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

cc zx,zy;
vector<cc>r(4);
cc f(cc p){
	cc a(real(p),0),b(0,imag(p));
	return zx*a+zy*b+r[0];
}
ll it=1e6;
int main(){FIN;
	ld h,w; cin>>h>>w;
	cout<<fixed<<setprecision(15);
	fore(i,0,4){
		ld a,b; cin>>a>>b;
		r[i]={a,b};
	}
	fore(_,0,it){
		zx=(r[1]-r[0])/cc(w,0);
		zy=(r[3]-r[0])/cc(0,h);
		vector<cc>ri(4);
		fore(i,0,4)ri[i]=f(r[i]);
		r=ri;
	}
	cout<<real(r[0])<<" "<<imag(r[0])<<"\n";
	return 0;
}
