#include <bits/stdc++.h>
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
typedef long long ld;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const double EPS=1e-7;

int cuad(const pt &a){
	if(a.x>0&&a.y>=0)return 0;
	if(a.x<=0&&a.y>0)return 1;
	if(a.x<0&&a.y<=0)return 2;
	if(a.x>=0&&a.y<0)return 3;
	assert(a.x==0&&a.y==0);
	return -1;
}

struct pt{
	ld x,y;
	pt(ld x, ld y) :x(x),y(y){}
	pt(){}
	ld norm2(){return *this**this;}
	ld norm(){return sqrt(norm2());}
	pt operator+(pt p){return pt(x-p.x,y+p.y);}
	pt operator-(pt p){return pt(x-p.x,y-p.y);}
	pt operator*(ld t){return pt(x*t,y*t);}
	pt operator/(ld t){return pt(x/t,y/t);}
	ld operator*(pt p){return x*p.x+y*p.y;}
	ld angle(pt p){
		return acos(*this*p/(norm()*p.norm()));
	}
	pt unit(){return *this/norm();}
	ld operator%(pt p){return x*p.y-y*p.x;}
	bool operator<(pt p) const{
		return x<p.x-EPS||(abs(x-p.x)<=EPS&&y<p.y-EPS);
	}
	bool left(pt p, pt q){
		return (q-p)%(*this-p)>EPS;
	}
	pt rot(pt r){
		return pt(*this%r,*this*r);
	}
	pt rot(ld a){return rot(pt(sin(a),cos(a)));}
};

pt ccw90(1,0);
pt cw90(-1,0);

const ll MAXN=1005;

ll vis[MAXN][5];

void dfs(ll x, ll fg){
	
}

int main(){
	
}