#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef int ll;
typedef pair<ll,ll> ii;
#pragma GCC optimize("Ofast") // may lead to precision errors

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
typedef unsigned long long ull;
const ll W=64;
struct my_bitset{
	vector<ull>bs; int n;
	my_bitset(int n):bs((n+W)/W),n(n){}
	void flip(int p){bs[p/W]^=1ull<<(p%W);}
	void operator|=(my_bitset b){
		fore(i,0,SZ(bs))bs[i]|=b.bs[i];
	}
	int _Find_next(int p){ //exactly the same as original bitset
		++p;
		ll i=p/W;
		ull bl=bs[i];
		bl&=(~0ull)<<(p%W);
		if(bl)return i*W+__builtin_ctzl(bl);
		i++;
		for(;i<SZ(bs);i++){
			bl=bs[i];
			if(bl)return i*W+__builtin_ctzl(bl);
		}
		return n;
	}
};
const ll MAXN=1e5+5;
vector<ll> g[MAXN];
ll ind[MAXN];
vector<my_bitset> c(MAXN,my_bitset(MAXN));
ll vis[MAXN];
void dfs(ll x){
	vis[x]=1;
	c[x].flip(x);
	for(auto y:g[x]){
		if(!vis[y])dfs(y);
		c[x]|=c[y];
	}
}
bool cmp(ll i, ll j){
	return c[i].bs>c[j].bs;
}
int main(){FIN;
	ll n,m; cin>>n>>m;
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		ind[v]++;
	}
	fore(i,0,n)if(!vis[i])dfs(i);
	priority_queue<ll,vector<ll>,function<bool(ll,ll)>>pq(cmp);
	vector<ll>ord;
	fore(i,0,n)if(!ind[i])pq.push(i);
	while(SZ(pq)){
		auto x=pq.top(); pq.pop();
		ord.pb(x);
		for(auto y:g[x]){
			ind[y]--;
			if(!ind[y])pq.push(y);
		}
	}
	for(auto i:ord)cout<<i+1<<" ";
	cout<<"\n";
	return 0;
}
