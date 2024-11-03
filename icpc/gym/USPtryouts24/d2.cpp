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
typedef pair<ll,ll> ii;
typedef long double ld;
typedef vector<ld> vv;
const ld EPS=1e-7,INF=1e15;
const ld sQ=sqrt(3);
struct pt{
	ld x,y,z;
	pt(ld x,ld y,ld z): x(x), y(y), z(z) {}	
	pt() {}
	ld norm2() {return *this**this;}
	ld norm() {return sqrt(norm2());}
	pt operator+(pt p) {return pt(x+p.x, y+p.y,z+p.z);}
	pt operator-(pt p) {return pt(x-p.x, y-p.y,z-p.z);}
	ld operator*(pt p) {return x*p.x+y*p.y+z*p.z;}
	pt operator*(ld t) {return pt(x*t,y*t,z*t);}
	pt operator/(ld t) {return pt(x/t,y/t,z/t);}
	pt unit() {return *this/norm();};
	void show(){cout<<x<<" "<<y<<" "<<z<<" ";}
};
pt e,t;
pt E[8];
pt D[8];
//pt C[6];
//pt A[12];
bool in(pt p, ld r){
	return p.x-r>=-EPS&&p.y-r>=-EPS&&p.z-r>=-EPS&&p.x+r<=e.x+EPS&&p.y+r<=e.y+EPS&&p.z+r<=e.z+EPS;
}
ld r;
bool can(ld h, ll i){
	pt lol=E[i]+D[i]*h;
	bool y=in(lol,h/sQ);
	//cout<<"ESQUINA "<<i<<" "<<E[i].x<<" "<<E[i].y<<" "<<E[i].z<<"\n";
	//cout<<lol.x<<" "<<lol.y<<" "<<lol.z<<" "<<h/sQ<<" "<<h<<"\n";
	//cout<<y<<"\n";
	y&=(abs((t-lol).norm()-r)>=h/sQ-EPS);
	//t.show(); lol.show(); cout<<y<<"\n";
	//cout<<y<<"\n";
	return y;
}
int main(){
	JET
	
	cin>>e.x>>e.y>>e.z>>t.x>>t.y>>t.z>>r;
	vv v1={0,e.x};
	vv v2={0,e.y};
	vv v3={0,e.z};
	vv xd={1.,-1.};
	fore(i,0,2)fore(j,0,2) fore(k,0,2){
		E[4*i+2*j+k]=(pt(v1[i],v2[j],v3[k]));
		D[4*i+j*2+k]=(pt(xd[i],xd[j],xd[k])).unit();
	}
	//fore(i,0,8) cout<<"ESQUINA "<<i<<" "<<E[i].x<<" "<<E[i].y<<" "<<E[i].z<<" "<<D[i].x<<" "<<D[i].y<<" "<<D[i].z<<"\n";
	ld m=0.;
	fore(i,0,8){
		ld l=0., f=INF;
		while(f-l>=EPS){
			ld h=(l+f)/2;
			if(can(h,i)) l=h;
			else f=h;
		}
		l/=sQ;
		m=max(m,l);
	}
	 cout<<fixed<<setprecision(15)<<m<<"\n";
		
}