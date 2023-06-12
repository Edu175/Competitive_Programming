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
const ll MAXN=2e3+5,INF=1e17;

ll n;
vector<ll>g[MAXN];
ll c[MAXN];
ll d[MAXN][MAXN][2];
ll bfs(){
	queue<pair<ii,ll>>q;
	q.push({{0,n-1},0});
	d[0][n-1][0]=0;
	while(SZ(q)){
		auto y=q.front(); q.pop();
		ll a=y.fst.fst,b=y.fst.snd,w=y.snd;
		if(a==n-1&&b==0&&!w)return d[a][b][w]/2;
		if(w){
			for(auto i:g[b]){
				if(c[a]==c[i])continue;
				if(d[a][i][w^1]==-1)d[a][i][w^1]=d[a][b][w]+1,q.push({{a,i},w^1});
			}
		}
		else{
			for(auto i:g[a]){
				if(d[i][b][w^1]==-1)d[i][b][w^1]=d[a][b][w]+1,q.push({{i,b},w^1});
			}
		}
	}
	return -1;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll m; cin>>n>>m;
		fore(i,0,n){
			g[i].clear();
			fore(j,0,n)fore(h,0,2)d[i][j][h]=-1;
		}
		fore(i,0,n)cin>>c[i];
		fore(i,0,m){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		
		cout<<bfs()<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
