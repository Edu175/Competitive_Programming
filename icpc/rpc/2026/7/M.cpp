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
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
typedef long double ld;
const ld EPS=1e-12;

struct pt {  // for 3D add z coordinate
	ld x,y;
	pt(ld x, ld y):x(x),y(y){}
	pt(){}
	ld norm2(){return *this**this;}
	ld norm(){return sqrt(norm2());}
	bool operator==(pt p){return abs(x-p.x)<=EPS&&abs(y-p.y)<=EPS;}
	pt operator+(pt p){return pt(x+p.x,y+p.y);}
	pt operator-(pt p)const {return pt(x-p.x,y-p.y);}
	pt operator*(ld t){return pt(x*t,y*t);}
	pt operator/(ld t){return pt(x/t,y/t);}
	ld operator*(pt p){return x*p.x+y*p.y;}
//	pt operator^(pt p){ // only for 3D
//		return pt(y*p.z-z*p.y,z*p.x-x*p.z,x*p.y-y*p.x);}
	ld angle(pt p){ // redefine acos for values out of range
		return acos(*this*p/(norm()*p.norm()));}
	pt unit(){return *this/norm();}
	ld operator%(pt p){return x*p.y-y*p.x;}
	bool operator<(pt p)const{ // for convex hull
		return x<p.x-EPS||(abs(x-p.x)<=EPS&&y<p.y-EPS);}
	bool left(pt p, pt q){return (q-p)%(*this-p)>EPS;}
	bool leftOrAt(pt p, pt q){return !left(q,p);}
	pt rot(pt r){return pt(*this%r,*this*r);}
	pt rot(ld a){return rot(pt(sin(a),cos(a)));}
};
pt ccw90(1,0), cw90(-1,0);
vector<pt> chull(vector<pt> p){// CCW order
	if(SZ(p)<3) return p;
	vector<pt> r; sort(ALL(p)); int k=0;
	fore(_,0,2){//first lower hull, then upper hull
		fore(i,0,SZ(p)){
			while(SZ(r)>1+k&&r.back().leftOrAt(r[SZ(r)-2],p[i]))r.pop_back();
			r.pb(p[i]);
		}
        r.pop_back(),k=SZ(r),reverse(ALL(p));
	}
	return r;
}
struct ln {
	pt p,pq;
	ln(pt p, pt q):p(p),pq(q-p){}
	ln(){}
	pt proj(pt r){return p+pq*((r-p)*pq/pq.norm2());}
	pt ref(pt r){return proj(r)*2-r;}
};
void fail(){
	cout<<"impossible\n";
	exit(0);
}
void joya(){
	cout<<"possible\n";
	exit(0);
}
int main(){FIN;
	ll n; cin>>n;
	if(n==1)joya();
	vector<pt> a(n),b(n);
	map<pt,ll> ty;
	vector<pt> all;
	fore(i,0,n){
		cin>>a[i].x>>a[i].y;
		a[i]=a[i]*2;
		ty[a[i]]=0;
		all.pb(a[i]);
	}
	fore(i,0,n){
		cin>>b[i].x>>b[i].y;
		b[i]=b[i]*2;
		ty[b[i]]=1;
		all.pb(b[i]);
	}
	auto c=chull(all);
	if(SZ(c)&1)fail();
	vector<pt> ms;
	fore(i,0,SZ(c)){
		ll j=(i+1)%(SZ(c));
		pt me=c[i],he=c[j];
		if(ty[me]!=ty[he]){
			ms.pb((he+me)/2);
		}
	}
	if(SZ(ms)!=2)fail();
	pt p=ms[0],q=ms[1];
	if(p==q){
		pt d=c[0]-p;
		d=d.rot(ccw90);
		q=p+d;
	}
	if(!a[0].left(p,q))swap(p,q);
	ln l(p,q);
	for(auto me:a)if(!me.left(p,q))fail();
	for(auto me:b)if(!me.left(q,p))fail();
	for(auto &i:b)i=l.ref(i);
	sort(ALL(a));
	sort(ALL(b));
	fore(i,0,n)if(a[i]!=b[i])fail();
	joya();
	return 0;
}
