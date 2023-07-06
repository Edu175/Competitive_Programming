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

struct edge{
	ll to,w,s,p; // to, weight, start, periodicidad
	edge(){}
	edge(ll to, ll w, ll s, ll p):to(to),w(w),s(s),p(p){}
};
vector<edge>G[MAXN],g[MAXN]; // normal, invertido
ll n;
ll dis[MAXN];
void dijkstra(ll st, ll t){
	mset(dis,-1);
	priority_queue<ii>pq;
	dis[st]=t; pq.push({t,st});
	while(SZ(pq)){
		auto f=pq.top(); pq.pop();
		ll x=f.snd,d=f.fst;
		if(d<dis[x])continue;
		for(auto i:g[x]){
			d-=i.w;
			cout<<x<<" "<<d<<": "<<i.to<<" "<<i.w<<" "<<i.s<<" "<<i.p;
			if(d>=i.s){
				ll di=d-(d%i.p-i.s%i.p+i.p)%i.p;
				cout<<": "<<di;
				if(di>dis[i.to])dis[i.to]=di,pq.push({di,i.to});
			}
			cout<<"\n";
		}
	}
}
int main(){FIN;
	ll m,l; cin>>n>>m>>l;
	fore(i,0,m){
		ll u,v,w,s,p; cin>>u>>v>>w>>s>>p;
		G[u].pb(edge(v,w,s,p));
		g[v].pb(edge(u,w,s,p));
	}
	dijkstra(n-1,l);
	cout<<dis[0]<<"\n";
	return 0;
}
