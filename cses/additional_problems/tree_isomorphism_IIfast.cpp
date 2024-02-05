#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef int ll;
typedef unsigned long long ull;
typedef pair<ll,ll> ii;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")

static uint64_t up(uint64_t x) {
    // http://xorshift.di.unimi.it/splitmix64.c
    x += 0x9e3779b97f4a7c15;
    return x ^ (x >> 31);
}
const ll MAXN=1e5+5;
vector<ll> g[MAXN];
typedef ull node;
node h[MAXN],ch[MAXN];
#define NEUT 0
bitset<MAXN>vis;
void dfs1(ll x){
	h[x]=NEUT;
	vis[x]=1;
	for(auto y:g[x])if(!vis[y]){
		dfs1(y);
		h[x]+=up(h[y]);
	}
}
void dfs2(ll x){
	vis[x]=1;
	for(auto y:g[x])if(!vis[y]){
		ch[y]=up(ch[x]+h[x]-up(h[y]));
		dfs2(y);
	}
}
void reroot(ll n){
	fore(i,0,n)vis[i]=0;
	dfs1(0);
	ch[0]=NEUT;
	fore(i,0,n)vis[i]=0;
	dfs2(0);
}

node dfs(ll x){
	vis[x]=1;
	node res=NEUT;
	for(auto y:g[x])if(!vis[y])res+=up(dfs(y));
	return res;
}
static inline int getint() {
    int x, y;
    while((x = getchar_unlocked()) < '0') {}
    x -= '0';
    while((y = getchar_unlocked()) >= '0') { x = x * 10 + y - '0'; }
    return x;
}
int main(){FIN;
	ll t=getint();
	while(t--){
		ll n=getint();
		fore(i,0,n){
			g[i].clear();
			vis[i]=0;
		}
		fore(i,0,n-1){
			ll u=getint(),v=getint(); u--,v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		node t1=dfs(0);
		fore(i,0,n){
			g[i].clear();
		}
		fore(i,0,n-1){
			ll u=getint(),v=getint(); u--,v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		reroot(n);
		ll flag=0;
		//cout<<t1<<"\n";
		//fore(i,0,n)cout<<tot[i]<<"\n";
		fore(i,0,n)if(h[i]+ch[i]==t1){flag=1;break;}
		if(flag){
			puts("YES");
		}
		else {
			puts("NO");
		}
	}
	return 0;
}
