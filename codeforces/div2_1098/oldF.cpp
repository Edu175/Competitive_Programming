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
typedef tuple<ll,ll,ll> tri;
typedef vector<ll> vv;
const ll MAXN=2e5+5,INF=1e18;
// tag[y]>=tag[x] for every y in x's connected subgraph (unrooted subtree)
vector<int> g[MAXN];
int tag[MAXN]; // time of discovery of centroid
int fat[MAXN]; // father in centroid decomposition
int szt[MAXN]; // size of subtree
int calcsz(int x, int f){
	szt[x]=1;
	for(auto y:g[x])if(y!=f&&tag[y]<0)szt[x]+=calcsz(y,x);
	return szt[x];
}
int ccnt=0;
void cdfs(int x, int f, int sz=-1){ // O(nlogn)
	if(sz<0)sz=calcsz(x,-1);
	for(auto y:g[x])if(tag[y]<0&&szt[y]*2>=sz){
		szt[x]=0;cdfs(y,f,sz);return;
	}
	tag[x]=ccnt++; fat[x]=f;
	for(auto y:g[x])if(tag[y]<0)cdfs(y,x);
}
void centroid(ll n){
	fore(i,0,n)tag[i]=-1;
	ccnt=0;cdfs(0,-1);
}

ll a[MAXN];

vector<ll> rev[MAXN];
ll tot=0;
vv sz[MAXN];
ll dfs0(ll x, ll fa){
	ll ret=a[x];
	fore(i,0,SZ(g[x])){
		ll y=g[x][i];
		if(y==fa)continue;
		ll got=dfs0(y,x);
		ret+=got;
		sz[x][i]=got;
		sz[y][rev[x][i]]=tot-got;
	}
	return ret;
}

ll rt;
vector<tri> all; // {ram,d,minw}
ll ram,mxd;
void dfs(ll x, ll d, ll mnw, ll w, ll fa){
	mnw=min(mnw,w); mxd=max(mxd,d);
	all.pb({ram,d,mnw});
	fore(i,0,SZ(g[x])){
		ll y=g[x][i];
		if(!(tag[y]>=tag[rt])||y==fa)continue;
		ll pw=sz[x][i];
		dfs(y,d+1,min(mnw,w-pw),pw,x);
	}
}
ll k;
bool can(ll h){
	vector<ll> bu;
	vv mn(mxd+1,INF); // for each d, the min w_ram that survived
	mn[0]=0; // 
	ll prev=-1,we=-1;
	for(auto &[ram,d,mnw]:all)if(mnw>=h){
		if(ram!=prev){
			for(auto d:bu)mn[d]=min(mn[d],we);
			bu.clear();
			prev=ram;
			we=sz[rt][ram];
		}
		if(d>k)continue;
		if(k-d<=mxd){
			ll cand=tot-we-mn[k-d];
			if(cand>=h)return 1;
		}
		bu.pb(d);
	}
	return 0;
}

const ll R=2e14+10000;
ll doit(ll _rt){
	rt=_rt;
	all.clear();
	// cerr<<"doit "<<rt<<": ";
	mxd=0;
	fore(i,0,SZ(g[rt])){
		ll y=g[rt][i];
		if(!(tag[y]>=tag[rt]))continue;
		ram=i;
		ll pw=sz[rt][i];
		dfs(y,1,tot-pw,pw,rt);
	}
	ll l=-1,r=R;
	while(r-l>1){
		ll h=(l+r)/2;
		if(can(h))l=h;
		else r=h;
	}
	// cerr<<"= "<<l<<"\n";
	return l;
}

ll nl[MAXN]; // new label for helping cache
ll cnt=0;
void cache(ll x, ll fa=-1){
	nl[x]=cnt++;
	for(auto y:g[x])if(y!=fa)cache(y,x);
}


int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n>>k;
		fore(i,0,n){
			g[i].clear();
			rev[i].clear();
		}
		tot=0;
		fore(i,0,n)cin>>a[i],tot+=a[i];
		vector<ii> ed;
		fore(i,0,n-1){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
			g[v].pb(u);
			ed.pb({u,v});
		}
		cnt=0;
		cache(0,-1);
		fore(i,0,n)g[i].clear();
		vv _a(a,a+n);
		fore(i,0,n)a[nl[i]]=_a[i];
		for(auto [u,v]:ed){
			u=nl[u],v=nl[v];
			g[u].pb(v);
			g[v].pb(u);
			rev[u].pb(SZ(g[v])-1);
			rev[v].pb(SZ(g[u])-1);
		}
		fore(i,0,n)sz[i]=vv(SZ(g[i]));
		dfs0(0,-1);
		centroid(n);
		ll mx=-1;
		fore(rt,0,n)mx=max(mx,doit(rt));
		cout<<mx<<"\n";
	}
	return 0;
}
