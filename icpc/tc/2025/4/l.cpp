#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ld pi=acosl(-1),EPS=1e-8;

struct pt{
	ld x,y;
	pt(){}
	pt(ld x, ld y):x(x),y(y){}
	ld norm2(){return *this**this;}
	ld norm(){return sqrtl(norm2());}
	pt operator+(pt p){return pt(x+p.x,y+p.y);}
	pt operator-(pt p){return pt(x-p.x,y-p.y);}
	ld operator*(pt p){return x*p.x+y*p.y;}
};


ld go(ld l, pt p, ld alp){
	// cout<<"go "<<l<<" "<<p.x<<","<<p.y<<" "<<alp<<"\n";
	p=p-pt(l,0);
	ld d=p.norm();
	ld t=atan2(p.y,p.x);
	ld bet=pi-t-alp;
	if(bet<=EPS)return INFINITY;
	ld c=sin(alp)*d/sin(bet);
	// cout<<l+c<<"\n";
	return l+c;
}

#define maxig(a,b) a=max(a,b)

int main(){
	JET
	ll n,l,r; cin>>n>>l>>r;
	ll N=1ll<<n;
	vector<pt> a(n);
	vector<ld> ang(n);
	fore(i,0,n){
		cin>>a[i].x>>a[i].y;
		ld alp; cin>>alp;
		alp=alp/180*pi;
		ang[i]=alp;
	}
	vector<ld> dp(N,l-5);
	dp[0]=l;
	fore(mk,0,N){
		auto &res=dp[mk];
		// cout<<mk<<": "<<res<<"\n";
		fore(x,0,n)if(!(mk>>x&1))
			maxig(dp[mk|(1ll<<x)],go(res,a[x],ang[x]));
	}
	auto res=dp[N-1];
	// cout<<r<<"\n";
	res=min(res,(ld) r);
	res-=l;
	cout<<fixed<<setprecision(15)<<res<<"\n";
	return 0;
}