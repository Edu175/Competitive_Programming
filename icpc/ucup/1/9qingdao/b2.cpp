#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=1e5+5,MAXM=MAXN;
vector<ii> g[MAXN]; // {node,edge}
int lw[MAXN],D[MAXN],art[MAXN]; // articulation point iff !=0
bool br[MAXM],vised[MAXM]; 
void dfs_(ll x){
	lw[x]=D[x];
	for(auto [y,i]:g[x])if(!vised[i]){
		vised[i]=1;
		if(lw[y]==-1){ // tree edge
			D[y]=D[x]+1;
			dfs_(y);
			lw[x]=min(lw[x],lw[y]);
			art[x]+=(lw[y]>=D[x]);
			br[i]=(lw[y]>=D[y]);
		}
		else lw[x]=min(lw[x],D[y]); // back edge
	}
}
void dfs_tree(int n, int m=0){
	if(!m)mset(lw,-1), mset(art,0), mset(vised,0);
	else { // multiple testcases
		fore(i,0,n)lw[i]=-1,art[i]=0;
		fore(i,0,m)vised[i]=0;
	}
	fore(i,0,n)if(lw[i]==-1)D[i]=0,dfs_(i),art[i]--;
}
int uf[MAXN];
int uf_find(int x){return uf[x]<0?x:uf[x]=uf_find(uf[x]);}
bool uf_join(int x, int y){
	x=uf_find(x);y=uf_find(y);
	if(x==y)return false;
	if(uf[x]>uf[y])swap(x,y);
	uf[x]+=uf[y];uf[y]=x;
	return true;
}
ll a[MAXN];
vector<ii> t[MAXN];
ll ans[MAXM],cans[MAXN];
vv h[MAXN];
ll idx;
vector<ii>all;
struct node{
	map<ll,ll>mp;
	multiset<ll>st;
	ll po=0,other=0;
	node(){}
	void put(ll v){st.erase(st.find(mp[v]++));st.insert(mp[v]);}
	void put(vv v){for(auto i:v)put(i);}
	void out(ll v){st.erase(st.find(mp[v]--));st.insert(mp[v]);}
	void out(vv v){for(auto i:v)out(i);}
	ll get(){return SZ(st)?*st.rbegin():0;}
};
node now;
ll vis[MAXN];
void dfs0(ll x){
	vis[x]=1;
	down.put(h[x]);
	for(auto [y,i]:t[x])if(!vis[y])dfs0(y);
}
void dfs1(ll x, ll y){
	
}
int main(){
	JET
	ll te; cin>>te;
	while(te--){
		ll n,m; cin>>n>>m;
		fore(i,0,n){
			uf[i]=-1;
			g[i].clear();
			t[i].clear();
			h[i].clear();
			vis[i]=0;
		}
		fore(i,0,n)cin>>a[i];
		vector<ii>ed;
		fore(i,0,m){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb({v,i});
			g[v].pb({u,i});
			ed.pb({u,v});
		}
		dfs_tree(n,m);
		fore(i,0,m)if(!br[i])uf_join(ed[i].fst,ed[i].snd);
		fore(i,0,m)if(br[i]){
			auto [x,y]=ed[i];
			x=uf_find(x); y=uf_find(y);
			t[x].pb({y,i});
			t[y].pb({x,i});
		}
		fore(i,0,n)h[uf_find(i)].pb(a[i]);
		idx=0;
		fore(i,0,n){
			ll x=uf_find(i);
			if(vis[x])continue;
			idx++;
			up=down=node();
			
		}
		
		
	}
	return 0;
}