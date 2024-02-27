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
const ll MAXN=2e5+5,MAXM=MAXN;

vector<ii> g[MAXN]; // {node,edge}
ll lw[MAXN],dis[MAXN],br[MAXM],vised[MAXM];
//ll cnt=0;
void dfs(ll x){
	lw[x]=dis[x];
	for(auto [y,ed]:g[x])if(!vised[ed]){
		//cnt+=(x==0);
		vised[ed]=1;
		if(lw[y]==-1){ //tree edge
			dis[y]=dis[x]+1;
			dfs(y);
			lw[x]=min(lw[x],lw[y]);
			//art[x]|=(lw[y]>=dis[x]);
			br[ed]=(lw[y]>=dis[y]);
		}
		else lw[x]=min(lw[x],dis[y]); //back edge
	}
}
ll n,m;
void dfs_tree(){
	//mset(lw,-1); mset(art,0); mset(br,0); mset(vised,0);
	fore(i,0,n)lw[i]=-1;
	fore(i,0,m)vised[i]=0;
	fore(i,0,n)if(lw[i]==-1){
		dis[i]=0;
		dfs(i);
	}
	//art[rt]=(cnt>1);
}
vector<ll>p;
ll vis[MAXN];
ll done=0,e=0,edg=0;
void dfs2(ll x){
	vis[x]=1;
	p.pb(x);
	if(x==e){done=1; return;}
	for(auto [y,i]:g[x])if(i!=edg){
		if(done)return;
		if(!vis[y])dfs2(y);
	}
	if(done)return;
	p.pop_back();
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n>>m;
		fore(i,0,n+3){
			g[i].clear();
			vis[i]=0;
		}
		vector<pair<ll,ii>>ed;
		fore(i,0,m){
			ll u,v,w; cin>>u>>v>>w; u--,v--;
			ed.pb({w,{u,v}});
		}
		sort(ALL(ed));
		fore(i,0,m){
			auto [w,e]=ed[i];
			auto [u,v]=e;
			g[u].pb({v,i});
			g[v].pb({u,i});
		}
		dfs_tree();
		ll res=0;
		fore(i,0,m){
			if(!br[i]){
				auto [w,asd]=ed[i];
				auto [u,v]=asd;
				res=w;
				p.clear();
				done=0;
				edg=i;
				e=v;
				dfs2(u);
				break;
			}
		}
		cout<<res<<" "<<SZ(p)<<"\n";
		for(auto i:p)cout<<i+1<<" ";;cout<<"\n";
	}
	return 0;
}

