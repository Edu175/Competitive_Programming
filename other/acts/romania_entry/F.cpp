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
typedef pair<ll,ll> ii;
ll fqrt(ll x){ //if ceil change to r*r<x and return r
	ll r=sqrt(x)-3;
	for(;r<0||r*r<=x;r++)if(r<0)continue;
	return r-1;
}
vector<ll> bhas(ll a, ll b, ll c){
	ll d=b*b-4*a*c;
	if(d<0||fqrt(d)*fqrt(d)!=d)return {};
	ll x1=-b+fqrt(d),x2=-b-fqrt(d);
	vector<ll>r;
	if(x1%(2*a)==0)r.pb(x1/(2*a));
	if(x2%(2*a)==0)r.pb(x2/(2*a));
	return r;
}

int main(){FIN;
	ll a,b,s; cin>>a>>b>>s;
	auto r=bhas(1,-(a+b),a*b-s);
	if(SZ(r))cout<<r[0]<<"\n";
	else cout<<"-1\n";
	return 0;
}
