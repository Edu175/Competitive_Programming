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
const ll MAXN=105,MAXM=1005;
vector<ii> g[MAXN]; // {node,edge}
int lw[MAXN],D[MAXN];
bool br[MAXM],vised[MAXM];
ll good[MAXN]; // si se queda
vv nod;
vv t[MAXN];
void dfs_(ll x){
	lw[x]=D[x];
	nod.pb(x);
	for(auto [y,i]:g[x])if(!vised[i]){
		vised[i]=1;
		if(lw[y]==-1){ // tree edge
			D[y]=D[x]+1;
			dfs_(y);
			lw[x]=min(lw[x],lw[y]);
			br[i]=(lw[y]>=D[y]);
			t[x].pb(y);
			t[y].pb(x);
		}
		else lw[x]=min(lw[x],D[y]),br[i]=0; // back edge
		if(!br[i])good[y]=good[x]=0;
	}
}

ii doit(int n){ // nod
	vv deg(n);
	queue<ll> q;
	for(auto x:nod){
		deg[x]=SZ(t[x]);
		if(deg[x]<=1)q.push(x);
	}
	vv vis(n);
	ll cant=0;
	while(SZ(q)){
		ll x=q.front(); q.pop();
		if(vis[x])continue;
		vis[x]=1;
		if(good[x]){cant++;continue;}
		for(auto y:t[x])if(--deg[y]<=1)q.push(y);
	}
	return {cant,SZ(nod)};
}

vector<ii> dfs_tree(int n){
	mset(lw,-1), mset(vised,0);
	fore(i,0,n)good[i]=1;
	vector<ii> ret;
	fore(i,0,n)if(lw[i]==-1){
		D[i]=0,dfs_(i);
		ret.pb(doit(n));
		nod.clear();
	}
	return ret;
}

int main(){FIN;
	while(1){
		ll n,m; cin>>n>>m;
		if(n==-1)break;
		fore(i,0,n)g[i].clear(),t[i].clear();
		fore(i,0,m){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb({v,i});
			g[v].pb({u,i});
		}
		auto a=dfs_tree(n);
		sort(ALL(a));
		// cerr<<"a: ";for(auto i:a)cerr<<i.fst<<","<<i.snd<<" ";;cerr<<"\n";
		ll res=0;
		for(auto [h,sz]:a)res+=h+(h==1);
		res=(res+1)/2;
		sort(ALL(a));
		ll fg=0;
		if(SZ(a)<=2){
			if(SZ(a)==1)fg|=a[0].snd<=2;
			else fg|=a[0].snd==1&&a[1].snd==1;
		}
		res+=fg;
		cout<<res<<"\n";
	}
	return 0;
}