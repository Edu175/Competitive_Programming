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

ll solve(ll n, vector<vector<ii>> g, vv vis){ // 2 is bad, 1 is in process, g is arista padre, no self loops
	assert(SZ(g)==n&&SZ(vis)==n);
	fore(x,0,n)if(!vis[x])sort(ALL(g[x]),[&](ii a, ii b){return a.snd>b.snd;});
	vv wf(n,-1);
	ll res=0;
	fore(s,0,n)if(!vis[s]){
		ll x=s;
		vv nod;
		while(!vis[x]){
			nod.pb(x); vis[x]=1;
			if(!SZ(g[x])){vis[x]=2;break;}
			auto [y,w]=g[x].back();
			wf[x]=w; res+=w;
			x=y;
		}
		if(vis[x]==1){ // cycle, vis[y]=-1
			vv cyc;
			for(ll y=x;vis[y]==1;y=g[y].back().fst)vis[y]-=2,cyc.pb(y);
			vector<vector<ii>> ng(n+1);
			fore(_x,0,n)for(auto [y,w]:g[_x]){
				x=_x;
				if(vis[x]==-1)w-=wf[x],x=n;
				if(vis[y]==-1)y=n;
				if(x!=y)ng[x].pb({y,w});
			}
			for(auto i:nod)if(vis[i]==1){
				res-=wf[i];
				vis[i]=0;
			}
			for(auto i:cyc)vis[i]=2;
			vis.pb(0);
			return res+solve(n+1,ng,vis);
		}
		for(auto i:nod)vis[i]=2;
	}
	assert(vis==vv(SZ(vis),2));
	return res;
}

// deja solo aristas utiles (reacheables desde 0), y checkea possible de paso

const ll MAXN=1005;
vector<vector<ii>> rev,g;
ll vis[MAXN];

void dfs(ll x){
	vis[x]=1;
	for(auto [y,w]:g[x]){
		if(!vis[y])dfs(y);
		rev[y].pb({x,w});
	}
}

int main(){FIN;
	ll t; cin>>t;
	fore(_,0,t){
		cout<<"Case #"<<_+1<<": ";
		ll n,m; cin>>n>>m;
		g.clear(); rev.clear();
		g.resize(n); rev.resize(n);
		fore(i,0,n)vis[i]=0;
		fore(i,0,m){
			ll u,v,w; cin>>u>>v>>w;
			if(u!=v&&v)g[u].pb({v,w});
		}
		dfs(0);
		if(count(vis,vis+n,1)!=n){
			cout<<"Possums!\n";
			continue;
		}
		ll res=solve(n,rev,vv(n));
		cout<<res<<"\n";
	}
	return 0;
}