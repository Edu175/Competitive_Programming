// #include <bits/stdc++.h>
#include <cassert>
#include <cfloat>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <iostream>
#include <map>
#include <new>
#include <string>
#include <vector>
#include <array>
#include <unordered_map>
#include <unordered_set>

#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
#define inp(v) {for(auto &i:v)cin>>i;}
#define menos1(v) {for(auto &i:v)i--;}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

// vv divs(ll n){
// 	vv ret;
// 	for(ll i=2;i*i<=n;i++){
// 		if(n%i==0){
// 			ret.pb(i);
// 			ret.pb(n/i);
// 		}
// 		if(i*i==n)ret.pop_back();
// 	}
// 	// sort()
// 	return ret;
// }

ll fqrt(ll n){
	ll r=sqrt(n)-3;
	while(r<0||r*r<=n)r++;
	r--;
	return r;
}

vv solve(ll a, ll b, ll c){
	ll det=b*b-4*a*c;
	if(det<0)return {};
	ll r=fqrt(det);
	if(r*r!=det)return {};
	ll x1=-b+r;
	ll x2=-b-r;
	vv ret;
	if(x1%(2*a)==0)
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n);
		inp(a)
		map<ll,ll> mp;
		for(auto i:a)mp[i]++;
		ll q; cin>>q;
		while(q--){
			ll x,y; cin>>x>>y;
			vv ds=divs()
		}
	}
	return 0;
}
