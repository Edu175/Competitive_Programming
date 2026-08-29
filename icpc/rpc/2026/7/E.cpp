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
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
typedef long double ld;
const ld EPS=1e-10;

struct pt {
	ld x,y;
	pt(ld x, ld y):x(x),y(y){}
	pt(){}
	ld norm2(){return *this**this;}
	ld norm(){return sqrt(norm2());}
	pt tra(){return pt(y,x);}
	pt neg(){return pt(-x,-y);}
	pt operator+(pt p){return pt(x+p.x,y+p.y);}
	pt operator-(pt p){return pt(x-p.x,y-p.y);}
	pt operator*(ld t){return pt(x*t,y*t);}
	pt operator/(ld t){return pt(x/t,y/t);}
	ld operator*(pt p){return x*p.x+y*p.y;}
};
const ll ITER3=100; // 50 should be ok
const ll ITER2=60; // 30 should be ok

int main(){FIN;
	pt a,b; cin>>a.x>>a.y>>b.x>>b.y;
	ld len; cin>>len;
	vector<ld> ans;
	ld rad=len;
	fore(ty1,0,2){
		a=a.neg();
		b=b.neg();
		fore(ty2,0,2){ // look for max
			pt o=(a+b)/2;
			auto elip_dist=[&](pt p){
				return (p-a).norm()+(p-b).norm();
			};
			auto min_elip_dist=[&](ld x)->ld { // min elipse-dist of any point with given x coord
				ld l=o.y-len,r=o.y+len;
				ld ans=0;
				fore(_,0,ITER3){
					ld h1=l+(r-l)*1./3;
					ld h2=l+(r-l)*2./3;
					ld cur1=elip_dist(pt(x,h1));
					ld cur2=elip_dist(pt(x,h2));
					if(!_)ans=cur1;
					ans=min({ans,cur1,cur2});
					if(cur1<cur2)r=h2;
					else l=h1;
				}
				return ans;
			};
			ld l=o.x,r=o.x+len;
			fore(_,0,ITER2){
				ld m=(l+r)/2;
				if(min_elip_dist(m)<=rad)l=m;
				else r=m;
			}
			ld cur=l;
			if(!ty1)cur=-cur;
			ans.pb(cur);
			a=a.tra();
			b=b.tra();
		}
	}
	cout<<fixed<<setprecision(15);
	fore(i,0,SZ(ans)){
		if(i)cout<<" ";
		cout<<ans[i];
	}
	cout<<"\n";
	return 0;
}
