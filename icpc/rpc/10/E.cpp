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
const ld EPS=1e-11;
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
#define str to_string
string cv(pt p){return str(p.x)+","+str(p.y);}
pt ccw90(1,0);
pt cw90(-1,0);
struct ln{
	pt p,pq;
	ln(pt p, pt q):p(p),pq(q-p){}
	ln(){}
	bool has(pt r){return dist(r)<=EPS;}
	bool operator/(ln l){return abs(pq.unit()%l.pq.unit())<=EPS;}
	pt operator^(ln l){ // no son paralelas
		pt r=l.p+l.pq*((p-l.p)%pq/(l.pq%pq));
		return r;
	}
	pt proj(pt r){return p+pq*((r-p)*pq/pq.norm2());}
	ld dist(pt r){return (r-proj(r)).norm();}
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
		ln bor(pun(i-2),pun(i+2));
		if(bor.has(x)&&bor.has(l)&&bor.has(r))continue; // colineal
		
		ld rad=(r-l).norm()/2;
		circle c((l+r)/2,rad);
		
		auto get=[&](ln lin, pt out){
			auto rq=c^lin;
			// cerr<<"get ";
			// for(auto i:rq)cerr<<cv(i)<<" ";;cerr<<"\n";
			for(auto i:rq)if(i.left(r,l))return i;
			return out;
		};
		auto pinga=ln(l,pun(i-2));
		pt s0=get(pinga,l);
		pinga.pq=pinga.pq.rot(cw90);
		pt e0=get(pinga,r);
		
		pinga=ln(r,pun(i+2));
		pt e1=get(pinga,r);
		pinga.pq=pinga.pq.rot(ccw90);
		pt s1=get(pinga,l);
		
		// cerr<<cv(s0)<<" "<<cv(e0)<<"\n";
		// cerr<<cv(s1)<<" "<<cv(e1)<<"\n";
		
		auto val=[&](pt p){return (p-l).norm();};
		auto mymin=[&](pt p, pt q){
			return val(p)<val(q)?p:q;
		};
		auto mymax=[&](pt p, pt q){
			return val(p)>val(q)?p:q;
		};
		pt s=mymax(s0,s1);
		pt e=mymin(e0,e1);
		
		ld cur;
		pt p=(c.o-l).rot(cw90)+c.o;
		
		auto cand=[&](pt p){return (p-l).norm()+(p-r).norm();};
		if(val(s)>val(e)){
			assert(0);
			cur=cand(ln(pun(i-2),l)^ln(r,pun(i+2)));
		}
		if(val(s)-EPS<=val(p)&&val(p)<=val(e)+EPS){
			cur=sqrtl(2)*2*rad;
			// cerr<<"CHOTA\n";
		}
		else {
			cur=max(cand(s),cand(e));
		}
		
		ld seg=cand(x);
		
		// cerr<<i<<": "<<cv(s)<<" "<<cv(e)<<": "<<cv(p)<<" p: "<<cur<<": "<<cur-seg<<"\n\n";
		
		cur-=seg;
		res=max(res,cur);
	}
	cout<<fixed<<setprecision(15)<<res<<"\n";
	return 0;
}