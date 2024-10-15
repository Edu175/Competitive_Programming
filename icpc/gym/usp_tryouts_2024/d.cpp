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
const ld EPS=1e-9,INF=1e15;
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
};
pt e,t;
pt E[8];
pt C[6];
pt A[12];
bool in(pt p, ld r){
	return p.x-r>=0&&p.y-r>=0&&p.z-r>=0&&p.x+r<=e.x+0&&p.y+r<=e.y+0&&p.z+r<=e.z+0;
}
ld r;
bool can(ld h){
	bool y=false;
	fore(i,0,8){
		y=in(t+E[i]*h,h-r);
		//cout<<(t+E[i]*h).x<<" "<<(t+E[i]*h).y<<" "<<(t+E[i]*h).z<<"\n";
		if(y) return y;
	}
	fore(i,0,6){
		if(y) return y;
		y=in(t+C[i]*h,h-r);
	}
	fore(i,0,12){
		if(y) return y;
		y=in(t+A[i]*h,h-r);
	}
	return y;
}
int main(){
	JET
	
	cin>>e.x>>e.y>>e.z>>t.x>>t.y>>t.z>>r;
	vv v1={0,e.x};
	vv v2={0,e.y};
	vv v3={0,e.z};
	fore(i,0,2)fore(j,0,2) fore(k,0,2){
		E[4*i+2*j+k]=(pt(v1[i],v2[j],v3[k])-t).unit();
	}
	fore(i,0,2)fore(j,0,2){
		A[6*i+3*j]=(pt(v1[i],v2[j],v3[1]/2)-t).unit();
		A[6*i+3*j+1]=(pt(v1[1]/2,v2[i],v3[j])-t).unit();
		A[6*i+3*j+2]=(pt(v1[i],v2[1]/2,v3[j])-t).unit();
	}
	fore(i,0,12) cout<<"Arista "<<i<<" "<<A[i].x<<" "<<A[i].y
<<" "<<A[i].z<<"\n";
	// fore(i,0,8){
	// 	cout<<"vector esquina "<<i<<" "<< E[i].x<<" "<<E[i].y<<" "<<E[i].z<<"\n";
	// }

	C[0]=pt(1.,0,0);
	C[1]=pt(-1.,0,0);
	C[2]=pt(0,1,0);
	C[3]=pt(0,-1.,0);
	C[4]=pt(0,0,1.);
	C[5]=pt(0,0,-1.);
	ld l=r;//f=r+min(e.x,min(e.y,e.z));
	ld f=r+INF;
	 while(f-l>=EPS){
	 	ld h=(l+f)/2;
	 	if(can(h)) l=h;
	 	else f=h;
	 }
	l-=r;
	//cout<<can(5.72)<<"\n";
	 cout<<fixed<<setprecision(15)<<l<<"\n";
	return 0;
}
/*10 10 10
3.14159265 2.71828182 5.0000000
2.50000000
Arista 0 -0.756217 -0.654321 0
Arista 1 0.310413 -0.45404 -0.83516
Arista 2 -0.496259 0.36043 -0.789821
Arista 3 -0.39614 0.91819 0
Arista 4 0.310413 -0.45404 0.83516
Arista 5 -0.496259 0.36043 0.789821
Arista 6 0.929644 -0.368458 0
Arista 7 0.205884 0.806707 -0.553927
Arista 8 0.780353 0.259615 -0.568902
Arista 9 0.685631 0.727949 0
Arista 10 0.205884 0.806707 0.553927
Arista 11 0.780353 0.259615 0.568902
3.051871671643263
*/

/*
vector esquina 0 0.613285 0.651137 0.447104
vector esquina 1 0.613285 0.651137 -0.447104
vector esquina 2 0.769555 -0.305008 0.56103
vector esquina 3 0.769555 -0.305008 -0.56103
vector esquina 4 -0.335099 0.776706 0.533326
vector esquina 5 -0.335099 0.776706 -0.533326
vector esquina 6 -0.483272 -0.418154 0.769152
vector esquina 7 -0.483272 -0.418154 -0.769152
2.682764275010570


*/