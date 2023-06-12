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

vector<pair<ll,ll>>g[MAXN];
ll f[MAXN];
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n){
			g[i].clear();
			f[i]=-1;
		}
		fore(i,0,n-1){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb({v,i});
			g[v].pb({u,i});
		}
		set<pair<ll,ll>>st;
		f[0]=-1;
		for(auto i:g[0])st.insert({i.snd,i.fst}),f[i.fst]=0;
		ll res=0;
		while(SZ(st)){
			res++;
			pair<ll,ll> p={-1,-1};
			while(st.lower_bound(p)!=st.end()){
				p=*st.lower_bound(p);
				for(auto i:g[p.snd])if(i.fst!=f[p.snd]){
					f[i.fst]=p.snd;
					st.insert({i.snd,i.fst});
				}
				st.erase(p);
			}
		}
		cout<<res<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
