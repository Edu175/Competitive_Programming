#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> ii;
const ld EPS=1e-8;
struct pt {
	ld x,y;
	pt(ld x, ld y):x(x),y(y){}
	pt(){}
	pt operator+(pt p){return pt(x+p.x,y+p.y);}
	pt operator-(pt p){return pt(x-p.x,y-p.y);}
	pt operator*(ld t){return pt(x*t,y*t);}
	pt operator/(ld t){return pt(x/t,y/t);}
	ld operator%(pt p){return x*p.y-y*p.x;}
};
string cv(pt p){return to_string(p.x)+","+to_string(p.y);}
struct lat{
	ll x,y;
	lat(ll x, ll y):x(x),y(y){}
	lat(){}
	lat operator+(lat p){return lat(x+p.x,y+p.y);}
	lat operator-(lat p){return lat(x-p.x,y-p.y);}
	ll operator%(lat p){return x*p.y-y*p.x;}
};
int cuad(pt &a){
	if(a.x>0&&a.y>=0)return 0;
	if(a.x<=0&&a.y>0)return 1;
	if(a.x<0&&a.y<=0)return 2;
	if(a.x>=0&&a.y<0)return 3;
	assert(0);
//	assert(a.x==0&&a.y==0);
//	return -1;
}
bool cmp(pt& p1, pt& p2){
	int c1=cuad(p1),c2=cuad(p2);
//	cout<<"cmp "<<cv(p1)<<" "<<cv(p2)<<": ";
	if(c1==c2){
		
		return p1%p2>0;
	}
	return c1<c2;
}
pt go(pt a, pt b){
	pt d=b-a;
	return a+d*0.5;
}
int main(){FIN;
	srand(175);
	ll n; cin>>n;
	vector<pt>a;
	vector<lat>b;
	fore(i,0,n){
		ll x,y; cin>>x>>y;
		a.pb(pt(x,y));
		b.pb(lat(x,y));
	}
	ll j=-1;
	fore(i,2,n){
		lat p0=b[1]-b[0],p1=b[i]-b[0];
		if(p0%p1){j=i;break;}
	}
	if(j==-1){
		cout<<"No solution\n";
		return 0;
	}
	pt p=go(a[0],a[1]);
	p=go(p,a[j]);
//	cerr<<cv(p)<<"\n";
	for(auto &i:a)i=i-p;
//	for(auto i:a)cout<<cuad(i)<<" ";;cout<<"\n";
	vector<ll>res;
	fore(i,0,n)res.pb(i);
	auto lam=[&](ll i, ll j){
//		cout<<"comp "<<i<<" "<<j<<": ";
		if(cuad(a[i])==cuad(a[j])&&abs(a[i]%a[j])<=EPS){
			assert(0);
//			cout<<"desempate "<<cv(a[i])<<" "<<cv(a[j])<<"("<<a[i]%a[j]<<") = "<<(a[i].x+a[i].y<a[j].x+a[j].y)<<"\n";
			return a[i].x+a[i].y<a[j].x+a[j].y;
		}
		return cmp(a[i],a[j]);
	};
	sort(ALL(res),lam);
	for(auto i:res)cout<<i+1<<" ";;cout<<"\n";
	return 0;
}
