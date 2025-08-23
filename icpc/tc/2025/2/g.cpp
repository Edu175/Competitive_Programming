#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define pb push_back
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

int main(){
	JET
	ll n; cin>>n;
	vv a(n);
	fore(i,0,n) cin>>a[i];
	ll r =0 ;
	ll ant = 1e18;
	for(ll i=n-1;i>=0;i--){
		ll local = min(ant-1,a[i]);
		local = max(local,0ll);
		r+=local;
		ant = local;
		// cout<<r<<" debubfsa\n"	;
	}
	cout<<r<<"\n";
	return 0;
}