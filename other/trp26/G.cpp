#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=2e5+5;
vv g[MAXN],gt[MAXN],ord;
ll vis[MAXN],cmp[MAXN],truth[MAXN],qcmp=0,n;
void dfsk(ll x, ll t){
	vis[x]=1; if(t)cmp[x]=qcmp;
	for(auto y:t?gt[x]:g[x])if(!vis[y])dfsk(y,t);
	if(!t)ord.pb(x);
}
void scc(){
	qcmp=0; ord.clear(); fore(i,0,n)vis[i]=0;
	fore(i,0,n)if(!vis[i])dfsk(i,0);
	reverse(ALL(ord)); 
	fore(i,0,n)vis[i]=0;
	for(auto x:ord)if(!vis[x])dfsk(x,1),qcmp++;
}
ll neg(ll x){return n-x-1;}
void add_edge(ll x, ll y){
	g[x].pb(y);
	gt[y].pb(x);
}
void add_impl(ll x, ll y){
	// cerr<<"add impl "<<x<<","<<y<<"\n";
	add_edge(x,y);
	add_edge(neg(y),neg(x));
}
// void add_xor(ll x,ll y){
// 	add_impl(neg(x),y);
// 	add_impl(neg(y),x);
// }
bool satis(){
	scc();
	fore(i,0,n){
		if(cmp[i]==cmp[neg(i)])return 0;
		truth[i]=cmp[i]>cmp[neg(i)];
	}
	return 1;
}
vv doit(vector<vv> myg, vv a, ll rt){
	// cerr<<"doit "<<rt<<"\n";
	n=SZ(a);
	fore(i,0,n)g[i].clear(),gt[i].clear();
	vector<vv> pos(n/2);
	fore(i,0,n)pos[a[i]].pb(i);
	auto get_var=[&](ll x){
		ll c=a[x];
		ll ret=c;
		if(pos[c][0]!=x)ret=neg(ret);
		return ret;
	};
	auto dfs=[&](ll x, ll fa, auto &&dfs)->void {
		// cerr<<"dfs "<<x<<" "<<fa<<"\n";
		for(auto y:myg[x])if(y!=fa){
			add_impl(neg(get_var(x)),neg(get_var(y)));
			dfs(y,x,dfs);
		}
	};
	dfs(rt,-1,dfs);
	ll vrt=get_var(rt);
	add_impl(neg(vrt),vrt);
	if(!satis())return {};
	vv ret;
	fore(c,0,n/2){
		ll x=pos[c][!truth[c]];
		ret.pb(x);
	}
	return ret;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n; n*=2;
		vv a(n);
		fore(i,0,n)cin>>a[i],a[i]--;
		vector<vv> pos(n/2);
		fore(i,0,n)pos[a[i]].pb(i);
		vector<vv> g(n);
		fore(i,0,n-1){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		auto got=doit(g,a,pos[0][0]);
		if(!SZ(got))got=doit(g,a,pos[0][1]);
		if(!SZ(got)){
			cout<<"-1\n";
			continue;
		}
		for(auto i:got)cout<<i+1<<" ";;cout<<"\n";
	}
	return 0;
}
