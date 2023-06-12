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
ll c[MAXN],q[2];
bool vis[MAXN];
void dfs(ll x, ll b){
	vis[x]=1;
	c[x]=b;
	q[b]++;
	for(auto i:g[x])if(!vis[i])dfs(i,b^1);
}
ll w[MAXN],p=0,god=0;
void dfs2(ll x){
	vis[x]=1;
	if(c[x]==p)w[x]=SZ(g[x]);
	ll sum=0;
	for(auto i:g[x]){
		if(!vis[i])dfs2(i);
		sum+=w[i];
	}
	if(w[x]==sum)god++;
}
int main(){FIN;
	ll n; cin>>n;
	fore(i,0,n-1){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(0,0);
	fore(i,0,n)w[i]=1,vis[i]=0;
	if(q[1]>q[0])p=1;
	dfs2(0);
	ll sum=0;
	fore(i,0,n)sum+=w[i];
	cout<<god<<" "<<sum<<"\n";
	fore(i,0,n)cout<<w[i]<<" ";
	cout<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home

