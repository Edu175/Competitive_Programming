#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,mxcon=b;i<mxcon;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);;cout.tie(0);
#define imp(v) {for(auto kjdfhg:v)cout<<kjdfhg<<" ";cout<<"\n";}
using namespace std;
typedef int ll;
typedef pair<ll,ll> ii;
const ll MAXN=1e5+5,MAXM=6e6+5;
ll uf[MAXN];
ll uf_find(ll x){return uf[x]<0?x:uf[x]=uf_find(uf[x]);}
void uf_join(ll x, ll y){
	x=uf_find(x),y=uf_find(y);
	if(x==y)return;
	if(uf[x]>uf[y])swap(x,y);
	uf[x]+=uf[y],uf[y]=x;
}
bitset<MAXM> vised,br;
bitset<MAXN> vis;
ll lw[MAXN],D[MAXN];
vector<ii> g[MAXN];
vector<ii>ed;
void dfs(ll x){
	// cout<<"dfs "<<x<<" "<<fa<<"\n";
	vis[x]=1;
	lw[x]=D[x];
	for(auto [y,i]:g[x])if(!vised[i]){
		vised[i]=1;
		if(!vis[y]){
			D[y]=D[x]+1;
			dfs(y);
			if(lw[y]>=D[y])br[i]=1;//,cout<<"tree ";
			lw[x]=min(lw[x],lw[y]);
		}
		else {
			lw[x]=min(lw[x],D[y]);
			// cout<<"back ";
		}
		// cout<<x<<" "<<y<<"\n";
	}
}
ll n;
void doit(){
	vised.reset();
	vis.reset();
	br.reset();
	fore(i,0,SZ(ed)){
		auto [u,v]=ed[i];
		u=uf_find(u); v=uf_find(v);
		if(u==v)continue;
		g[u].pb({v,i});
		g[v].pb({u,i});
	}
	fore(i,0,n)if(!vis[i]){
		D[i]=0;
		dfs(i);
	}
	fore(i,0,n){
		g[i].clear();
	}
	
	vector<ii>edi;
	while(SZ(ed)){
		auto i=SZ(ed)-1;
		if(br[i])edi.pb(ed[i]);
		else uf_join(ed[i].fst,ed[i].snd);
		ed.pop_back();
	}
	// fore(i,0,SZ(ed)){
	// }
	swap(ed,edi);
	// fore(i,0,n)cout<<lw[i]<<" ";;cout<<"\n";
}
const ll MK=25e3;
int main(){FIN;
	mset(uf,-1);
	ll m; cin>>n>>m;
	// ll K=100,MK=(m+K-1)/K;
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		ed.pb({u,v});
		if(i==m-1||i%MK==MK-1)doit();
	}
	for(auto [u,v]:ed)cout<<u+1<<" "<<v+1<<"\n";
	return 0;
}