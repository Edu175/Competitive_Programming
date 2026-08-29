#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=1e5+5;

map<ll,ll> mp;
vv g[MAXN];
ll ans[MAXN],a[MAXN];
ll cant=0;
void dfs(ll x, ll fa){
	cant+=!(mp[a[x]]++);
	ans[x]=cant;
	for(auto y:g[x])if(y!=fa)dfs(y,x);
	cant-=!(--mp[a[x]]);
}

int main(){FIN;
	ll n,q; cin>>n>>q;
	fore(i,0,n)cin>>a[i];
	fore(i,0,n-1){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(0,-1);
	while(q--){
		ll x; cin>>x; x--;
		cout<<ans[x]<<"\n";
	}
	return 0;
}
