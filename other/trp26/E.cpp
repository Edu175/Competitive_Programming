#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXS=5e4+105;

int main(){FIN;
	ll q,n; cin>>q>>n;
	bitset<MAXS> dp; dp[0]=1;
	fore(i,0,n){
		ll x; cin>>x;
		fore(_,0,MAXS/x)dp|=dp<<x; // ya fue seguro se la banca
	}
	while(q--){
		ll s; cin>>s;
		assert(s>=1);
		ll p=dp._Find_next(s-1);
		cout<<p-s<<"\n";
	}
	return 0;
}
