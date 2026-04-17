#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oia=b; i<oia;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(a) for(auto messi:a)cout<<messi<<" ";cout<<"\n"
using namespace std;
typedef long long ll;
typedef long double ld;
//#define bint __int128
//typedef __int128 bint;
#define angle pair<ll,ld>
const ld EPS=1e-9;

struct pt{
	ld x,y;
	pt(ll x, ll y):x(x),y(y){}
	pt(){}
	bool operator==(pt p){return (abs(x-p.x)<=EPS&&abs(y-p.y)<=EPS);}
	bool operator!=(pt p){return !(*this==p);}
};
bool operator<(pt p, pt q){
	pair<ld,ld>p0={p.x,p.y},p1={q.x,q.y};
	return p0<p1;
}
struct ln{
	pt p, q;
	ld a,b;
	ln(){}
	ln(pt p, pt q):p(p),q(q){
		a=(p.y-q.y)/(p.x-q.x),b=p.y-a*p.x;
	}
	pt operator^(ln l){ //intersection  PUNTO NO ENTERO
		pt res;
		res.x=(b-l.b)/(l.a-a);
		res.y=a*res.x+b;
		return res;
	}
};
vector<pt>a; ll n;
angle ang(pt p, pt q){
	angle res;
	res.snd=(p.y-q.y)/(p.x-q.x);
	res.fst=(q<p);
	return res;
}
bool cmp(angle a, angle b){
	if(a.fst<b.fst)return 1;
	if(a.fst==b.fst){
		if(abs(a.snd-b.snd)<=EPS)return 0;
		return a.snd<b.snd;
	}
	return 0;
}
vector<angle> srt(pt p){// sort points by pendiente
	vector<angle>res;
	fore(i,0,n)if(a[i]!=p){
		res.pb(ang(p,a[i]));
	}
	sort(ALL(res),cmp);
	return res;
}
pair<bool,bool> check(vector<angle>&b, ld m){ //sorted vector of points, check if line m cumple
	ll l0,l1,r0,r1;
	angle s={0,m},e={1,m};
	l0=lower_bound(ALL(b),s,cmp)-b.begin(); l1=upper_bound(ALL(b),s,cmp)-b.begin();
	r0=lower_bound(ALL(b),e,cmp)-b.begin(); r1=upper_bound(ALL(b),e,cmp)-b.begin();
	ll q0=l0+SZ(b)-r1,q1=r0-l1;
	return {(q0==q1),(l1-l0==r1-r0)};
}
vector<double> apuesta(vector<int> &X, vector<int> &Y){
	n=SZ(X);
	a.resize(n);
	fore(i,0,n)a[i]=pt(X[i],Y[i]);
	pt l0=a[0],r0=l0; ll flag=0;
	vector<angle>h=srt(l0);
	fore(i,0,n)if(a[i]!=l0&&check(h,ang(l0,a[i]).snd).fst){r0=a[i],flag=1;}
	if(!flag)return {};
	pt l1,r1;
	ld ph=ang(l0,r0).snd; flag=0;
	fore(i,0,n)if(a[i]!=l0&&ang(a[i],l0).snd-ph>EPS){
		l1=a[i];
		flag=1;
		break;
	}
	if(!flag){// alineados
		sort(ALL(a));
		ld x=a[(n+1)/2-1].x,y=a[(n+1)/2-1].y;
		return {x,y};
	}
	r1=l1; flag=0;
	h=srt(l1);
	fore(i,0,n)if(a[i]!=l1&&check(h,ang(l1,a[i]).snd).fst){r1=a[i],flag=1;}
	if(!flag)return {};
	pt c=ln(l0,r0)^ln(l1,r1); // might not be lattice
	h=srt(c);
	flag=1;
	fore(i,0,n){
		if(a[i]!=c&&!check(h,ang(c,a[i]).snd).snd)flag=0;
	}
	if(flag)return{c.x,c.y};
	return {};
}
