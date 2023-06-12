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
const ll MAXN=3e5+5;

set<ll>g[MAXN];
int main(){FIN;
	ll n,q; cin>>n>>q;
	ll c=n;
	while(q--){
		ll ty; cin>>ty; ty--;
		if(!ty){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].insert(v);
			g[v].insert(u);
			c-=(SZ(g[u])==1)+(SZ(g[v])==1);
		}
		else {
			ll x; cin>>x; x--;
			for(auto i:g[x]){
				g[i].erase(x);
				c+=(SZ(g[i])==0);
			}
			c+=(SZ(g[x])>0);
			g[x].clear();
		}
		cout<<c<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
