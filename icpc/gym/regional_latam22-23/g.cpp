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
const ld EPS=1e-7;

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
};
string cv(ld x){
	string s=str(x);
	s.resize(SZ(s)-4); // le saco 4 digitos
	return s;
}
string cv(pt p){return cv(p.x).substr()+","+cv(p.y);}

int cuad(const pt &p){
	if(p.x>0&&p.y>=0)return 0;
	if(p.x<=0&&p.y>0)return 1;
	if(p.x<0&&p.y<=0)return 2;
	if(p.x>=0&&p.y<0)return 3;
	assert(p.x==0&&p.y==0);
	return -1;
}

bool radial(const pt &p, const pt &q){
	int c1=cuad(p),c2=cuad(q);
	if(c1!=c2)return c1<c2;
	return p%q>0;
}
typedef vector<pt> pol;
string cv(pol a){
	string s="{ ";
	for(auto i:a)s+=cv(i)+" ";
	s+="} ";
	return s;
}

pol minkowski(pol a, pol b){ // convex
	auto rot=[&](pol &a){
		ll mn=0;
		fore(i,0,SZ(a)){
			if(a[i].y<a[mn].y || (a[i].y==a[mn].y&&a[i].x<a[mn].x))mn=i;
		}
		rotate(a.begin(),a.begin()+mn,a.end());
	};
	// cout<<"minkowski: "<<cv(a)<<" "<<cv(b)<<"\n";
	rot(a); rot(b);
	a.pb(a[0]); b.pb(b[0]);
	// cout<<"rotated: "<<cv(a)<<" "<<cv(b)<<"\n";
	ll n=SZ(a),m=SZ(b);
	forr(i,1,n)a[i]=a[i]-a[i-1];
	forr(i,1,m)b[i]=b[i]-b[i-1];
	pol r={a[0]+b[0]};
	ll p=1,q=1;
	while(p<n||q<m){
		ll w=0;
		if(p==n || (q<m&&radial(b[q],a[p])))w=1;
		// cout<<p<<" "<<q<<": "<<(p<n?cv(a[p]):"no")<<" "<<(q<n?cv(b[q]):"no")<<"\n";
		if(!w)r.pb(r.back()+a[p++]);
		else r.pb(r.back()+b[q++]);
	}
	// cout<<"r: "<<cv(r)<<endl;
	// assert(r[0]==r.back());
	r.pop_back();
	return r;
}
bool in(pt p, pol& a){ // convex, O(log)
	// cerr<<"in "<<cv(p)<<" "<<cv(a)<<":\n";
	if(p.left(a[1],a[0])||p.left(a[0],a.back()))return 0;
	ll l=1,r=SZ(a);
	while(r-l>1){
		ll m=(l+r)/2;
		if(p.left(a[0],a[m]))l=m;
		else r=m;
	}
	ll ret=!p.left(a[l+1],a[l]);
	// cerr<<ret<<" ret\n";
	return ret;
}

pol operator*(pol a, ld t){
	for(auto &i:a)i=i*t;
	return a;
}
pol operator/(pol a, ld t){
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
	for(auto p:qs){
		ll fg=0;
		for(auto &a:cand)fg|=in(p,a);
		if(fg)cout<<"Y";
		else cout<<"N";
		// cerr<<"\n\n";
	}
	cout<<"\n";
}