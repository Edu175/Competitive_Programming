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
struct pt{
    ld x,y;
    pt (ld x, ld y):x(x),y(y){}
    pt(){}
    ld norm2(){return *this**this;}
    ld norm(){return sqrt(norm2());}
    bool operator==(pt p){return abs(x-p.x)<=EPS&&abs(y-p.y)<=EPS;}
    pt operator+(pt p){return pt(x+p.x,y+p.y);}
    pt operator- (pt p){return pt(x-p.x,y-p.y);}
    pt operator*(ld t){return pt(x*t,y*t);}
    pt operator/(ld t){return pt(x/t,y/t);}
    ld operator*(pt p){return x*p.x+y*p.y;}
    ld angle (pt p){
        return acos(*this*p/(norm()*p.norm()));
    } 
    pt unit(){return *this/norm();}
    ld operator%(pt p){return x*p.y-y*p.x;}
    bool operator<(pt p)const{
        return x<p.x-EPS||(abs(x-p.x)<=EPS&&y<p.y-EPS);
    }
    bool left(pt p, pt q){
        return (q-p)%(*this-p)>EPS;
    }
    pt rot(pt r){return pt(*this%r,*this*r);}
    pt rot(ld a){return rot(pt(sin(a),cos(a)));}
};
pt ccw90(1,0);
pt cw90(-1,0);
ll eq(ld a, ld b){return abs(a-b)<=EPS;}

ld angulo(pt p){
	ld ret=ccw90.angle(p);
	if(p.y<0)ret=-ret;
	return ret;
}

int main(){JET
	ll n; cin>>n;
	vector<pt>a(n);
	fore(i,0,n)cin>>a[i].x>>a[i].y;
	ld d=(a[1]-a[0]).norm(),ang=angulo(a[1]-a[0]);
	auto v=a[2]-a[0];
	// cout<<v.x<<","<<v.y<<" rotar "<<-ang<<": ";
	v=v.rot(-ang);
	// cout<<v.x<<","<<v.y<<" v\n";
	// vector<pt>vs(2);
	// vs[0]=a[2]-a[1];
	// vs[1]={-vs[0].x,vs[0].y};
	ll res=0;
	// pt o={0,0};
	vector<pt>sa=a;
	sort(ALL(sa));
	auto cant=[&](pt p){
		ll ret=upper_bound(ALL(sa),p)-lower_bound(ALL(sa),p);
		// cout<<"cant "<<p.x<<","<<p.y<<": "<<ret<<"\n";
		return ret;
	};
	// cout<<"trinagles\n";
	// fore(i,0,n)fore(j,0,n)if(i!=j)fore(k,0,n)if(k!=j&&k!=i){
	// 	ld b=(a[1]-a[0]).norm();
	// 	ld c=(a[2]-a[1]).norm();
	// 	ld d=(a[0]-a[2]).norm();
		
	// 	ld b1=(a[j]-a[i]).norm();
	// 	ld c1=(a[k]-a[j]).norm();
	// 	ld d1=(a[i]-a[k]).norm();
		
	// 	if(eq(b/b1,c/c1)&&eq(c/c1,d/d1)){
	// 		cout<<i<<" "<<j<<" "<<k<<"\n";
	// 	}
	// }
	// cout<<"fin trinagles\n";
	
	fore(i,0,n)fore(j,0,n)if(i!=j){
		// cout<<"\n"<<i<<" "<<j<<"\n";
		auto x=a[i],y=a[j];
		auto b=y-x;
		auto vi=v*(b.norm()/d);
		// cout<<vi.x<<","<<vi.y<<" escalado\n";
		fore(ry,0,2){
			auto v1=vi;
			// if(rx)v1.x*=-1;
			if(ry)v1.y*=-1;
			// cout<<v1.x<<","<<v1.y<<" dado vuelta\n";
			ld al=angulo(b);
			auto v2=v1.rot(al);
			// cout<<al<<" grados\n";
			ll q=0;
			// if(rx)q=cant(y+v2);
			q=cant(x+v2);
			// cout<<v2.x<<","<<v2.y<<": "<<q<<"\n";
			res+=q;
		}
	}
	ld l0=(a[1]-a[0]).norm();
	ld l1=(a[2]-a[1]).norm();
	ld l2=(a[0]-a[2]).norm();
	assert(!(eq(l0,l1)&&eq(l1,l2)));
	if(eq(l0,l1)||eq(l1,l2)||eq(l0,l2))res/=2;
	cout<<res<<"\n";
	// cout<<fixed<<setprecision(6);
    return 0;
}