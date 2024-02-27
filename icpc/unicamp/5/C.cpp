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
const ll MAXN=1e6+5;

vector<ll>g[MAXN];
ll c[MAXN];
ll vis[MAXN];
ll avs=0,usa=1;
void dfs(ll x, ll w){
	c[x]=w;
	vis[x]=1;
	for(auto y:g[x]){
		if(!vis[y])dfs(y,w^1);
		else if(c[x]==c[y])avs++,usa=c[x];
	}
}


int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		fore(i,0,n){
			g[i].clear();
			vis[i]=0;
		}
		avs=0,usa=1; //
		fore(i,0,m){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		dfs(rand()%n,rand()%2);
		if(avs>1)cout<<"NO\n";
		else {
			cout<<"YES\n";
			fore(i,0,n){
				if(usa==0)c[i]^=1;
				cout<<c[i];
			}
			cout<<"\n";
		}
	}
	return 0;
}
