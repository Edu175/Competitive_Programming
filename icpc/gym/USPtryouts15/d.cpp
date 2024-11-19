#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second 
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=2e5+5;
ll n;
vector<ii> g[MAXN];
vv dijkstra(ll s){
	vv d(n,-1);
	d[s]=0;
	priority_queue<ii> pq;
	pq.push({0,s});
	while(SZ(pq)){
		auto [dis,x]=pq.top(); pq.pop(); dis=-dis;
		if(d[x]<dis)continue;
		for(auto [y,w]:g[x]){
			ll nd=dis+w;
			if(d[y]==-1||nd<d[y])d[y]=nd,pq.push({-nd,y});
		}
	}
	return d;
}
vv d;
ll k;
const ld EPS=1e-9;
const ll INF=2e10+5;
int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll m; cin>>n>>m>>k;
		fore(i,0,n){
			g[i].clear();
		}
		fore(i,0,m){
			ll u,v,w; cin>>u>>v>>w; u--,v--;
			g[u].pb({v,w});
			g[v].pb({u,w});
		}
		d=dijkstra(n-1);
		for(auto &i:d)if(i==-1)i=INF;
		ld res=d[0];
		sort(ALL(d));
		ll sum=0;
		// for(auto i:d)cout<<i<<" ";;cout<<"\n";
		fore(i,1,n){
			ld vu=ld(sum+k*n)/i;
			// ll p=upper_bound(ALL(d),vu+EPS)-d.begin();
			res=min(res,vu);
			// cout<<"res "<<res<<"\n";
			// cout<<i<<": "<<vu<<" "<<p<<"\n";
			sum+=d[i];
		}
		// cout<<res<<"\n";
		cout<<fixed<<setprecision(15)<<res<<"\n";
	}
	return 0;
}


/*

0 5 15 
0: -0.5 0
1: -1 0
2: inf 3
-0.500000000000000
0 5 15 
0: -50.000000000000000 0
1: -100.000000000000000 0
2: inf 3
-50.000000000000000




v*/