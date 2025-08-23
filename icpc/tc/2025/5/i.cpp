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
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;



int main(){
	JET
	ll n; cin>>n;
	ll a[n];
	ordered_set os;
	map<ll,vv> mp;
	fore(i,0,n){
		ll x; cin>>x;
		a[i] = x;
		os.insert(i+1);
		mp[x].pb(i+1);
	}
	
	ll r = 0;
	fore(i,0,n){
		os.erase(i+1);
		// cout<<"os\n";
		// for(auto x:os) cout<<x<<" ";
		// cout<<"\n";
		r+=os.order_of_key(a[i]+1);
		for(auto x:mp[i+1]) os.erase(x);
		// cout<<"r es "<<r<<"\n";
	}
	cout<<r<<"\n";
	return 0;
}