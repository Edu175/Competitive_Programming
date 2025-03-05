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
typedef ll ld;
const ld EPS=0;

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

int main(){FIN;
	ll n; cin>>n;
	vector<pt>a(n);
	fore(i,0,n)cin>>a[i].x>>a[i].y;
	
	ll l=0,r=0;
	fore(i,0,n){
		if(a[i].x<a[l].x)l=i;
		if(a[i].x>a[r].x)r=i;
	}
	ll u=-1,d=-1;
	for(ll i=r+1,did=0;i!=r;i=(i+1)%n){
		if(i==l){did=1;continue;}
		ll &w=(did?d:u);
		if(w==-1||a[i].y<a[w].y)w=i;
	}
	ll hago=0;
	if(d!=-1&&u!=-1)hago=a[d].y>a[u].y;
	else {
		ll p=u,sw=0;
		if(p==-1)sw=1,p=d;
		hago=a[p].left(a[r],a[l]);
		hago^=sw;
	}
	// cout<<l<<" "<<r<<": "<<u<<" "<<d<<"\n";
	if(hago)reverse(ALL(a));//,cout<<"did it\n";
	// esta antihorario
	
	ll res=0;
	fore(i,0,n){
		pt p(a[i]),q(a[(i+1)%n]),r(a[(i+2)%n]);
		res+=q.left(p,r);
	}
	cout<<res<<"\n";
	return 0;
}