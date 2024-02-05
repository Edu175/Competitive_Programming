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
typedef vector<vector<ll>> Matrix;

Matrix operator*(Matrix a, Matrix b){	//no conmutativa
	ll n=SZ(a),m=SZ(b[0]),z=SZ(a[0]);
	Matrix r(n,vector<ll>(m));
	fore(i,0,n)fore(j,0,m)fore(k,0,z)r[i][j]=(r[i][j]+a[i][k]*b[k][j])%MOD;
	return r;
}
cc zx,zy;
vector<cc>R,r(4);
cc f(cc p){
	cc a(real(p),0),b(0,imag(p));
	return zx*a+zy*b+r[0];
}
ll it=2;
int main(){FIN;
	ld h,w; cin>>h>>w;
	R={{0,0},{w,0},{w,h},{0,h}};
	cout<<fixed<<setprecision(15);
	fore(i,0,4){
		ld a,b; cin>>a>>b;
		r[i]={a,b};
	}
	fore(_,0,it){
		zx=(r[1]-r[0])/R[1];
		zy=(r[3]-r[0])/R[3];
		vector<cc>ri(4);
		fore(i,0,4)ri[i]=f(r[i]);
		R=r,r=ri;
	}
	//cout<<f(cc(w,0))<<" "<<f(cc(0,h))<<"\n";
	cc p=(r[0]+r[2])/cc(2,0);
	cout<<real(r[0])<<" "<<imag(r[0])<<"\n";
	return 0;
}
