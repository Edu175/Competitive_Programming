#include "wiring.h"
#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ioi=b;i<ioi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto dfhg:v)cout<<dfhg<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

long long min_total_length(vector<int> a, vector<int> b){
	ll res=0,n=SZ(a),m=SZ(b);
	fore(i,0,n)res+=a[n-1]-a[i];
	fore(i,0,m)res+=b[i]-b[0];
	res+=max(n,m)*(b[0]-a[n-1]);
	return res;
}
