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
const ll MAXN=1e5+5;
vv divs[MAXN];

int main(){FIN;
	fore(d,1,MAXN){
		for(ll i=d;i<MAXN;i+=d)divs[i].pb(d);
	}
	ll n; cin>>n;
	vv cant(MAXN);
	vv a(n); inp(a);
	fore(i,0,n)for(auto d:divs[a[i]])cant[d]++;
	// fore(i,0,10)cout<<cant[i]<<" ";;cout<<"\n";
	auto mx=max_element(cant.begin()+2,cant.end());
	// cout<<mx-cant.begin()<<" mx\n";
	ll res=max(1ll,*mx);
	cout<<res<<'\n';
	return 0;
}
