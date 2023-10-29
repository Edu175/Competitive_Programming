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
const ll MAXN=2e5+5;

ll n,r=0;
vector<pair<ll,ll>>g[MAXN];
ll d[MAXN],f[MAXN];
void dfs(ll x){
	if(d[x]>d[r])r=x;
	for(auto y:g[x]){
		if(y.fst==f[x])continue;
		f[y.fst]=x;
		d[y.fst]=d[x]+y.snd;
		dfs(y.fst);
	}
}
int main(){FIN;
	cin>>n;
	ll sum=0;
	fore(i,0,n-1){
		ll u,v,w; cin>>u>>v>>w; u--,v--;
		g[u].pb({v,w});
		g[v].pb({u,w});
		sum+=w;
	}
	mset(f,-1);
	d[0]=0;
	dfs(0);
	mset(f,-1);
	d[r]=0;
	dfs(r);
	cout<<2*sum-d[r]<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
