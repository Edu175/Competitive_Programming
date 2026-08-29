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
typedef vector<ll> vv;
const ll MAXN=2e5+5;

vv g[MAXN];

bool good(ll x){return SZ(g[x])%2==0;}
ll cnt=0;
ll vis[MAXN];

void dfs(ll x){
	vis[x]=1;
	for(auto y:g[x]){
		if(good(y)){
			if(!vis[y])dfs(y);
		}
		else cnt++;
	}
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n){
			vis[i]=0;
			g[i].clear();
		}
		fore(i,0,n-1){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		ll res=0;
		fore(i,0,n)if(good(i)&&!vis[i]){
			dfs(i);
			res+=cnt*(cnt-1)/2;
			cnt=0;
		}
		fore(x,0,n)for(auto y:g[x])if(y<x&&!good(y)&&!good(x))res++;
		cout<<res<<"\n";
	}
	return 0;
}
