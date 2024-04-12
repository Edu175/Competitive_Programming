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
const ll MAXN=1e4+5;

vector<ii>g[2][MAXN];
ll dist[2][MAXN];
void dijkstra(int x, ll h){
	priority_queue<pair<ll,int> > q;
	dist[h][x]=0;q.push({0,x});
	while(!q.empty()){
		x=q.top().snd;ll c=-q.top().fst;q.pop();
		if(dist[h][x]!=c)continue;
		fore(i,0,g[h][x].size()){
			int y=g[h][x][i].fst; ll c=g[h][x][i].snd;
			if(dist[h][y]<0||dist[h][x]+c<dist[h][y])
				dist[h][y]=dist[h][x]+c,q.push({-dist[h][y],y});
		}
	}
}
int main(){FIN;
	memset(dist,-1,sizeof(dist));
	ll n,m,k,s,t; cin>>n>>m>>k>>s>>t; s--,t--;
	fore(i,0,m){
		ll u,v,w; cin>>u>>v>>w; u--,v--;
		g[0][u].pb({v,w});
		g[1][v].pb({u,w});
	}
	dijkstra(s,0);
	dijkstra(t,1);
	ll res=dist[0][t];
	fore(i,0,k){
		ll u,v,w; cin>>u>>v>>w; u--,v--;
		if(dist[0][u]==-1||dist[1][v]==-1)continue;
		ll nd=dist[0][u]+w+dist[1][v];
		if(res==-1||nd<res)res=nd;
	}
	cout<<res<<"\n";
	return 0;
}
