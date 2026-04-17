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
#include <set>

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
#define pres cout<<res<<"\n";
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll x,y; cin>>x>>y;
		ll c=0;
		while(x%2==y%2)c++,x/=2,y/=2;
		cout<<(1ll<<c)<<"\n";
	}
	return 0;
}
