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
typedef unsigned long long ull;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
random_device rd;
mt19937_64 rng(rd());
ull FIXED_RANDOM=rng(); // 0x9e3779b97f4a7c15
ull falopa(ull x) {
	// http://xorshift.di.unimi.it/splitmix64.c
	x += FIXED_RANDOM;
	x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
	x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
	return x ^ (x >> 31);
}
const ll MAXN=55;

vector<ll> g[MAXN];
vector<ll> t[MAXN];
ll n;
vv bfs(ll s){
	vv d(n,-1);
	d[s]=0;
	queue<ll>q;
	q.push(s);
	while(SZ(q)){
		auto x=q.front(); q.pop();
		for(auto y:g[x])if(d[y]==-1){
			d[y]=d[x]+1;
			q.push(y);
		}
	}
	return d;
}
ll vis[MAXN];
ull h[MAXN];
void dfs(ll x){
	vis[x]=1;
	for(auto y:g[x])if(!vis[y]){
		dfs(y);
		t[x].pb(y);
		h[x]+=h[y];
	}
	h[x]=falopa(h[x]);
}
vector<vv>ret;
vv per;
void dfs2(ll x, ll y){
	swap(per[x],per[y]);
	auto get=[&](ll x){
		vector<ii>ret;
		for(auto y:t[x])ret.pb({h[y],y});
		sort(ALL(ret));
		return ret;
	};
	auto u=get(x);
	auto v=get(y);
	fore(i,0,SZ(u)){
		dfs2(u[i].snd,v[i].snd);
	}
}
void agr(ll x, ll y){
	per=vv(n); iota(ALL(per),0);
	dfs2(x,y);
	ret.pb(per);
}

int main(){FIN;
	cin>>n;
	fore(i,0,n-1){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	auto d0=bfs(0);
	ll mx0=max_element(ALL(d0))-d0.begin();
	d0=bfs(mx0);
	ll mx1=max_element(ALL(d0))-d0.begin();
	auto d1=bfs(mx1);
	vv c;
	ll diam=d0[mx1];
	fore(i,0,n)if(max(d0[i],d1[i])==(diam+1)/2)c.pb(i);
	// cout<<"diam "<<diam<<"\n";
	// cout<<mx0<<": "; imp(d0);
	// cout<<mx1<<": "; imp(d1);
	// imp(c);
	// cout<<endl;
	assert(SZ(c)<=2);
	for(auto i:c)vis[i]=1;
	for(auto i:c)dfs(i);
	if(SZ(c)>1&&h[c[0]]==h[c[1]])agr(c[0],c[1]);
	fore(x,0,n){
		unordered_map<ull,vv> buc;
		for(auto y:g[x])buc[h[y]].pb(y);
		for(auto [shfd,v]:buc){
			fore(i,0,SZ(v)-1)agr(v[i],v[i+1]);
		}
	}
	if(!SZ(ret)){
		per=vv(n); iota(ALL(per),0);
		ret.pb(per);
	}
	cout<<SZ(ret)<<"\n";
	for(auto v:ret){
		for(auto i:v)cout<<i+1<<" ";
		cout<<"\n";
	}
	return 0;
}