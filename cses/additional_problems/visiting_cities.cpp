#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi.fst<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=1e5+5,MAXM=2e5+5;

vector<ii>g[MAXN],t[MAXN];
ll n;
vector<ll> distra(ll s, ll bol){
	priority_queue<ii>q;
	vector<ll>d(n,-1);
	q.push({0,s});
	d[s]=0;
	while(SZ(q)){
		auto [di,x]=q.top(); q.pop(); di=-di;
		if(di>d[x])continue;
		for(auto [y,w]:(bol?t[x]:g[x]))if(d[y]==-1||d[x]+w<d[y]){
			d[y]=d[x]+w;
			q.push({-d[y],y});
		}
	}
	return d;
}
vector<ll> d[2];
ll lw[MAXN],dis[MAXN],art[MAXN],br[MAXM],vised[MAXM];
ll cnt_=0;
void dfs_(ll x){
	lw[x]=dis[x];
	for(auto [y,ed]:g[x])if(!vised[ed]){
		cnt_+=(x==0);
		vised[ed]=1;
		if(lw[y]==-1){ //tree edge
			dis[y]=dis[x]+1;
			dfs_(y);
			lw[x]=min(lw[x],lw[y]);
			art[x]|=(lw[y]>=dis[x]);
			br[ed]=(lw[y]>=dis[y]);
		}
		else lw[x]=min(lw[x],dis[y]); //back edge
	}
}
void dfs_init(ll n=0, ll m=0){
	mset(lw,-1); mset(art,0); mset(vised,0);
	//fore(i,0,n)lw[i]=-1,art[i]=0;
	//fore(i,0,m)vised[i]=0;
}
void dfs_tree(ll rt=0){
	if(lw[rt]!=-1)return;
	dis[rt]=0; cnt_=0;
	dfs_(rt);
	art[rt]=(cnt_>1);
}
int main(){FIN;
	ll m; cin>>n>>m;
	fore(i,0,m){
		ll u,v,w; cin>>u>>v>>w; u--,v--;
		g[u].pb({v,w});
		t[v].pb({u,w});
	}
	d[0]=distra(0,0);
	d[1]=distra(n-1,1);
	vector<ii>ed;
	fore(x,0,n)if(d[0][x]!=-1){
		for(auto [y,w]:g[x]){
			if(d[0][x]+w+d[1][y]==d[0][n-1])ed.pb({x,y});
		}
	}
	fore(i,0,n)g[i].clear();
	fore(i,0,SZ(ed)){
		auto [u,v]=ed[i];
		g[u].pb({v,i});
		g[v].pb({u,i});
	}
	/*fore(i,0,n){
		cout<<i<<": ";
		imp(g[i]);
	}
	for(auto [u,v]:ed)cout<<u+1<<" "<<v+1<<"\n";
	cout<<d[0][n-1]<<"\n";*/
	dfs_init();
	dfs_tree(0);
	vector<ll>res;
	fore(i,0,n)if(i==0||i==n-1||art[i])res.pb(i);
	cout<<SZ(res)<<"\n";
	for(auto i:res)cout<<i+1<<" ";;cout<<"\n";
	return 0;
}
