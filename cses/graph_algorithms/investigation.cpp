#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define impp(v) {for(auto gdljh:v)cout<<gdljh.fst<<","<<gdljh.snd<<" "; cout<<"\n";}
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=1e5+5,MOD=1e9+7;

ll add(ll a, ll b){a+=b;if(a>=MOD)a-=MOD;return a;}
vector<ii> g[MAXN],gr[MAXN];
ll n;
vector<ll> dijkstra(ll s, ll b){
	vector<ll>d(n,-1);
	priority_queue<ii>pq;
	pq.push({0,s});
	d[s]=0;
	while(SZ(pq)){
		auto [dis,x]=pq.top(); pq.pop(); dis=-dis;
		if(d[x]<dis)continue;
		for(auto [y,w]:(b?gr:g)[x]){
			ll nd=dis+w;
			if(d[y]==-1||nd<d[y])d[y]=nd,pq.push({-nd,y});
		}
	}
	return d;
}
vector<ll>dag[MAXN];

int main(){FIN;
	ll m; cin>>n>>m;
	fore(i,0,m){
		ll u,v,w; cin>>u>>v>>w; u--,v--;
		g[u].pb({v,w});
		gr[v].pb({u,w});
	}
	vector<ll>d[2];
	d[0]=dijkstra(0,0);
	d[1]=dijkstra(n-1,1);
	ll mind=d[0][n-1];
	fore(x,0,n)if(d[0][x]!=-1){
		for(auto [y,w]:g[x])if(d[1][y]!=-1){
			if(d[0][x]+w+d[1][y]==mind)dag[x].pb(y);
		}
	}
	/*fore(i,0,n){
		cout<<i<<": ";
		imp(dag[i]);
	}*/
	vector<ll>num(n),mx(n),mn(n),vis(n);
	auto dfs=[&](ll x, auto &&dfs)->void{
		vis[x]=1;
		if(x==n-1){
			num[x]=1,mn[x]=0;
			return;
		}
		mn[x]=n+5;
		for(auto y:dag[x]){
			if(!vis[y])dfs(y,dfs);
			mx[x]=max(mx[x],mx[y]);
			mn[x]=min(mn[x],mn[y]);
			num[x]=add(num[x],num[y]);
		}
		mx[x]++,mn[x]++;
	};
	dfs(0,dfs);
	cout<<mind<<" "<<num[0]<<" "<<mn[0]<<" "<<mx[0]<<"\n";
	return 0;
}
