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

vector<ii>ret;
void dfs(ll x, ll c, ll fa){
	for(auto y:g[x])if(y!=fa){
		if(!c)ret.pb({x,y});
		else ret.pb({y,x});
		dfs(y,c^1,x);
	}
}


int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n)g[i].clear();
		ret.clear();
		fore(i,0,n-1){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		ll x=-1;
		fore(i,0,n)if(SZ(g[i])==2)x=i;
		if(x==-1){
			cout<<"NO\n";
			continue;
		}
		ll y=g[x][0];
		ret.pb({x,y});
		dfs(y,1,x);
		dfs(x,1,y);
		cout<<"YES\n";
		for(auto [u,v]:ret)cout<<u+1<<" "<<v+1<<"\n";
	}
	return 0;
}
