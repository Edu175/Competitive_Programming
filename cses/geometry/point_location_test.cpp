#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,b=oia;i<oia;i++)
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

struct pt{
	ll x,y;
	pt(ll x, ll y):x(x),y(y){};
	pt(){};
	pt operator-(pt p){return pt(x-p.x,y-p.y);}
	bool operator==(pt p){return (x==p.x&&y==p.y);}
	ll operator%(pt p){return x*p.y-y*p.x;}
	bool left(pt p, pt q){return (p-*this)%(q-*this)>0}
};

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		pt a,b,c; cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y;
		ll s=(b-a)%(c-a);
		if(s>0)cout<<"LEFT\n";
		if(s<0)cout<<"RIGHT\n";
		if(s==0)cout<<"TOUCH\n";
	}
	return 0;
}
