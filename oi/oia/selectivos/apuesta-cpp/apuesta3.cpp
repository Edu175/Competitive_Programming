#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oia=b; i<oia;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(a) for(auto messi:a)cout<<messi<<" ";cout<<"\n"
using namespace std;
typedef long long ll;
typedef double ld;
const ld EPS=1e-9, DINF=1e7;
struct pt {  // for 3D add z coordinate
	double x,y;
	pt(double x, double y):x(x),y(y){}
	pt(){}
	double norm2(){return *this**this;}
	double norm(){return sqrt(norm2());}
	bool operator==(pt p){return abs(x-p.x)<=EPS&&abs(y-p.y)<=EPS;}
	bool operator!=(pt p){return (!(*this==p));}
	pt operator+(pt p){return pt(x+p.x,y+p.y);}
	pt operator-(pt p){return pt(x-p.x,y-p.y);}
	pt operator*(double t){return pt(x*t,y*t);}
	pt operator/(double t){return pt(x/t,y/t);}
	double operator*(pt p){return x*p.x+y*p.y;}
//	pt operator^(pt p){ // only for 3D
//		return pt(y*p.z-z*p.y,z*p.x-x*p.z,x*p.y-y*p.x);}
	double angle(pt p){ // redefine acos for values out of range
		return acos(*this*p/(norm()*p.norm()));}
	pt unit(){return *this/norm();}
	double operator%(pt p){return x*p.y-y*p.x;}
	// 2D from now on
	bool operator<(pt p)const{ // for convex hull
		return x<p.x-EPS||(abs(x-p.x)<=EPS&&y<p.y-EPS);}
	bool left(pt p, pt q){ // is it to the left of directed line pq?
		return (q-p)%(*this-p)>EPS;}
	pt rot(pt r){return pt(*this%r,*this*r);}
	pt rot(double a){return rot(pt(sin(a),cos(a)));}
};
pt ccw90(1,0);
pt cw90(-1,0);
int sgn2(double x){return x<0?-1:1;}
struct ln {
	pt p,pq;
	ln(pt p, pt q):p(p),pq(q-p){}
	ln(){}
	bool has(pt r){return dist(r)<=EPS;}
	bool seghas(pt r){return has(r)&&(r-p)*(r-(p+pq))<=EPS;}
//	bool operator /(ln l){return (pq.unit()^l.pq.unit()).norm()<=EPS;} // 3D
	bool operator/(ln l){return abs(pq.unit()%l.pq.unit())<=EPS;} // 2D
	bool operator==(ln l){return *this/l&&has(l.p);}
	pt operator^(ln l){ // intersection
		if(*this/l)return pt(DINF,DINF);
		pt r=l.p+l.pq*((p-l.p)%pq/(l.pq%pq));
//		if(!has(r)){return pt(NAN,NAN,NAN);} // check only for 3D
		return r;
	}
	double angle(ln l){return pq.angle(l.pq);}
	int side(pt r){return has(r)?0:sgn2(pq%(r-p));} // 2D
	pt proj(pt r){return p+pq*((r-p)*pq/pq.norm2());}
	pt ref(pt r){return proj(r)*2-r;}
	double dist(pt r){return (r-proj(r)).norm();}
//	double dist(ln l){ // only 3D
//		if(*this/l)return dist(l.p);
//		return abs((l.p-p)*(pq^l.pq))/(pq^l.pq).norm();
//	}
	ln rot(auto a){return ln(p,p+pq.rot(a));} // 2D
};
ln bisector(ln l, ln m){ // angle bisector
	pt p=l^m;
	return ln(p,p+l.pq.unit()+m.pq.unit());
}
ln bisector(pt p, pt q){ // segment bisector (2D)
	return ln((p+q)*.5,p).rot(ccw90);
}
bool cmp(double a, double b){
	if(abs(a-b)<=EPS)return 0;
	return a<b;
}
vector<pt>a; ll n;
vector<double> srt(pt p){// sort points by pendiente
	vector<double>res;
	fore(i,0,n)if(a[i]!=p){
		res.pb(p.angle(a[i]));
	}
	sort(ALL(res));
	return res;
}
pair<bool,bool> check(vector<double>&b, ld m){ //sorted vector of points, check if line m cumple
	ll l0,l1,r0,r1;
	double s=m,e=(s+180>=360?s-180:s+180);
	if(s>e)swap(s,e);
	l0=lower_bound(ALL(b),s,cmp)-b.begin(); l1=upper_bound(ALL(b),s,cmp)-b.begin();
	r0=lower_bound(ALL(b),e,cmp)-b.begin(); r1=upper_bound(ALL(b),e,cmp)-b.begin();
	ll q0=l0+SZ(b)-r1,q1=r0-l1;
	return {(q0==q1),(l1-l0==r1-r0)};
}
vector<double> apuesta(vector<int> &X, vector<int> &Y){
	n=SZ(X);
	a.resize(n);
	fore(i,0,n)a[i]=pt(X[i],Y[i]);
	pt l0=a[0],r0=l0; ll flag=0;
	vector<double>h=srt(l0);
	imp(h);
	fore(i,0,n)if(a[i]!=l0&&check(h,l0.angle(a[i])).fst){r0=a[i],flag=1;}
	cout<<l0.x<<","<<l0.y<<" "<<r0.x<<","<<r0.y<<" "<<flag<<"\n";
	if(!flag)return {};
	pt l1,r1;
	ld ph=l0.angle(r0); flag=0;
	fore(i,0,n)if(a[i]!=l0&&abs(l0.angle(a[i])-ph)>EPS){
		l1=a[i];
		flag=1;
		break;
	}
	if(!flag){// alineados
		sort(ALL(a));
		ld x=a[(n+1)/2-1].x,y=a[(n+1)/2-1].y;
		return {x,y};
	}
	r1=l1; flag=0;
	h=srt(l1);
	fore(i,0,n)if(a[i]!=l1&&check(h,l1.angle(a[i])).fst){r1=a[i],flag=1;}
	cout<<l1.x<<","<<l1.y<<" "<<r1.x<<","<<r1.y<<" "<<flag<<"\n";
	if(!flag)return {};
	pt c=ln(l0,r0)^ln(l1,r1); // might not be lattice
	h=srt(c);
	flag=1;
	fore(i,0,n){
		if(a[i]!=c&&!check(h,c.angle(a[i])).snd)flag=0;
	}
	cout<<c.x<<","<<c.y<<" "<<flag<<"\n";
	if(flag)return{c.x,c.y};
	return {};
}
