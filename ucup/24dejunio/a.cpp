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
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=1e6+5;

ll vis[MAXN];

vector<ll> prox;
vv g[MAXN]; // only good edges (endpoint good)

ll good[MAXN]; // reachable from end

void go(ll x){
	if(vis[x])return;
	vis[x]=1;
	
	assert(SZ(g[x]));
	for(auto y:g[x])prox.pb(y);
	ll y=prox.back();
	prox.pop_back();
	go(y);
}

vv tra[MAXN];
void dfs(ll x){
	good[x]=1;
	for(auto y:tra[x])if(!good[y])dfs(y);
}

int main(){FIN;
	ll n,m; cin>>n>>m;
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		tra[v].pb(u);
	}
	dfs(n-1);
	fore(y,0,n)if(good[y])for(auto x:tra[y])g[x].pb(y);
	
	prox=g[0];
	ll res=0;
	vis[n-1]=1;
	while(SZ(prox)){
		res++;
		ll x=prox.back();
		prox.pop_back();
		go(x);
	}
	cout<<res<<"\n";
	return 0;
}
