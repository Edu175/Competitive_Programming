#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oii=b;i<oii;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto dksjfg:v)cout<<dksjfg<<" ";cout<<"\n";}
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> ii;
const ll MAXN=1e5+5;

vector<ii> g[MAXN];
ll n;
ll dijkstra(ll s, ll e){
	vector<ll>d(n,-1);
	priority_queue<ii>pq;
	pq.push({0,s});
	d[s]=0;
	while(SZ(pq)){
		auto [di,x]=pq.top(); pq.pop(); di=-di;
		if(d[x]<di)continue;
		for(auto [y,w]:g[x]){
			ll nd=di+w;
			if(d[y]==-1||nd<d[y])pq.push({-nd,y}),d[y]=nd;
		}
	}
	return d[e];
}



int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll m,k; cin>>n>>m>>k;
		ll a,b,l,r; cin>>a>>b>>l>>r;
		a--,b--;
		fore(i,0,n){
			g[i].clear();
		}
		// cout<<n<<" "<<m<<" "<<k<<endl;
		fore(i,0,m){
			ll u,v,w; cin>>u>>v>>w; u--,v--;
			g[u].pb({v,w});
			g[v].pb({u,w});
			// cout<<u<<" "<<v<<" "<<w<<endl;
		}
		ll res=0;
		fore(x,0,n)fore(y,x+1,n){
			ll is=0;
			for(auto [j,sfkjhg]:g[x])is|=j==y;
			if(is)continue;
			fore(w,l,r+1){
				g[x].pb({y,w});
				g[y].pb({x,w});
				res+=dijkstra(a,b)==k;
				g[x].pop_back();
				g[y].pop_back();
			}
			
		}
		cout<<res<<"\n";
	}
	return 0;
}