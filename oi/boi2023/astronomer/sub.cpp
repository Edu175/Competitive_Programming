#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,boi=b;i<boi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto skdauf:v)cout<<skdauf<<" ";cout<<"\n"
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> ii;
const ll PRES=55;
const ld EPS=1e-7;

struct pt{
	ll x,y;
	pt(){}
	pt(ll x, ll y):x(x),y(y){}
	ld norm2(){return x*x+y*y;}
	ld norm(){return sqrt(norm2());}
};
ll n,k;
const ll MAXN=705;
pt a[MAXN];

bool can(ld d){
	ll c=0;
	fore(i,0,n)c+=a[i].norm2()<=d*d;
	return c>=k;
}
int main(){FIN;
	ll s,t; cin>>k>>n>>s>>t;
	fore(i,0,n)cin>>a[i].x>>a[i].y;
	ld l=0,r=1e9+5;
	ll it=PRES;
	cout<<fixed<<setprecision(15);
	while(r-l>=EPS){
		//cout<<l<<","<<r<<": "<<r-l<<endl;
		ld m=(l+r)/2.0;
		if(can(m))r=m;
		else l=m;
	}
	cout<<l*t<<"\n";
	return 0;
}
