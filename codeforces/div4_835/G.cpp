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
const ll MAXN=1e5+5;

vector<pair<ll,ll>>g[MAXN];
bool vis[2][MAXN];
ll xr[2][MAXN];
ll a,b;
void dfs(ll x,ll m){
	for(auto i:g[x]){
		if(!vis[m][i.fst]){
			vis[m][i.fst]=1;
			if(m==0&&i.fst==b&&(xr[m][x]^i.snd)!=0)continue;
			xr[m][i.fst]=xr[m][x]^i.snd;
			dfs(i.fst,m);
		}
	}
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n>>a>>b; a--,b--;
		fore(i,0,n-1){
			ll u,v,w; cin>>u>>v>>w;u--,v--;
			g[u].pb({v,w});
			g[v].pb({u,w});
		}
		xr[0][a]=0;
		vis[0][a]=1;
		dfs(a,0);
		xr[1][b]=0;
		vis[1][b]=1;
		dfs(b,1);
		set<ll>st;
		fore(i,0,n){
			if(vis[0][i])st.insert(xr[0][i]);
			//cout<<xr[0][i]<<" ";
		}
		//cout<<"\n";
		ll flag=0;
		fore(i,0,n){
			if(i==b)continue;
			if(vis[1][i]&&st.count(xr[1][i]))flag=1;
			//cout<<xr[1][i]<<" ";
		}
		//cout<<"\n";
		if(flag)cout<<"YES\n";
		else cout<<"NO\n";
		fore(i,0,n){
			g[i].clear();
			vis[0][i]=0;
			vis[1][i]=0;
			xr[0][i]=0;
			xr[1][i]=0;
		}
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
