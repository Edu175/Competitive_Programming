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
const ll MAXN=2e+5+5;
ll n;
vector<ll>g[MAXN];
bool vis[MAXN];
ll flag;
void dfs(ll x){
	vis[x]=1;
	if(SZ(g[x])!=2)flag=0;
	for(auto i:g[x])if(!vis[i])dfs(i);
}
int main(){FIN;
	ll m; cin>>n>>m;
	fore(i,0,m){
		ll u,v;char w,x; cin>>u>>w>>v>>x; u--,v--;
		g[u].pb(v); g[v].pb(u);
	}
	ll a=0,b=0;
	fore(i,0,n){
		if(!vis[i]){
			flag=1;
			dfs(i);
			if(flag)a++;
			else b++;
		}
	}
	cout<<a<<" "<<b<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
