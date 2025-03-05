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
typedef float ld;
const ld EPS=1e-8;

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
int sgn2(double x){return x<0?-1:1;}
struct ln {
	pt p,pq;
	ln(pt p, pt q):p(p),pq(q-p){}
	ln(){}
	// bool has(pt r){return abs(pq%(r-p))<=EPS;} // 2,5 // less precise
	bool has(pt r){return dist(r)<=EPS;} // 5
	// bool has(pt r){return p==r||*this/ln(p,r);} // 6,5
	
	bool seghas(pt r){return has(r)&&(r-p)*(r-(p+pq))<=EPS;}
//	bool operator /(ln l){return (pq.unit()^l.pq.unit()).norm()<=EPS;} // 3D
	bool operator/(ln l){return abs(pq.unit()%l.pq.unit())<=EPS;} // 2D
	bool operator==(ln l){return *this/l&&has(l.p);}
	pt operator^(ln l){ // intersection
		assert(!(*this/l));
		// if(*this/l)return pt(DINF,DINF);
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
string cv(pt p){return to_string(p.x)+","+to_string(p.y);}
string cv(ln l){return cv(l.p)+" -> "+cv(l.pq);}
pt o(0,0);
ln ox(o,{1,0}),oy(o,{0,1});

int main(){FIN;

	// cout<<ox.has({0,0})<<"\n";
	// cout<<ox.has({0.5,0})<<"\n";
	// cout<<ox.has({0,1})<<"\n";
	// return 0;	
	ll n; cin>>n;
	if(n==1){cout<<"0\n";exit(0);}
	vector<pt>a(n);
	set<pt>st;
	fore(i,0,n)cin>>a[i].x>>a[i].y,st.insert(a[i]);
	map<pt,ll>o;
	map<pair<pt,pt>,ll>b;
	ll res=0;
	fore(i,0,n)fore(j,i+1,n){
		res=max(res,++o[(a[i]+a[j])/2]);
		ln l=bisector(a[i],a[j]);
		auto &d=l.pq;
		ll hago=0;
		if(abs(d.y)<EPS)hago=(d.x<0);
		else hago=d.y<0;
		if(hago)d.x*=-1,d.y*=-1;
		l.p=l^(l/ox?oy:ox);
		d=d.unit();
		++b[{l.p,d}];
		b[{a[i],a[j]-a[i]}];
	}
	for(auto [k,v]:o)res=max(res,2*v+(ll)st.count(k));
	for(auto [_k,v]:b){
		auto k=_k; // por que pija es const _k
		ln l(k.fst,k.fst+k.snd);
		v*=2;
		// cout<<cv(l)<<": ";
		fore(i,0,n)v+=l.has(a[i]);//,cout<<cv(a[i])<<"["<<l.has(a[i])<<"] ";;cout<<"\n";
		res=max(res,v);
	}
	cout<<n-res<<"\n";
	return 0;
}