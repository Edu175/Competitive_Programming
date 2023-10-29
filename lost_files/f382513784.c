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

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// find_by_order(i) -> iterator to ith element
// order_of_key(k) -> position (int) of lower_bound of k

int main(){FIN;
	ll n,m; cin>>n>>m;
	ll a[n][m];
	ordered_set st;
	fore(i,0,n)fore(j,0,m){
		cin>>a[i][j];
		st.insert(a[i][j]);
	}
	ll res=0;
	fore(i,0,n){
		fore(j,0,m)st.erase(a[i][j]);
		fore(j,0,m){
			res+=st.order_of_key(a[i][j])+(n-1-i)*(j+1);
			//cout<<i<<" "<<j<<": "<<st.order_of_key(a[i][j])<<" + "<<(n-1-i)<<"*"<<j+1<<"\n";
		}
	}
	cout<<res<<"\n";
	return 0;
}
