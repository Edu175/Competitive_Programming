#include <bits/stdc++.h>
#include <cassert>
#include <cfloat>
#include <algorithm>
#include <bitset>
#include <map>
#include <deque>
#include <algorithm>
#include <bitset>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <array>
#include <unordered_map>
#include <unordered_set>
#include <set>
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
		ll n; cin>>n; n--;
		vv a(n);
		inp(a)
		ll res=0;
		fore(i,0,n)res+=a[i]/2*2,a[i]%=2;
		ll q=0;
		ll mx=0;
		fore(i,0,n){
			q+=a[i];
			if(i==n-1||a[i]!=a[i+1]){
				mx=max(mx,q);
				q=0;
			}
		}
		cout<<res+mx<<"\n";
	}
	return 0;
}
