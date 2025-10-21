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
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
const ll MAXN=1e6+5;
random_device rd;
mt19937 rng(rd());
const ld EPS=0;
struct pt {  // for 3D add z coordinate
	ld x,y;
	pt(ld x, ld y):x(x),y(y){}
	pt(){}
	pt operator+(pt p){return pt(x+p.x,y+p.y);}
	pt operator-(pt p)const{return pt(x-p.x,y-p.y);}
	pt operator*(ld t){return pt(x*t,y*t);}
	// ld operator*(pt p){return x*p.x+y*p.y;}
	ld operator%(pt p){return x*p.y-y*p.x;}
};
int cuad(const pt &a){
	if(a.x>0&&a.y>=0)return 0;
	if(a.x<=0&&a.y>0)return 1;
	if(a.x<0&&a.y<=0)return 2;
	if(a.x>=0&&a.y<0)return 3;
	assert(a.x==0&&a.y==0);
	return -1;
}
bool cmp(const pt& p1, const pt& p2){
	int c1=cuad(p1),c2=cuad(p2);
	if(c1==c2)return p1.y*p2.x<p1.x*p2.y;
	return c1<c2;
}

int get(int i, vector<pt>& a){
	int n=SZ(a);
	pt p=a[i];
	vector<pt> b;
	fore(j,0,n)if(i!=j){
		pt q=a[j]-p;
		if(cuad(q)>1)q=q*(-1);
		b.pb(q);
	}
	sort(ALL(b),cmp);
	ll q=0,res=0;
	fore(i,0,SZ(b)){
		q++;
		if(i==SZ(b)-1||b[i]%b[i+1]>0)res=max(res,q),q=0;
	}
	return res+1;
}
const ll TL=60*5,TOT=TL*CLOCKS_PER_SEC;
bool fits(){return clock()<TOT;}
int main(){FIN;
	ll t; cin>>t;
	vector<pt>a[t];
	fore(h,0,t){
		ll n; cin>>n;
		a[h].resize(n);
		fore(i,0,n)cin>>a[h][i].x>>a[h][i].y;
		shuffle(ALL(a[h]),rng);
	}
	vector<ll>per(t); iota(ALL(per),0);
	sort(ALL(per),[&](ll i, ll j){return SZ(a[i])<SZ(a[j]);});
	imp(per);
	return 0;
	ll p=0,pos=0;
	vector<int>res(t);
	while(p<t&&fits()){
		fore(_,p,t)if(fits()){
			ll h=per[_];
			// cout<<p<<": "<<_<<" "<<h<<" "<<pos<<"\n";
			res[h]=max(res[h],get(pos,a[h]));
			if(pos+1>=SZ(a[h]))p++;
		}
		pos++;
	}
	fore(caso,0,t){
		cout<<"Case #"<<caso+1<<": ";
		cout<<SZ(a[caso])-res[caso]<<"\n";
	}
	return 0;
}
