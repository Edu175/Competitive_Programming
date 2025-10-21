#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ld EPS=1e-10,LIM=1e-5;
// ,DINF=1e40;

struct pt{
	ld x,y;
	pt(){}
	pt(ld x, ld y):x(x),y(y){}
	ld norm2(){return *this**this;}
	ld norm(){return sqrtl(norm2());}
	pt operator+(pt p){return pt(x+p.x,y+p.y);}
	pt operator-(pt p){return pt(x-p.x,y-p.y);}
	pt operator*(ld t){return pt(x*t,y*t);}
	pt operator/(ld t){return pt(x/t,y/t);}
	ld operator*(pt p){return x*p.x+y*p.y;}
	ld operator%(pt p){return x*p.y-y*p.x;}
	pt unit(){return *this/norm();}
};
struct ln {
	pt p,pq;
	ln(pt p, pt q):p(p),pq(q-p){}
	ln(){}
	bool operator/(ln l){return abs(pq.unit()%l.pq.unit())<=EPS;} // 2D
	pt proj(pt r){return p+pq*((r-p)*pq/pq.norm2());}
	pt ref(pt r){return proj(r)*2-r;}
	bool interhas(ln l){ // l seghas intersection?
		if(*this/l)return 0;
		ld alp=((p-l.p)%pq/(l.pq%pq)); // w.r.t l
		return min(alp,1-alp)>=LIM; // covers seghas
	}
};

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<pt> a(n);
		fore(i,0,n)cin>>a[i].x>>a[i].y;
		a.pb(a[0]); n++;
		fore(i,1,n-2){
			ln sid(a[i],a[i+1]);
			fore(j,i+2,n)a[j]=sid.ref(a[j]);
		}
		// for(auto p:a)cout<<p.x<<","<<p.y<<" ";;cout<<"\n";
		ln ray(a[0],a[n-1]);
		ll fg=1;
		fore(i,1,n-2)fg&=ray.interhas(ln(a[i],a[i+1]));
		if(!fg){
			cout<<"NO\n";
			continue;
		}
		cout<<"YES\n";
		ld ang=atan2l(ray.pq.y,ray.pq.x);
		ang=ang*180/atan2l(0,-1);
		cout<<fixed<<setprecision(30)<<ang<<"\n";
	}
	return 0;
}
