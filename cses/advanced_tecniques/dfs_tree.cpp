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
ll lw[MAXN],dis[MAXN],art[MAXN],br[MAXM],vised[MAXM];
ll cnt=0;
void dfs(ll x){
	lw[x]=dis[x];
	for(auto [y,ed]:g[x])if(!vised[ed]){
		cnt+=(x==0);
		vised[ed]=1;
		if(lw[y]==-1){
			dis[y]=dis[x]+1;
			dfs(y);
			lw[x]=min(lw[x],lw[y]);
			art[x]|=(lw[y]>=dis[x]);
			br[ed]=(lw[y]>=dis[y]);
		}
		else lw[x]=min(lw[x],dis[y]);
	}
}
void dfs_tree(ll rt=0){
	mset(lw,-1); mset(art,0); mset(br,0); mset(vised,0);
	dis[rt]=0; cnt=0;
	dfs(rt);
	art[rt]=(cnt>1);
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
	dfs_tree();
	vector<ll>res;
	fore(i,0,n)if(art[i])res.pb(i+1);
	cout<<SZ(res)<<"\n";
	imp(res);
	return 0;
}
