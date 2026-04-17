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
const ll MAXN=1e5+5,MAXM=2e5+5;

ll vised[MAXM];
ll vis[MAXN],lw[MAXN],D[MAXN];

vector<ii> g[MAXN];

vector<ii> ret;
bool hay=0;

void dfs(ll x){
	vis[x]=1;
	lw[x]=D[x];
	for(auto [y,i]:g[x])if(!vised[i]){
		vised[i]=1;
		ret.pb({x,y});
		if(!vis[y]){
			D[y]=D[x]+1;
			dfs(y);
			if(lw[y]>=D[y])hay=1; // bridge
			lw[x]=min(lw[x],lw[y]);
		}
		else lw[x]=min(lw[x],D[y]);
	}
}

int main(){FIN;
	ll n,m; cin>>n>>m;
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb({v,i});
		g[v].pb({u,i});
	}
	D[0]=0;
	dfs(0);
	fore(i,0,n)hay|=!vis[i];
	if(hay){
		cout<<"IMPOSSIBLE\n";
		return 0;
	}
	for(auto [x,y]:ret){
		cout<<x+1<<" "<<y+1<<"\n";
	}
	return 0;
}