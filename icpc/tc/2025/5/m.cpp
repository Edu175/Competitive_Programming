#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){
	JET
	ll n; cin>>n;
	ll a[n]; fore(i,0,n) cin>>a[i];
	sort(a,a+n);
	ll q; cin>>q;
	while(q--){
		ll m; cin>>m;
		cout<<upper_bound(a,a+n,m)-a<<"\n";
	}
	return 0;
}