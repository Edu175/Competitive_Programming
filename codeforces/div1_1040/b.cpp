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
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<typename T>
using indexed_set = tree
<T,null_type,less<T>,rb_tree_tag,
tree_order_statistics_node_update>;
// find_by_order(i) -> iterator to ith element
// order_of_key(k) -> position (int) of lower_bound of k
//less_equal for repeated elements (erase only with pointer)

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n),p(n);
		indexed_set<ll> st;
		fore(i,0,n){
			cin>>a[i]; a[i]--;
			p[a[i]]=i;
			st.insert(i);
		}
		ll res=0;
		fore(x,0,n){
			ll i=p[x];
			ll cl=st.order_of_key(i);
			ll cr=SZ(st)-1-cl;
			st.erase(i);
			res+=min(cl,cr);
		}
		cout<<res<<"\n";
	}
	return 0;
}
