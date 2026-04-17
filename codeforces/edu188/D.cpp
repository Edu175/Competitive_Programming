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

const ll MAXN=2e5+5;

ll c[MAXN];
vv g[MAXN];

vv cant(2);
ll good=1;
void dfs(ll x){
	cant[c[x]]++;
	for(auto y:g[x]){
		if(c[y]!=-1)good&=c[x]!=c[y];
		else {
			c[y]=c[x]^1;
			dfs(y);
		}
	}
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		fore(i,0,n){
			g[i].clear();
			c[i]=-1;
		}
		fore(i,0,m){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		ll res=0;
		fore(x,0,n)if(c[x]==-1){
			cant={0,0}; good=1;
			c[x]=0;
			dfs(x);
			ll q=max(cant[0],cant[1]);
			res+=good*q;
		}
		cout<<res<<"\n";
	}
	return 0;
}
