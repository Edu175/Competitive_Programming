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
const ll MAXN=2e5+5;

vector<ii> g[MAXN];

vector<ll> d[2];

ll n;
vector<ll> dijkstra(ll s){
	vector<ll>d(n,-1);
	priority_queue<ii>pq;
	pq.push({0,s});
	d[s]=0;
	while(SZ(pq)){
		auto [dx,x]=pq.top(); pq.pop(); dx=-dx;
		if(d[x]<dx)continue;
		for(auto [y,w]:g[x])if(d[y]==-1||dx+w<d[y]){
			d[y]=dx+w;
			pq.push({-d[y],y});
		}
	}
	return d;
}


int main(){FIN;
	while(cin>>n){
		ll m; cin>>m;
		fore(i,0,n){
			g[i].clear();
		}
		fore(i,0,m){
			ll u,v,w; cin>>u>>v>>w; u--,v--;
			g[u].pb({v,w});
			g[v].pb({u,w});
		}
		d[0]=dijkstra(0);
		d[1]=dijkstra(n-1);
		ll res=0;
		/*fore(i,0,n){
			cout<<i<<": "<<d[0][i]<<"" <<d[1][i]<<"\n";
		}*/
		vector<ll>p;
		fore(i,0,n)res+=d[0][i],p.pb(d[1][i]-d[0][i]);
		sort(ALL(p));
		fore(i,0,n/2)res+=p[i];
		res*=2;
		cout<<res<<"\n";
	}
	return 0;
}
