#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ld EPS=1e-7;

struct pt {
	ld x,y;
	pt(ld x, ld y):x(x),y(y){}
	pt(){}
	ld norm2(){return *this**this;}
	ld norm(){return sqrt(norm2());}
	pt operator+(pt p){return pt(x+p.x,y+p.y);}
	pt operator-(pt p) const {return pt(x-p.x,y-p.y);}
	pt operator*(ld t){return pt(x*t,y*t);}
	pt operator/(ld t){return pt(x/t,y/t);}
	ld operator*(pt p){return x*p.x+y*p.y;}
	ld operator%(pt p){return x*p.y-y*p.x;}
	pt rot(pt r){return pt(*this%r,*this*r);}
	// pt rot(ld a){return rot(pt(sin(a),cos(a)));}
	ld angle(pt p){return acos(*this*p/(norm()*p.norm()));}
};
pt ccw90(1,0),cw90(-1,0);
struct Cmp{
	pt r;
	Cmp(pt r):r(r){}
	int cuad(const pt &a)const {
		if(a.x>0&&a.y>=0)return 0;
		if(a.x<=0&&a.y>0)return 1;
		if(a.x<0&&a.y<=0)return 2;
		if(a.x>=0&&a.y<0)return 3;
		assert(a.x==0&&a.y==0);
		return -1;
	}
	bool cmp(const pt& p1, const pt& p2)const {
		int c1=cuad(p1),c2=cuad(p2);
		if(c1==c2)return p1.y*p2.x<p1.x*p2.y;
		return c1<c2;
	}
	bool operator()(const pt& p1,const pt& p2)const {
		return cmp(p1-r,p2-r);
	}
};

const ld pi=acosl(-1),tau=2*pi;
struct circle {
	pt o; ld r;
	circle(){}
	circle(pt o, ld r):o(o),r(r){}
	vector<pt> operator^(circle c){
		vector<pt> s; ld d=(o-c.o).norm();
		if(d>r+c.r+EPS||d+min(r,c.r)+EPS<max(r,c.r))return s;
		ld x=(d*d-c.r*c.r+r*r)/(2*d),y=sqrt(r*r-x*x);
		pt v=(c.o-o)/d; s.pb(o+v*x-v.rot(ccw90)*y);
		if(y>EPS)s.pb(o+v*x+v.rot(ccw90)*y);
		return s;
	}
	bool in(circle c){
		ld d=(o-c.o).norm();
		return d+r<=c.r+EPS;
	}
	// ld area(){
	// 	return pi*r*r;
	// }
	vector<ld> intercircles(vector<circle> c){
		vector<ld> r(SZ(c)+1);
		fore(i,0,SZ(c)){
			int k=1;Cmp s(c[i].o);
			vector<pair<pt,int> > p={
				{c[i].o+pt(1,0)*c[i].r,0},
				{c[i].o-pt(1,0)*c[i].r,0}};
			fore(j,0,SZ(c))if(j!=i){
				bool b0=c[i].in(c[j]),b1=c[j].in(c[i]);
				if(b0&&(!b1||i<j))k++;
				else if(!b0&&!b1){
					auto v=c[i]^c[j];
					if(SZ(v)==2){
						p.pb({v[0],1});p.pb({v[1],-1});
						if(s(v[1],v[0]))k++;
					}
				}
			}
			sort(ALL(p),[&](pair<pt,int> a, pair<pt,int> b){return s(a.fst,b.fst);});
			fore(j,0,SZ(p)){
				pt p0=p[j?j-1:SZ(p)-1].fst,p1=p[j].fst;
				ld a=(p0-c[i].o).angle(p1-c[i].o);
				r[k]+=(p0.x-p1.x)*(p0.y+p1.y)/2+c[i].r*c[i].r*(a-sin(a))/2;
				k+=p[j].snd;
			}
		}
		return r;
	}
};
int main(){FIN;
	circle a,b;
	cin>>a.o.x>>a.o.y>>a.r;
	cin>>b.o.x>>b.o.y>>b.r;
	cout<<fixed<<setprecision(15);
	auto r=a.intercircles({a,b});
	cout<<r[1]<<"\n";
	return 0;
}
