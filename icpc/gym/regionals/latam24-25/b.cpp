#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet;i++)
#define pb push_back
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=3e5+5;

vector<ii> g[MAXN];
ll vis[MAXN],D[MAXN],vised[MAXN];
ii fa[MAXN];
ll u,v,idx=-1;

void dfs(ll x){
	vis[x]=1;
	for(auto [y,i]:g[x])if(!vised[i]){
		vised[i]=1;
		if(!vis[y]){ // tree edge
			fa[y]={x,i};
			D[y]=D[x]+1;
			dfs(y);
		}
		else { // back edge
			if(idx==-1||D[y]>D[v])idx=i,u=x,v=y;
		}
	}
}

int main(){
	JET
	ll n,m; cin>>n>>m;
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb({v,i});
		g[v].pb({u,i});
	}
	fa[0]={-1,-1};
	dfs(0);
	vv ans={idx};
	for(ll x=u;x!=v;x=fa[x].fst)ans.pb(fa[x].snd);
	cout<<SZ(ans)<<"\n";
	for(auto i:ans)cout<<i+1<<" ";;cout<<"\n";
	return 0;
}