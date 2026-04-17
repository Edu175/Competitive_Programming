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
typedef int ll;
typedef double ld;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

const ld EPS=1e-8;
struct pt {
	ld x,y;
	pt(ld x, ld y):x(x),y(y){}
	pt(){}
	inline ld norm2()const{return *this**this;}
	inline ld norm()const{return sqrt(norm2());}
	inline pt operator+(const pt& p)const {return pt(x+p.x,y+p.y);}
	inline pt operator-(const pt& p)const {return pt(x-p.x,y-p.y);}
	inline pt operator*(ld t)const {return pt(x*t,y*t);}
	// inline pt operator/(ld t)const {return *this*(1.0/t);}
	inline pt operator/(ld t){return pt(x/t,y/t);}
	inline ld operator*(const pt& p)const{return x*p.x+y*p.y;}
	inline ld operator%(pt p)const{return x*p.y-y*p.x;}
	inline pt rot(pt r)const{return pt(*this%r,*this*r);}
	// inline pt rot(double a){return rot(pt(sin(a),cos(a)));}
};
// string cv(pt p){return to_string(p.x)+","+to_string(p.y);}
int cuad(const pt &a){
	if(a.x>EPS&&a.y>=-EPS)return 0;
	if(a.x<=EPS&&a.y>EPS)return 1;
	if(a.x<-EPS&&a.y<=EPS)return 2;
	if(a.x>=-EPS&&a.y<-EPS)return 3;
	assert(abs(a.x)<EPS&&abs(a.y)<EPS);
	return -1;
}
bool operator<(const pt& p1, const pt& p2){ // RADIAL
	int c1=cuad(p1),c2=cuad(p2);
	if(c1==c2)return p1.y*p2.x+EPS<p1.x*p2.y; // maybe add eps
	return c1<c2;
}
bool operator<=(const pt& p1, const pt& p2){ // RADIAL
	return !(p2<p1);
}
pt ccw90(1,0);
pt cw90(-1,0);

pair<pt,ld> circumcenter(const pt &a, const pt &b, const pt &c) {
    pt p1=b-a;
    pt p2=c-a;
    ld d=2.0*(p1%p2);
	if(abs(d)<=EPS)return {a,-1}; // collinear
    ld n1=p1.norm2();
    ld n2=p2.norm2();
    // ld inv_d=1.0/d;
    ld cx=(p2.y*n1-p1.y*n2)/d;
    ld cy=(p1.x*n2-p2.x*n1)/d;
	pt o(a.x+cx,a.y+cy);
	ld r2=cx*cx+cy*cy;
    return {o,r2}; 
}
struct circle {
	pt o;ld r;
	circle(pt o, ld r):o(o),r(r){}
	circle(){}
	bool in(pt p){return (o-p).norm()<r-EPS;} // strictly inside
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
random_device rd;
mt19937 rng(175);

int main(){FIN;
	ll n; cin>>n;
	vector<circle> a(n);
	ld res=0;
	fore(i,0,n)cin>>a[i].o.x>>a[i].o.y>>a[i].r,res=max(res,a[i].r);
	vector<pt> b;
	fore(i,0,n)fore(j,i+1,n)for(auto p:(a[i]^a[j])){
		ll bad=0;
		for(auto c:a)bad|=c.in(p);
		if(!bad)b.pb(p);
	}
	// shuffle(ALL(b),rng);
	ld res2=res*res;
	ll m=SZ(b);
	fore(i,0,m)fore(j,i+1,m)fore(k,j+1,m){
		auto [o,r2]=circumcenter(b[i],b[j],b[k]);
		if(r2<=res2)continue;
		circle c(o,sqrt(r2));
		vector<pair<pt,pt>> rans(n);
		vv good(n);
		fore(i,0,n){
			auto v=a[i]^c;
			if(SZ(v)<2)continue;
			good[i]=1;
			auto p=v[0],q=v[1];
			p=p-o; q=q-o;
			if(!(p%q>0))swap(p,q);
			p=p/p.norm();
			q=q/q.norm();
			rans[i]={p,q};
		}
		pt p({1,0});
		fore(i,0,n)if(good[i]){
			auto &[l,r]=rans[i];
			if(cuad(l)<=cuad(r))continue;
			if(p<=r)p=r;
		}
		fore(_,0,n)fore(i,0,n)if(good[i]){
			auto &[l,r]=rans[i];
			if(l<=p&&p<=r)p=r;
		}
		ll did=0;
		fore(i,0,n)if(good[i]){
			auto &[l,r]=rans[i];
			if(cuad(l)<=cuad(r))continue;
			did|=l<=p;
		}
		if(!did)continue;
		res=c.r;
		res2=r2;
	}
	cout<<fixed<<setprecision(15)<<res<<"\n";
	return 0;
}