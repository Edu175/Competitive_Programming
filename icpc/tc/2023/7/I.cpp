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

int main(){FIN;
	ll n; cin>>n;
	vector<vv> g(n);
	fore(i,0,n-1){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	vv col(n,-1);
	vv cant(2);
	auto dfs=[&](ll x, auto &&dfs)->void {
		cant[col[x]]++;
		for(auto y:g[x])if(col[y]==-1){
			col[y]=col[x]^1;
			dfs(y,dfs);
		}
	};
	col[0]=0;
	dfs(0,dfs);
	ll res=min(cant[0],cant[1])-1;
	cout<<res<<"\n";
	return 0;
}
