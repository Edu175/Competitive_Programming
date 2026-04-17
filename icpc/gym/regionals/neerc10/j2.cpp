#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
auto pinchilon=[](){
	#ifdef ONLINE_JUDGE
	freopen("jungle.in","r",stdin);
	freopen("jungle.out","w",stdout);
	#endif
};
const ld EPS=1e-10;
struct pt {
	double x,y;
	pt(double x, double y):x(x),y(y){}
	pt(){}
	double norm2(){return *this**this;}
	double norm(){return sqrt(norm2());}
// 	bool operator==(pt p){return abs(x-p.x)<=EPS&&abs(y-p.y)<=EPS;}
	pt operator+(pt p){return pt(x+p.x,y+p.y);}
	pt operator-(pt p){return pt(x-p.x,y-p.y);}
	pt operator*(double t){return pt(x*t,y*t);}
	pt operator/(double t){return pt(x/t,y/t);}
	double operator*(pt p){return x*p.x+y*p.y;}
	pt unit(){return *this/norm();}
	double operator%(pt p){return x*p.y-y*p.x;}
	bool left(pt p, pt q){ // is it to the left of directed line pq?
		return (q-p)%(*this-p)>EPS;}
};
pt ccw90(1,0);
pt cw90(-1,0);
int sgn2(double x){return x<0?-1:1;}
struct ln {
	pt p,pq;
	ln(pt p, pt q):p(p),pq(q-p){}
	ln(){}
	bool operator/(ln l){return abs(pq.unit()%l.pq.unit())<=EPS;} // 2D
	pt operator^(ln l){ // intersection
		// if(*this/l)return pt(DINF,DINF);
		pt r=l.p+l.pq*((p-l.p)%pq/(l.pq%pq));
		return r;
	}
};
vector<pt>a;
ll n;

bool can(ll m){
	deque<ln>p;
	auto add=[&](ln l){
		while(SZ(p)>=2&&
		!(p.end()[-2]^p.end()[-1]).left(l.p,l.p+l.pq))
			p.pop_back();
		p.pb(l);
	};
	fore(i,0,n){
		ln l(a[i],a[(i+m)%n]);
		add(l);
	}
	
}

int main(){pinchilon();
	JET
	cin>>n;
	a.resize(n);
	fore(i,0,n)cin>>a[i].x>>a[i].y;
	reverse(ALL(a));
	
	return 0;
}