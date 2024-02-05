#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=1e5+5,MAXM=2e5+5;

vector<ii> g[MAXN];
ll lw[MAXN],dis[MAXN],br[MAXM],vised[MAXM];

void dfs(ll x){
	lw[x]=dis[x];
	for(auto [y,ed]:g[x])if(!vised[ed]){
		vised[ed]=1;
		if(lw[y]==-1){
			dis[y]=dis[x]+1;
			dfs(y);
			lw[x]=min(lw[x],lw[y]);
			br[ed]=(lw[y]>=dis[y]);
		}
		else lw[x]=min(lw[x],dis[y]);
	}
}
void bridges(ll rt=0){
	mset(lw,-1); mset(br,0); mset(vised,0);
	dis[rt]=0;
	dfs(rt);
}

int main(){FIN;
	ll n,m; cin>>n>>m;
	vector<ii>ed;
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb({v,i});
		g[v].pb({u,i});
		ed.pb({u,v});
	}
	bridges();
	vector<ii>res;
	fore(i,0,m)if(br[i])res.pb(ed[i]);
	cout<<SZ(res)<<"\n";
	for(auto [u,v]:res)cout<<u+1<<" "<<v+1<<"\n";
	return 0;
}
