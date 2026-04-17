#include <bits/stdc++.h>
#define fore(i,a,b) for(int i=a, jet=b; i<jet;i++)
#define fst first
#define snd second 
#define pb push_back
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ld EPS=1e-9;

struct pt {  // for 3D add z coordinate
	ld x,y,z;
	pt(ld x, ld y, ld z):x(x),y(y),z(z){}
	pt(){}
	ld norm2(){return *this**this;}
	ld norm(){return sqrt(norm2());}
	pt operator+(pt p){return pt(x+p.x,y+p.y,z+p.z);}
	pt operator-(pt p){return pt(x-p.x,y-p.y,z-p.z);}
	pt operator*(ld t){return pt(x*t,y*t,z*t);}
	pt operator/(ld t){return pt(x/t,y/t,z/t);}

	ld operator*(pt p){return x*p.x+y*p.y+z*p.z;}
	pt operator^(pt p){ // only for 3D
		return pt(y*p.z-z*p.y,z*p.x-x*p.z,x*p.y-y*p.x);}
	pt unit(){return *this/norm();}
};
string str(auto x){return to_string(x);}
string cv(pt p){return str(p.x)+","+str(p.y)+","+str(p.z);}
struct plane {
	pt a,n; // n: normal unit vector
	plane(pt a, pt b, pt c):a(a),n(((b-a)^(c-a)).unit()){
		// cout<<"[created "<<cv(a)<<" "<<cv(n)<<"] \n";
	}
	plane(){}
	bool has(pt p){return abs((p-a)*n)<=EPS;}
	bool up(pt p){
		// cout<<"up "<<cv(a)<<" "<<cv(n)<<" | "<<cv(p)<<": "<<((p-a)*n)<<" = "<<(((p-a)*n)>=-EPS)<<"\n";
		return ((p-a)*n)>=-EPS;} // o igual
};
const ld pi=acosl(-1);
pt cv(ld d, ld l){
	// cout<<"cv "<<d<<" "<<l<<": ";
	d=d/180*pi; l=l/180*pi;
	auto res=pt(cos(l)*cos(d),sin(l)*cos(d),sin(d));
	// cout<<d<<" "<<l<<": "<<cv(res)<<"\n";
	return res;
}
ld sq(ld x){return x*x;}
vector<ld> bhaskara(ld a, ld b, ld c){
	ld lam=sq(b)-4*a*c;
	// cout<<lam<<" lam\n";
	if(lam<-EPS)return {};
	lam=abs(lam);
	ld x1=(-b+sqrtl(lam))/(2*a);
	ld x2=(-b-sqrtl(lam))/(2*a);
	vector<ld> res;
	if(x1>-EPS)res.pb(x1);
	if(x2>-EPS)res.pb(x2);
	return res;
	// if(abs(lam)<=EPS)return {x1};
	// return {x1,x2};
}
int main(){
	JET
	pt o; cin>>o.x>>o.y>>o.z;
	ld r; cin>>r;
	vector<pt> a;
	fore(i,0,3){
		ld d,l; cin>>d>>l;// l=-l;
		// cout<<d<<" "<<l<<" d l\n";
		pt p=cv(d,l);
		p=p*r;
		a.pb(p);
	}
	// for(auto i:a)cout<<cv(i)<<" ";;cout<<" a\n";
	if(plane(a[0],a[1],a[2]).up(pt(0,0,0)))swap(a[2],a[1]);
	// for(auto i:a)cout<<cv(i)<<" ";;cout<<" a\n";
	
	pt p,d;
	cin>>p.x>>p.y>>p.z; p=p-o;
	cin>>d.x>>d.y>>d.z;
	auto ks=bhaskara(sq(d.x)+sq(d.y)+sq(d.z),
					 2*(p.x*d.x+p.y*d.y+p.z*d.z),
					 sq(p.x)+sq(p.y)+sq(p.z)-sq(r));
	auto is=[&](pt p)->bool{
		// cout<<"is: "<<cv(p)<<": ";
		// return plane(a[0],a[1],a[2]).up(p); // falso
		bool res=1;
		fore(i,0,3){
			pt u=a[i],v=a[(i+1)%3];
			res&=(plane(pt(0,0,0),u,v).up(p));
		}
		// cout<<res<<"\n";
		return res;
	};
	if(!SZ(ks)){
		cout<<"NO\n";
		return 0;
	}
	// cout<<SZ(ks)<<"\n";
	if(SZ(ks)>1&&abs(ks[0])>abs(ks[1]))swap(ks[0],ks[1]);
	bool flag=is(p+d*ks[0]);
	// for(auto k:ks)flag|=is(p+d*k);
	if(flag)cout<<"YES\n";
	else cout<<"NO\n";
	return 0;
}
