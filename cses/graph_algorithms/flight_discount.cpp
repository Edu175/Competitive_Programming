#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=1e5+5;

ll cv(ii x){return (x.fst<<1)|x.snd;}
ii cv(ll x){return {x>>1,x&1};}
ll n;
vector<ii> g[MAXN];
ll dijkstra(ll s){
	vector<ll>d(2*n,-1);
	priority_queue<ii>pq;
	d[s]=0;
	pq.push({-d[s],s});
	while(SZ(pq)){
		auto [dis,x]=pq.top();pq.pop(); dis=-dis;
		if(d[x]<dis)continue;
		auto [u,b]=cv(x);
		for(auto [v,w]:g[u]){
			auto go=[&](ll nd, ll y){
				if(d[y]==-1||nd<d[y])d[y]=nd,pq.push({-nd,y});
			};
			go(dis+w,cv({v,b}));
			if(!b)go(dis+w/2,cv({v,1}));
		}
	}
	return min(d[2*(n-1)],d[2*(n-1)+1]);
}

int main(){FIN;
	ll m; cin>>n>>m;
	fore(i,0,m){
		ll u,v,w; cin>>u>>v>>w; u--,v--;
		g[u].pb({v,w});
	}
	cout<<dijkstra(cv({0,0}))<<"\n";
	return 0;
}