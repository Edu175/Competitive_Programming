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
typedef ll ld;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ld EPS=0;
// ld abs(ld x){return x<0?-x:x;}
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
#define str to_string
string cv(pt p){return str(p.x)+","+str(p.y);}
pt ccw90(1,0), cw90(-1,0);
vector<pt> chull(vector<pt> p){
	// if(SZ(p)<3)return p;
	vector<pt> r;
	sort(p.begin(),p.end()); // first x, then y
	p.erase(unique(ALL(p)), p.end());
	fore(i,0,p.size()){ // lower hull
		while(SZ(r)>=2&&r.back().leftOrAt(r[r.size()-2],p[i]))r.pop_back();
		r.pb(p[i]);
	}
	r.pop_back();
	int k=r.size(),pr=k-1;
	for(int i=p.size()-1;i>=0;--i){ // upper hull
		while(SZ(r)>=k+2&&r.back().leftOrAt(r[r.size()-2],p[i]))r.pop_back();
		while(pr>=0&&p[i]<r[pr]) pr--;
		if(pr<0||!(p[i]==r[pr])) r.pb(p[i]);
	}
	// cerr<<"chull de ";
	// showvp(p)
	// showvp(r)
	return r;
}
void reorder(vector<pt> &p){
	if(!p[2].left(p[0],p[1])) reverse(ALL(p));
	int pos=0;
	fore(i,1,SZ(p)) if(pt(p[i].y,p[i].x) < pt(p[pos].y,p[pos].x)) pos=i;
	rotate(p.begin(), p.begin()+pos, p.end());
}
vector<pt> minkowski_sum(vector<pt> p, vector<pt> q){
	if(min(SZ(p),SZ(q))<3){
	  	vector<pt> v;
		for(pt pp:p) for(pt qq:q) v.pb(pp+qq);
		return chull(v);
	}
	reorder(p); reorder(q);
	fore(i,0,2) p.pb(p[i]), q.pb(q[i]);
	vector<pt> r;
	int i=0,j=0;
	while(i+2<SZ(p)||j+2<SZ(q)){
		r.pb(p[i]+q[j]);
		auto cross=(p[i+1]-p[i])%(q[j+1]-q[j]);
		i+=cross>=-EPS;
		j+=cross<=EPS;
	}
	return r;
}
void normalize(vector<pt> &p){
	int n=SZ(p);
	if(SZ(p)>=3&&p[2].left(p[0],p[1]))reverse(p.begin(),p.end());
	int pi=min_element(p.begin(),p.end())-p.begin();
	vector<pt> s(n);
	fore(i,0,n)s[i]=p[(pi+i)%n];
	p.swap(s);
}
pt farthest(vector<pt> &p, pt v){ // O(log(n)) only CONVEX
	int n=SZ(p);
	if(n<10){
		// cerr<<"chico\n";
		int k=0; fore(i,1,n)if(v*(p[i]-p[k])>EPS)k=i;
		return p[k];
	}
	if(n==SZ(p))p.pb(p[0]);
	pt a=p[1]-p[0]; int s=0,e=n,ua=v*a>EPS;
	if(!ua&&v*(p[n-1]-p[0])<=EPS)return p[0];
	while(1){
		int m=(s+e)/2;
		pt c=p[m+1]-p[m];
		int uc=v*c>EPS;
		if(!uc&&v*(p[m-1]-p[m])<=EPS)return p[m];
		if(ua&&(!uc||v*(p[s]-p[m])>EPS))e=m;
		else if(ua||uc||v*(p[s]-p[m])>=-EPS)s=m,a=c,ua=uc;
		else e=m;
		assert(e>s+1);
	}
}
vector<vector<pt>> w;
void add(pt q){ // add(q), O(log^2(n))
	vector<pt> p={q};
	while(!w.empty()&&SZ(w.back())<2*SZ(p)){
		for(pt v:w.back())p.pb(v);
		w.pop_back();
	}
	w.pb(vector<pt>(chull(p)));
}
ll query(pt v){ // max(q*v:q in w), O(log^2(n))
	ll r=-1e18;
	for(auto& p:w)r=max(r,farthest(p,v)*v);
	return r;
}
int main(){FIN;
	ll n,q; cin>>n>>q;
	vector<pt> a(n);
	fore(i,0,n){
		ll z,x,c,v; cin>>z>>x>>c>>v;
		a[i]={z-x,c-v};
	}
	// showvp(a)
	vector<pt> p={{0,0}};
	for(auto ad:a){
		// cerr<<"\n\nvuelta\n";
		// showvp(p)
		p=minkowski_sum(p,{{0,0},ad});
	}
	p=chull(p); // removes collinear
	normalize(p);
	// showvp(p)
	while(q--){
		ll k,l; cin>>k>>l;
		pt v(k,l);
		ll res=0;
		fore(i,0,2)fore(j,0,2){
			pt u=v;
			if(i)u.x*=-1;
			if(j)u.y*=-1;
			auto got=query(p,u);
			ll cand=abs(got.x)*v.x+abs(got.y)*v.y;
			// cerr<<"dir "<<cv(u)<<": "<<cv(got)<<": "<<cand<<"\n";
			res=max(res,cand);
		}
		// ll cand2=0;
		// for(auto pp:p){
		// 	ll cur=abs(pp.x)*v.x+abs(pp.y)*v.y;
		// 	// cerr<<cv(pp)<<": "<<cur<<"\n";
		// 	cand2=max(cand2,cur);
		// }
		// cerr<<cand2<<" cand2\n";
		// assert(res==cand2);
		res=cand2;
		cout<<res<<"\n";
	}
	return 0;
}
