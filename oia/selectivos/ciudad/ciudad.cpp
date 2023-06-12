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
const ll MAXN=1e4+5,INF=1e9;

struct edge{
	ll to,w,id;
	edge(ll to,ll w,ll id):to(to),w(w),id(id){}
};
vector<edge>g[MAXN],g1[MAXN];
ll d[5][MAXN];
vector<ll>ed[5][MAXN];

void dijkstra(ll s){
	fore(i,0,5)fore(j,0,MAXN)d[i][j]=INF;
	d[0][s]=0;
	priority_queue<pair<ii,ll>>pq;
	pq.push({{0,0},s});
	while(SZ(pq)){
		auto f=pq.top(); pq.pop();
		ll x=f.snd,c=-f.fst.snd,h=-f.fst.fst;
		//cout<<h<<" "<<x<<" "<<c<<": "<<d[h][x]<<"\n";
		if(d[h][x]<c)continue;
		for(auto i:g[x]){
			ll y=i.to,w=i.w;
			//cout<<"meto0? "<<h<<" "<<y<<" "<<c+w<<": "<<d[h][y]<<"\n";
			if(c+w<d[h][y])d[h][y]=c+w,ed[h][y]=ed[h][x],pq.push({{-h,-d[h][y]},y});
		}
		if(h==2)continue;
		//cout<<h<<" paso\n";
		h++;
		for(auto i:g1[x]){
			ll y=i.to,w=i.w;
			vector<ll>us=ed[h-1][x];
			us.pb(i.id);
			//cout<<"meto1? "<<h<<" "<<y<<" "<<c+w<<": "<<d[h][y]<<"\n";
			if(c+w<d[h][y])d[h][y]=c+w,ed[h][y]=us,pq.push({{-h,-d[h][y]},y});
		}
	}
}
int main(){FIN;
	ifstream cin;   cin.open("ciudad.in", ios::in);
	ofstream cout; cout.open("ciudad.out", ios::out);
	ll n,m,b; cin>>n>>m>>b;
	fore(i,0,m){
		ll u,v,w; cin>>u>>v>>w; u--,v--;
		g[u].pb(edge(v,w,i));
		g[v].pb(edge(u,w,i));
	}
	fore(i,0,b){
		ll u,v,w; cin>>u>>v>>w; u--,v--;
		g1[u].pb(edge(v,w,i));
		g1[v].pb(edge(u,w,i));
	}
	dijkstra(0);
	ll res=INF;
	fore(i,0,3)res=min(res,d[i][n-1]);//,cout<<d[i][n-1]<<" ";
	//cout<<"\n";
	fore(i,0,3){
		if(d[i][n-1]==res){
			cout<<i+1<<" ";
			sort(ALL(ed[i][n-1]));
			for(auto j:ed[i][n-1])cout<<j+1<<" ";
			cout<<res<<"\n";
			break;
		}
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home

