#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=2e5+5,INF=1e14;

// vector<vector<ii>> g(MAXN),tra(MAXN),dag(MAXN);
ll n;
vector<ii> g[MAXN];
ll dijkstra(ll s, ll t){
	vv d(n,-1);
	priority_queue<ii>pq;
	d[s]=0;
	pq.push({d[s],s});
	while(SZ(pq)){
		auto [dis,x]=pq.top(); pq.pop(); dis=-dis;
		if(d[x]!=dis)continue;
		for(auto [y,w]:g[x]){
			ll nd=dis+w;
			if(d[y]==-1||nd<d[y]){
				d[y]=nd;
				pq.push({-nd,y});
			}
		}
	}
	return d[t];
}

void saca(ll u, ll v, ll w){
	g[u].erase(find(ALL(g[u]),ii({v,w})));
}
void pone(ll u, ll v, ll w){
	g[u].pb({v,w});
}

int main(){
	JET
	ll m,s,t; cin>>n>>m>>s>>t; s--,t--;
	vector<array<ll,3>> ed;
	fore(i,0,m){
		ll u,v,w; cin>>u>>v>>w; u--,v--;
		pone(u,v,w);
		ed.pb({u,v,w});
	}
	ll dis=dijkstra(s,t);
	if(dis==-1){
		cout<<"invalido\n";
		cerr<<"invalido\n";
		exit(0);
	}
	fore(i,0,m){
		auto [u,v,w]=ed[i];
		saca(u,v,w);
		ll nd=dijkstra(s,t);
		if(nd==-1||nd>dis){
			cout<<"YES\n";
			pone(u,v,w);
			continue;
		}
		ll we=-1;
		fore(nw,1,w){
			pone(u,v,nw);
			if(dijkstra(s,t)<dis)we=nw;
			saca(u,v,nw);
		}
		pone(u,v,w);
		if(we!=-1)cout<<"CAN "<<w-we<<"\n";
		else cout<<"NO\n";
	}
	return 0;
}