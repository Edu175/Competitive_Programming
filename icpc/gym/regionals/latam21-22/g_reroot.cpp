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
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=4e5+5;
// worst hcn: (332640,192)
ull falopa(ull x) {
	// http://xorshift.di.unimi.it/splitmix64.c
	x += 0x9e3779b97f4a7c15;
	x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
	x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
	return x ^ (x >> 31);
}

vector<vv> g;

ll c[MAXN],k;
ull hsh[MAXN];
vector<ull> big;
void dfs(ll x, ll fa){
	hsh[x]=0; c[x]=1;
	for(auto y:g[x])if(y!=fa){
		dfs(y,x);
		if(c[y]%k)hsh[x]+=falopa(hsh[y]);
	}
	if(c[x]%k==0)big.pb(hsh[x]);
}

bool check(vector<ull> &small, vector<vv> &_g){
	g=_g; k=SZ(small);
	big.clear();
	dfs(0,-1);
	for(auto i:big){
		auto p=lower_bound(ALL(small),i);
		if(p==small.end()||*p!=i)return 0;
	}
	return 1;
}
typedef ull node;
node h[MAXN],ch[MAXN],tot[MAXN];
node NEUT=0;
node merge(node a, node b){
	return a+b;
}
node sub(node a, node b){
	return a-b;
}
node up(node a){
	return falopa(a);
}
void dfs1(ll x, ll f=-1){
	h[x]=NEUT;
	for(auto y:g[x])if(y!=f){
		dfs1(y,x);
		h[x]=merge(h[x],up(h[y]));
	}
}
void dfs2(ll x, ll f=-1){
	tot[x]=merge(tot[x],h[x]);
	for(auto y:g[x])if(y!=f){
		ch[y]=up(merge(ch[x],sub(h[x],up(h[y]))));
		tot[y]=ch[y];
		dfs2(y,x);
	}
}
void reroot(ll rt=0){
	dfs1(rt);
	ch[rt]=NEUT;
	tot[rt]=NEUT;
	dfs2(rt);
}
vector<ull> get_hashes(vector<vv>&_g){
	g=_g;
	reroot();
	vector<ull> ret;
	fore(i,0,SZ(g))ret.pb(tot[i]);
	sort(ALL(ret));
	return ret;
}

int main(){FIN;
	ll n; cin>>n;
	vector<vector<vv>> gs(n);
	vector<vv> sz(MAXN),cand(MAXN);
	fore(i,0,n){
		ll m; cin>>m;
		auto &g=gs[i];
		g.resize(m);
		fore(i,0,m-1){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		sz[m].pb(i);
	}
	fore(n,1,MAXN)if(SZ(sz[n])){
		for(ll z=n;z<MAXN;z+=n){
			for(auto i:sz[z])cand[n].pb(i);
		}
	}
	fore(i,0,n){
		auto &t=gs[i];
		ll m=SZ(t);
		auto st=get_hashes(t);
		for(ll z=m;)
	}
	return 0;
}
