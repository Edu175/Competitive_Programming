#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(x) {cerr<<#x<<": ";for(auto y:x)cerr<<y<<" ";cerr<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
typedef vector<vector<ii>> Graph;
Graph g;
vv vis;
ll done=0;
vv c;
ll rep;
ll dfs(ll x, ll fa){
	// cerr<<"dfs "<<x<<" "<<done<<" "<<vis[x]<<"\n";
	if(done)return 0;
	if(vis[x]){
		done=1;
		rep=x;
		return 1;
	}
	vis[x]=1;
	for(auto [y,i]:g[x])if(y!=fa){
		auto got=dfs(y,x);
		if(got){
			c.pb(i);
			return x!=rep;
		}
	}
	return 0;
}

vv getCycle(Graph &_g){
	// cerr<<"getCycle\n";
	g=_g;
	ll n=SZ(g);
	// fore(i,0,n){
	// 	cerr<<i<<": ";
	// 	for(auto [x,y]:g[i])cerr<<x<<","<<y<<" ";;
	// 	cerr<<"\n";
	// }
	vis=vv(n);
	done=0;
	c.clear();
	dfs(0,-1);
	// cerr<<"found cycle ";
	// show(c)
	assert(SZ(c));
	return c;
}
vv ans;
struct Coso{
	vv id;
	vector<vv> comp;
	vector<set<ll>> has;
	Coso(ll n, vector<ii> qs):id(n),comp(n),has(n){
		fore(i,0,n)id[i]=i,comp[i]={i};
		fore(i,0,SZ(qs)){
			auto [u,v]=qs[i];
			has[u].insert(i);
			has[v].insert(i);
		}
	}
	ll val;
	void join(ll x, ll y){
		x=id[x],y=id[y];
		if(x==y)return;
		if(SZ(comp[x])+SZ(has[x])<SZ(comp[y])+SZ(has[y]))swap(x,y);
		for(auto i:comp[y])id[i]=x,comp[x].pb(i);
		comp[y].clear();
		for(auto idx:has[y]){
			if(has[x].count(idx)){
				has[x].erase(idx);
				if(ans[idx]==-1){
					ans[idx]=val;
					// cerr<<"answered "<<idx<<"\n";
				}
			}
			else has[x].insert(idx);
		}
		has[y].clear();
	}
	void process(vector<ii> ed, ll _val){
		val=_val;
		for(auto [u,v]:ed)join(u,v);
	}
};
int main(){
	JET
	ll n,q; cin>>n>>q;
	ll m=n+1;
	vector<ii> ed;
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		ed.pb({u,v});
	}
	vector<vv> cs;
	Graph curG(n);
	fore(i,0,m){
		auto [u,v]=ed[i];
		curG[u].pb({v,i});
		curG[v].pb({u,i});
	}
	auto c=getCycle(curG);
	cs.pb(c);
	ll ban=c[0];
	curG=Graph(n);
	fore(i,0,m)if(i!=ban){
		auto [u,v]=ed[i];
		curG[u].pb({v,i});
		curG[v].pb({u,i});
	}
	c=getCycle(curG);
	
	cs.pb(c);
	vector<ii> qs(q);
	fore(i,0,q){
		ll u,v; cin>>u>>v; u--,v--;
		qs[i]={u,v};
	}
	ans=vv(q,-1);
	vv ty(m);
	fore(wh,0,2)for(auto i:cs[wh])ty[i]|=1<<wh;
	// show(cs[0])
	// show(cs[1])
	// show(ty)
	auto doit=[&](vv tys, ll val){
		// cerr<<"doit "<<val<<": ";
		// show(tys)
		Coso cosa(n,qs);
		vector<ii> mando;
		fore(i,0,m)if(count(ALL(tys),ty[i]))mando.pb(ed[i]);
		cosa.process(mando,val);
	};
	ll fg=0;
	fore(i,0,m)fg|=ty[i]==3;
	doit({0},1);
	doit({0,1},2+fg);
	doit({0,2},2+fg);
	doit({0,3},2+fg);
	fore(i,0,q)if(ans[i]==-1)ans[i]=4;
	fore(i,0,q){
		cout<<ans[i]<<"\n";
	}
	return 0;
}
