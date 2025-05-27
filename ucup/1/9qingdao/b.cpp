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
		else lw[x]=min(lw[x],D[y]),br[i]=0; // back edge
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
vector<ii>all; // >
map<ll,ll>oc;
struct node{
	map<ll,ll>mp;
	multiset<ll>st,ast;
	ll po=0;
	node(){}
	void put(ll v, ll d){
		ll was=mp.count(v);
		ll cmp=oc[v]-mp[v];
		
		if(was)st.erase(st.find(mp[v]));
		mp[v]+=d; st.insert(mp[v]);
		
		if(was)ast.erase(ast.find(cmp));
		ast.insert(cmp-d);
		
		while(po<SZ(all)&&mp.count(all[po].snd))po++;
	}
	ll get(){
		// cout<<"{ ";;for(auto i:st)cout<<i<<" ";;cout<<"} ";
		// cout<<"{ ";;for(auto i:ast)cout<<i<<" ";;cout<<"} "<<po<<": ";
		ll abj=(SZ(st)?*st.rbegin():0);
		ll arr=(SZ(ast)?*ast.rbegin():0);
		if(po<SZ(all))arr=max(arr,all[po].fst);
		// cout<<abj<<" "<<arr<<"\n";
		return abj+arr;
	}
};
ll vis[MAXN],idx,cmp[MAXN];
void dfs0(ll x){
	vis[x]=1; cmp[x]=idx;
	for(auto i:h[x])oc[i]++;
	for(auto [y,i]:t[x])if(!vis[y])dfs0(y);
}
node dfs1(ll x, ll fa){
	node ret;
	for(auto i:h[x])ret.put(i,1);
	for(auto [y,i]:t[x])if(y!=fa){
		auto cur=dfs1(y,x);
		// cout<<"ans "<<i<<": ";
		ans[i]=cur.get();
		if(SZ(ret.mp)<SZ(cur.mp))swap(ret,cur);
		for(auto [v,d]:cur.mp)ret.put(v,d);
	}
	return ret;
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
		// fore(i,0,m)ans[i]=0;
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
		// fore(i,0,n){
		// 	cout<<i<<": ";
		// 	for(auto j:h[i])cout<<j<<" ";;cout<<"\n";
		// }
		ll tot=0; idx=0;
		fore(i,0,n){
			ll x=uf_find(i);
			if(i!=x||vis[x])continue;
			oc.clear();
			all.clear();
			dfs0(i);
			for(auto [k,v]:oc)all.pb({v,k});
			sort(ALL(all)); reverse(ALL(all));
			// cout<<"cmp "<<idx<<": ";
			// for(auto i:all)cout<<i.fst<<","<<i.snd<<" ";;cout<<"\n";
			tot+=(cans[idx]=all[0].fst);
			dfs1(i,-1);
			idx++;
		}
		fore(i,0,m){
			if(i)cout<<" ";
			ll p=cmp[uf_find(ed[i].fst)];
			ll res=!br[i]?tot:tot-cans[p]+ans[i];
			// cout<<"\n"<<i<<" "<<br[i]<<": "<<p<<": "<<cans[p]<<" "<<ans[i]<<" = ";
			cout<<res;
		}
		cout<<"\n";
		
	}
	return 0;
}