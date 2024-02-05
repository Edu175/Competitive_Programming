#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree
<ii,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update>
ordered_set;
// find_by_order(i) -> iterator to ith element
// order_of_key(k) -> position (int) of lower_bound of k
//less_equal for repeated elements (erase only with pointer)

int main(){FIN;
	ll n; cin>>n;
	vector<ii>a(n);
	map<ll,vector<ll>>ev;
	fore(i,0,n){
		cin>>a[i].fst>>a[i].snd;
		ev[a[i].fst].pb(i);
	}
	//sort(ALL(ev));
	ordered_set st;
	ll res[2][n];
	vector<ll>ord;
	for(auto [v,b]:ev){
		ord.pb(v);
		for(auto i:b)st.insert({a[i].snd,i});
		for(auto i:b){
			ii p={a[i].snd,-1};
			res[1][i]=SZ(st)-st.order_of_key(p)-1;
		}
	}
	st.clear();
	reverse(ALL(ord));
	for(auto v:ord){
		for(auto i:ev[v])st.insert({a[i].snd,i});
		for(auto i:ev[v]){
			ii p={a[i].snd,1e10};
			res[0][i]=st.order_of_key(p)-1;
		}
	}
	fore(h,0,2){
		for(auto i:res[h])cout<<i<<" ";
		cout<<"\n";
	}
	return 0;
}
