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

pair<ll,ll> extendedEuclid (ll a, ll b){ //a * x + b * y = gcd(a,b)
	ll x,y;
	if (b==0) return {1,0};
	auto p=extendedEuclid(b,a%b);
	x=p.snd;
	y=p.fst-(a/b)*x;
	if(a*x+b*y==-__gcd(a,b)) x=-x, y=-y;
	return {x,y};
}
pair<pair<ll,ll>,pair<ll,ll> > diophantine(ll a,ll b, ll r) {
	//a*x+b*y=r where r is multiple of gcd(a,b);
	ll d=__gcd(a,b);
	a/=d; b/=d; r/=d;
	auto p = extendedEuclid(a,b);
	p.fst*=r; p.snd*=r;
	cout<<a<<"*"<<p.fst<<"+"<<b<<"*"<<p.snd<<"=="<<r<<endl;
	cout<<a*p.fst+b*p.snd<<"=="<<r<<endl;
	assert(a*p.fst+b*p.snd==r);
	return {p,{-b,a}}; // solutions: p+t*ans.snd
}

int main(){FIN;
	ll a,b,c,d; cin>>a>>b>>c>>d;
	cout<<__gcd(a,b)<<" "<<__gcd(d,c)<<"\n";
	cout<<__gcd(2,-1)<<" "<<__gcd(-1,2)<<"\n";
	return 0;
	/*ll x,y; cin>>x>>y;
	ll a=x,b=-y;
	if(2%__gcd(a,b))cout<<"-1\n";
	else {
		ii res=diophantine(a,b,2).fst;
		cout<<res.snd<<" "<<res.fst<<"\n";
	}*/
	return 0;
}
