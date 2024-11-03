#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet; i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define ET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> ii;
typedef vector <ll> vv;
random_device rd;
mt19937 rng(rd());
const ld EPS=1e-13;
struct pt{
	ld x,y;
	pt(ld x, ld y):x(x),y(y){}
	pt(){}
	ld norm(){return sqrtl(x*x+y*y);}
};
const ll MAXN=1e4+5;
ll n;
pt a[MAXN];
const ld pi=acosl(-1);

bool can(ld l){
	ld S=0,E=pi/2;
	vector<pair<ld,ll>>ev;
	fore(i,0,n){
		ld d=a[i].norm();
		if(l>d)return 0;
		if(l*sqrtl(2)<d)continue;
		ld alp=atan2(a[i].y,a[i].x);
		ld bet=acosl(l/d);
		ld s=alp-bet,e=alp+bet;
		if(s<S||e>E){
			assert(!(s<S&&e>E));
			if(e>E)e-=pi/2;
			else s+=pi/2;
			swap(s,e);
			ev.pb({s,1});
			ev.pb({e,-1});
		}
		else {
			ev.pb({S,1});
			ev.pb({s,-1});
			ev.pb({e,1});
			ev.pb({E,-1});
		}
	}
	ev.pb({S,0});
	ev.pb({E,0});
	// sweep
	sort(ALL(ev));
	ll c=0;
	fore(i,0,SZ(ev)){
		c+=ev[i].snd;
		if(ev[i].fst<E&&c==0&&abs(ev[i].fst-ev[i+1].fst)>EPS)
			return 1;
	}
	return 0;
}

int main(){ET
	cin>>n;
	fore(i,0,n)cin>>a[i].x>>a[i].y;
	fore(i,0,n){
		ld &x=a[i].x,&y=a[i].y;
		while(!(x>0&&y>=0)){
			ld xi=-y,yi=x;
			x=xi,y=yi;
		}
	}
	ld l=0,r=a[0].norm()+5;
	ll it=100;
	while(it--){
		ld m=(l+r)/2;
		if(can(m))l=m;
		else r=m;
	}
	ld res=r*8;
	// if(n>10){
	// 	cout<<fixed<<setprecision(15);
	// 	cout<<l*8<<" "<<r*8<<"\n";
	// 	cout<<res<<"\n";
	// }
	cout<<fixed<<setprecision(4);
	// cout<<pi<<"\n";
	cout<<res<<"\n";
}