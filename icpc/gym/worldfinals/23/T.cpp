#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {for(auto p: v)p.print();;cout<<endl;}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
typedef long double ld;
const ld EPS=1e-9;
struct pt{
	ld	x,y;
	pt(ld x, ld y): x(x), y(y) {}
	pt(){}
	ld norm2(){return *this**this;}
	ld norm(){return sqrtl(norm2());}
	bool operator==(pt p){return abs(x-p.x)<=EPS&&abs(y-p.y)<=EPS;}
	pt operator+(pt p){return pt(x+p.x,y+p.y);}
	pt operator-(pt p){return pt(x-p.x,y-p.y);}
	pt operator*(ld t){return pt(x*t,y*t);}
	pt operator/(ld t){return pt(x/t,y/t);}
	ld operator*(pt p){return x*p.x+y*p.y;}
	ld operator%(pt p){return x*p.y-y*p.x;}
	pt unit(){return *this/norm();}
	bool left(pt p, pt q){return (q-p)%(*this-p)>-EPS;} 
	pt rot(pt r){return pt(*this%r,*this*r);}
	bool operator<(pt p)const{return x<p.x-EPS||(abs(x-p.x)<=EPS&&y<p.y-EPS);} 
	void print(){cout<<"("<<x<<","<<y<<") ";}
};
pt ccw90(1,0),cw90(-1,0);

const ld INF=1e18;


bool check(vector<pt> p, pt q, bool t){
	return t^(q.left(p[0],p[1])&&q.left(p[1],p[2]));
}
vector<pt> dame_triangulo(pt p1, pt p2, ld h){
	pt m=(p1+p2)/2;
	pt d=(m-p1).unit();
	d=d.rot(ccw90);
	// d.print(); "cout<< de "; p1.print(); p2.print(); cout<<endl;
	return {p2,m+(d*h),p1};
}
vector<pt> chull(vector<pt> p){
	if(SZ(p)<3) return p;
	vector<pt> r; sort(ALL(p)); int k=0;
	fore(_,0,2){
		fore(i,0,SZ(p)){
			while(SZ(r)>1+k&&r.back().left(r[SZ(r)-2],p[i])) r.pop_back();
			r.pb(p[i]);
		}
		r.pop_back(), k=SZ(r),reverse(ALL(p));
	}
	return r;
}
int sgn(ld x){return x<-EPS?-1:x>EPS;}
struct ln{
	pt p, pq; 
	ln(pt p, pt q):	p(p), pq(q-p) {}
	bool has(pt r){return dist(r)<=EPS;}
	bool seghas(pt r){return has(r)&&(r-p)*(r-(p+pq))<=EPS;}
	pt proj(pt r){return p+pq*((r-p)*pq/pq.norm2());}
	ld dist(pt r){return (r-proj(r)).norm();}
};
bool pol_has(vector<pt> p, pt q){
	ll n=SZ(p);
	fore(i,0,n) if(ln(p[i],p[(i+1)%n]).seghas(q)) return false; //for this problem
	int cnt=0;
	fore(i,0,n){
		int j=(i+1)%n, k=sgn((q-p[j])%(p[i]-p[j]));
		int u=sgn(p[i].y-q.y), v=sgn(p[j].y-q.y);
		if(k>0&&u<0&&v>=0) cnt++;
		if(k<0&&v<0&&u>=0) cnt--;
	}
	return cnt!=0;
}
bool checktr(vector<pt> tr, vector<pt> c){
	vector<pt> ch;
	fore(i,0,3) fore(j,0,4){
		ch.pb(tr[i]-c[j]);
	}
	ch=chull(ch);
	return !pol_has(ch,pt(0,0));
}
int main(){
	JET
	vector<pt> c[2]; ld h[2],H[2];
	fore(i,0,2){
		fore(j,0,2){
			pt p; cin>>p.x>>p.y; c[i].pb(p);
		}
		cin>>h[i];
		ld L=(c[i][0]-c[i][1]).norm();
		H[i]=sqrtl(h[i]*h[i]+L*L/2.L);
		h[i]=sqrtl(h[i]*h[i]+L*L/4.L);
	}
	
	fore(i,0,2){
		fore(j,0,4){
			pt p1=c[i].back(),p2=c[i][SZ(c[i])-2];
			swap(p1,p2);
			c[i].pb(p2+(p2-p1).rot(ccw90));
		}
	}
	// cout<<"c1: ";
	// imp(c[0]); 
	// cout<<"h1 = "<<h[0]<<"\n";
	// cout<<"c2: ";
	// imp(c[1]);
	// cout<<"h2 = "<<h[1]<<"\n";
	
	ld r=INF;
	
	fore(i,1,5)fore(j,1,5){
		vector<vector<pt>> P[2];
		
		auto t1=dame_triangulo(c[0][i],c[0][i+1],h[0]);
		auto t2=dame_triangulo(c[1][j],c[1][j+1],h[1]);
		vector<pt> c1={c[0][i-1],c[0][i], c[0][i+1]};
		vector<pt> c2={c[1][j-1],c[1][j], c[1][j+1]};
		P[0].pb(t1); P[0].pb(c1);
		P[1].pb(t2); P[1].pb(c2);
		fore(k,0,2)fore(l,0,2){
			if(!k&&!checktr(P[0][k],c[1])) continue;
			if(!l&&!checktr(P[1][l],c[0])) continue;
			if(check(P[0][k],P[1][l][1],k)&&check(P[1][l],P[0][k][1],l)){
				ld delta=0;
				if(k) delta+=H[0];
				if(l) delta+=H[1];
				r=min(r,(P[0][k][1]-P[1][l][1]).norm()+delta);
			}
		}
	}
	
	cout<<fixed<<setprecision(16)<<r<<"\n";
	return 0;
}
// 0 0 10 0 4
// 9 18 34 26 42
// 20.5080738342

