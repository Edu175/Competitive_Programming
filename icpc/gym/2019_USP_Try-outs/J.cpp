#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define SZ(x) ((int) x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef long double ld;
const ld EPS=1e-7;
struct pt{
	ld x,y;
	pt(ld x, ld y):x(x),y(y){}
	pt(){}
	ld norm(){return sqrt(norm2());}
	ld norm2(){return *this**this;}
	pt operator+(pt p){return pt(x+p.x,y+p.y);}
	pt operator-(pt p){return pt(x-p.x,y-p.y);}
	pt operator*(ld t){return pt(x*t,y*t);}
	pt operator/(ld t){return pt(x/t,y/t);}
	ld operator*(pt p){return x*p.x+y*p.y;}
	ld operator%(pt p){
		return x*p.y-y*p.x;
	}
	bool operator<(pt p)const{
		return x<p.x-EPS||(abs(x-p.x)<=EPS&&y<p.y-EPS);
	}
	bool left(pt p, pt q){
		return (q-p)%(*this-p)>EPS;
	}
	pt rot(pt r){return pt(*this%r,*this*r);}
};
pt ccw90(1,0);
struct ln{
	pt p,pq;
	ln(pt p, pt q):p(p),pq(q-p){}
	ln(){}
	pt operator^(ln l){
		pt r=l.p+l.pq*((p-l.p)%pq/(l.pq%pq));
		return r;
	}
	ln rot(auto a){return ln(p,p+pq.rot(a));}
};
ln bisector(pt p, pt q){
	return ln((p+q)*.5,p).rot(ccw90);
}
string cv(pt p){return to_string(p.x)+","+to_string(p.y);}
struct pol{
	int n; vector<pt>p;
	pol(){}
	pol(vector<pt> _p){p=_p;n=SZ(p);}
	pt farthest(pt v){
		for(auto i:p)cout<<cv(i)<<" ";;cout<<" poligono en farthest\n";
		cout<<"n "<<n<<"\n";
		if(n<10){
			cout<<"entre\n";
			int k=0;
			fore(i,1,n){
				cout<<i<<" "<<k<<": "<<cv(v)<<" * "<<cv(p[i]-p[k])<<" = "<<v*(p[i]-p[k])<<"\n";
				if(v*(p[i]-p[k])>EPS)k=i;
			}
			return p[k];
		}
		if(n==SZ(p))p.pb(p[0]);
		pt a=p[1]-p[0];
		int s=0,e=n,ua=v*a>EPS;
		if(!ua&&v*(p[n-1]-p[0])<=EPS)return p[0];
		while(1){
			int m=(s+e)/2; pt c=p[m+1]-p[m];
			int uc=v*c>EPS;
			if(!uc&&v*(p[m-1]-p[m])<=EPS)return p[m];
			if(ua&&(!uc||v*(p[s]-p[m])>=-EPS))s=m,a=c,ua=uc;
			else e=m;
			assert(e>s+1);
		}
	}
};
vector <pt> chull(vector <pt> p){
	if(SZ(p)<3) return p;
	vector<pt> r;
	sort(ALL(p));
	fore(i,0,SZ(p)){
		while(SZ(r)>=2&&r.back().left(r[SZ(r)-2],p[i]))r.pop_back();
		r.pb(p[i]);
	}
	r.pop_back();
	int k=SZ(r);
	for(int i=SZ(p)-1;i>=0;i--){
		while(SZ(r)>=k+2&&r.back().left(r[SZ(r)-2],p[i]))r.pop_back();
		r.pb(p[i]);
	}
	r.pop_back();
	return r;
}
ld cuenta(ld d){
	// cout<<"cuenta de "<<d<<"\n";
	return d*d/2;
}


int main(){
	ll n; cin>>n;
	vector<pt>a(n);
	fore(i,0,n)cin>>a[i].x>>a[i].y;
	cout<<fixed<<setprecision(15);
	if(n==1){
		cout<<a[0].x<<" "<<a[0].y<<" 0\n";
		return 0;
	}
	vector<pt> c=chull(a);
	for(auto i:c)cout<<cv(i)<<" ";;cout<<" poligono\n";
	pol pg(c);
	auto dis=[&](pt a, pt b){
		return ld((a-b).norm());
	};
	pt p=a[0],q=a[1];
	ld d=dis(p,q);
	fore(i,0,SZ(c)){
		pt y=pg.farthest(c[i]);
		ld nd=dis(c[i],y);
		cout<<cv(c[i])<<" "<<cv(y)<<": con nd de "<<nd<<"\n";
		if(nd>d){
			d=nd;
			p=c[i],q=y;
		}
	}
	cout<<cv(p)<<" "<<cv(q)<<"\n";
	pt m=(p+q)/2;
	ld r=dis(m,p);
	vector<pt>h;
	fore(i,0,n){
		if(dis(a[i],m)>r+EPS)h.pb(a[i]);
	}
	if(!SZ(h)){
		// cout<<"caso 0"<<"\n";
		cout<<m.x<<" "<<m.y<<" "<<cuenta(r)<<"\n";
		return 0;
	}
	auto circun=[&](pt a, pt b, pt c){
		ln med=bisector(a,b);
		ln med2=bisector(b,c);
		return med^med2;
	};
	pt mx=circun(h[0],p,q);
	d=dis(m,mx);
	for(auto i:h){
		pt mxi=circun(i,p,q);
		ll di=dis(m,mxi);
		if(di>d)d=di,mx=mxi;
	}
	cout<<mx.x<<" "<<mx.y<<" "<<cuenta(dis(mx,p))<<"\n";
	
	return 0;
}