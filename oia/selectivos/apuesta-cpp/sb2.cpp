#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<cv(gdljh)<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef long double ld;

vector<double> apuesta(vector<int> &X, vector<int> &Y){
	ll n=SZ(X);
	vector<ii>a;
	fore(i,0,n)a.pb({X[i],Y[i]});
	map<ii,ll>mp;
	for(auto i:a){
		ll x=i.fst,y=i.snd;
		ll g=__gcd(abs(x),abs(y));
		if(g)x/=g,y/=g;
		mp[{x,y}]++;
	}
	for(auto i:mp){
		ll x=i.fst.fst,y=i.fst.snd;
		x=-x; y=-y;
		if(i.snd!=mp[{x,y}])return {};
	}
	return {0,0};
}
