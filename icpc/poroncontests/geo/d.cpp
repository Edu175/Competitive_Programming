#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
typedef long double ld;
const ld EPS=1e-11;

struct pt {  // for 3D add z coordinate
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
//	pt operator^(pt p){ // only for 3D
//		return pt(y*p.z-z*p.y,z*p.x-x*p.z,x*p.y-y*p.x);}
	ld angle(pt p){ // redefine acos for values out of range
		return acos(*this*p/(norm()*p.norm()));}
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
int sgn2(ld x){return x<0?-1:1;}
struct ln {
	pt p,pq;
	ln(pt p, pt q):p(p),pq(q-p){}
	ln(){}
	bool has(pt r){return dist(r)<=EPS;}
	bool seghas(pt r){return has(r)&&(r-p)*(r-(p+pq))<=-EPS;}
//	bool operator /(ln l){return (pq.unit()^l.pq.unit()).norm()<=EPS;} // 3D
	bool operator/(ln l){return abs(pq.unit()%l.pq.unit())<=EPS;} // 2D
	bool operator==(ln l){return *this/l&&has(l.p);}
	pt operator^(ln l){ // intersection
		// if(*this/l)return pt(DINF,DINF);
		assert(!(*this/l));
		pt r=l.p+l.pq*((p-l.p)%pq/(l.pq%pq));
//		if(!has(r)){return pt(NAN,NAN,NAN);} // check only for 3D
		return r;
	}
	ld angle(ln l){return pq.angle(l.pq);}
	int side(pt r){return has(r)?0:sgn2(pq%(r-p));} // 2D
	pt proj(pt r){return p+pq*((r-p)*pq/pq.norm2());}
	pt ref(pt r){return proj(r)*2-r;}
	ld dist(pt r){return (r-proj(r)).norm();}
//	ld dist(ln l){ // only 3D
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
const ll ITER=45; // 36
const ll TER=70; // 60

const ld pi=acosl(-1);
string cv(pt p){return to_string(p.x)+","+to_string(p.y);}

struct circle {
	pt o;ld r;
	circle(pt o, ld r):o(o),r(r){}
	circle(pt x, pt y, pt z){o=bisector(x,y)^bisector(x,z);r=(o-x).norm();}
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
	vector<pt> tang(pt p){
		double d=sqrt((p-o).norm2()-r*r);
		return *this^circle(p,d);
	}
};
int main(){FIN;
	pt p,q;
	cin>>p.x>>p.y>>q.x>>q.y;
	pt o; ld rad; cin>>o.x>>o.y>>rad;
	auto in=[&](pt p){return (p-o).norm()+EPS<rad;};
	ln lin(p,q);
	pt pin=lin.proj(o);
	
	// segmento afuera
	auto afuera=[&](){
		cerr<<"afuera\n";
		pt d=(o-p);
		ld obj=d.norm()-rad;
		pt s=p+d.unit()*obj;
		d=(o-q);
		obj=d.norm()-rad;
		pt e=q+d.unit()*obj;
		pt to;
		auto val0=[&](ld m, ll hago=0){
			pt pinga=s+d*m;
			pt ray=pinga-o;
			ray=ray.unit()*rad;
			pt me=o+ray;
			ld ret=(me-p).norm()+(me-q).norm();
			if(hago)to=me;
			return ret;
		};
		auto val1=[&](ld m, ll dbg=0){
			pt me=s+d*m;
			ld ret=(me-p).norm()+(me-q).norm()+(me-to).norm();
			if(dbg){
				cout<<m<<": ";
				cout<<cv(me)<<": ";
				cout<<ret<<"\n";
			}
			return ret;
		};
		auto get=[&](auto val){
			d=e-s;
			// cout<<cv(s)<<" "<<cv(e)<<"\n";
			ld l=0,r=1;
			fore(_,0,TER){
				ld ter=(r-l)/3;
				ld m0=l+ter,m1=l+2*ter;
				if(val(m0)<val(m1))r=m1;
				else l=m0;
			}
			return l;
		};
		auto l=get(val0);
		val0(l,1);
		s=to,e=lin.proj(to);
		l=get(val1);
		cout<<fixed<<setprecision(15)<<val1(l)<<"\n";
		exit(0);
	};
	
	if(!in(pin)||!lin.seghas(pin))afuera();
	
	auto get=[&](pt s, pt e){
		// cout<<cv(s)<<" "<<cv(e)<<"\n";
		ld perim=2*pi*rad;
		ld res=(s-p).norm()+(q-e).norm();
		s=s-o,e=e-o;
		ld alp=atan2(e.y,e.x)-atan2(s.y,s.x);
		alp=abs(alp);
		assert(alp<=2*pi);
		// if(alp>=2*pi)alp-=pi;
		ld arc=perim*(alp/(2*pi));
		arc=min(arc,perim-arc);
		res+=arc;
		return res;
	};
	circle hoyo(o,rad);
	auto a=hoyo.tang(p);
	auto b=hoyo.tang(q);
	vector<ld>ans;
	fore(i,0,SZ(a))fore(j,0,SZ(b))ans.pb(get(a[i],b[j]));
	auto res=*min_element(ALL(ans));
	cout<<fixed<<setprecision(15)<<res<<"\n";
	return 0;
}