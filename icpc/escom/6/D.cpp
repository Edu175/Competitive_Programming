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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		vector<vv> g(n);
		fore(i,0,m){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		vv vis(n);
		vector<ii> ed;
		auto dfs=[&](ll x, auto &&dfs)->void {
			vis[x]=1;
			for(auto y:g[x])if(!vis[y]){
				ed.pb({x,y});
				dfs(y,dfs);
			}
		};
		dfs(0,dfs);
		g=vector<vv>(n);
		for(auto [u,v]:ed){
			g[u].pb(v);
			g[v].pb(u);
		}
		ll r=1; while(r*r<n)r++;
		vv deg(n);
		fore(x,0,n)deg[x]=SZ(g[x]);
		queue<ll>q;
		vis=vv(n,0);
		vv sz(n,1);
		fore(x,0,n)if(deg[x]<=1){
			q.push(x);
		}
		// fore(x,0,n)cout<<x<<": "<<SZ(g[x])<<"\n";
		ll lst=-1;
		vv ans;
		while(SZ(q)){
			auto x=q.front(); q.pop();
			if(vis[x])continue;
			vis[x]=1;
			// cerr<<"bfs "<<x<<": "<<d[x]<<"\n";
			if(sz[x]>=r){
				ans.pb(x);
				sz[x]=0;
				// cerr<<"lo ponemos\n";
			}
			lst=x;
			ll fa=-1;
			for(auto y:g[x])if(!vis[y])fa=y;
			if(fa==-1)continue;
			if((--deg[fa])<=1)q.push(fa);
			sz[fa]+=sz[x];
		}
		if(!SZ(ans))ans.pb(lst);
		assert(SZ(ans)<=r);
		cout<<SZ(ans)<<"\n";
		for(auto i:ans)cout<<i+1<<" ";;cout<<"\n";
	}
	return 0;
}
