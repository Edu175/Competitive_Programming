// #include <bits/stdc++.h>
#include <cassert>
#include <cfloat>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <bitset>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <array>
#include <unordered_map>
#include <unordered_set>
#include <numeric>

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
	// freopen("","r",stdin);
	// freopen("","w",stdout);
	ll t=1;
	// cin>>t;
	while(t--){
		ll k; cin>>k;
		ll n=1<<(k+1);
		vv a(n);
		cerr<<"n "<<n<<"\n";
		fore(i,2,n){
			cerr<<"hola\n";
			cin>>a[i];
		}
		vv dp(n);
		for(ll i=n-1;i>0;i--){
			if(2*i+1>=n)continue;
			ll x=dp[2*i]+a[2*i];
			ll y=dp[2*i+1]+a[2*i+1];
			
			dp[i]=max()
		}
		map<ll,ll> mp;
		fore(i,1,n){
			ll p=__lg(i);
			mp[p]=max(mp[p],a[i]);
		}
		ll res=0;
		fore(i,1,n){
			ll p=__lg(i);
			res+=mp[p]-a[i];
		}
		cout<<res<<"\n";
	}
	return 0;
}
