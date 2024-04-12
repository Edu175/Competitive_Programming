#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=2e5+5;

vector<ii>g[MAXN];
ll xp[MAXN];
void dfs(ll x, ll f=-1){
	for(auto [y,w]:g[x])if(y!=f){
		xp[y]^=w^xp[x];
		dfs(y,x);
	}
}
int main(){FIN;
	ll n,k; cin>>n>>k;
	fore(i,0,n-1){
		ll u,v,w; cin>>u>>v>>w; u--,v--;
		g[u].pb({v,w});
		g[v].pb({u,w});
	}
	dfs(0);
	map<ll,ll>c;
	ll res=0;
	fore(i,0,n){
		res+=c[k^xp[i]];
		c[xp[i]]++;
	}
	cout<<res<<"\n";
	return 0;
}
