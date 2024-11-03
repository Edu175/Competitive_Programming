#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet; i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define ET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> ii;
typedef vector <ll> vv;
const ll MAXN=90;

// prob of p0 wining
// h is p0
ld dp0[MAXN][MAXN];
ld dp1[MAXN][MAXN];

int main(){ET
	fore(c,0,74)dp0[75][c]=dp1[75][c]=1;
	fore(h,0,74)dp0[h][75]=dp1[h][75]=0;
	for(ll h=74;h>=0;h--)for(ll c=74;c>=0;c--){
		auto &f0=dp0[h][c];
		auto &f1=dp1[h][c];
		ld av0=0,av1=0,prob0=1,prob1=1;
		fore(hi,h+1,76){
			
		}
	}
	
	ll q; cin>>q;
	while(q--){
		
	}
}