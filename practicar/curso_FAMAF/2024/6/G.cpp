#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree
<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
indexed_set;
// find_by_order(i) -> iterator to ith element
// order_of_key(k) -> position (int) of lower_bound of k
//less_equal for repeated elements (erase only with pointer)


int main(){FIN;
	ll n; cin>>n;
	string s; cin>>s;
	vector<queue<ll>>pos(30);
	fore(i,0,n){
		pos[s[i]-'a'].push(i);
	}
	reverse(ALL(s));
	indexed_set st;
	fore(i,0,n)st.insert(i);
	ll res=0;
	fore(i,0,n){
		auto v=s[i];
		auto p=pos[v-'a'].front(); pos[v-'a'].pop();
		res+=st.order_of_key(p);
		st.erase(p);
	}
	cout<<res<<"\n";
	return 0;
}