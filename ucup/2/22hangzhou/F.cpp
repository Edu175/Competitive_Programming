#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {for(auto i:v)cout<<i<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
#define minig(a,b) a=min(a,b)
const ll MAXN=5e5+5;

vector<pair<int,ll>> g[MAXN];
int tag[MAXN];
int fat[MAXN];
int szt[MAXN];

int calcsz(int x, int f){
	szt[x]=1;
	for(auto [y,w]:g[x])if(y!=f&&tag[y]<0)szt[x]+=calcsz(y,x);
	return szt[x];
}
int ccnt=0;
void cdfs(int x, int f, int sz=-1){
	if(sz<0)sz=calcsz(x,-1);
	for(auto [y,w]:g[x])if(tag[y]<0&&szt[y]*2>=sz){
		szt[x]=0;cdfs(y,f,sz);return;
	}
	tag[x]=ccnt++; fat[x]=f;
	for(auto [y,w]:g[x])if(tag[y]<0)cdfs(y,x);
}
void centroid(){mset(tag,-1);ccnt=0;cdfs(0,-1);}

struct Coso{ll d; int t,idx;};
bool byd(const Coso &a, const Coso &b){return a.d<b.d;}
bool byidx(const Coso &a, const Coso &b){return a.idx<b.idx;}

ll mex=0;
int a[MAXN]; // if a[x]<mex its a good element
vector<ii> has[MAXN];
int ans[MAXN];
int rt,ram;
vector<Coso> bag,elems;
void dfs(ll x, ll fa, ll d){
	// cout<<"visited "<<x<<" "<<ram<<" "<<d<<"\n";
	for(auto [idx,r]:has[x]){
		r-=d;
		bag.pb((Coso){r,ram,(int)idx});
	}
	if(a[x]<mex)elems.pb((Coso){d,ram,a[x]});
	for(auto [y,w]:g[x])if(y!=fa&&tag[y]>=tag[rt])dfs(y,x,d+w);
}

Coso q[MAXN];

void doit(ll _rt){
	rt=_rt;
	// cerr<<"\ndoit "<<rt<<"\n";
	ram=0;
	bag.clear();
	elems.clear();
	
	for(auto [idx,r]:has[rt])bag.pb((Coso){r,-1,(int)idx});
	if(a[rt]<mex)elems.pb({(Coso){0,-1,a[rt]}});
	
	for(auto [y,w]:g[rt])if(tag[y]>=tag[rt]){
		dfs(y,rt,w);
		ram++;
	}
	sort(ALL(bag),byd); sort(ALL(elems),byidx);
	
	// cout<<"bag: ";;for(auto i:bag)cout<<i.d<<","<<i.t<<","<<i.idx<<" ";;cout<<"\n";
	// cout<<"elems: ";;for(auto i:elems)cout<<i.d<<","<<i.t<<","<<i.idx<<" ";;cout<<"\n";
	
	ll po=0;
	ll ql=0,qr=0;
	
	for(auto [d,t,v]:elems){
		// I want that j.d < d
		// and j.t != t
		
		// first empty q if possible
		while(ql<qr&&q[ql].d<d&&q[ql].t!=t){
			minig(ans[q[ql].idx],v);
			ql++;
		}
		
		while(po<SZ(bag)&&bag[po].d<d){
			if(bag[po].t==t){
				q[qr++]=bag[po++];
			}
			else {
				minig(ans[bag[po].idx],v);
				po++;
			}
		}
	}
}

ll nl[MAXN],cidx=0;
void cache(ll x, ll fa){
	nl[x]=cidx++;
	for(auto [y,w]:g[x])if(y!=fa)cache(y,x);
}

int main(){
	JET
	ll n,q; cin>>n>>q;
	set<ll> esta;
	fore(i,0,n)cin>>a[i],esta.insert(a[i]);
	while(esta.count(mex))mex++;
	vector<array<ll,3>> eds;
	fore(i,0,n-1){
		ll u,v,w; cin>>u>>v>>w; u--,v--;
		g[u].pb({v,w});
		g[v].pb({u,w});
		eds.pb({u,v,w});
	}
	
	cache(0,-1);
	vv _a(a,a+n);
	fore(x,0,n)g[x].clear();
	
	for(auto [x,y,w]:eds){
		x=nl[x];
		y=nl[y];
		g[x].pb({y,w});
		g[y].pb({x,w});
	}
	eds.clear();
	fore(x,0,n)a[nl[x]]=_a[x];
	_a.clear();
	
	centroid();
	fore(i,0,q){
		ll x,r; cin>>x>>r; x--; x=nl[x];
		has[x].pb({i,r});
		ans[i]=mex;
	}
	fore(x,0,n)doit(x);
	fore(i,0,q){
		cout<<ans[i]<<"\n";
	}
	return 0;
}
