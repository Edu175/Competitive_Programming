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
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
const ll MAXN = 1e5+5;
// Finds strongly connencted components , ord is a valid toposort of the component graph
ll n;
vv g[MAXN], gt[MAXN], ord;  //gt: transposed graph. ord: order for scc  
ll vis[MAXN], cmp[MAXN]; //cmp[x]: scc of node x. truth[x]: boolean value for 2sat  
ll qcmp = 0;

void kdfs(ll x, ll t){
    if(t) cmp[x] = qcmp;
    vis[x] = 1;
    for(auto y: t ? gt[x] : g[x])if(!vis[y]) kdfs(y,t);
    if(!t) ord.pb(x);
}
void scc(){
	fore(x,0,n)for(auto y:g[x])gt[y].pb(x);
	ord.clear(); mset(vis,0);
    fore(i,0,n) if(!vis[i]) kdfs(i,0);
    reverse(ALL(ord));
    mset(vis,0);
    for(auto x:ord)if(!vis[x]){
        kdfs(x,1);  
        qcmp++;
    }
}
bitset<MAXN> to[MAXN];

void dfs(ll x){
	vis[x]=1;
	to[x][x]=1;
	for(auto y:g[x]){
		if(!vis[y])dfs(y);
		to[x]|=to[y];
	}
}

int main(){FIN;
	ll m; cin>>n>>m;
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
	}
	scc();
	if(qcmp==1){
		cout<<"1\n";
		return 0;
	}
	set<ii> ed;
	fore(x,0,n)for(auto y:g[x])ed.insert({cmp[x],cmp[y]});
	fore(x,0,n)g[x].clear();
	
	vector<vv> nodes(qcmp);
	fore(x,0,n)nodes[cmp[x]].pb(x);
	
	n=qcmp;
	vv ind(n);
	for(auto [x,y]:ed)if(x!=y){
		g[x].pb(y),ind[y]++;
		cout<<x+1<<" "<<y+1<<endl;
	}
	cout<<"=======\n";
	mset(vis,0);
	fore(x,0,n)if(!vis[x])dfs(x);
	bitset<MAXN> out; // is out0
	fore(x,0,n)out[x]=!SZ(g[x]);
	
	fore(x,0,n)if(!ind[x]){
		fore(y,0,n)if(out[y]&&to[x][y])cout<<x+1<<" "<<y+1<<endl;
	}
	
	ll qin=0,qout=out.count();
	fore(x,0,n)qin+=!ind[x];
	vector<ii> ret;
	ll rep=-1;
	fore(x,0,n)if(!ind[x]){
		rep=x;
		ll y=((~to[x])&out)._Find_first();
		if(y>=MAXN)y=out._Find_first();
		ret.pb({y,x});
		if(!ind[y])to[y][x]=1;
		out[y]=0;
	}
	for(ll c=out.count(),y=out._Find_first();c>0;c--,y=out._Find_next(y)){
		ret.pb({y,rep});
	}
	cout<<SZ(ret)<<"\n";
	for(auto [a,b]:ret){
		cerr<<a+1<<" "<<b+1<<": ";
		cout<<nodes[a][0]+1<<" "<<nodes[b][0]+1<<"\n";
	}
	// cout<<endl;
	assert(SZ(ret)==max(qin,qout));
	return 0;
}