#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cerr<<cv(gdljh)<<" "; cerr<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef long double ld;
const ld EPS=1e-8;
struct pt{
	ld x,y;
	pt(ld X, ld Y):x(X),y(Y){
		if(abs(x)<=EPS)x=0;
		if(abs(y)<=EPS)y=0;
	}
	double norm2(){return *this**this;}
	double norm(){return sqrt(norm2());}
	pt operator+(pt p){return pt(x+p.x,y+p.y);}
	pt operator-(pt p){return pt(x-p.x,y-p.y);}
	pt operator*(ld t){return pt(x*t,y*t);}
	pt operator/(ld t){return pt(x/t,y/t);}
	ld operator*(pt p){return x*p.x+y*p.y;}
	ld operator%(pt p){return x*p.y-y*p.x;}
	pt unit(){return *this/norm();}
};
string cv(pt p){return to_string(p.x)+","+to_string(p.y);}
struct ln{
	pt p,d;
	ln(pt p, pt q): p(p),d(q-p){}
	bool operator/(ln l){return abs(d.unit()%l.d.unit())<=EPS;}
	pt operator^(ln l){
		assert(!(*this/l));
		//while(*this/l);
		return p+d*((l.p-p)%l.d/(d%l.d));
	}
};
string cv(ln l){return cv(l.p)+"--"+cv(l.p+l.d);}
ll quad(pt p){
	if(abs(p.x)<=EPS)p.x=0;
	if(abs(p.y)<=EPS)p.y=0;
	if(p.x>=0&&p.y>0)return 0;
	if(p.x<0&&p.y>=0)return 1;
	if(p.x<=0&&p.y<0)return 2;
	if(p.x>0&&p.y<=0)return 3;
	//while(!(p.x==0&&p.y==0));
	assert(p.x==0&&p.y==0);
	return -1;
}
bool operator<(pt a, pt b){
	ll c1=quad(a),c2=quad(b);
	if(c1==c2)return a.unit()%b.unit()>EPS;
	return c1<c2;
}
vector<pt>a;

bool check(pt p){
	vector<pt>_b,_c;
	//cerr<<"check "<<cv(p)<<"\n";
	for(auto i:a){
		pt q=i-p;
		if(quad(q)==-1)continue;
		if(quad(q)<=1)_b.pb(q);
		else _c.pb(q);
	}
	sort(ALL(_b));
	sort(ALL(_c));
	queue<pt>b,c;
	for(auto i:_b)b.push(i);
	for(auto i:_c)c.push(i);
	ll cnt=0;
	while(cnt<SZ(a)+5){
		if(SZ(b)!=SZ(c))return 0;
		auto x=b.front(),y=c.front();
		auto ry=y; ry.x*=-1,ry.y*=-1;
		if(!(x<ry)&&!(ry<x)){ //iguales
			cnt+=2;
			b.pop(); c.push(x);
			c.pop(); b.push(y);
		}
		else if(x<ry){
			cnt++;
			b.pop(); c.push(x);
		}
		else {
			cnt++;
			c.pop(); b.push(y);
		}
	}
	return 1;
}
vector<double> apuesta(vector<int> &X, vector<int> &Y){
	ll n=SZ(X);
	fore(i,0,n)a.pb(pt(X[i],Y[i]));
	//#define TRY(p) {if(check(p))return {(p).x,(p).y};}
	/*#define ANS(p) {TRY(p);return{};}
	if(n&1){
		sort(ALL(a),[](pt a, pt b){return a.x<b.x;});
		pt p(a[n/2].x,0);
		sort(ALL(a),[](pt a, pt b){return a.y<b.y;});
		p.y=a[n/2].y;
		ANS(p);
	}*/
	//ii flag={0,0};
	ll fh=(n-1)/2,sh=n/2;
	
	
	sort(ALL(a),[](pt a, pt b){return a.x<b.x;});
	//cerr<<"sorted by x "; imp(a);
	pt p((a[fh].x+a[sh].x)/2,0);
	//flag.fst=a[fh].x==a[sh].x;
	
	
	sort(ALL(a),[](pt a, pt b){return a.y<b.y;});
	//cerr<<"sorted by y "; imp(a);
	//flag.snd=a[fh].y==a[sh].y;
	p.y=(a[fh].y+a[sh].y)/2;
	
	
	vector<pt> mn(4,pt(0,0)),mx(4,pt(0,0));
	for(auto i:a){
		pt q=i-p;
		auto c=quad(q);
		if(c==-1)continue;
		if((mn[c].x==0&&mn[c].y==0)||q<mn[c])mn[c]=q;
		if((mx[c].x==0&&mx[c].y==0)||mx[c]<q)mx[c]=q;
	}
	
	vector<ln>ls;
	auto ADD=[&](pt r, pt q){
		if(quad(r)!=-1&&quad(q)!=-1)ls.pb(ln(p+r,p+q));
	};
	ADD(mn[0],mn[2]);
	ADD(mx[1],mx[3]);
	ADD(mx[0],mx[2]);
	ADD(mn[1],mn[3]);
	//cerr<<cv(p)<<"\n";
	//imp(ls);
	fore(i,0,SZ(ls))fore(j,i+1,SZ(ls)){
//		cout<<i<<" "<<j<<":\n";
		if(ls[i]/ls[j])continue;
		pt p=ls[i]^ls[j];
		if(check(p))return {p.x,p.y};
	}
	if(check(p))return {p.x,p.y};
	return {};
}
