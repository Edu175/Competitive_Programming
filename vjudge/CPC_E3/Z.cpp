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
<ii,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// find_by_order(i) -> iterator to ith element
// order_of_key(k) -> position (int) of lower_bound of k
//less_equal for repeated elements (erase only with pointer)
const ll MAXN=1e5+5;

vector<ll> g[MAXN];
ll a[MAXN],fa[MAXN],dp[MAXN];

ordered_set st;
ll get(){
	if(SZ(st)&1)return st.find_by_order(SZ(st)/2)->fst;
	else {
		assert(SZ(st));
		ll l=st.find_by_order(SZ(st)/2-1)->fst;
		ll r=st.find_by_order(SZ(st)/2)->fst;
		return (l+r)/2;
	}
}
void dfs(ll x, ll p){
	st.insert({a[x],x});
	if(p)dp[x]=1e10;
	else dp[x]=0;
	for(auto y:g[x])if(y!=fa[x]){
		fa[y]=x;
		dfs(y,p^1);
		if(p)dp[x]=min(dp[x],dp[y]);
		else dp[x]=max(dp[x],dp[y]);
	}
	if(x&&SZ(g[x])==1)dp[x]=get();
	st.erase({a[x],x});
}

int main(){FIN;
	ll n; cin>>n;
	fore(i,0,n)cin>>a[i];
	fore(i,0,n-1){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	fa[0]=-1;
	dfs(0,0);
	cout<<dp[0]<<"\n";
	return 0;
}
