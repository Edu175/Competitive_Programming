#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ld EPS=1e-10;
struct pt {
	ld x,y,z;
	pt(ld x, ld y, ld z):x(x),y(y),z(z){}
	pt(){}
	ld norm2(){return *this**this;}
	ld norm(){return sqrt(norm2());}
	pt operator+(pt p){return pt(x+p.x,y+p.y,z+p.z);}
	pt operator-(pt p){return pt(x-p.x,y-p.y,z-p.z);}
	pt operator*(ld t){return pt(x*t,y*t,z*t);}
	pt operator/(ld t){return pt(x/t,y/t,z/t);}
	ld operator*(pt p){return x*p.x+y*p.y+z*p.z;}
	pt operator^(pt p){ // only for 3D
		return pt(y*p.z-z*p.y,z*p.x-x*p.z,x*p.y-y*p.x);}
	pt unit(){return *this/norm();}
	// #define str to_string
	// string cv(){return str(x)+","+str(y)+","+str(z);}
};
pt bary(pt A, pt B, pt C, ld a, ld b, ld c) {
    return (A*a+B*b+C*c) / (a+b+c);
}
pt circumcenter(pt A, pt B, pt C) {
    // intersection of perpendicular bisectors
    ld a=(B-C).norm(), b=(C-A).norm(), c=(A-B).norm();
    return bary(A, B, C, a*(b+c-a), b*(c+a-b), c*(a+b-c));
}
void full(){
	cout<<"90\n";
	exit(0);
}
int main(){
	JET
	ll n; cin>>n;
	if(n<=3){
		full();
	}
	vector<pt> a(n);
	fore(i,0,n)cin>>a[i].x>>a[i].y>>a[i].z;
	for(auto &p:a)p=p.unit();
	vector<vv> vis(n,vv(n));
	ll s=0,t=1;
	fore(j,1,n)if((a[j]-a[s]).norm()<(a[t]-a[s]).norm())t=j;
	queue<ii> q;
	q.push({s,t});
	ld res=0;
	while(SZ(q)){
		auto [s,t]=q.front(); q.pop();
		if(vis[s][t])continue;
		ll u=-1;
		pt nor; // centrado en a[s]
		fore(j,0,n)if(j!=s&&j!=t&&(u==-1||nor*(a[j]-a[s])>EPS)){
			u=j;
			nor=(a[u]-a[s])^(a[t]-a[s]);
		}
		if(nor*(pt(0,0,0)-a[s])>=-EPS)full();
		// cerr<<s<<" "<<t<<" "<<u<<"\n";
		// cerr<<a[s].cv()<<" "<<a[t].cv()<<" "<<a[u].cv()<<"\n";
		pt o=circumcenter(a[s],a[t],a[u]);
		// cerr<<o.cv()<<" o\n";
		o=o.unit();
		
		ld alp=a[s]*o;
		assert(abs(alp-a[t]*o)<EPS&&abs(alp-a[u]*o)<EPS);
		res=max(res,alp);
		
		vis[s][t]=vis[t][u]=vis[u][s]=1;
		q.push({s,u});
		q.push({u,t});
		q.push({t,s});
	}
	res=acosl(res);
	res=res*180/acosl(-1);
	res=min(res,90.l);
	cout<<fixed<<setprecision(15)<<res<<"\n";
	return 0;
}