#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef long double ld;
const ld EPS=1e-8;
struct pt{
	ld x,y;
	pt(ld x, ld y):x(x),y(y){}
	pt operator+(pt p){return pt(x+p.x,y+p.y);}
	pt operator-(pt p){return pt(x-p.x,y-p.y);}
	pt operator*(ld t){return pt(x*t,y*t);}
	pt operator/(ld t){return pt(x/t,y/t);}
	ld operator*(pt p){return x*p.x+y*p.y;}
	ld operator%(pt p){return x*p.y-y*p.x;}
	bool operator/(pt q){return abs(*this*q)<=EPS;}
	ld pen(){return x==0?INFINITY:y/x;}
	/*ii pen(){
		if(x==0)return {1,0};
		ll g=gcd(x,y);
		ii r={x/g,y/g};
		if(r.snd<0)r.fst*=-1,r.snd*=-1;
		return r;
	}*/
};
string cv(pt p){return to_string(p.x)+","+to_string(p.y);}
struct ln{
	pt p,d;
	ln(pt p, pt q): p(p),d(q-p){}
	bool operator/(ln l){return d/l.d;}
	pt operator^(ln l){
		//if(*this/l);
		assert(!(*this/l));
		return p+d*((l.p-p)*l.d/(d*l.d));
	}
};
ll quad(pt p){
	if(p.x>0&&p.y>=0)return 0;
	if(p.x<=0&&p.y>0)return 1;
	if(p.x<0&&p.y<=0)return 2;
	if(p.x>=0&&p.y<0)return 3;
	assert(p.x==0&&p.y==0);
	return -1;
}
/*bool operator<(pt a, pt b){
	ll c1=quad(a),c2=quad(b);
	if(c1==c2)return a%b>0;
	return c1<c2;
}*/
vector<pt>a;

bool check(pt p){
//	cout<<"check "<<cv(p)<<"\n";
//	map<ld,vector<pt>>mp;
	vector<pair<ld,pt>>b;
	for(auto i:a){
		pt q=i-p;
		if(!(q.x==0&&q.y==0))b.pb({q.pen(),q});
	}
	sort(ALL(b),[](pair<ld,pt>a,pair<ld,pt>b){return a.fst<b.fst;});
	vector<pair<ld,pt>>c={b[0]};
	auto fail=[&](){
		ll s=0;
		for(auto i:c)s+=quad(i.snd)>1?1:-1;
		return s!=0;
	};
	fore(i,1,SZ(b)){
		if(abs(b[i].fst-b[i-1].fst)<=EPS)c.pb(b[i]);
		else {
			if(fail())return 0;
			c={b[i]};
		}
	}
	return !fail();
//		for(auto i:c)cout<<cv(i)<<" ";;cout<<"\n";
		//cout<<s<<""
}
vector<double> ans(pt p){
	if(check(p))return {p.x,p.y};
	return {};
}
vector<double> apuesta(vector<int> &X, vector<int> &Y){
	ll n=SZ(X);
	fore(i,0,n)a.pb(pt(X[i],Y[i]));
	if(n&1){
		sort(ALL(a),[](pt a, pt b){return a.x<b.x;});
		pt p(a[n/2].x,0);
		sort(ALL(a),[](pt a, pt b){return a.y<b.y;});
		p.y=a[n/2].y;
		return ans(p);
	}
	if(check(pt(0,0)))return {0,0};
	assert(0);
}
