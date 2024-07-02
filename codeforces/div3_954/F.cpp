#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=1e5+5,MAXM=MAXN;
ll n;
ll calc(ll c){
	return c*(c-1)/2+(n-c)*(n-c-1)/2;
}
vector<ii> g[MAXN];
ll lw[MAXN],dis[MAXN],art[MAXN],br[MAXN],vised[MAXM],c[MAXN];
ll cnt_=0;
void dfs_(ll x){
	lw[x]=dis[x];
	c[x]=1;
	for(auto [y,ed]:g[x])if(!vised[ed]){
		cnt_+=(x==0);
		vised[ed]=1;
		if(lw[y]==-1){ //tree edge
			dis[y]=dis[x]+1;
			dfs_(y);
			c[x]+=c[y];
			lw[x]=min(lw[x],lw[y]);
			art[x]|=(lw[y]>=dis[x]);
			br[y]=(lw[y]>=dis[y]);
		}
		else lw[x]=min(lw[x],dis[y]); //back edge
	}
}
void dfs_init(ll n=0, ll m=0){
	// mset(lw,-1); mset(art,0); mset(vised,0);
	fore(i,0,n)lw[i]=-1,art[i]=0;
	fore(i,0,m)vised[i]=0;
}
void dfs_tree(ll rt=0){
	if(lw[rt]!=-1)return;
	dis[rt]=0; cnt_=0;
	dfs_(rt);
	art[rt]=(cnt_>1);
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll m; cin>>n>>m;
		fore(i,0,n){
			g[i].clear();
			
		}
		fore(i,0,m){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb({v,i});
			g[v].pb({u,i});
		}
		dfs_init(n,m);
		dfs_tree();
		ll res=calc(n);
		fore(x,0,n)if(br[x]){
			// cout<<x<<": "<<c[x]<<" "<<calc(c[x])<<"\n";
			res=min(res,calc(c[x]));
		}
		cout<<res<<"\n";
	}
	return 0;
}
