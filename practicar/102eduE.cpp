#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=2e5+5,INF=1e15;

vector<ii>g[MAXN];
ll d[MAXN][2][2];
void dijkstra(ll s){
	fore(i,0,MAXN)fore(j,0,2)fore(h,0,2)d[i][j][h]=INF;
	priority_queue<vector<ll>>pq; //{-cost, added?, erased?, node}
	pq.push({0,0,0,s});
	d[s][0][0]=0;
	while(SZ(pq)){
		auto f=pq.top(); pq.pop();
		ll di=-f[0],b=f[1],c=f[2],x=f[3];
		if(di>d[x][b][c])continue;
		//cout<<x<<" "<<b<<" "<<c<<": "<<di<<" "<<d[x][b][c]<<"\n";
		for(auto i:g[x]){
			ll y=i.fst,w=i.snd;
			ll &r=d[y][b][c];
			if(di+w<r)r=di+w,pq.push({-r,b,c,y}); // nothing
			ll &r1=d[y][1][c];
			if(!b&&di+2*w<r1)r1=di+2*w,pq.push({-r1,1,c,y}); // add
			ll &r2=d[y][b][1];
			if(!c&&di<r2)r2=di,pq.push({-r2,b,1,y}); // erase
			ll &r3=d[y][1][1];
			if(!c&&!b&&di+w<r3)r3=di+w,pq.push({-r3,1,1,y}); // both
		}
	}
	
}
int main(){FIN;
	ll n,m; cin>>n>>m;
	fore(i,0,m){
		ll u,v,w; cin>>u>>v>>w; u--,v--;
		g[u].pb({v,w});
		g[v].pb({u,w});
	}
	dijkstra(0);
	fore(i,1,n)cout<<d[i][1][1]<<" ";
	cout<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home

