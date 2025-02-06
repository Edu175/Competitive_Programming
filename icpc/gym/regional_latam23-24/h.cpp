#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet; i++)
#define fst first
#define snd second
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((ll)x.size())
#define pb push_back
#define mset(v,a) memset((a),(v),sizeof(a))
#define ET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
typedef long double du;
const du EPS=1e-11;
const du DINF=1e8;
struct pt{
	du x, y;
	pt(du x, du y): x(x), y(y) {}
	pt() {}
	du norm2(){return *this**this;}
	du norm(){return sqrt(norm2());}
	pt operator+(pt p){return pt(x+p.x,y+p.y);}
	pt operator-(pt p){return pt(x-p.x,y-p.y);}	
	du operator*(pt p){return x*p.x+y*p.y;}
	du operator%(pt p){return x*p.y-y*p.x;}
	pt operator*(du t){return pt(x*t,y*t);}
	pt operator/(du t){return pt(x/t,y/t);}
	pt unit(){
		return *this/norm();
	}
	bool left(pt p, pt q){
		return (q-p)%(*this-p)>EPS;
	}
};
struct ln{
	pt p, pq;
	ln(pt p, pt q): p(p), pq(q-p) {}
	ln(){}
	bool operator/(ln l){return abs(pq.unit()%l.pq.unit())<=EPS;}
	pt operator^(ln l){
		if(*this/l) return pt(DINF,DINF);
		pt r=l.p+l.pq*((p-l.p)%pq/(l.pq%pq));
		return r;
	}
};
struct halfplane:public ln{
	du angle;
	halfplane(){}
	halfplane(pt a, pt b){p=a; pq=b-a; angle=atan2(pq.y,pq.x);}
	bool operator<(halfplane b)const{return angle<b.angle;}
	bool out(pt q){return pq%(q-p)<-EPS;}
};

vector<pt> intersect(vector<halfplane> b){
	vector<pt> bx={{DINF,DINF},{-DINF,DINF},{-DINF,-DINF},{DINF,-DINF}};
	fore(i,0,4) b.pb(halfplane(bx[i],bx[(i+1)%4]));
	sort(ALL(b));
	int n=SZ(b),q=1,h=0;
	vector<halfplane> c(SZ(b)+10);
	fore(i,0,n){
		while(q<h&&b[i].out(c[h]^c[h-1])) h--;
		while(q<h&&b[i].out(c[q]^c[q+1])) q++;
		c[++h]=b[i];
		if(q<h&&abs(c[h].pq%c[h-1].pq)<EPS){
			if(c[h].pq*c[h-1].pq<=0) return {};
			h--;
			if(b[i].out(c[h].p)) c[h]=b[i];
		}
	}
	while(q<h-1&&c[q].out(c[h]^c[h-1])) h--;
	while(q<h-1&&c[h].out(c[q]^c[q+1])) q++;
	if(h-q<=1) return {};
	c[h+1]=c[q];
	vector<pt> s;
	fore(i,q,h+1) s.pb(c[i]^c[i+1]);
	return s;
}
pt ci=pt(0,0);
int main(){
	ET;
	int n; du d; cin>>n>>d;
//	cout<<d<<"\n";
	vector<halfplane> H;
	fore(i,0,n){
		pt a,b; cin>>a.x>>a.y>>b.x>>b.y; 
		if(!ci.left(a,b)) swap(a,b);
		H.pb(halfplane(a,b));
	}	
	ll l=3, r=n;
	vector<halfplane> q;
	while(l<=r){
		ll h=(l+r)/2;
		while(SZ(q)<h) q.pb(H[SZ(q)]);
		while(SZ(q)>h) q.pop_back();
//		cout<<h<<" "<<SZ(q)<<"\n";
		vector <pt> poly=intersect(q);
		bool y=true;
		fore(i,0,SZ(poly)){
		//	cout<<poly[i].x<<" "<<poly[i].y<<"\n";
			if(poly[i].norm2()+EPS>d*d){
				y=false; break;
			}
		}
		if(y) r=h-1;
		else l=h+1;
	}	
	if(l>n)cout<<"*\n";
	else cout<<l<<"\n";
	// cout<<(l>n?"*":to_string(l))<<"\n";
}


