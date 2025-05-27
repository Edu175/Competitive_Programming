#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
ll get(ll l, ll r){ // first non-composite in [l,r)
	// in O(sqrt(r)+(r-l)log(r-l))
	vv vis(r-l);
	for(ll i=2;i*i<r;i++){
		ll s=(l+i-1)/i*i; if(s<=i)s=2*i;
		for(ll j=s;j<r;j+=i)vis[j-l]=1;
	}
	fore(i,0,r-l)if(!vis[i])return i+l;
	assert(0);
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		cout<<get(n+1,n+1000)<<"\n"; // largest gap ???
	}
	return 0;
}