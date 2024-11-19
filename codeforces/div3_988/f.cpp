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
typedef tree
<ii,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update>
indexed_set;
// find_by_order(i) -> iterator to ith element
// order_of_key(k) -> position (int) of lower_bound of k
//less_equal for repeated elements (erase only with pointer)

const ll MAXN=1e5+5;
ll n,m,k;
ll h[MAXN],x[MAXN];

bool can(ll c, ll fg=0){
	vv cant(n);
	indexed_set st;
	fore(i,0,n){
		ll q=SZ(st)-st.order_of_key({c*x[i],-1});
		cant[i]+=q;
		st.insert({c*m+c*x[i]-h[i],SZ(st)});
	}
	st.clear();
	if(fg){
		fore(i,0,n)cout<<h[i]<<" ";;cout<<"\n";
		fore(i,0,n)cout<<x[i]<<" ";;cout<<"\n";
		
	}
	for(ll i=n-1;i>=0;i--){
		if(fg){
			cout<<i<<" st: ";
			for(auto [i,dfg]:st)cout<<i<<","<<dfg<<" ";
			cout<<"\n";
			cout<<"find "<<c*x[i]<<","<<SZ(st)+5<<"\n";
		}
		ll q=st.order_of_key({c*x[i],SZ(st)+5});
		cant[i]+=q;
		st.insert({-c*m+c*x[i]+h[i],SZ(st)});
	}
	fore(i,0,n)cant[i]+=c*m>=h[i];
	if(fg){
		cout<<"can "<<c<<": ";
		imp(cant);
	}
	fore(i,0,n){
		if(cant[i]>=k)return 1;
	}
	return 0;
}
const ll INF=1e9+10;
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n>>m>>k;
		fore(i,0,n)cin>>h[i];
		fore(i,0,n)cin>>x[i];
		ll l=1,r=INF;
		while(l<=r){
			ll mid=(l+r)/2;
			if(can(mid))r=mid-1;
			else l=mid+1;
		}
		can(1e9,1);
		if(l>=INF)l=-1;
		cout<<l<<"\n";
	}
	return 0;
}
