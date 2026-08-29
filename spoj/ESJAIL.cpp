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
#define dbg(x) cerr<<#x<<": ";show(x)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){FIN;
	while(1){
		ll n,k,m; cin>>n>>k>>m;
		if(n==-1)break;
		vector<vv> g(n);
		vv key(n,-1),dor(n,-1),wh(k);
		fore(i,0,k){
			ll a,b; cin>>a>>b; a--,b--;
			key[a]=i,dor[b]=i; wh[i]=b;
		}
		fore(i,0,m){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		vv vis(n);
		queue<ll> q;
		auto visit=[&](ll x){
			// cerr<<"visit "<<x<<"\n";
			assert(!vis[x]);
			vis[x]=1;
			q.push(x);
		};
		visit(0);
		set<ll> ks,ds;
		while(SZ(q)){
			auto x=q.front(); q.pop();
			// cerr<<"bfs "<<x<<"\n";
			// dbg(ks)
			// dbg(ds)
			ll id=key[x];
			if(id!=-1){
				if(!ds.count(id))ks.insert(id);
				else {
					visit(wh[id]);
					ds.erase(id); // unnecessary
				}
			}
			for(auto y:g[x])if(!vis[y]){
				// cerr<<"veo "<<y<<"\n";
				ll id=dor[y];
				if(id==-1){
					visit(y);
					continue;
				}
				if(ds.count(id))continue;
				if(ks.count(id)){
					ks.erase(id);
					visit(y);
				}
				else ds.insert(id);
			}
		}
		if(vis[n-1])cout<<"Y\n";
		else cout<<"N\n";
	}
	return 0;
}