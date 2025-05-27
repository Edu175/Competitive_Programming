#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef long long ld;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
//  n³ logn ... n<=5000 :skull_emoji:
const ld EPS=0;
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
	// 2D from now on
	bool operator<(pt p)const{ // for convex hull
		return x<p.x-EPS||(abs(x-p.x)<=EPS&&y<p.y-EPS);}
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
	bool operator()(const pair<pt,ll>& p1, const pair<pt,ll>& p2)const {
		return cmp(p1.fst-r,p2.fst-r);
	}
};

const ll MAXN=5005,MAXQ=4e6+5;

pt a[MAXN];
ll ans[MAXQ];
ll n;
void answer(ll p, ll q, vector<ii>qs){
	if(!SZ(qs))return;
	vv posp(n,-1),posq(n,-1);
	auto doit=[&](ll p, ll q, vv &pos, bool rev){
		vector<pair<pt,ll>>b;
		fore(i,0,n)if(i!=p)b.pb({a[i],i});
		sort(ALL(b),Cmp(a[p]));
		ll w=-1;
		fore(i,0,SZ(b))if(b[i].snd==q)w=i;
		rotate(b.begin(),b.begin()+w,b.end());
		if(rev)reverse(ALL(b));
		fore(i,0,SZ(b))pos[b[i].snd]=i;
	};
	doit(p,q,posp,0);
	doit(q,p,posq,1);
	vector<array<ll,3>>v;
	fore(i,0,n)if(i!=p&&i!=q)v.pb({posp[i],posq[i],i});
	sort(ALL(v));
	vv good(n);
	ll mn=n+5;
	for(auto [dkfj,val,i]:v){
		mn=min(mn,val);
		good[i]=mn==val;
	}
	for(auto [i,wh]:qs){
		assert(i!=p&&i!=q);
		ans[wh]=good[i];
	}
}


int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll q; cin>>n>>q;
		map<pt,ll>mp;
		fore(i,0,n)cin>>a[i].x>>a[i].y,mp[a[i]]=i;
		
	}
	return 0;
}
