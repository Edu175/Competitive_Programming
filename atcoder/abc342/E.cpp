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
const ll MAXN=2e5+5,INF=3e18;

struct edge{
	ll l,d,k,c,u,v;
};
vector<edge> g[MAXN];  // u->[(v,cost)]
ll d[MAXN];
void dijkstra(ll s){
	priority_queue<ii>q;
	q.push({INF,s});
	mset(d,-1);
	d[s]=INF;
	while(SZ(q)){
		auto [w,x]=q.top(); q.pop();
		//cout<<x<<" "<<w<<":\n";
		//cout<<d[x]<<"\n";
		if(d[x]>w||d[x]<0)continue;
		//cout<<"passed\n";
		for(auto e:g[x]){
			ll m=(w-e.l-e.c)/e.d;
			m=min(m,e.k-1);
			ll t=e.l+e.d*m;
			//cout<<e.u<<" --> "<<e.v<<": "<<t<<" "<<w<<"\n";
			if(m<0)continue;
			if(t>d[e.u])q.push({t,e.u}),d[e.u]=t;
		}
	}
}

int main(){FIN;
	ll n,m; cin>>n>>m;
	fore(i,0,m){
		ll l,d,k,c,u,v; cin>>l>>d>>k>>c>>u>>v; u--,v--;
		g[v].pb(edge({l,d,k,c,u,v}));
	}
	dijkstra(n-1);
	fore(i,0,n-1){
		if(d[i]<0)cout<<"Unreachable\n";
		else cout<<d[i]<<"\n";
	}
	return 0;
}
