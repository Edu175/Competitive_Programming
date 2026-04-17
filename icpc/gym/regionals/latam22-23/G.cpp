#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet; i++)
#define forr(i,a,b) for(ll i=b-1, jet=a; i>=jet; i--)
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define pb push_back
#define ET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef ll ld;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ld EPS=0;

#define str to_string
struct pt{
	ld x,y;
	pt(ld x, ld y):x(x),y(y){}
	pt(){}
	pt operator+(pt p){return pt(x+p.x, y+p.y);}
	pt operator-(pt p){return pt(x-p.x, y-p.y);}
	pt operator*(ld t){return pt(x*t, y*t);}
	pt operator/(ld t){return pt(x/t, y/t);}
	// bool operator==(pt p){return x==p.x&&y==p.y;}
	ld operator%(const pt &p) const {return x*p.y-y*p.x;}
	bool left(pt p, pt q){return (q-p)%(*this-p)>EPS;}
	bool operator<(pt p)const{ // for convex hull
		return x<p.x-EPS||(abs(x-p.x)<=EPS&&y<p.y-EPS);}
};
string cv(ld x){
	string s=str(x);
	s.resize(SZ(s)-4); // le saco 4 digitos
	return s;
}
string cv(pt p){return cv(p.x).substr()+","+cv(p.y);}

string cv(vector<pt> a){
	string s="{ ";
	for(auto i:a)s+=cv(i)+" ";
	s+="} ";
	return s;
}
// Compute Minkowski sum of two CONVEX polygons (remove collinear first)
// Returns answer in CCW order
void reorder(vector<pt> &p){
	if(!p[2].left(p[0],p[1])) reverse(ALL(p));
	int pos=0;
	fore(i,1,SZ(p)) if(pt(p[i].y,p[i].x) < pt(p[pos].y,p[pos].x)) pos=i;
	rotate(p.begin(), p.begin()+pos, p.end());
}
vector<pt> minkowski(vector<pt> p, vector<pt> q){
	assert(min(SZ(p),SZ(q))>=3);
	//   vector<pt> v;
	// 	for(pt pp:p) for(pt qq:q) v.pb(pp+qq);
	// 	return chull(v);
	// }
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
struct pol {
	int n;vector<pt> p;
	pol(){}
	pol(vector<pt> _p){p=_p;n=p.size();}
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
};
vector<pt> operator*(vector<pt> a, ld t){
	for(auto &i:a)i=i*t;
	return a;
}
vector<pt> operator/(vector<pt> a, ld t){
	for(auto &i:a)i=i/t;
	return a;
}
void ingr(ld &a){
	cin>>a;
	a*=2;
}
int main(){
	ET
	ll n; cin>>n;
	vector<pt> a(n);
	fore(i,0,n)ingr(a[i].x),ingr(a[i].y);
	
	ll m; cin>>m;
	vector<pt> b(m);
	fore(i,0,m)ingr(b[i].x),ingr(b[i].y);
	
	ll q; cin>>q;
	vector<pt> qs(q);
	fore(i,0,q)ingr(qs[i].x),ingr(qs[i].y);
	
	vector<pol> cand={
		minkowski(a,b)/2,
		minkowski(a*2,b*(-1)),
		minkowski(b*2,a*(-1))
	};
	for(auto &a:cand)a.normalize();
	for(auto p:qs){
		ll fg=0;
		for(auto &a:cand)fg|=a.haslog(p);
		if(fg)cout<<"Y";
		else cout<<"N";
		// cerr<<"\n\n";
	}
	cout<<"\n";
}