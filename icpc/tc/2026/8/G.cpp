#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(a) {for(auto x:a) cout<<x<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=3e5+5;

vv g[MAXN];

ll res=0;

ll dfs(ll x, ll fa){
	vv got;
	for(auto y:g[x])if(y!=fa)got.pb(dfs(y,x));
	got.pb(1); got.pb(1);
	sort(ALL(got)); reverse(ALL(got));
	ll deg=SZ(g[x]);
	ll cur=got[0]+got[1]-2+deg;
	res=max(res,cur);
	ll ret=got[0]-1+deg;
	// cerr<<x<<": ";
	// for(auto i:got)cerr<<i<<" ";
	// cerr<<": "<<cur<<": "<<ret<<"\n";
	return ret;
}

int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n)g[i].clear();
		fore(i,0,n-1){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		res=0;
		dfs(0,-1);
		cout<<res+1<<"\n";
	}
	return 0;
}


