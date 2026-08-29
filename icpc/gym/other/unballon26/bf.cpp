#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
#define showvp(v) {cout<<#v<<": ";;for(auto i:v)cout<<cv(i)<<" ";;cout<<"\n";}
using namespace std;
typedef long long ll;
typedef long long ld;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ld EPS=0;
struct pt {  // for 3D add z coordinate
	ld x,y;
	pt(ld x, ld y):x(x),y(y){}
	pt(){}
	ld norm2(){return *this**this;}
	// ld norm(){return sqrt(norm2());}
	bool operator==(pt p){return abs(x-p.x)<=EPS&&abs(y-p.y)<=EPS;}
	pt operator+(pt p){return pt(x+p.x,y+p.y);}
	pt operator-(pt p){return pt(x-p.x,y-p.y);}
	pt operator*(ld t){return pt(x*t,y*t);}
	pt operator/(ld t){return pt(x/t,y/t);}
	ld operator*(pt p){return x*p.x+y*p.y;}
	ld operator%(pt p){return x*p.y-y*p.x;}
	bool operator<(pt p)const{ // for convex hull
		return x<p.x-EPS||(abs(x-p.x)<=EPS&&y<p.y-EPS);}
	bool left(pt p, pt q){return (q-p)%(*this-p)>EPS;}
	bool leftOrAt(pt p, pt q){return !left(q,p);}
};
int main(){FIN;
	ll n,q; cin>>n>>q;
	vector<pt> a(n);
	fore(i,0,n){
		ll z,x,c,v; cin>>z>>x>>c>>v;
		a[i]={z-x,c-v};
	}
	while(q--){
		ll k,l; cin>>k>>l;
		pt v(k,l);
		ll res=0;
		fore(mk,0,1ll<<n){
			pt p(0,0);
			fore(i,0,n)if(mk>>i&1)p=p+a[i];
			ll cur=abs(p.x)*k+abs(p.y*l);
			res=max(res,cur);
		}
		cout<<res<<"\n";
	}
	return 0;
}
