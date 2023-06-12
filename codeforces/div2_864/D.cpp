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

vector<ll> g[MAXN];
ll sz[MAXN],val[MAXN],a[MAXN],f[MAXN];
set<ii> son[MAXN];
void dfs(ll x){
	sz[x]=1;
	val[x]=a[x];
	for(auto y:g[x])if(y!=f[x]){
		f[y]=x;
		dfs(y);
		sz[x]+=sz[y];
		val[x]+=val[y];
		son[x].insert({-sz[y],y});
	}
}
int main(){FIN;
	ll n,q; cin>>n>>q;
	//cout<<"scan\n";
	fore(i,0,n)cin>>a[i];
	fore(i,0,n-1){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	//cout<<"dfs\n";
	f[0]=-1;
	dfs(0);
	/*fore(i,0,n){
		cout<<i<<": "<<f[i]<<" "<<sz[i]<<" "<<val[i]<<": ";
		for(auto j:son[i])cout<<j.fst<<","<<j.snd<<" ";
		cout<<"\n";
	}*/
	while(q--){
		ll ty,x; cin>>ty>>x; ty--,x--;
		if(!ty)cout<<val[x]<<"\n";
		else{
			if(!SZ(son[x]))continue;
			ll s=(*(son[x].begin())).snd;
			ll fa=f[x];
			son[fa].erase((ii){-sz[x],x});
			son[x].erase((ii){-sz[s],s});
			val[x]-=val[s];
			val[s]+=val[x];
			sz[x]-=sz[s];
			sz[s]+=sz[x];
			son[fa].insert((ii){-sz[s],s});
			son[s].insert((ii){-sz[x],x});
			f[s]=fa;
			f[x]=s;
		}
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
