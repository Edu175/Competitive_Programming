#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef long double ld;
const ld EPS=1e-12;
struct pt{
	ld x,y;
	pt(ld x, ld y):x(x),y(y){}
	pt(){}
	ld norm2(){return *this**this;}
	ld norm(){return sqrt(norm2());}
	bool operator==(pt p){return abs(x-p.x)<=EPS&&abs(y-p.y)<=EPS;}
	pt operator+(pt p){return pt(x+p.x,y+p.y);}
	pt operator-(pt p){return pt(x-p.x,y-p.y);}
	pt operator*(ld t){return pt(x*t,y*t);}
	pt operator/(ld t){return pt(x/t,y/t);}
	ld operator*(pt p){return x*p.x+y*p.y;}
};
//void prnt(pt p){cout<<p.x<<","<<p.y<<" ";}
pt s[3],v[2];
ld res;
ll vel[3];
pt go(ll w, ld t){
	if(s[w].norm()/vel[w]<=EPS*1e-2+t)return pt(0,0);
	pt ret=s[w]+v[w]*t;
	//if(ret==pt(0,0)||ret.x<=EPS||ret.y<=EPS)return pt(0,0);
	return ret;
}
bool reach(ll w, ld t){
	pt p=go(w,t);
	return ((s[2]-p).norm()/vel[2]<=EPS*1e-2+t);
}
int main(){FIN;
	fore(i,0,2){
		cin>>s[i].x>>s[i].y;
		cin>>vel[i];
		v[i]=(pt(0,0)-s[i])/s[i].norm()*vel[i];
	}
	cin>>vel[2];
	s[2]=s[0];
	//prnt(s[0]); prnt(s[1]); prnt(s[2]); cout<<"\n";
	//prnt(v[0]); prnt(v[1]); cout<<endl;
	ll w=1;
	while(!((s[0]-s[1]).norm()<=EPS)){
		//prnt(s[0]); prnt(s[1]); prnt(s[2]); cout<<endl;
		ld l=0,r=1e5;
		ll it=100;
		while(it--){
			ld m=(l+r)/2.0;
			if(reach(w,m))r=m;
			else l=m;
		}
		res+=(s[2]-go(w,l)).norm();
		s[w]=s[2]=go(w,l);
		s[w^1]=go(w^1,l);
		w^=1;
	}
	
	cout<<fixed<<setprecision(15)<<res<<"\n";
	return 0;
}
