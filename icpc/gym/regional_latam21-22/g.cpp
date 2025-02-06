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
typedef unsigned long long ull;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
// #pragma GCC optimize("Ofast")
const ll MAXN=2e5+5;
// worst hcn: (332640,192)
ull falopa(ull x) {
	// http://xorshift.di.unimi.it/splitmix64.c
	x += 0x9e3779b37f4a7c15;
	x = (x ^ (x >> 27)) * 0x92d049bc133111eb;
	return x ^ (x >> 31);
}

vector<vv> g;
ll bl[MAXN],d[MAXN];

vv nod;
void dfs0(ll x, ll fa){
	nod.pb(x);
	for(auto y:g[x])if(y!=fa&&!bl[y])dfs0(y,x);
}
ull dfs1(ll x, ll fa){
	ull h=0;
	for(auto y:g[x])if(y!=fa&&!bl[y])h+=dfs1(y,x);
	return falopa(h);
}
ull get_hash(ll rt){ // with blocked!!
	nod.clear();
	dfs0(rt,-1);
	// cout<<"get_hash\n";
	// for(auto i:nod){
	// 	cout<<i<<": ";
	// 	for(auto j:g[i])cout<<j<<" ";
	// 	cout<<"| "<<bl[i]<<"\n";
	// }
	auto bfs=[&](ll s){
		for(auto i:nod)d[i]=-1;
		queue<ll>q;
		d[s]=0;
		q.push(s);
		ll mx=s;
		while(SZ(q)){
			auto x=q.front(); q.pop();
			if(d[x]>d[mx])mx=x;
			for(auto y:g[x])if(!bl[y]&&d[y]==-1)
				d[y]=d[x]+1,q.push(y);
		}
		assert(s!=mx);
		return mx;
	};
	ll e=bfs(rt);
	ll s=bfs(e);
	vv d0;
	for(auto i:nod)d0.pb(d[i]);
	ll diam=d[s];
	bfs(s);
	vv cs;
	// for(auto i:nod)cout<<i<<": "<<d[i]<<"\n";
	// cout<<diam<<" diam\n";
	fore(i,0,SZ(nod)){
		auto x=nod[i];
		ll a=d0[i],b=d[x];
		if(a+b==diam&&(a==diam/2||a==(diam+1)/2))cs.pb(x);
	}
	assert(SZ(cs)<=2);
	// imp(cs)
	for(auto i:cs)bl[i]=1;
	ull h=0;
	for(auto i:cs)h+=dfs1(i,-1);
	for(auto i:cs)bl[i]=0;
	// cout<<h<<"\n";
	return h;
}


ll c[MAXN],k;
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
		auto ha=get_hash(x);
		if(did)flag&=ha==h;
		else h=ha,did=1;
		if(fa!=-1)bl[fa]=0;
		bl[x]=1;
	}
}

vector<ull> um[MAXN];

ll cnt=0;
ll nl[MAXN];
// dfs
void chdfs(ll x, ll fa){
	nl[x]=cnt++;
	for(auto y:g[x])if(y!=fa)chdfs(y,x);
}
// bfs
// void chdfs(ll x, ll fa){
// 	queue<ii>q; q.push({x,fa});
// 	while(SZ(q)){
// 		auto [x,fa]=q.front(); q.pop();
// 		nl[x]=cnt++;
// 		for(auto y:g[x])if(y!=fa)q.push({y,x});
// 	}
// }
int main(){FIN;
	// cerr<<falopa(0)<<" f0\n";
	ll n; cin>>n;
	vector<vector<vv>> gs(n);
	vector<vv> sz(MAXN);
	fore(i,0,n){
		ll m; cin>>m;
		auto &_g=gs[i];
		_g.resize(m);
		fore(i,0,m-1){
			ll u,v; cin>>u>>v; u--,v--;
			_g[u].pb(v);
			_g[v].pb(u);
		}
		sz[m].pb(i);
		g=_g; cnt=0; chdfs(0,-1);
		_g.clear(); _g.resize(m);
		fore(x,0,m)for(auto y:g[x])_g[nl[x]].pb(nl[y]);
	}
	// vector<ull>hs(n);
	fore(i,0,n){
		g=gs[i];
		auto h=get_hash(0);
		um[SZ(g)].pb(h);
	}
	vv res(n);
	fore(z,1,MAXN)if(SZ(sz[z])){
		auto &v=um[z];
		sort(ALL(v));
		vector<ull>u; vv cs;
		for(auto i:v){
			if(!SZ(u)||i!=u.back())u.pb(i),cs.pb(1);
			else cs.back()++;
		}
		k=z;
		for(ll n=z;n<MAXN;n+=z){
			for(auto i:sz[n]){
				g=gs[i]; did=0,flag=1;
				fore(j,0,SZ(g))bl[j]=0;
				dfs(0,-1);
				if(flag){
					ll p=lower_bound(ALL(u),h)-u.begin();
					if(p<SZ(u)&&u[p]==h)res[i]+=cs[p];
				}
				// cout<<n<<" "<<k<<": "<<did<<" "<<flag<<" "<<h<<"\n";
			}
		}
	}
	for(auto i:res)cout<<i-1<<" ";;cout<<"\n";
	return 0;
}
