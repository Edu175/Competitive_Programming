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
const ld EPS=1e-7;
struct pt{
	ld x,y;
	pt(ld x, ld y):x(x),y(y){}
	pt(){}
	ld norm2(){return *this**this;}
	ld norm(){return sqrt(norm2());}
	pt operator-(pt p){return pt(x-p.x,y-p.y);}
	ld operator*(pt p){return x*p.x+y*p.y;}
	ld operator%(pt p){return x*p.y-y*p.x;}
	bool operator<(pt p)const{
		return x<p.x-EPS||(abs(x-p.x)<=EPS&&y<p.y-EPS);
	}
	
};
bool left(pt p, pt q){
		return q%p>EPS;
}
vector<pt> chull(vector<pt>p){
	if(SZ(p)<3)return p;
	vector<pt> r;
	sort(ALL(p));
	fore(i,0,SZ(p)){
		while(SZ(r)>=2&&r.back().left(r[SZ(r)-2],p[i]))
			r.pop_back();
		r.pb(p[i]);
	}
	r.pop_back();
	int k=SZ(r);
	for(ll i=SZ(p)-1;i>=0;i--){
		while(SZ(r)>=k+2&&r.back().left(r[SZ(r)-2],p[i]))
			r.pop_back();
			r.pb(p[i]);
	}
	return r;
}
struct ln{
	pt p,pq;
	ln(pt p, pt q):p(p),pq(q-p){}
	ln(){}
	pt operator^(ln l){
		
	}
};
int main(){
	#ifdef ONLINE_JUDGE
	freopen("dome.in","r",stdin);     freopen("dome.out","w",stdout);
	#endif
	JET
	ll n; cin>>n;
	vector<pt>a;
	fore(i,0,n){
		ld x,y,z; cin>>x>>y>>z;
		pt p=pt(pt(x,y).norm(),z);
		a.pb(p);
	}
	auto c=chull(a);
	ld res=-1;
	ld h,r;
	ll j=0;
	auto addm=[&](ll x, ll y){
		x+=y;
		return x<SZ(c)?x:x-SZ(c);
	};
	auto subm=[&](ll x, ll y){
		x-=y;
		return x<0?x+SZ(c):x;
	};
	while(c[j]<c[addm(j,1)]){
		j++;
	}
	fore(i,j,SZ(c)){
		pt p=pt(3*c[j].x/2,0);
		p=c[j]-p;
		if(!(left(c[subm(i,1)]-c[i],p)&&left(p,c[addm(i,1)]-c[i]))){
			
		}
	}
	return 0;
}