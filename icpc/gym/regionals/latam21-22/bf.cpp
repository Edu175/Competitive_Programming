#include <bits/stdc++.h>
#define  fore(i,a,b) for(ll i=a, jet=b; i<jet; i++)
#define pb push_back
#define fst first 
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define ET ios::sync_with_stdio(0);cout.tie(0);cin.tie(0);
#define imp(v) {for(auto i:v)cerr<<i<<" "; cerr<<"\n";}
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
	bool left(pt p, pt q){ // is it to the left of directed line pq?
		return (q-p)%(*this-p)>0;}
	string cv(){return to_string(x)+","+to_string(y);}
};
ll s;
bool good(vector<pt>a){
	assert(SZ(a)==4);
	ll flag=0;
	fore(i,0,2){
		pt p=a[i],q=a[i+2];
		flag|=a[i^1].left(p,q)&&a[i^3].left(q,p);
		flag|=a[i^1].left(q,p)&&a[i^3].left(p,q);
	}
	// for(auto i:a)cout<<i.cv()<<" ";;cout<<": "<<flag<<"\n";
	if(!flag)return 0;
	ll res=0;
	fore(i,0,SZ(a)){
		auto x=a[i],y=a[(i+1)%4];
		res+=x%y;
	}
	res=abs(res);
	return res>=2*s;
}

int main(){
	ET
	ll n; cin>>s>>n;
	vector<pt> a(n);
	fore(i,0,n)cin>>a[i].x>>a[i].y;
	set<vv>st;
	fore(i,0,n)fore(j,i+1,n)fore(k,i+1,n)if(j!=k)fore(l,i+1,n)if(l!=j&&l!=k){
		vv v={i,j,k,l};
		vector<pt> ps; for(auto i:v)ps.pb(a[i]);
		if(good(ps)){
			auto rv=v; reverse(rv.begin()+1,rv.end());
			st.insert(min(v,rv));
		}
	}
	cout<<SZ(st)<<"\n";
	for(auto v:st){
		imp(v)
	}
}