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

bool sacIf(multiset<ll> &st, ll x){ // true iff it was erased
	auto it=st.find(x);
	if(it!=st.end()){
		st.erase(it);
		return 1;
	}
	return 0;
}
struct node{
	multiset<ll> a,b;
	ll wa=0,wb=0;
	ll sz(){
		return SZ(a)+SZ(b);
	}
	void merge(node &rhs){
		wa+=rhs.wa;
		wb+=rhs.wb;
		for(auto i:rhs.a)if(!sacIf(b,i))a.insert(i);
		for(auto i:rhs.b)if(!sacIf(a,i))b.insert(i);
		rhs.a.clear();
		rhs.b.clear();
	}
	bool good(){
		return wa>=SZ(b)&&wb>=SZ(a);
	}
};
const ll MAXN=2e5+5;
vv g[MAXN];
ll a[MAXN],b[MAXN];
ll res[MAXN];
node dfs(ll x, ll fa){
	node ans;
	if(!a[x])ans.wa++;
	else ans.a.insert(a[x]);
	if(!b[x])ans.wb++;
	else {
		ll elem=b[x];
		if(!sacIf(ans.a,elem))ans.b.insert(elem);
	}
	for(auto y:g[x])if(y!=fa){
		auto cur=dfs(y,x);
		if(ans.sz()<cur.sz())swap(ans,cur);
		ans.merge(cur);
	}
	// cout<<x<<": "<<SZ(ans.a)<<","<<SZ(ans.b)<<" "<<ans.wa<<" "<<ans.wb<<"\n";
	res[x]=ans.good();
	return ans;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n){
			g[i].clear();
		}
		fore(i,0,n)cin>>a[i];
		fore(i,0,n)cin>>b[i];
		fore(i,0,n-1){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		dfs(0,-1);
		fore(i,0,n)cout<<res[i];;cout<<"\n";
	}
	return 0;
}
