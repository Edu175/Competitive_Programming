#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh.fst<<","<<gdljh.snd<<" "; cout<<endl;}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
vector<ll> eulerWalk(vector<vector<ii>>& gr, ll nedges, ll src=0) {
	ll n = SZ(gr);
	vector<ll> D(n), its(n), eu(nedges), ret, s = {src};
	// D[src]++; // to allow Euler paths, not just cycles
	while (!s.empty()) {
		ll x = s.back(), y, e, &it = its[x], end = SZ(gr[x]);
		if (it == end){ ret.pb(x); s.pop_back(); continue; }
		tie(y, e) = gr[x][it++];
		if (!eu[e]) {
			D[x]--, D[y]++;
			eu[e] = 1; s.pb(y);
		}}
	for (ll x : D) if (x < 0 || SZ(ret) != nedges+1) return {};
	return {ret.rbegin(), ret.rend()};
}
const ll MAXN=5e5+5,MAXM=MAXN;

vector<ii> g[MAXN];
vector<ii> t[MAXN];
ll vis[MAXN];
void dfs(ll x){
	vis[x]=1;
	for(auto [y,i]:g[x])if(!vis[y]){
		t[x].pb({y,i});
		dfs(y);
	}
}
ll es[MAXM],deg[MAXN];
ll c=0;
void dfs2(ll x){
	vis[x]=1;
	c^=deg[x];
	for(auto [y,i]:t[x]){
		es[i]^=c;
		dfs2(y);
		es[i]^=c;
	}
}
int main(){FIN;
	ll ___; cin>>___;
	while(___--){
		ll n,m; cin>>n>>m;
		
		fore(i,0,n){
			g[i].clear();
			t[i].clear();
			vis[i]=deg[i]=0;
		}
		fore(i,0,m){
			es[i]=0;
		}
		c=0;
		
		
		vector<vector<ii>>eul(n);
		vector<ii>ed;
		fore(i,0,m){
			ll u,v,w; cin>>u>>v>>w; u--,v--;
			if(u>v)swap(u,v);
			ed.pb({u,v});
			if(w){
				deg[u]^=1;
				deg[v]^=1;
				es[i]=1;
				continue;
			}
			g[u].pb({v,i});
			g[v].pb({u,i});
		}
		fore(i,0,n)if(!vis[i])dfs(i);
		fore(i,0,n)vis[i]=0;
		fore(i,0,n)if(!vis[i])dfs2(i);
		ll id=0;
		fore(i,0,m)if(es[i]){
			auto [u,v]=ed[i];
			eul[u].pb({v,id});
			eul[v].pb({u,id});
			id++;
		}
		/*fore(i,0,n){
			cout<<i<<": ";
			imp(eul[i]);
		}*/
		auto r=eulerWalk(eul,id);
		if(!SZ(r))cout<<"NO\n";
		else {
			cout<<"YES\n"<<SZ(r)-1<<"\n";
			for(auto i:r)cout<<i+1<<" ";
			cout<<"\n";
		}
		
	}
	return 0;
}
