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
typedef long double ld;
typedef pair<ll,ll> ii;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const ld EPS=1e-10,DINF=63736546543696876837774671.0;
struct pt{
	ld x,y;
	pt(ld x, ld y):x(x),y(y){}
	pt(){}
	ld norm2(){return *this**this;}
	ld norm(){return sqrt(norm2());}
	pt operator+(pt p){return pt(x+p.x,y+p.y);}
	pt operator-(pt p){return pt(x-p.x,y-p.y);}
	pt operator*(ld t){return pt(x*t,y*t);}
	pt operator/(ld t){return pt(x/t,y/t);}
	ld operator*(pt p){return x*p.x+y*p.y;}
	pt unit(){return *this/norm();}
	ld operator%(pt p){return x*p.y-y*p.x;}
	
	bool left(pt p, pt q){
		return (q-p)%(*this-p)>EPS;
	}
	pt rot90(){
		return pt(-y,x);
	}
};
bool operator<(pt a, pt p){
	return a.x<p.x-EPS||(abs(a.x-p.x)<=EPS&&a.y<p.y-EPS);
}
struct ln{
	pt p,pq;
	ln(pt p, pt q):p(p),pq(q-p){}
	ln(){}
	bool operator/(ln l){return abs(pq.unit()%l.pq.unit())<=EPS;}
	pt operator^(ln l){ // intersection
		assert(!(*this/l));
		pt r=l.p+l.pq*((p-l.p)%pq/(l.pq%pq));
		return r;
	}
	ln rot90(){
		return ln(p,pq.rot90());
	}
	ld pen(){
		return pq.y/pq.x;
	}
};
string cv(pt p){
	return to_string(p.x)+","+to_string(p.y);
}
string cv(ln l){
	return cv(l.p)+" -> "+cv(l.pq);
}
vector<ln>a;

int main(){FIN;
	cout<<fixed<<setprecision(15);
	bool did=0;
	ld minx,maxx,miny,maxy;
	ll n; cin>>n;
	while(n--){
		char ty; cin>>ty;
		pt p,q; cin>>p.x>>p.y>>q.x>>q.y;
		ln l(p,q);
		if(ty=='+'){
			fore(i,0,SZ(a))if(!(a[i]/l)){
				pt p=l^a[i];
				if(!did){
					minx=maxx=p.x;
					miny=maxy=p.y;
				}
				minx=min(minx,p.x);
				miny=min(miny,p.y);
				maxx=max(maxx,p.x);
				maxy=max(maxy,p.y);
				did=1;
			}
			a.pb(l);
		}
		else {
			if(!did){
				cout<<"0\n";
				continue;
			}
			ld resi=(maxx-minx)*(maxy-miny);
			cout<<resi<<"\n";
		}
		
	}
	return 0;
}
