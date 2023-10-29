#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

/*#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ii,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// find_by_order(i) -> iterator to ith element
// order_of_key(k) -> position (int) of lower_bound of k*/

int main(){FIN;
	ll n,k,q; cin>>n>>k>>q;
	vector<ll>a(n);
	if(k==n){
		ll sum=0;
		while(q--){
			ll p,v; cin>>p>>v; p--;
			sum+=-a[p]+v;
			a[p]=v;
			cout<<sum<<"\n";
		}
		return 0;
	}
	ll sum=0;
	set<ii> st;
	fore(i,0,n)st.insert({a[i],i});
	ll l=n-k;
	while(q--){
		ll p,v; cin>>p>>v; p--;
		if(ii({a[p],p})>=ii({a[l],l})){
			sum-=a[p];
			l=(*prev(st.lower_bound({a[l],l}))).snd;
			sum+=a[l];
		}
		a[p]=v;
		st.insert({a[p],p});
		if(ii({a[p],p})>=ii({a[l],l})){
			sum-=a[l];
			l=(*next(st.lower_bound({a[l],l}))).snd;
			sum+=a[p];
		}
		cout<<sum<<"\n";
	}
	return 0;
}
