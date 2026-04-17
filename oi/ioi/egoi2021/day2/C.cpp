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
const ll MAXN=3e5+5,MAXW=1e9+5;

vector<ii>g[MAXN];
ll c[MAXN], d[MAXN];
ll n;
void dijkstra(){
	mset(d,-1);
	priority_queue<ii>pq;
	fore(i,0,n)if(c[i]==1){
		pq.push({0,i});
		d[i]=0;
	}
	while(SZ(pq)){
		auto f=pq.top(); pq.pop();
		ll x=f.snd,b=-f.fst;
		if(d[x]!=b)continue;
		for(auto i:g[x]){
			ll y=i.fst,w=i.snd;
			if(d[y]==-1||b+w<d[y])d[y]=b+w,pq.push({-d[y],y});
		}
	}
}
ll vis[MAXN],is[MAXN],flag=1;
vector<ll>wall;
void dfs(ll x, ll m){
	vis[x]=1;
	if(c[x]==1)flag=0;
	if(c[x]==0&&d[x]<=m){
		wall.pb(x);
		is[x]=1;
		return;
	}
	for(auto i:g[x]){
		ll y=i.fst;
		if(vis[y])continue;
		dfs(y,m);
	}
}
void dfs2(ll x){
	vis[x]=1;
	if(is[x])return;
	for(auto i:g[x]){
		ll y=i.fst;
		if(vis[y])continue;
		dfs2(y);
	}
}
bool can(ll m){
	mset(vis,0); flag=1; wall.clear(); mset(is,0);
	fore(i,0,n)if(c[i]==-1&&!vis[i])dfs(i,m);
	mset(vis,0);
	fore(i,0,n)if(c[i]==1){
		dfs2(i);
		break;
	}
	fore(i,0,n)if(c[i]==1&&!vis[i])flag=0;
	return flag;
}
int main(){FIN;
	ll m; cin>>n>>m;
	fore(i,0,n)cin>>c[i];
	fore(i,0,m){
		ll u,v,w; cin>>u>>v>>w; u--,v--;
		g[u].pb({v,w});
		g[v].pb({u,w});
	}
	dijkstra();
	//fore(i,0,n)cout<<i<<": "<<d[i]<<"\n";
	ll l=0,r=MAXN*MAXW;
	while(l<=r){
		ll m=(l+r)/2;
		if(can(m))r=m-1;
		else l=m+1;
	}
	//cout<<l<<"\n";
	if(can(l)){
		cout<<SZ(wall)<<"\n";
		for(auto i:wall)cout<<i+1<<" ";
		cout<<"\n";
	}
	else cout<<"-1\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
