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
	vv deg(n);
	fore(i,0,n-1){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
		deg[u]++;
		deg[v]++;
	}
	vv vis(n);
	ll mis=0;
	auto f=[&](ll x, ll bl, auto &&f)->void {
		if(!vis[x]&&(deg[x]<=1||bl)){
			vis[x]=1;
			ll hoj=!bl;
			mis+=hoj;
			for(auto y:g[x])if(!vis[y]){
				deg[y]--;
				f(y,hoj,f);
			}
		}
	};
	fore(i,0,n)f(i,0,f);
	ll mvc=n-mis;
	cout<<mvc-1<<"\n";
	return 0;
}
