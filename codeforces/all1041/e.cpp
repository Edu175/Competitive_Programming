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

struct node{
	set<ll> col;
	vv lib;
	ll sz(){return SZ(col)+SZ(lib);}
};
const ll MAXN=2e5+5;

vv g[MAXN];

ll c[MAXN],is[MAXN];

node dfs(ll x, ll fa){
	node ans;
	set<ll> tras;
	
	for(auto y:g[x])if(y!=fa){
		auto cur=dfs(y,x);
		if(ans.sz()<cur.sz())swap(ans,cur);
		for(auto i:cur.lib)ans.lib.pb(i);
		for(auto i:cur.col){
			if(ans.col.count(i))tras.insert(i);
			else ans.col.insert(i);
		}
	}
	if(SZ(tras)==1){
		ll put=*tras.begin();
		if(c[x]==-1)c[x]=put;
		is[x]=c[x]!=put;
	}
	else is[x]=SZ(tras)>1;
	
	if(c[x]!=-1){
		for(auto i:ans.lib)c[i]=c[x];
		ans.lib.clear();
		ans.col.insert(c[x]);
		// is[x]=SZ(tras)>=1&&(SZ(tras)>1||c[x]!=*tras.begin());
	}
	else {
		ans.lib.pb(x);
	}
	return ans;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		fore(i,0,n){
			is[i]=0;
			g[i].clear();
		}
		vv we(n);
		fore(i,0,n)cin>>we[i];
		fore(i,0,n)cin>>c[i],c[i]--;
		fore(i,0,n-1){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		auto ans=dfs(0,-1);
		for(auto i:ans.lib)c[i]=0;
		ll res=0;
		fore(i,0,n)res+=is[i]*we[i];
		// fore(i,0,n){
		// 	cerr<<i<<": "<<is[i]<<"\n";
		// }
		cout<<res<<"\n";
		fore(i,0,n)cout<<c[i]+1<<" ";;cout<<"\n";
	}
	return 0;
}
