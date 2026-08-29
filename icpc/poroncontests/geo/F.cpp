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
const ld EPS=1e-15;
#define str to_string
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
string cv(pt a){return str(a.x)+","+str(a.y);}
pt ccw90(1,0);
pt cw90(-1,0);

bool in(pt p, pt v, pt q){ // projection of q in line p,p+v lies strictly on segment?
	ld val=v*(q-p);
	return val>0 && val<v.norm2();
}
// ll cnt=0;
vector<pt> solve(vector<pt> all){
	// ll db=cnt==5;
	// if(db)cerr<<"cnt "<<cnt<<"\n";
	// cnt++;
	pt a=all[0],b=all[1],c=all[2],d=all[3];
	pt v=((b-a)-(d-c).rot(cw90)).rot(ccw90);
	if((b-a)*v<0)v=v*(-1); // could assert negation?
	if(v==pt(0,0))v=(b-a);
	// if(db)cerr<<"all ";
	// if(db){for(auto p:all)cerr<<cv(p)<<" ";;cerr<<"\n";}
	// if(db)cerr<<"v: "<<cv(v)<<": "<<v*(b-a)<<" "<<v.rot(ccw90)*(d-c)<<"\n";
	assert(abs(v*(b-a)-v.rot(ccw90)*(d-c))<=EPS);
	v=v*(v*(b-a)/v.norm2());
	if(!in(a,v,c)||!in(a,v,d))return {};
	auto v2=v.rot(ccw90);
	if(!in(c,v2,a)||!in(c,v2,b))return {};
	pt p=a+v;
	ld cu=(p-c)*v2/v2.norm2();
	p=p-v2*cu;
	vector<pt> ret;
	pt dir=v2;
	fore(_,0,4){
		ret.pb(p);
		p=p+dir;
		dir=dir.rot(ccw90);
	}
	assert(p==ret[0]);
	return ret;
}

int main(){FIN;
	#ifdef ONLINE_JUDGE
	freopen("four.in","r",stdin);
	freopen("four.out","w",stdout);
	#endif
	vector<pt> all(4);
	fore(i,0,4)cin>>all[i].x>>all[i].y;
	sort(ALL(all));
	do{
		auto got=solve(all);
		if(SZ(got)){
			cout<<fixed<<setprecision(15);
			fore(i,0,4)cout<<got[i].x<<" "<<got[i].y<<"\n";
			return 0;
		}
	}while(next_permutation(ALL(all)));
	fore(i,0,4)cout<<"0 0\n";
	return 0;
}