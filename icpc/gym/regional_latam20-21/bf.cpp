#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet; i++)
#define pb push_back
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ll(x.size())
#define ET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define impr(v) {cout<<#v<<": ";for(auto [i,j]:v)cout<<i<<","<<j<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll INF=1e9+5;
int main(){
	ET
	ll n,q; cin>>n>>q;
	vv a(n);
	fore(i,0,n)cin>>a[i];
	auto can=[&](ll l, ll r)->bool{
		if(r-l<3)return 0;
		fore(k,l+1,r-1){
			ll flag=1;
			fore(i,0,k)flag&=a[i]<=a[i+1];
			fore(i,k,r-1)flag&=a[i]>=a[i+1];
			if(flag)return 1;
		}
		return 0;
		// if(a[l]!=-1&&a[l+1]!=-1&&a[l+1]<a[l])return 0;
		// if(a[r-1]!=-1&&a[r-2]!=-1&&a[r-2]<a[r-1])return 0;
		// ll did=0;
		// fore(i,l+1,r){
		// 	did|=a[i]<a[i-1];
		// 	if(did&&a[i]>a[i-1])return 0;
		// }
		// return 1;
	};
	while(q--){
		ll l,r; cin>>l>>r;
		cout<<can(l,r)<<"\n";
	}
}