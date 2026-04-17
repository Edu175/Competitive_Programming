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
		ll n; cin>>n;
		vv a(n);
		inp(a);
		fore(i,0,n)fore(j,0,n)if(i!=j)fore(k,0,n)if(i!=k&&j!=k){
			if(a[i]==a[j]+a[k]){
				cout<<i+1<<" "<<j+1<<" "<<k+1<<"\n";
				exit(0);
			}
		}
		cout<<"-1\n";
	}
	return 0;
}
