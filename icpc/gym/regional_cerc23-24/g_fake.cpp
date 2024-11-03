#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet =b;i<jet;i++)
#define pb push_back
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

struct pt{
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
	ld operator%(pt p){return x*p.y-y*p.x;}
	pt unit(){return *this/norm();}
};

pt inter(pt p, pt q, ld r){ // p is center
	pt d=q-p;
	d=d.unit();
	d=d*r;
	return p+d;
}
struct ln{
	pt p,pq;
	ln(pt p, pt q):p(p),pq(q-p){}
	ln(){}
	ld dist(pt r){return (r-proj(r)).norm();}
	pt proj(pt r){return p+pq*((r-p)*pq/pq.norm());}
	pt operator^(ln l){
		pt r=l.p+l.pq*((p-l.p)%pq/(l.pq%pq));
		return r;
	}
};
ln bisector(ln l, ln m, pt p){
	return ln(p,p+l.pq.unit()+m.pq.unit());
}
const ld EPS=1e-9;
int main(){JET
	ll t; cin>>t;
	while(t--){
		pt a,b,c; ld r;
		cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y>>r;
		auto proba=[&](pt p)->ld{
			return (p-a).norm()+(p-b).norm();
		};
		ld res=proba(c);
		// bisectirz
		ln li=bisector(ln(a,c),ln(b,c),c);
		pt di=li.pq;
		di=di.unit();
		di=di*r;
		res=min(res,proba(c+di));
		res=min(res,proba(c-di));
		//
		if(ln(a,b).dist(c)<=r+EPS)res=(b-a).norm();
		pt s=inter(c,a,r),e=inter(c,b,r);
		pt d=(e-s);
		auto val=[&](ld t){
			pt p=s+d*t;
			pt q=inter(c,p,r);
			return proba(q);
		};
		ld l=0,R=1;
		ll it=200;
		while(it--){
			ld ter=(R-l)/3;
			ld m1=l+ter,m2=l+2*ter;
			if(val(m1)>val(m2))l=m1;
			else R=m2;
		}
		res=min(res,val(R));
		cout<<fixed<<setprecision(15)<<res<<"\n";
	}
    return 0;
}