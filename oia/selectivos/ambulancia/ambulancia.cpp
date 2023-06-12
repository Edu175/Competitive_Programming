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
const ll MAXN=1.5e4,INF=1e12;

vector<ii> g[MAXN];
ll n,m,s,e;
ll d[2][MAXN];
void dijkstra(ll x, ll b){
	d[b][x]=0;
	priority_queue<ii,vector<ii>,greater<ii>>pq;
	pq.push({0,x});
	while(SZ(pq)){
		auto u=pq.top(); pq.pop();
		if(d[b][u.snd]!=u.fst)continue;
		for(auto v:g[u.snd]){
			ll di=u.fst+v.snd;
			if(di<d[b][v.fst])d[b][v.fst]=di,pq.push({di,v.fst});
		}
	}
}
vector<ll>g2[MAXN];
ll dp[MAXN];
ll f(ll x){
	ll &res=dp[x];
	if(res!=-1)return res;
	if(x==e)return res=1;
	res=0;
	for(auto i:g2[x])res+=f(i);
	return res;
}
int main(){FIN;
	ifstream cin;   cin.open("ambulancia.in", ios::in);
	ofstream cout; cout.open("ambulancia.out", ios::out);
	cin>>n>>m>>s>>e; s--,e--;
	fore(i,0,m){
		ll u,v,w; cin>>u>>v>>w; u--,v--;
		g[u].pb({v,w});
		g[v].pb({u,w});
	}
	fore(i,0,2)fore(j,0,MAXN)d[i][j]=INF;
	dijkstra(s,0); dijkstra(e,1);
	fore(u,0,n)for(auto v:g[u]){
		if(d[0][v.fst]>d[0][u]&&d[1][v.fst]<d[1][u])g2[u].pb(v.fst);
	}
	mset(dp,-1);
	cout<<f(s)<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home

