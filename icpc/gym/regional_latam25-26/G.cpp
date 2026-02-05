#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=305*305;

ll n,m; // [] both

ll cv(ll i, ll j){return (m+1)*i+j;}
ii cv(ll x){return {x/(m+1),x%(m+1)};}

vector<ii> g[MAXN]; // {to, idx of weight function}
ll r[MAXN],c[MAXN];

void add_edge(ll u, ll v, ll i){
	g[u].pb({v,i});
	g[v].pb({u,i});
}
ll cost(ll idx, ll t){
	ll res=c[idx]+r[idx]*t;
	assert(res>=0);
	return res;
}
ll d[MAXN];
ll s,e; // start, end
ll dijkstra(ll t){ // time
	mset(d,-1);
	priority_queue<ii> pq;
	d[s]=0;
	pq.push({0,s});
	while(SZ(pq)){
		auto [dis,x]=pq.top(); pq.pop(); dis=-dis;
		if(dis!=d[x])continue;
		if(x==e)break; // por el overflow, ahora las dis son <= mxf+mxc = 1e18+1e18 = 2e18 < 9e18
		for(auto [y,idx]:g[x]){
			ll w=cost(idx,t);
			ll nd=dis+w;
			if(d[y]==-1||nd<d[y]){
				d[y]=nd;
				pq.push({-nd,y});
			}
		}
	}
	auto res=d[e];
	assert(res!=-1);
	return res;
}

int main(){FIN;
	ll p,k; cin>>n>>m>>p>>k;
	fore(i,0,n)fore(j,0,m)cin>>c[cv(i,j)];
	fore(i,0,n)fore(j,0,m)cin>>r[cv(i,j)];
	vector<vv> bl(n,vv(m));
	fore(_,0,p){
		ll i0,j0,i1,j1; cin>>i0>>j0>>i1>>j1;
		i0--,j0--,i1--,j1--;
		if(i0>i1||j0>j1)swap(i0,i1),swap(j0,j1);
		bl[i0][j0]|=1+(j0==j1);
	}
	ll vac=(n+1)*(m+1);
	fore(i,0,n)fore(j,0,m){
		ll x=cv(i,j);
		// horizontal
		ll w=x;
		if(i&&!(bl[i-1][j]&2))w=vac;
		add_edge(x,cv(i,j+1),w);
		// hor desde la casilla de arriba
		if(i&&w!=vac)add_edge(x,cv(i,j+1),cv(i-1,j));
		
		// vertical
		w=x;
		if(j&&!(bl[i][j-1]&1))w=vac;
		add_edge(x,cv(i+1,j),w);
		// vertical desde la casilla de la izquierda
		if(j&&w!=vac)add_edge(x,cv(i+1,j),cv(i,j-1));
		
		// diag abajo
		w=x;
		add_edge(x,cv(i+1,j+1),w);
	}
	fore(i,1,n+1)fore(j,0,m){ // diag arriba
		ll w=cv(i-1,j);
		add_edge(cv(i,j),cv(i-1,j+1),w);
	}
	// bordes (sin las de al lado de primera o ultima casilla)
	fore(j,0,m){
		if(j!=0)add_edge(cv(0,j),cv(0,j+1),vac);
		if(j+1!=m)add_edge(cv(n,j),cv(n,j+1),vac);
	}
	fore(i,0,n){
		if(i!=0)add_edge(cv(i,0),cv(i+1,0),vac);
		if(i+1!=n)add_edge(cv(i,m),cv(i+1,m),vac);
	}
	s=cv(n,0),e=cv(0,m);
	
	auto sub=[&](ll t){
		return dijkstra(t)<dijkstra(t+1);
	};
	
	ll lo=-1,hi=k;
	while(hi-lo>1){
		ll mid=(lo+hi)/2;
		if(sub(mid))lo=mid;
		else hi=mid;
	}
	ll t=hi;
	// cerr<<"t: "<<t<<"\n";
	ll res=dijkstra(t);
	cout<<res<<"\n";
	return 0;
}