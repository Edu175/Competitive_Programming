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
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

pair<ll,ll> extendedEuclid (ll a, ll b){ //a * x + b * y = gcd(a,b)
	ll x,y;
	if (b==0) return {1,0};
	auto p=extendedEuclid(b,a%b);
	x=p.snd;
	y=p.fst-(a/b)*x;
	if(a*x+b*y==-gcd(a,b)) x=-x, y=-y;
	return {x,y};
}
pair<pair<ll,ll>,pair<ll,ll> > diophantine(ll a,ll b, ll r) {
	//a*x+b*y=r where r is multiple of gcd(a,b);
	ll d=gcd(a,b);
	a/=d; b/=d; r/=d;
	auto p = extendedEuclid(a,b);
	p.fst*=r; p.snd*=r;
	assert(a*p.fst+b*p.snd==r);
	return {p,{-b,a}}; // solutions: p+t*ans.snd
}
ll get(ll n, ll m, ll d){
	ll a;
	
	if(!a)a+=d;
}

int main(){FIN;
	ll n,m; cin>>n>>m;
	ll did=0;
	if(n==2){
		fore(a,1,m+1){
			ll b=m-a;
			if(b<=a)break;
			cout<<a*b+1<<" ";
			did=1;
		}
		cout<<"\n";
	}
	else {
		fore(d,1,m+3)if(n*(n-1)*d<=m){
			ll a=get(n,m,d);
			if(a==-1)continue;
			if(n*a+n*(n-1)*d<=m && a*a%d==d-1)cout<<d<<" ",did=1;
		}
		cout<<"\n";
	}
	if(!did)cout<<"-1\n";
	return 0;
}