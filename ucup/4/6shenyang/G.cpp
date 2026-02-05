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
typedef long long td;
const td EPS=0;
// const td EPS=1e-9;
struct pt {  // for 3D add z coordinate
	td x,y;
	pt(td x, td y):x(x),y(y){}
	pt(){}
	td norm2(){return *this**this;}
	// td norm(){return sqrt(norm2());}
	bool operator==(pt p){return abs(x-p.x)<=EPS&&abs(y-p.y)<=EPS;}
	pt operator+(pt p){return pt(x+p.x,y+p.y);}
	pt operator-(pt p){return pt(x-p.x,y-p.y);}
	pt operator*(td t){return pt(x*t,y*t);}
	// pt operator/(td t){return pt(x/t,y/t);}
	td operator*(pt p){return x*p.x+y*p.y;}
//	pt operator^(pt p){ // only for 3D
//		return pt(y*p.z-z*p.y,z*p.x-x*p.z,x*p.y-y*p.x);}
	// td angle(pt p){ // redefine acos for values out of range
	// 	return acos(*this*p/(norm()*p.norm()));}
	// pt unit(){return *this/norm();}
	td operator%(pt p){return x*p.y-y*p.x;}
	// 2D from now on
	bool operator<(pt p)const{ // for convex hull
		return x<p.x-EPS||(abs(x-p.x)<=EPS&&y<p.y-EPS);}
	bool left(pt p, pt q){ // is it to the left of directed line pq?
		return (q-p)%(*this-p)>EPS;}
	// pt rot(pt r){return pt(*this%r,*this*r);}
	// pt rot(td a){return rot(pt(sin(a),cos(a)));}
};
pt ccw90(1,0);
pt cw90(-1,0);
// Compute Minkowski sum of two CONVEX polygons (remove collinear first)
// Returns answer in CCW order
void reorder(vector<pt> &p){
	if(!p[2].left(p[0],p[1])) reverse(ALL(p));
	int pos=0;
	fore(i,1,SZ(p)) if(pt(p[i].y,p[i].x) < pt(p[pos].y,p[pos].x)) pos=i;
	rotate(p.begin(), p.begin()+pos, p.end());
}
vector<pt> minkowski_sum(vector<pt> p, vector<pt> q){
	assert(min(SZ(p),SZ(q))>=3);
	// if(min(SZ(p),SZ(q))<3){
	//   vector<pt> v;
	// 	for(pt pp:p) for(pt qq:q) v.pb(pp+qq);
	// 	return chull(v);
	// }
	reorder(p); reorder(q);
	fore(i,0,2) p.pb(p[i]), q.pb(q[i]);
	vector<pt> r;
	int i=0,j=0;
	while(i+2<SZ(p)||j+2<SZ(q)){
		r.pb(p[i]+q[j]);
		auto cross=(p[i+1]-p[i])%(q[j+1]-q[j]);
		i+=cross>=-EPS;
		j+=cross<=EPS;
	}
	return r;
}

ll area2(vector<pt> a){ // area por dos
	ll res=0;
	ll n=SZ(a);
	fore(i,0,n){
		res+=a[i]%a[(i+1)%n];
	}
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		vector<pt> a(n);
		fore(i,0,n)cin>>a[i].x>>a[i].y;
		vector<pt> b(m);
		fore(i,0,m)cin>>b[i].x>>b[i].y;
		fore(i,0,m)b[i].x*=-1,b[i].y*=-1;
		auto c=minkowski_sum(a,b);
		// for(auto p:c){
		// 	cout<<p.x<<","<<p.y<<" ";
		// }
		// cout<<"\n";
		// cout<<"area2 "<<area2(c)<<"\n";
		ld res=area2(a)*area2(b)/ld(area2(c)*2);
		cout<<fixed<<setprecision(15)<<res<<"\n";
	}
	return 0;
}
