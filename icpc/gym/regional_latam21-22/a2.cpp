#include <bits/stdc++.h>
#define  fore(i,a,b) for(ll i=a, jet=b; i<jet; i++)
#define pb push_back
#define fst first 
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define ET ios::sync_with_stdio(0);cout.tie(0);cin.tie(0);
using namespace std;
typedef long long ll;
typedef long long ld;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
struct pt {  // for 3D add z coordinate
	ld x,y;
	pt(ld x, ld y):x(x),y(y){}
	pt(){}
	pt operator+(pt p){return pt(x+p.x,y+p.y);}
	pt operator-(pt p)const{return pt(x-p.x,y-p.y);}
	pt operator*(ld t){return pt(x*t,y*t);}
	pt operator/(ld t){return pt(x/t,y/t);}
	ld operator*(pt p){return x*p.x+y*p.y;}
	ld operator%(pt p){return x*p.y-y*p.x;}
	bool operator==(pt p){return x==p.x&&y==p.y;}
	bool left(pt p, pt q){ // is it to the left of directed line pq?
		return (q-p)%(*this-p)>0;}
	string cv(){return to_string(x)+","+to_string(y);}
};
struct Cmp { // IMPORTANT: add const in pt operator -
	pt r;
	Cmp(pt r):r(r){}
	int cuad(const pt &a)const {
		if(a.x>0&&a.y>=0)return 0;
		if(a.x<=0&&a.y>0)return 1;
		if(a.x<0&&a.y<=0)return 2;
		if(a.x>=0&&a.y<0)return 3;
		assert(a.x==0&&a.y==0);
		return -1;
	}
	bool cmp(const pt& p1, const pt& p2)const {
		int c1=cuad(p1),c2=cuad(p2);
		if(c1==c2)return p1.y*p2.x<p1.x*p2.y;
		return c1<c2;
	}
	bool operator()(const pt& p1, const pt& p2)const {
		return cmp(p1-r,p2-r);
	}
};
const ll MAXN=405;
int ft[MAXN+1]; // for more dimensions, make ft multi-dimensional
void upd(int i0, int v){ // add v to i0th element (0-based)
	// add extra fors for more dimensions
	for(int i=i0+1;i<=MAXN;i+=i&-i)ft[i]+=v;
}
int get(int i0){ // get sum of range [0,i0)
	int r=0;
	// add extra fors for more dimensions
	for(int i=i0;i;i-=i&-i)r+=ft[i];
	return r;
}
int get_sum(int i0, int i1){ // get sum of range [i0,i1) (0-based)
	return get(i1)-get(i0);
}
pt a[MAXN];
ll n,s;
ll concavo(pt &p, pt &q){
	vector<pt>l,r;
	vv ra;
	auto area=[&](pt r){
		ll res=abs(p%q+q%r+r%p);
		return res;
	};
	fore(i,0,n){ // no collinear with p,q (ah, lo garantizan xd)
		if(a[i].left(p,q))l.pb(a[i]);
		if(a[i].left(q,p))r.pb(a[i]),ra.pb(area(a[i]));
	}
	sort(ALL(ra));
	auto get_idx=[&](pt &a){
		return SZ(ra)-1-(lower_bound(ALL(ra),area(a))-ra.begin());
	};
	ll n=SZ(l),m=SZ(r);
	for(auto i:r)upd(get_idx(i),1);
	auto ordena=[&](vector<pt> &a){
		a.pb(p);
		sort(ALL(a),Cmp(q));
		ll pos=-1; fore(i,0,SZ(a))if(a[i]==p)pos=i;
		pos=(pos+1)%SZ(a);
		rotate(a.begin(),a.begin()+pos,a.end());
		a.pop_back();
	};
	ordena(l);
	ordena(r);
	ll po=0,res=0;
	for(auto i:l){
		while(po<m&&i.left(r[po],q))upd(get_idx(r[po++]),-1);
		ll idx=lower_bound(ALL(ra),s-area(i))-ra.begin();
		ll resi=get(m-idx);
		res+=resi;
	}
	while(po<m)upd(get_idx(r[po++]),-1);
	// cout<<"concavo "<<p.cv()<<" "<<q.cv()<<": "<<res<<"\n";
	return res;
}

ll todos(pt p, pt q){ // counts convex twice
	vector<pt>l,r;
	vv ra;
	auto area=[&](pt r){
		ll res=abs(p%q+q%r+r%p);
		return res;
	};
	fore(i,0,n){ // no collinear with p,q
		if(a[i].left(p,q))l.pb(a[i]);
		if(a[i].left(q,p))r.pb(a[i]),ra.pb(area(a[i]));
	}
	sort(ALL(ra));
	ll n=SZ(l),m=SZ(r);
	ll res=0;
	for(auto i:l){
		ll idx=lower_bound(ALL(ra),s-area(i))-ra.begin();
		ll resi=m-idx;
		res+=resi;
	}
	// cout<<"todos "<<p.cv()<<" "<<q.cv()<<": "<<res<<"\n";
	return res;
}

int main(){
	ET
	cin>>s>>n; s*=2;
	fore(i,0,n)cin>>a[i].x>>a[i].y;
	ll all=0,conc=0;
	fore(i,0,n)fore(j,0,n)if(i!=j){
		if(i<j)all+=todos(a[i],a[j]);
		conc+=concavo(a[i],a[j]);
	}
	// cout<<all<<" all\n";
	// cout<<conc<<" conc\n";
	ll res=(all+conc)/2;
	cout<<res<<"\n";
}