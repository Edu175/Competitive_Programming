#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
random_device rd;
mt19937 rng(rd());
const ld EPS=1e-9;
struct pt{
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
	pt unit(){return *this/norm();}
	ld operator%(pt p){return x*p.y-y*p.x;}
	pt rot(pt r){return pt(*this%r,*this*r);}
};
pt ccw90(1,0);
 
struct ln {
	pt p,pq;
	ln(pt p, pt q):p(p),pq(q-p){}
	ln(){}
	bool has(pt r){return dist(r)<=EPS;}
	bool operator/(ln l){return abs(pq.unit()%l.pq.unit())<=EPS;} // 2D
	bool operator==(ln l){return *this/l&&has(l.p);}
	pt operator^(ln l){ // intersection
		assert(!(*this/l));
		// if(*this/l)return pt(DINF,DINF);
		pt r=l.p+l.pq*((p-l.p)%pq/(l.pq%pq));
		return r;
	}
	pt proj(pt r){return p+pq*((r-p)*pq/pq.norm2());}
	ld dist(pt r){return (r-proj(r)).norm();}
	ln rot(auto a){return ln(p,p+pq.rot(a));} // 2D
};
ln bisector(pt p, pt q){return ln((p+q)*.5,p).rot(ccw90);}
 
 
struct circle {
	pt o;ld r;
	circle(pt o, ld r):o(o),r(r){}
	circle(pt x, pt y, pt z){o=bisector(x,y)^bisector(x,z);r=(o-x).norm();}
	bool has(pt p){return (o-p).norm()<=r+EPS;}
};
 
circle get(pt x, pt y){
	pt mid=(x+y)/2;
	return circle(mid,(mid-x).norm());
}
 
circle get(pt x, pt y,pt z){
	ld xy=(x-y).norm();
	ld yz=(y-z).norm();
	ld xz=(x-z).norm();
	ld mx=max({xy,yz,xz});
	pt mid;
	if(abs(xy-mx)<EPS) mid=(x+y)/2;
	if(abs(yz-mx)<EPS) mid=(z+y)/2;
	if(abs(xz-mx)<EPS) mid=(x+z)/2;
	ld r=max({(mid-x).norm(),(mid-y).norm(),(mid-z).norm()});
	return circle(mid,r);
}
int main(){
	JET
	ll n; cin>>n;
	vector<pt>a(n);
	fore(i,0,n)cin>>a[i].x>>a[i].y;
	
	ll m; cin>>m;
	vector<pt>b(m);
	fore(i,0,m)cin>>b[i].x>>b[i].y;
	
	vector<pt> all;
	fore(i,0,n)fore(j,0,m)all.pb(a[i]-b[j]);
	
	circle ans(pt(0,0),-1);
	shuffle(ALL(all),rng);
	fore(i,0,n) if(!ans.has(all[i])){
		ans=circle(all[i],0);
		fore(j,0,i) if(!ans.has(all[j])){
			ans=get(all[i],all[j]);
			fore(k,0,j) if(!ans.has(all[k])){
				if(ln(all[i],all[j]).has(all[k])) ans=get(all[i],all[j],all[k]);
				else ans=circle(all[i],all[j],all[k]);
			}
		}
	}
	cout<<fixed<<setprecision(15)<<ans.r<<" "<<ans.o.x<<" "<<ans.o.y<<"\n";
	return 0;
}