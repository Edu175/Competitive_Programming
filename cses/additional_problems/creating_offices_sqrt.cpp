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
typedef int ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=2e5+5;

vector<ll> g[MAXN];

ll D[MAXN],fa[MAXN],P[MAXN];
vv ord;
void lca_dfs(ll x){
	for(auto y:g[x])if(y!=fa[x]){
		fa[y]=x;
		D[y]=D[x]+1;
		ord.pb(x);
		lca_dfs(y);
	}
	P[x]=SZ(ord);
	ord.pb(x);
}
const ll K=19;//K such that 2^k>n
ll oper(ll i, ll j){return D[i]<D[j]?i:j;}
ll st[K][1ll<<K];
void st_init(vector<ll> &a){
	ll n=SZ(a);
	fore(i,0,n)st[0][i]=a[i];
	fore(k,1,K)fore(i,0,n-(1ll<<k)+1)
		st[k][i]=oper(st[k-1][i],st[k-1][i+(1ll<<(k-1))]);
}
ll st_query(int s, int e){
	int k=31-__builtin_clz(e-s);
	return oper(st[k][s],st[k][e-(1<<k)]);
}
ll n;
random_device rd;
mt19937 rng(rd());
void lca_init(){
	ll rt=rng()%n;
	fa[rt]=-1; D[rt]=0;
	lca_dfs(0);
	st_init(ord);
}
ll lca(ll x, ll y){
	ll l=P[x],r=P[y];
	if(l>r)swap(l,r);
	return st_query(l,r+1);
}
ll dis(ll x, ll y){return D[x]+D[y]-2*D[lca(x,y)];}
bitset<MAXN> is;
bitset<MAXN>bs;
ll k;
void bfs(){
	queue<ii>q;
	bs.set();
	fore(i,0,n)if(is[i])q.push({0,i}),bs[i]=0;
	while(SZ(q)){
		auto [d,x]=q.front(); q.pop();
		if(d==k-1)break;
		for(auto y:g[x])if(bs[y]){
			q.push({d+1,y}); bs[y]=0;
		}
	}
}
// cache relabeling
// helpful to reduce constant when the slow part is a dfs
// you can generalize this for other problems
// for centroid is roughly a x2 speedup
ll nl[MAXN],orig[MAXN]; // new label for helping cache
void cache(){
	mset(nl,-1);
	queue<ll>q;
	ll cnt=0;
	fore(s,0,n)if(cnt<1&&SZ(g[s])<=1){
		q.push(s);
		nl[s]=cnt;
		orig[cnt++]=s;
	}
	while(SZ(q)){
		auto x=q.front(); q.pop();
		for(auto y:g[x])if(nl[y]==-1){
			nl[y]=cnt;
			orig[cnt++]=y;
			q.push(y);
		}
	}
}

const ll B=450;
int main(){FIN;
	cin>>n>>k;
	vector<ii>ed;
	fore(i,0,n-1){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
		ed.pb({u,v});
	}
	// inside main (store edges in ed in the same order as inserted)
	cache();
	fore(i,0,n)g[i].clear();
	for(auto [x,y]:ed){
		ll u=nl[x],v=nl[y];
		g[u].pb(v);
		g[v].pb(u);
	}
	//
	cerr<<"lca init\n";
	lca_init();
	vv deg(n); // pa abajo
	priority_queue<ii>pq;
	auto putif=[&](ll x){if(!deg[x])pq.push({D[x],x});};
	fore(x,0,n){
		deg[x]=SZ(g[x])-(fa[x]!=-1);
		putif(x);
	}
	bfs();
	vv bag;
	vv ans;
	// print(pq);
	cerr<<"problem\n";
	while(SZ(pq)){
		if(SZ(bag)>=B)bfs(),bag.clear();
		auto [sdkj,x]=pq.top(); pq.pop();
		ll good=bs[x];
		if(good)for(auto i:bag)good&=k<=dis(i,x);
		// cout<<x<<": "<<good<<"\n";
		if(good){
			is[x]=1;
			bag.pb(x);
			ans.pb(x);
		}
		if(fa[x]!=-1){
			deg[fa[x]]--;
			putif(fa[x]);
		}
	}
	cout<<SZ(ans)<<"\n";
	for(auto i:ans)cout<<orig[i]+1<<" ";;cout<<"\n";
	return 0;
}
