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

ll d;
vector<ll> g[MAXN];
ll dis[MAXN];
ll c[2][MAXN],deep[2][MAXN];
ll path[2][MAXN];
bool vis[MAXN],vis1[2][MAXN];
void dfs(ll x){
	vis[x]=1;
	c[0][x]+=path[0][x];
	c[1][x]+=path[1][x];
	if(path[0][x])deep[0][x]=dis[x];
	if(path[1][x])deep[1][x]=dis[x];
	for(auto i:g[x]){
		if(!vis[i]){
			dis[i]=dis[x]+1;
			dfs(i);
			c[0][x]+=c[0][i];
			c[1][x]+=c[1][i];
			if(deep[0][i])deep[0][x]=max(deep[0][x],deep[0][i]);
			if(deep[1][i])deep[1][x]=max(deep[1][x],deep[1][i]);
		}
	}
}
ll cnt(ll b, ll x){
	vis1[b][x]=1;
	ll res=0;
	for(auto i:g[x]){
		if(!vis1[b][i]){
			if(c[b][i])res+=2+cnt(b,i);
			else if(deep[b^1][i]-dis[x]>d)res+=2+cnt(b,i);
		}
	}
	//cout<<"cnt "<<x<<": "<<res<<"\n";
	return res;
}

int main(){FIN;
	ll n; cin>>n>>d;
	fore(i,0,n-1){
		ll a,b; cin>>a>>b; a--,b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	fore(i,0,2){
		ll m; cin>>m;
		fore(j,0,m){
			ll a; cin>>a; a--;
			path[i][a]=1;
		}
	}
	dis[0]=0;
	dfs(0);
	/*fore(i,0,2){
		cout<<i<<":\n";
		fore(j,0,n){
			cout<<j<<": c="<<c[i][j]<<" deep="<<deep[i][j]<<"\n";
		}
	}*/
	//cout<<"0:\n";
	ll a=cnt(0,0);
	//cout<<"1:\n";
	ll b=cnt(1,0);
	//cout<<a<<" "<<b<<"\n";
	cout<<a+b<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
