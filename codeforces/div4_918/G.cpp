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
const ll MAXN=1005;

vector<ii>g[MAXN];
ll d[MAXN][MAXN];
ll s[MAXN];
ll n;

ll dijkstra(){
	fore(i,0,n)fore(j,0,n)d[i][j]=-1;
	priority_queue<pair<ll,ii>>pq;
	pq.push({0,{0,0}});
	d[0][0]=0;
	while(SZ(pq)){
		auto [di,p]=pq.top(); pq.pop();
		auto [x,b]=p; di=-di;
		//cout<<x<<" "<<b<<endl;
		if(di>d[x][b])continue;
		for(auto [y,w]:g[x]){
			ll nd=s[b]*w+di;
			if(d[y][b]==-1||nd<d[y][b]){d[y][b]=nd,pq.push({-nd,{y,b}});}
			if(d[y][y]==-1||nd<d[y][y]){d[y][y]=nd,pq.push({-nd,{y,y}});}
		}
	}
	ll res=-1;
	fore(i,0,n){
		assert(d[n-1][i]!=-1);
		if(res==-1||d[n-1][i]<res)res=d[n-1][i];
	}
	return res;
}


int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll m; cin>>n>>m;
		fore(i,0,n){
			g[i].clear();
		}
		fore(i,0,m){
			ll u,v,w; cin>>u>>v>>w; u--,v--;
			g[u].pb({v,w});
			g[v].pb({u,w});
		}
		fore(i,0,n)cin>>s[i];
		cout<<dijkstra()<<"\n";
	}
	return 0;
}
