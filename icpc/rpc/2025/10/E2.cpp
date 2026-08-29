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
typedef long double ld;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ld EPS=1e-9;
struct pt{
	ld x,y;
	pt(ld x, ld y):x(x),y(y){}
	pt(){}
	ld norm2(){return *this**this;}
	ld norm(){return sqrtl(norm2());}
	pt operator+(pt p){return pt(x+p.x,y+p.y);}
	pt operator-(pt p){return pt(x-p.x,y-p.y);}
	pt operator*(ld t){return pt(x*t,y*t);}
	pt operator/(ld t){return pt(x/t,y/t);}
	ld operator%(pt p){return x*p.y-y*p.x;}
	ld operator*(pt p){return x*p.x+y*p.y;}
	bool left(pt p, pt q){
		return (q-p)%(*this-p)>EPS;
	}
	pt unit(){return *this/norm();}
	pt rot(pt r){return pt(*this%r,*this*r);}
};
pt ccw90(1,0);
pt cw90(-1,0);
struct ln{
	pt p,pq;
	ln(pt p, pt q):p(p),pq(q-p){}
	ln(){}
	bool has(pt r){return *this/ln(p,r);}
	bool operator/(ln l){return abs(pq.unit()%l.pq.unit())<=EPS;}
	pt operator^(ln l){ // no son paralelas
		pt r=l.p+l.pq*((p-l.p)%pq/(l.pq%pq));
		return r;
	}
	pt proj(pt r){return p+pq*((r-p)*pq/pq.norm2());}
};

struct circle{
	pt o; ld r;
	circle(pt o, ld r):o(o),r(r){}
	vector<pt> operator^(ln l){
		vector<pt> s;
		pt p=l.proj(o);
		ld d=(p-o).norm();
		if(d-EPS>r)return s;
		if(abs(d-r)<=EPS){s.pb(p);return s;}
		d=sqrtl(r*r-d*d);
		s.pb(p+l.pq.unit()*d);
		s.pb(p-l.pq.unit()*d);
		return s;
	}
};

int main(){FIN;
	ll n; cin>>n;
	vector<pt> a(n);
	fore(i,0,n)cin>>a[i].x>>a[i].y;
	// ld sum=0;
	// fore(i,0,n)sum+=(a[(i+1)%n]-a[i]).norm();
	auto pun=[&](ll i){return a[(i+3*n)%n];};
	ld res=0;
	fore(i,0,n){
		pt l=pun(i-1);
		pt x=pun(i);
		pt r=pun(i+1);
		if(ln(l,r).has(x))continue; // colineal
		ld seg=(l-x).norm()+(r-x).norm();
		pt p; // inter
		bool aden=0;
		ln l0(pun(i-2),l);
		ln l1(pun(i+2),r);
		ld rad=(r-l).norm()/2;
		if(!(l0/l1)){
			p=l0^l1;
			if(p.left(r,l))aden=(p-x).norm()<=rad+EPS;
		}
		ld del=0;
		if(aden)del=(p-l).norm()+(p-r).norm();
		else del=2*rad*sqrtl(2);
		
		
		del-=seg;
		cerr<<i<<": "<<aden<<" "<<rad<<": "<<p.x<<","<<p.y<<": "<<seg<<" "<<del<<"\n";
		res=max(res,del);
	}
	cout<<fixed<<setprecision(15)<<res<<"\n";
	return 0;
}