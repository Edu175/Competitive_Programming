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
const ll MAXN=2e5+5;

vv g[MAXN];

ll h[MAXN];
ll res=0;
ll dfs(ll x, ll fa){
	vv got={0};
	for(auto y:g[x])if(y!=fa)got.pb(dfs(y,x));
	sort(ALL(got));
	reverse(ALL(got));
	auto &a=got[0];
	if(a<h[x])res+=h[x]-a,a=h[x];
	if(fa==-1){
		assert(SZ(got)>=2);
		auto &b=got[1];
		res+=max(0ll,h[x]-b);
	}
	return a;
}

int main(){FIN;
	ll t=1;
	// cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n){
			g[i].clear();
		}
		fore(i,0,n)cin>>h[i];
		fore(i,0,n-1){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		ll rt=max_element(h,h+n)-h;
		res=0;
		dfs(rt,-1);
		cout<<res<<"\n";
	}
	return 0;
}
