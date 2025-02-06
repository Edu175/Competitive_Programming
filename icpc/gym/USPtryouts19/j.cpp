#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define SZ(x) ((int) x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
const ld EPS=1e-9;

struct pt {  // for 3D add z coordinate
	ld x,y;
	pt(ld x, ld y):x(x),y(y){}
	pt(){}
	ld norm2(){return *this**this;}
	ld norm(){return sqrt(norm2());}
	pt operator+(pt p){return pt(x+p.x,y+p.y);}
	pt operator-(pt p){return pt(x-p.x,y-p.y);}
	pt operator*(ld t){return pt(x*t,y*t);}
	pt operator/(ld t){return pt(x/t,y/t);}
	ld operator*(pt p){return x*p.x+y*p.y;}
//	pt operator^(pt p){ // only for 3D
//		return pt(y*p.z-z*p.y,z*p.x-x*p.z,x*p.y-y*p.x);}
	ld angle(pt p){ // redefine acos for values out of range
		return acos(*this*p/(norm()*p.norm()));}
	pt unit(){return *this/norm();}
	ld operator%(pt p){return x*p.y-y*p.x;}
	pt rot(pt r){return pt(*this%r,*this*r);}
	pt rot(ld a){return rot(pt(sin(a),cos(a)));}
};
pt ccw90(1,0);
pt cw90(-1,0);
struct ln {
	pt p,pq;
	ln(pt p, pt q):p(p),pq(q-p){}
	ln(){}
	// bool operator/(ln l){return abs(pq.unit()%l.pq.unit())<=EPS;} // 2D
	pt operator^(ln l){ // intersection
		// if(*this/l)return pt(DINF,DINF);
		pt r=l.p+l.pq*((p-l.p)%pq/(l.pq%pq));
		return r;
	}
	ln rot(auto a){return ln(p,p+pq.rot(a));} // 2D
};
ln bisector(pt p, pt q){ // segment bisector (2D)
	return ln((p+q)*.5,p).rot(ccw90);
}
random_device rd;
mt19937 rng(rd());

int main(){
	JET
	ll n; cin>>n;
	vector<pt>a(n);
	fore(i,0,n)cin>>a[i].x>>a[i].y;
	shuffle(ALL(a),rng);
	auto f=[&](vector<pt> r, ll i, auto &&f)->pair<pt,ld>{
		if(SZ(r)==3){
			auto a=r[0],b=r[1],c=r[2];
			auto med=bisector(a,b);
			auto med2=bisector(b,c);
			auto o=med^med2;
			return {o,(a-o).norm2()};
		}
		if(i==n){
			if(SZ(r)<=1)return {(SZ(r)?r[0]:pt({0,0})),0};
			pt o=(r[0]+r[1])/2;
			return {o,(r[0]-o).norm2()};
		}
		auto [o,d]=f(r,i+1,f);
		if((a[i]-o).norm2()<=d)return {o,d};
		r.pb(a[i]);
		return f(r,i+1,f);
	};
	auto [o,d]=f({},0,f);
	cout<<fixed<<setprecision(15);
	cout<<o.x<<" "<<o.y<<" "<<d/2.<<"\n";
	return 0;
}