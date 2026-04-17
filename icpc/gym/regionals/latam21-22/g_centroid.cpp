#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cerr<<i<<" "; cerr<<"\n";}
using namespace std;
typedef int ll;
typedef unsigned int ull;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
#pragma GCC optimize("Ofast")
const ll MAXN=2e5+5;
ull falopa(ull x) {
	// http://xorshift.di.unimi.it/splitmix64.c
	x += 0x9e3779b37f4a7c15;
	x = (x ^ (x >> 27)) * 0x92d049bc133111eb;
	return x ^ (x >> 31);
}

vector<vv> g;
ll bl[MAXN],d[MAXN];

ll c[MAXN],k,sz;
vv cs;

void gocen(ll x, ll fa){
	ll is=1; c[x]=1;
	for(auto y:g[x])if(y!=fa&&!bl[y]){
		gocen(y,x);
		c[x]+=c[y];
		is&=2*c[y]<=sz;
	}
	is&=2*(sz-c[x])<=sz;
	if(is)cs.pb(x);
}
ull dfs1(ll x, ll fa){
	ull h=0;
	for(auto y:g[x])if(y!=fa&&!bl[y])h+=dfs1(y,x);
	return falopa(h);
}
ull get_hash(ll rt, ll _sz){ // with blocked!!
	sz=_sz;
	cs.clear();
	gocen(rt,-1);
	// imp(cs) cout<<endl;
	assert(SZ(cs)<=2);
	for(auto i:cs)bl[i]=1;
	ull h=0;
	for(auto i:cs)h+=dfs1(i,-1);
	for(auto i:cs)bl[i]=0;
	// cout<<h<<"\n";
	return h;
}


ull h=0; ll did=0,flag=1;
void dfs(ll x, ll fa){
	if(!flag)return;
	c[x]=1;
	for(auto y:g[x])if(y!=fa){
		dfs(y,x),c[x]+=c[y];
		if(!flag)return;
	}
	if(c[x]%k==0){
		if(fa!=-1)bl[fa]=1;
		auto ha=get_hash(x,c[x]);
		if(did)flag&=ha==h;
		else h=ha,did=1;
		if(fa!=-1)bl[fa]=0;
		bl[x]=1;
		c[x]=0;
	}
}

vector<ull> um[MAXN];
vv cants[MAXN];

ll cnt=0;
ll nl[MAXN];
// dfs
void chdfs(ll x, ll fa){
	nl[x]=cnt++;
	for(auto y:g[x])if(y!=fa)chdfs(y,x);
}
int main(){FIN;
	ll n; cin>>n;
	vector<vector<vv>> gs(n);
	fore(i,0,n){
		ll m; cin>>m;
		auto &_g=gs[i];
		_g.resize(m);
		fore(i,0,m-1){
			ll u,v; cin>>u>>v; u--,v--;
			_g[u].pb(v);
			_g[v].pb(u);
		}
		g=_g; cnt=0; chdfs(0,-1);
		_g.clear(); _g.resize(m);
		fore(x,0,m)for(auto y:g[x])_g[nl[x]].pb(nl[y]);
	}
	fore(i,0,n){
		g=gs[i];
		auto h=get_hash(0,SZ(g));
		um[SZ(g)].pb(h);
	}
	vv ds[MAXN];
	fore(d,0,MAXN)if(SZ(um[d]))for(ll n=d;n<MAXN;n+=d)if(SZ(um[n]))ds[n].pb(d);
	fore(z,0,MAXN)sort(ALL(um[z]));
	vv res(n);
	fore(i,0,n){
		g=gs[i];
		for(auto d:ds[SZ(g)]){
			k=d; did=0,flag=1;
			fore(j,0,SZ(g))bl[j]=0;
			dfs(0,-1);
			if(flag){
				res[i]+=upper_bound(ALL(um[d]),h)-lower_bound(ALL(um[d]),h);
			}
		}
	}
	for(auto i:res)cout<<i-1<<" ";;cout<<"\n";
	return 0;
}
