#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b;i<jet;i++)
#define pb push_back
#define fst first
#define snd second 
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ld EPS=1e-9;
const ll MAXN=2005;

ld app(ld k, ld d){
	if(abs(k-d)<EPS)return 2*(d+k);
	if(d<k)return 2*sqrtl(d*k)+d+k;
	return -2*sqrtl(d*k)+d+k;
}

vector<ii> g[MAXN];
ll n;
vector<ld> dijkstra(ll s){
	vector<ld> k(n,-1);
	k[s]=0;
	priority_queue<pair<ld,ll>>pq;
	pq.push({k[s],s});
	while(SZ(pq)){
		auto [dis,x]=pq.top(); pq.pop(); dis=-dis;
		if(k[x]<dis)continue;
		for(auto [y,d]:g[x]){
			ld nd=app(k[x],d);
			if(k[y]<-.5||nd<k[y])k[y]=nd,pq.push({-nd,y});
		}
	}
	return k;
}

int main(){JET
	ll m,t; cin>>n>>m>>t;
	fore(i,0,m){
		ll u,v,w1,w2; cin>>u>>v>>w1>>w2; u--,v--;
		ll d=w1*w2;
		g[u].pb({v,d});
		g[v].pb({u,d});
	}
	auto k=dijkstra(0);
	ld res=k[n-1]/t;
	cout<<fixed<<setprecision(15)<<res<<"\n";
}