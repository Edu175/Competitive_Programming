#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define pb push_back
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef long long ld;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ld EPS=0;
struct pt{
	ld x,y;
	pt(ld x, ld y):x(x),y(y) {}
	pt(){}
	pt operator+(pt p){return pt(x+p.x,y+p.y);}
	pt operator-(pt p)const{return pt(x-p.x,y-p.y);}
	ld operator%(pt p){return x*p.y-y*p.x;}
	bool operator<(pt p)const{
		return x<p.x-EPS||(abs(x-p.x)<=EPS&&y<p.y-EPS);
	}
	bool operator==(pt p){
		return x==p.x&&y==p.y;
	}
	bool left(pt p, pt q){
		return (q-p)%(*this-p)>EPS;
	}
};
vector<pt> chull(vector<pt> p){
	if(SZ(p)<3)return p;
	vector<pt> r;
	sort(ALL(p));
	fore(i,0,SZ(p)){
		while(SZ(r)>=2&&r.back().left(r[SZ(r)-2],p[i]))r.pop_back();
		r.pb(p[i]);
	}
	r.pop_back();
	int k=SZ(r);
	for(int i=SZ(p)-1;i>=0;i--){
		while(SZ(r)>=k+2&&r.back().left(r[SZ(r)-2],p[i]))r.pop_back();
		r.pb(p[i]);
	}
	r.pop_back();
	return r;
}
struct Cmp{
	pt r;
	typedef pair<pt,ll> node;
	Cmp(pt r):r(r){}
	int cuad(const pt &a)const{
		if(a.x>0&&a.y>=0)return 0;
		if(a.x<=0&&a.y>0)return 1;
		if(a.x<0&&a.y<=0)return 2;
		if(a.x>=0&&a.y<0)return 3;
		assert(a.x==0&&a.y==0);
		return -1;
	}
	bool cmp(const pt &p1,const pt &p2) const{
		int c1=cuad(p1);
		int c2=cuad(p2);
		if(c1==c2)return p1.y*p2.x<p1.x*p2.y;
		return c1<c2;
	}
	bool operator()(const node &p1,const node &p2)const {
		return cmp(p1.fst-r,p2.fst-r);
	}
};
string cv(pt a){return to_string(a.x)+","+to_string(a.y);}
const ll MAXN=2e3+5;

ll n;
pair<pt,ll> b[MAXN]; // con los i
ll is[MAXN];// in chull
ll cant(pt p, pt q){
	vv pos0(n),pos1(n);
	auto get=[&](vv &pos, pt p, pt q, ll rev){
		sort(b,b+n,Cmp(p));
		if(rev)reverse(b,b+n);
		ll w=-1;
		fore(i,0,n)if(b[i].fst==q)w=i;
		rotate(b,b+w,b+n);
		fore(i,0,n)pos[b[i].snd]=i;
	};
	get(pos0,p,q,0);
	get(pos1,q,p,1);
	vector<ii>v;
	fore(i,0,n)if(!is[i])v.pb({pos0[i],pos1[i]});
	sort(ALL(v));
	ll mn=n+5,res=0;
	fore(i,0,SZ(v)){
		if(v[i].snd<mn)res++,mn=v[i].snd;
	}
	// cout<<cv(p)<<" "<<cv(q)<<":\n";
	// for(auto i:pos0)cout<<i<<" ";;cout<<"\n";
	// for(auto i:pos1)cout<<i<<" ";;cout<<"\n";
	// cout<<res<<"\n\n";
	return res;
}


int main(){
    JET
	cin>>n;
	vector<pt>a(n);
	fore(i,0,n)cin>>a[i].x>>a[i].y,b[i]={a[i],i};
	auto c=chull(a);
	map<pt,ll>mp;
	fore(i,0,n)mp[a[i]]=i;
	for(auto p:c)is[mp[p]]=1;
	ll res=0;
	fore(i,0,SZ(c)){
		pt p=c[i],q=c[(i+1)%SZ(c)];
		res+=cant(p,q);
	}
	cout<<res+1<<"\n";
    return 0;
}

// g++ -Wall -Wextra -std=c++17 -D_GLIBCXX_DEBUG -g tempate.cpp -o a
// for i in {a..z}; do cp tempate.cpp $i.cpp;done