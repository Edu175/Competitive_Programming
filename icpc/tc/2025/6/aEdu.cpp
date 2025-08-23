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
const ld EPS=1e-15;
void tle(bool b){
	if(b){
		while(clock()/CLOCKS_PER_SEC<100);
	}
}
random_device rd;
mt19937 rng(rd());

struct pt{
	ld x,y;
	pt(ld x, ld y): x(x), y(y){}
	pt() {}
	ld norm2(){return *this**this;}
	ld norm(){return sqrtl(norm2());}
	pt operator+(pt p){return pt(x+p.x,y+p.y);}
	pt operator-(pt p){return pt(x-p.x,y-p.y);}
	pt operator*(ld t){return pt(x*t,y*t);}
	pt operator/(ld t){return pt(x/t,y/t);}
	ld operator*(pt p){return x*p.x+y*p.y;}
	ld operator%(pt p){return x*p.y-y*p.x;}
	bool operator<(pt p)const{
		return ii({x,y}) < ii({p.x,p.y});
	}
	bool left(pt p, pt q){
		return (q-p)%(*this-p)>0;
	}
	pt rot(pt r){return pt(*this%r,*this*r);}
	pt rot(ld a){return rot(pt(sin(a),cos(a)));}
	pt unit(){return *this/norm();}
};
pt ccw90(1,0);
pt cw90(-1,0);
struct ln {
	pt p,pq;
	ln(pt p, pt q):p(p),pq(q-p){}
	ln(){}
	bool operator/(ln l){return abs(pq.unit()%l.pq.unit())<=EPS;} // 2D
	pt operator^(ln l){ // intersection
		// if(*this/l)return pt(DINF,DINF);
		assert(!(*this/l));
		pt r=l.p+l.pq*((p-l.p)%pq/(l.pq%pq));
		return r;
	}
	ln rot(auto a){return ln(p,p+pq.rot(a));} // 2D
};
ln bisector(pt p, pt q){ // segment bisector (2D)
	return ln((p+q)*.5,p).rot(ccw90);
}
int main(){
	JET
	
	ll m; cin>>m;
	vector<pt>b(m);
	fore(i,0,m)cin>>b[i].x>>b[i].y;
	
	ll n; cin>>n;
	vector<pt>a(n);
	fore(i,0,n)cin>>a[i].x>>a[i].y;
	
	vector<pt> all(n*m);
	ll cnt=0;
	fore(i,0,n)fore(j,0,m)all[cnt++]=(a[i]-b[j]);
	
	shuffle(ALL(all),rng);
	auto f=[&](vector<pt> r, ll i, auto &&f)->pair<pt,ld>{
		if(SZ(r)==3){
			auto a=r[0],b=r[1],c=r[2];
			auto med=bisector(a,b);
			auto med2=bisector(b,c);
			pt o;
			if(med/med2){
				o=(min({a,b,c})+max({a,b,c}))/2;
			}
			else o=med^med2;
			return {o,(a-o).norm()};
		}
		if(i==n*m){
			if(SZ(r)<=1)return {(SZ(r)?r[0]:pt({0,0})),0};
			pt o=(r[0]+r[1])/2;
			return {o,(r[0]-o).norm()};
		}
		auto [o,d]=f(r,i+1,f);
		if((all[i]-o).norm()<=d)return {o,d};
		r.pb(all[i]);
		return f(r,i+1,f);
	};
	auto [o,d]=f({},0,f);
	cout<<fixed<<setprecision(15)<<d<<" "<<o.x<<" "<<o.y<<"\n";
	return 0;
}