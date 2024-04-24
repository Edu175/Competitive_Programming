#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef int ll;
typedef double ld;
typedef pair<ll,ll> ii;
//#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const ld EPS=1e-11;

struct pt {
	ld x,y;
	pt(ld x, ld y):x(x),y(y){}
	pt(){}
	ld norm2(){return *this**this;}
	ld norm(){return sqrt(norm2());}
	bool operator==(pt p){return abs(x-p.x)<EPS&&abs(y-p.y)<EPS;}
	pt operator+(pt p){return pt(x+p.x,y+p.y);}
	pt operator-(pt p){return pt(x-p.x,y-p.y);}
	pt operator*(ld t){return pt(x*t,y*t);}
	pt operator/(ld t){return pt(x/t,y/t);}
	ld operator*(pt p){return x*p.x+y*p.y;}
//	pt operator^(pt p){ // only for 3D
//		return pt(y*p.z-z*p.y,z*p.x-x*p.z,x*p.y-y*p.x);}
	ld angle(pt p){ // redefine acos for values out of range
		return acos(*this*p/(norm()*p.norm()));}
	pt unit(){return *this/norm();}
	ld operator%(pt p){return x*p.y-y*p.x;}
	// 2D from now on
	bool operator<(pt p)const{ // for convex hull
		return x<p.x||x==p.x&&y<p.y;}
	bool left(pt p, pt q){ // is it to the left of directed line pq?
		return (q-p)%(*this-p)>=0;}
	pt rot(pt r){return pt(*this%r,*this*r);}
	pt rot(ld a){return rot(pt(sin(a),cos(a)));}
	pt rot90(){
		return pt(-y,x);
	}
};
pt ccw90(1,0);
pt cw90(-1,0);
struct ln{
	pt p,pq;
	ld pen,c;
	ln(pt p, pt q):p(p),pq(q-p){
		pen=pq.y/pq.x;
		if(pq.x<=EPS)c=p.x;
		else c=p.y-pen*p.x;
	}
	ln(){}
	bool operator/(ln l){return abs(pq.unit()%l.pq.unit())<=EPS;}
	//bool operator/(ln l){return abs(pen-l.pen)<=EPS;}
	pt operator^(ln l){ // intersection
		//assert(!(*this/l));
		pt r=l.p+l.pq*((p-l.p)%pq/(l.pq%pq));
		return r;
	}
	ln rot90(){
		return ln(p,p+pq.rot90());
	}
};

// CCW order
// Includes collinear points (change sign of EPS in left to exclude)
vector<pt> chull(vector<pt> p){
	vector<pt> r;//r.reserve(SZ(p));
	sort(p.begin(),p.end()); // first x, then y
	fore(i,0,p.size()){ // lower hull
		while(r.size()>=2&&r.back().left(r[r.size()-2],p[i]))r.pop_back();
		r.pb(p[i]);
	}
	r.pop_back();
	int k=r.size();
	for(int i=p.size()-1;i>=0;--i){ // upper hull
		while(r.size()>=k+2&&r.back().left(r[r.size()-2],p[i]))r.pop_back();
		r.pb(p[i]);
	}
	r.pop_back();
	if(!SZ(r))return p;
	return r;
}

struct pol {
	int n;vector<pt> p;
	pol(){}
	pol(vector<pt> _p){p=_p;n=p.size();}
	pt farthest(pt v){ // O(log(n)) only CONVEX
		if(n<10){
			int k=0;
			fore(i,1,n)if(v*(p[i]-p[k])>EPS)k=i;
			return p[k];
		}
		if(n==SZ(p))p.pb(p[0]);
		pt a=p[1]-p[0];
		int s=0,e=n,ua=v*a>EPS;
		if(!ua&&v*(p[n-1]-p[0])<=EPS)return p[0];
		while(1){
			int m=(s+e)/2;pt c=p[m+1]-p[m];
			int uc=v*c>EPS;
			if(!uc&&v*(p[m-1]-p[m])<=EPS)return p[m];
			if(ua&&(!uc||v*(p[s]-p[m])>EPS))e=m;
			else if(ua||uc||v*(p[s]-p[m])>=-EPS)s=m,a=c,ua=uc;
			else e=m;
			assert(e>s+1);
		}
	}
};


vector<pol> w;
void add(pt q){
	vector<pt> p={q};
	while(!w.empty()&&SZ(w.back().p)<2*SZ(p)){
		for(pt v:w.back().p)p.pb(v);
		w.pop_back();
	}
	w.pb(pol(chull(p)));
}
ld query(pt v){
	ld r=w[0].farthest(v)*v;
	for(auto& p:w)r=max(r,p.farthest(v)*v);
	return r;
}
vector<ln>a;
bool operator<(ln l, ln r){
	return l.pen<r.pen-EPS||(abs(l.pen-r.pen)<=EPS&&l.c<r.c-EPS);
}
string cv(pt p){
	return to_string(p.x)+","+to_string(p.y);
}
string cv(ln l){
	return cv(l.p)+" -> "+cv(l.pq);
}
void new_point(ln l, ln r){
	//cout<<"new point "<<cv(l)<<" ^ "<<cv(r)<<" ??\n";
	if(l/r)return;
	//cout<<"okay\n";
	add(l^r);
}

int main(){FIN;
	cout<<fixed<<setprecision(15)<<"\n";
	set<ln>st;
	ll n; cin>>n;
	while(n--){
		char ty; cin>>ty;
		pt p,q; cin>>p.x>>p.y>>q.x>>q.y;
		ln l(p,q);
		if(ty=='+'){
			st.insert(l);
			auto it=st.lower_bound(l);
			if(it!=st.begin())new_point(l,*prev(it));
			else new_point(l,*prev(st.end()));
			if(it!=prev(st.end()))new_point(l,*next(it));
			else new_point(l,*st.begin());
		}
		else {
			pt v[4];
			v[0]=l.pq;
			fore(i,1,4)v[i]=v[i-1].rot90();
			if(!SZ(w)){
				cout<<"0\n";
				continue;
			}
			ld ans[4];
			fore(i,0,4)ans[i]=query(v[i]);
			fore(i,0,4)ans[i]/=v[i].norm();
			ld res=(ans[0]+ans[2])*(ans[1]+ans[3]);
			//imp(ans);
			cout<<res<<"\n";
		}
		
	}
	return 0;
}
