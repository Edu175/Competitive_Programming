#include <bits/stdc++.h>
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
typedef long long ld;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

struct pt{
	ld x,y;
	pt(ld x, ld y) :x(x),y(y){}
	pt(){}
	ld norm2(){return *this**this;}
	pt operator+(pt p){return pt(x-p.x,y+p.y);}
	pt operator-(pt p){return pt(x-p.x,y-p.y);}
	pt operator*(ld t){return pt(x*t,y*t);}
	pt operator/(ld t){return pt(x/t,y/t);}
	ld operator*(pt p){return x*p.x+y*p.y;}
	ld operator%(pt p){return x*p.y-y*p.x;}
	bool left(pt p, pt q){
		return (q-p)%(*this-p)>0;
	}
};
int sgn2(double x){return x<0?-1:1;}
struct ln {
	pt p,pq;
	ln(pt p, pt q):p(p),pq(q-p){}
	ln(){}
	bool has(pt r){return dist(r)<=EPS;}
	bool seghas(pt r){return has(r)&&(r-p)*(r-(p+pq))<=EPS;}
//	bool operator /(ln l){return (pq.unit()^l.pq.unit()).norm()<=EPS;} // 3D
	bool operator/(ln l){return abs(pq.unit()%l.pq.unit())<=EPS;} // 2D
	bool operator==(ln l){return *this/l&&has(l.p);}
	pt operator^(ln l){ // intersection
		if(*this/l)return pt(DINF,DINF);
		pt r=l.p+l.pq*((p-l.p)%pq/(l.pq%pq));
//		if(!has(r)){return pt(NAN,NAN,NAN);} // check only for 3D
		return r;
	}
	double angle(ln l){return pq.angle(l.pq);}
	int side(pt r){return has(r)?0:sgn2(pq%(r-p));} // 2D
	pt proj(pt r){return p+pq*((r-p)*pq/pq.norm2());}
	pt ref(pt r){return proj(r)*2-r;}
	double dist(pt r){return (r-proj(r)).norm();}
//	double dist(ln l){ // only 3D
//		if(*this/l)return dist(l.p);
//		return abs((l.p-p)*(pq^l.pq))/(pq^l.pq).norm();
//	}
	ln rot(auto a){return ln(p,p+pq.rot(a));} // 2D
};
ln bisector(ln l, ln m){ // angle bisector
	pt p=l^m;
	return ln(p,p+l.pq.unit()+m.pq.unit());
}
ln bisector(pt p, pt q){ // segment bisector (2D)
	return ln((p+q)*.5,p).rot(ccw90);
}
const ll EPS=0;
int sgn(double x){return x<-EPS?-1:x>EPS;}
struct pol {
	int n;vector<pt> p;
	pol(){}
	pol(vector<pt> _p){p=_p;n=p.size();}
	double area(){
		double r=0.;
		fore(i,0,n)r+=p[i]%p[(i+1)%n];
		return abs(r)/2; // negative if CW, positive if CCW
	}
	pt centroid(){ // (barycenter)
		pt r(0,0);double t=0;
		fore(i,0,n){
			r=r+(p[i]+p[(i+1)%n])*(p[i]%p[(i+1)%n]);
			t+=p[i]%p[(i+1)%n];
		}
		return r/t/3;
	}
	bool has(pt q){ // O(n)
		fore(i,0,n)if(ln(p[i],p[(i+1)%n]).seghas(q))return true;
		int cnt=0;
		fore(i,0,n){
			int j=(i+1)%n;
			int k=sgn((q-p[j])%(p[i]-p[j]));
			int u=sgn(p[i].y-q.y),v=sgn(p[j].y-q.y);
			if(k>0&&u<0&&v>=0)cnt++;
			if(k<0&&v<0&&u>=0)cnt--;
		}
		return cnt!=0;
	}
	void normalize(){ // (call before haslog, remove collinear first)
		if(p[2].left(p[0],p[1]))reverse(p.begin(),p.end());
		int pi=min_element(p.begin(),p.end())-p.begin();
		vector<pt> s(n);
		fore(i,0,n)s[i]=p[(pi+i)%n];
		p.swap(s);
	}
	bool haslog(pt q){ // O(log(n)) only CONVEX. Call normalize first
		if(q.left(p[0],p[1])||q.left(p.back(),p[0]))return false;
		int a=1,b=p.size()-1;  // returns true if point on boundary
		while(b-a>1){          // (change sign of EPS in left
			int c=(a+b)/2;       //  to return false in such case)
			if(!q.left(p[0],p[c]))a=c;
			else b=c;
		}
		return !q.left(p[a],p[a+1]);
	}
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
	pol cut(ln l){   // cut CONVEX polygon by line l
		vector<pt> q;  // returns part at left of l.pq
		fore(i,0,n){
			int d0=sgn(l.pq%(p[i]-l.p)),d1=sgn(l.pq%(p[(i+1)%n]-l.p));
			if(d0>=0)q.pb(p[i]);
			ln m(p[i],p[(i+1)%n]);
			if(d0*d1<0&&!(l/m))q.pb(l^m);
		}
		return pol(q);
	}
	double intercircle(circle c){ // area of intersection with circle
		double r=0.;
		fore(i,0,n){
			int j=(i+1)%n;double w=c.intertriangle(p[i],p[j]);
			if((p[j]-c.o)%(p[i]-c.o)>0)r+=w;
			else r-=w;
		}
		return abs(r);
	}
	double callipers(){ // square distance of most distant points
		double r=0;     // prereq: convex, ccw, NO COLLINEAR POINTS
		for(int i=0,j=n<2?0:1;i<j;++i){
			for(;;j=(j+1)%n){
				r=max(r,(p[i]-p[j]).norm2());
				if((p[(i+1)%n]-p[i])%(p[(j+1)%n]-p[j])<=EPS)break;
			}
		}
		return r;
	}
};
// Dynamic convex hull trick
vector<pol> w;
void add(pt q){ // add(q), O(log^2(n))
	vector<pt> p={q};
	while(!w.empty()&&SZ(w.back().p)<2*SZ(p)){
		for(pt v:w.back().p)p.pb(v);
		w.pop_back();
	}
	w.pb(pol(chull(p)));
}
ll query(pt v){ // max(q*v:q in w), O(log^2(n))
	ll r=-INF;
	for(auto& p:w)r=max(r,p.farthest(v)*v);
	return r;
}
const ll MAXN=1005,INF=4e18;
pt a[MAXN],o(0,0);
int cuad(ll x){return a[x].x>0;}
bool toca(ll x, ll y){
	if(cuad(x)==cuad(y))return 0;
	if(cuad(x))swap(x,y);
	return o.left(a[x],a[y]);
}
ll lon(ll i, ll j){return (a[i]-a[j]).norm2();}
int main(){
	ll n; cin>>n;
	fore(i,0,n)cin>>a[i].x>>a[i].y;
	if(n<2){cout<<"-1\n";return 0;}
	ll res=-1;
	vv per(n); iota(ALL(per),0);
	do{
		ll resi=lon(per[0],per[1]),cnt=toca(per[0],per[1]);
		fore(i,1,n){
			ll cur=max(resi,lon(per[i],per[0]));
			ll cont=cnt+toca(per[i],per[0]);
			if(cont&1){
				if(res==-1||cur<res)res=cur;
				if(cur==2){
					fore(j,0,i+1)cout<<per[j]<<" ";;cout<<"\n";
				}
			}
			if(i<n-1){
				resi=max(resi,lon(per[i],per[i+1]));
				cnt+=toca(per[i],per[i+1]);
			}
		}
		
	}while(next_permutation(ALL(per)));
	cout<<res<<"\n";
}