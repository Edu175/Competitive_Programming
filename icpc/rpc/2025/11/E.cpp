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

struct pt{
	ld x,y;
	pt(ld x, ld y):x(x),y(y){}
	pt(){}
	pt operator-(pt p){return pt(x-p.x,y-p.y);}
	ld operator*(pt p){
		return x*p.x+y*p.y;
	}
};

int main(){FIN;
	vector<pt> a(4);
	fore(i,0,4)cin>>a[i].x>>a[i].y;
	ld w,h; cin>>w>>h;
	pt l1=a[1]-a[0];
	pt l2=a[2]-a[1];
	auto can=[&](ld r){
		pt d1(r*w,r*h);
		pt d2(-r*w,r*h);
		bool cond1 = max(abs(l1*d1),abs(l1*d2))<=l1*l1;
		bool cond2 = max(abs(l2*d1),abs(l2*d2))<=l2*l2;
		return cond1&&cond2;
	};
	ld l=1e-7,r=1e6;
	fore(_,0,64){
		ld m;
		if(2*l<r)m=sqrtl(l*r);
		else m=(l+r)/2;
		if(can(m))l=m;
		else r=m;
	}
	ld m=l;
	ld area=m*w * m*h;
	cout<<fixed<<setprecision(15)<<area<<"\n";
	return 0;
}
