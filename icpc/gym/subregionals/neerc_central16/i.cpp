#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define snd second
#define fst first
#define pb push_back
#define SZ(x) ((int)x.size())
#define ALL(x) (x.begin(),x.end())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
typedef long double ld;
const ld EPS=1e-7;
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
	// ld operator%(pt p){return x*p.y-y*p.x;}
};
struct ln{
	pt p,pq;
	ln(pt p, pt q):p(p),pq(q-p){}
	ln(){}
	bool has(pt r){return dist(r)<=EPS;}
	bool seghas(pt r){return has(r)&&(r-p)*(r-(p+pq))<=EPS;}
	pt proj(pt r){return p+pq*((r-p)*pq/pq.norm2());}
	ld dist(pt r){return (r-proj(r)).norm();}
};
ld dis(pt p, ln l){
	if(l.seghas(l.proj(p)))return l.dist(p);
	return min((p-l.p).norm(),(l.p+l.pq-p).norm());
}
ld dis(ln l, ln k){
	pt p=k.p,q=k.p+k.pq;
	ld res= min(dis(p,l),dis(q,l));
	p=l.p,q=l.p+l.pq;
	res= min({res,dis(p,k),dis(q,k)});
	return res;
}
int main(){JET
	#ifdef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ll n,m,m2; cin>>n>>m>>m2;
	vector<pt>a(n);
	fore(i,0,n)cin>>a[i].x>>a[i].y;
	ld res=-1;
	fore(i,0,n)fore(j,0,n)if(i!=j){
		pt p=a[i],q=a[j];
		ln l(a[i],a[(i+1)%n]),k(a[j],a[(j+1)%n]);
		// cout<<i<<" "<<j<<": ";
		// seg seg
		ll c0=(j-i+n)%n+2,c1=(i-j+n)%n+2;
		ld d=dis(l,k);
		auto check=[&](){
			ll can=(c0==m&&c1==m2)||(c0==m2&&c1==m);
			// cout<<(can?d:-1.0)<<" ";
			if(can&&(res==-1||d<res))res=d;
		};
		check();
		// pt seg
		c1--;
		d=dis(p,k);
		check();
		// pt pt
		c0--;
		d=(q-p).norm();
		check();
		// cout<<"\n";
	}
	cout<<fixed<<setprecision(15)<<res<<"\n";
	return 0;
}