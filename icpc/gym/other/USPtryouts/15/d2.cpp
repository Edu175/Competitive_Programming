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
bool can(ld vu){
	ld sum=0;
	fore(x,0,n){
		if(d[x]<vu)sum+=d[x];
		else sum+=vu;
	}
	sum=sum/n+k;
	return sum<=vu;
}


int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll m; cin>>n>>m>>k;
		fore(i,0,m){
			ll u,v,w; cin>>u>>v>>w; u--,v--;
			g[u].pb({v,w});
			g[v].pb({u,w});
		}
		d=dijkstra(n-1);
		
		// for(auto i:d){
		// 	cout<<i<<" ";
		// }
		// cout<<"\n";
		
		ld l=0,r=d[0]+5;
		ll it=60;
		while(it--){
			ld m=(l+r)/2;
			if(can(m))r=m;
			else l=m;
		}
		ld res=min(r,(ld)d[0]);
		cout<<fixed<<setprecision(15)<<res<<"\n";
	}
	return 0;
}


/*
15 5 0 
7.666666666666667
15 5 0 
15.000000000000000



v*/