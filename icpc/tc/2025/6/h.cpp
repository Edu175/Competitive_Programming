#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=1e6+5;

vv g[MAXN];

// vv nod;
ll col[MAXN];
ll vis[MAXN];
ll qidx=0;
void dfs(ll x){
	col[x]=qidx;
	vis[x]=1;
	// nod.pb(x);
	for(auto y:g[x])if(!vis[y])dfs(y);
}

int main(){
	JET
	ll n,m; cin>>n>>m;
	vv a(n);
	fore(i,0,n)cin>>a[i];
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	vector<vv> h(n);
	fore(i,0,n)if(!vis[i]){
		dfs(i);
		qidx++;
	}
	fore(i,0,n)h[col[i]].pb(a[i]);
	fore(i,0,n)sort(ALL(h[i]));
	vv res(n);
	fore(i,0,n)res[i]=h[col[i]].back(),h[col[i]].pop_back();
	for(auto i:res)cout<<i<<" ";;cout<<"\n";
	return 0;
}