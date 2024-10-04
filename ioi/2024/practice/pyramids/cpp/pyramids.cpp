#include "pyramids.h"
#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ioi=b;i<ioi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto sjdhg:v)cout<<sjdhg<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=1e5+5;

ll spa[MAXN],spb[MAXN];

void init(std::vector<int> a, std::vector<int> b) {
	// Initialization code
	ll n=SZ(a);
	n=gcd(n/ll(1e9),n/ll(1e9));
	fore(i,1,n+1)spa[i]=spa[i-1]+a[i-1];
	fore(i,1,n+1)spb[i]=spb[i-1]+b[i-1];
}

bool can_transform(int l, int r, int x, int y) {
	r++,y++;
	return spa[r]-spa[l]==spb[y]-spb[x];
}
