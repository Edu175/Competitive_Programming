#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
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
typedef vector<ll> vv;
typedef long double ld;
const ld EPS=1e-12;

struct pt {
	ld x,y;
	pt(ld x, ld y):x(x),y(y){}
	pt(){}
	ld norm2(){return *this**this;}
	ld norm(){return sqrt(norm2());}
	bool operator==(pt p){return abs(x-p.x)<=EPS&&abs(y-p.y)<=EPS;}
	pt operator+(pt p){return pt(x+p.x,y+p.y);}
	pt operator-(pt p){return pt(x-p.x,y-p.y);}
	pt operator*(ld t){return pt(x*t,y*t);}
	pt operator/(ld t){return pt(x/t,y/t);}
	ld operator*(pt p){return x*p.x+y*p.y;}
	pt unit(){return *this/norm();}
	ld operator%(pt p){return x*p.y-y*p.x;}
	// 2D from now on
	bool operator<(pt p)const{ // for convex hull
		return x<p.x-EPS||(abs(x-p.x)<=EPS&&y<p.y-EPS);}
	bool left(pt p, pt q){ // is it to the left of directed line pq?
		return (q-p)%(*this-p)>EPS;}
	pt rot(pt r){return pt(*this%r,*this*r);}
	pt rot(ld a){return rot(pt(sin(a),cos(a)));}
};
pt ccw90(1,0);
pt cw90(-1,0);

struct circle {
	pt o;ld r;
	circle(pt o, ld r):o(o),r(r){}
	// circle(pt x, pt y, pt z){o=bisector(x,y)^bisector(x,z);r=(o-x).norm();}
	bool has(pt p){return (o-p).norm()<=r+EPS;}
	vector<pt> operator^(circle c){ // ccw
		vector<pt> s;
		ld d=(o-c.o).norm();
		if(d>r+c.r+EPS||d+min(r,c.r)+EPS<max(r,c.r))return s;
		ld x=(d*d-c.r*c.r+r*r)/(2*d);
		ld y=sqrt(r*r-x*x);
		pt v=(c.o-o)/d;
		s.pb(o+v*x-v.rot(ccw90)*y);
		if(y>EPS)s.pb(o+v*x+v.rot(ccw90)*y);
		return s;
	}
};
const ld pi=acosl(-1),tau=2*pi;
ld cut(ld a){
	while(a<-EPS)a+=tau;
	while(a>=tau-EPS)a-=tau;
	if(a<0){assert(a>=-EPS);a=0;}
	return a;
}
ld angle(pt p, pt q){
	ld a=atan2l(q.y,q.x)-atan2l(p.y,p.x);
	return cut(a);
}
int main(){
    JET
	ll n,q; cin>>n>>q;
	vector<pt>a(n); a.pb(a[0]);
	vector<ld> d0(n),d1(n+1);
	fore(i,1,n)d0[i]=d0[i-1]+(a[i]-a[i-1]).norm();
	for(ll i=n-1;i>=0;i--)d1[i]=d1[i+1]+(a[i]-a[i+1]).norm();
	vv wh(n);
	fore(i,0,n)wh[i]=d1[i]>d0[i];
	
    return 0;
}