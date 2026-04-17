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
typedef double ld;
const ld EPS=1e-10,EPS2=1e-13;

string str(auto x){return to_string(x);}
struct pt {
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
	pt unit(){return *this/norm();}
	ld operator%(pt p){return x*p.y-y*p.x;}
	// 2D from now on
	bool left(pt p, pt q){ // is it to the left of directed line pq?
		return (q-p)%(*this-p)>EPS;}
	pt rot(pt r){return pt(*this%r,*this*r);}
	string cv(){return str(x)+","+str(y);}
};
ld area(vector<pt> a){
	ld res=0; ll n=SZ(a);
	fore(i,0,n)res+=a[i]%a[(i+1)%n];
	res=abs(res)/2.;
	return res;
}
pt ccw90(1,0);
pt cw90(-1,0);
struct ln {
	pt p,pq;
	ln(pt p, pt q):p(p),pq(q-p){}
	ln(){}
	bool operator/(ln l){return abs(pq.unit()%l.pq.unit())<=EPS;} // 2D
	pt operator^(ln l){ // intersection
		assert(!(*this/l));
		pt r=l.p+l.pq*((p-l.p)%pq/(l.pq%pq));
		return r;
	}
};
struct circle {
	pt o;ld r;
	circle(pt o, ld r):o(o),r(r){}
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
const ld pi=atan2(0,-1),tau=2*pi;
ld cut(ld a){
	while(a<-EPS2)a+=tau;
	while(a>=tau-EPS2)a-=tau;
	if(a<0){assert(a>=-EPS2);a=0;}
	return a;
}
ld angle(pt p, pt q, ll comp=0){ // may be more than pi
	if(comp)return angle(q,p);
	ld a=atan2(q.y,q.x)-atan2(p.y,p.x);
	return cut(a);
}

pt get(pt a, pt b, ld r0, ld r1){ // donde se tocan, para la derecha
	circle c0(a,r0),c1(b,r1);
	vector<pt> rq=c0^c1;
	if(SZ(rq)<=1)return (a+b)/2;
	fore(i,0,2)if(rq[i].left(b,a))return rq[i];
	assert(0);
}

struct elem{
	pt p; ld s; ll i; ld ang=0;
};

int main(){
	JET
	ll n,q; cin>>n>>q;
	vector<pt> _a(n);
	fore(i,0,n)cin>>_a[i].x>>_a[i].y;
	ld primero=angle(_a[n-1]-_a[0],_a[1]-_a[0]);
	vector<elem> oA={{_a[0],0,0,primero/2}},oB=oA;
	auto arma=[&](vv per, auto &out, ll wh){
		for(auto i:per){
			auto &[p,s,lkdjf,ang]=out.back();
			auto q=_a[i];
			ld dis=(p-q).norm();
			if(SZ(out)>=2){
				ang=angle(p-out[SZ(out)-2].p,q-p,wh);
			}
			out.pb({q,dis+s,i,-1}); // dsp
		}
	};
	vv per(n-1); iota(ALL(per),1);
	arma(per,oA,0);
	reverse(ALL(per));
	arma(per,oB,1);
	
	vector<ld> dA(n),dB(n);
	for(auto [asd,s,i,askhd]:oA)dA[i]=s;
	for(auto [asd,s,i,askhd]:oB)dB[i]=s;
	auto mine=[&](ll i, ll wh)->bool {
		if(i==0)return 1;
		return (dA[i]<dB[i]-EPS)^wh;
	};
	
	vector<pair<ld,ll>> qs(q);
	fore(i,0,q){
		ld r; cin>>r;
		qs[i]={r,i};
	}
	sort(ALL(qs));
	vector<ld> ans(q);
	
	ll pA=0,pB=0;
	vector<ld> c(3);
	ld fij=0;
	vector<elem> a,b;
	ld r;
	ll sz=0,gotall=0;
	auto upd=[&](elem x, ld sig){
		assert(x.s>-0.5);
		c[0]+=sig*x.s*x.s*x.ang/2;
		c[1]-=sig*x.s*x.ang;
		c[2]+=sig*x.ang/2;
	};
	auto agr=[&](ll w, elem x){
		auto &v=(w?b:a);
		if(SZ(v))upd(v.back(),1);
		v.pb(x);
		sz++;
		if(sz>=n+1)gotall=1;
	};
	auto sac=[&](ll w){
		auto &v=(w?b:a);
		v.pop_back();
		upd(v.back(),-1);
	};
	auto go=[&](ll w){
		auto &o=(w?oB:oA);
		auto &p=(w?pB:pA);
		while(mine(o[p].i,w)&&o[p].s<r-EPS){
			auto x=o[p]; p++;
			agr(w,x);
		}
	};
	auto bad=[&](ll w){ // ya saca
		auto &u=(w?a:b);
		auto &v=(w?b:a);
		elem x=u.back();
		elem y=v.back();
		elem z=v.end()[-2];
		ld r0=r-x.s;
		ld r1=r-y.s;
		ln l(z.p, y.p);
		l.p=y.p; l.pq=l.pq*(r1/l.pq.norm());
		pt q=l.p+l.pq;
		if(!((q-x.p).norm()<=r0+EPS))return 0;
		fij-=area({x.p,y.p,z.p});
		sac(w);
		u.back().ang+=angle(y.p-x.p, z.p-x.p, !w);
		v.back().ang+=angle(x.p-z.p, y.p-z.p, !w);
		return 1;
	};
	for(auto [_r,idx]:qs){
		r=_r;
		go(0); go(1);
		if(gotall){
			assert(min(SZ(a),SZ(b))>=2);
			while(bad(0));
			while(bad(1));
		}
		
		// ultima parte
		elem eA=a.back();
		elem eB=b.back();
		
		pt xA=eA.p;
		ld r0=r-eA.s;
		pt xB=eB.p;
		ld r1=r-eB.s;
		
		ld res=fij;
		res+=c[0]+r*c[1]+r*r*c[2];
		
		if(!gotall){
			res+=r0*r0*eA.ang/2;
			res+=r1*r1*eB.ang/2;
			ans[idx]=res;
			continue;
		}
		
		
		pt p=get(xA,xB,r0,r1);
		res+=area({xA,xB,p});
		
		ld sacA=angle(p-xA,xB-xA);
		ld sacB=angle(xA-xB,p-xB);
		res+=r0*r0*(eA.ang-sacA)/2;
		res+=r1*r1*(eB.ang-sacB)/2;
		
		ans[idx]=res;
	}
	for(auto i:ans)cout<<fixed<<setprecision(15)<<i<<"\n";
	
	return 0;
}