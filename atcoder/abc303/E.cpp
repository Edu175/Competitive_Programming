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

vector<ll>g[MAXN];
ll t[MAXN]; //2 if centro, 0,1 if pseudo hoja
void dfs(ll x,ll f,ll c){
	t[x]=c;
	//cout<<x<<": "<<c<<"\n";
	for(auto y:g[x])if(y!=f){
		dfs(y,x,(c+1)%3);
	}
}
int main(){FIN;
	ll n; cin>>n;
	fore(i,0,n-1){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	fore(i,0,n)if(SZ(g[i])==1){
		dfs(i,-1,1);
		break;
	}
	vector<ll>l;
	fore(i,0,n)if(t[i]==2)l.pb(SZ(g[i]));
	sort(ALL(l));
	imp(l);
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
