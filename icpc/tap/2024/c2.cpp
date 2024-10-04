#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
typedef long double ld;

const ld EPS=1e-7;
struct pt {  // for 3D add z coordinate
	ld x,y;
	pt(ld x, ld y):x(x),y(y){}
	pt(){}
	pt operator+(pt p){return pt(x+p.x,y+p.y);}
	pt operator-(pt p){return pt(x-p.x,y-p.y);}
	pt operator*(ld t){return pt(x*t,y*t);}
	pt operator/(ld t){return pt(x/t,y/t);}
	ld operator*(pt p){return x*p.x+y*p.y;}
	ld operator%(pt p){return x*p.y-y*p.x;}
	bool left(pt p, pt q){ // is it to the left of directed line pq?
		return (q-p)%(*this-p)>-EPS;}
};
struct ln {
	pt p,pq;
	ln(pt p, pt q):p(p),pq(q-p){}
	ln(){}
	pt operator^(ln l){ // intersection
		pt r=l.p+l.pq*((p-l.p)%pq/(l.pq%pq));
		return r;
	}
};

int main(){
    JET
    ll n; cin>>n;
	ll x,y,z,x2,y2,z2; cin>>x>>y>>z>>x2>>y2>>z2;
	pt px=ln(pt(x,z),pt(x2,z2))^ln(pt(0,0),pt(1,0));
	pt py=ln(pt(z,y),pt(z2,y2))^ln(pt(0,0),pt(0,1));
	pt p(px.x,py.y);
	// cout<<p.x<<","<<p.y<<"\n";
	vector<pt>a(n);
	fore(i,0,n)cin>>a[i].x>>a[i].y;
	reverse(ALL(a));
	ll fg=1;
	fore(i,0,n){
		fg&=p.left(a[i],a[(i+1)%n]);
	}
	if(fg)cout<<"N\n";
	else cout<<"S\n";
    return 0;
}
