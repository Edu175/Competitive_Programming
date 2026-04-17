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
const ld EPS=1e-10,DINF=1e20;
struct pt {
	ld x,y;
	pt(ld x, ld y):x(x),y(y){}
	pt(){}
	ld norm2(){return *this**this;}
	ld norm(){return sqrt(norm2());}
	bool operator==(pt p){return abs(x-p.x)<=EPS&&abs(y-p.y)<=EPS;}
	pt operator+(pt p){return pt(x+p.x,y+p.y);}
	pt operator-(pt p){return pt(x-p.x,y-p.y);}
	pt operator*(ld t){return pt(x*t,y*t);}
	pt operator/(ld t){return pt(x/t,y/t);}
	ld operator*(pt p){return x*p.x+y*p.y;}
	pt unit(){return *this/norm();}
	ld operator%(pt p){return x*p.y-y*p.x;}
	bool left(pt p, pt q){ // is it to the left of directed line pq?
		return (q-p)%(*this-p)>EPS;}
};
pt ccw90(1,0);
pt cw90(-1,0);
int sgn2(ld x){return x<0?-1:1;}
struct ln {
	pt p,pq;
	ln(pt p, pt q):p(p),pq(q-p){}
	ln(){}
	bool operator/(ln l){return abs(pq.unit()%l.pq.unit())<=EPS;} // 2D
	pt operator^(ln l){ // intersection
		if(*this/l)return pt(DINF,DINF);
		pt r=l.p+l.pq*((p-l.p)%pq/(l.pq%pq));
		return r;
	}
};
struct halfplane:public ln{
	ld angle;
	halfplane(){}
	halfplane(pt a,pt b){p=a; pq=b-a; angle=atan2(pq.y,pq.x);}
	bool operator<(halfplane b)const{return angle<b.angle;}
	bool out(pt q){return pq%(q-p)<-EPS;}
};
vector<pt> intersect(vector<halfplane> b){
	vector<pt>bx={{DINF,DINF},{-DINF,DINF},{-DINF,-DINF},{DINF,-DINF}};
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
	while(q<h-1&&c[q].out(c[h]^c[h-1]))h--;
	while(q<h-1&&c[h].out(c[q]^c[q+1]))q++;
	if(h-q<=1)return {};
	c[h+1]=c[q];
	vector<pt> s;
	fore(i,q,h+1) s.pb(c[i]^c[i+1]);
	return s;
}
vector<pt>a;
ll n;

bool can(ll k){
	vector<halfplane>b;
	fore(i,0,n)b.pb(halfplane(a[i],a[(i+k)%n]));
	auto r=intersect(b);
	// for(auto i:r)cout<<i.x<<","<<i.y<<" ";;cout<<"\n";
	ll flag=1;
	fore(i,0,SZ(r)-1)flag&=r[i]==r[i+1];
	return flag;
}

int main(){pinchilon();
	JET
	cin>>n;
	cout<<(n+1)/2-1<<"\n";
	return 0;
	a.resize(n);
	fore(i,0,n)cin>>a[i].x>>a[i].y;
	reverse(ALL(a));
	ll l=1,r=n;
	while(l<=r){
		ll m=(l+r)/2;
		if(can(m))r=m-1;
		else l=m+1;
	}
	cout<<l-1<<"\n";
	return 0;
}