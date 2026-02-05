#include <bits/stdc++.h> 
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define snd second 
#define fst first
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll) x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

const int maxn = 2e5+100;
const ld eps = 1e-7;
vector<ii> g[maxn];
ll dist[maxn], dist1[maxn];
void dijkstra(int x){
	mset(dist,-1);
	priority_queue<ii> q;
	dist[x] = 0; q.push({0,x});
	while(SZ(q)){
		x = q.top().snd; ll c = -q.top().fst; q.pop();
		if(dist[x] != c) continue;
		for(auto [y,c] : g[x]){
			if(dist[y] < 0 || dist[x] + c < dist[y])
				dist[y] = dist[x] + c, q.push({-dist[y],y});
		}
	}
}


int main(){
	JET
	ll n,m,k; cin>>n>>m>>k;
	fore(i,0,m){
		ll x,y,w; cin>>x>>y>>w;
		x--,y--;
		g[x].pb({y,w});
		g[y].pb({x,w});
	}
	dijkstra(n-1);
	fore(i,0,n) dist1[i] = dist[i];
	dijkstra(0);
	bool b = false;
	vector<pair<ld,ld>> vec;
	fore(i,0,k){
		ll x; ld p;
		cin>>x>>p; x--;
		if(abs(1-p) < eps) b = true;
		vec.pb({dist[x] + dist1[x], p});
	}
	if(!b){
		cout<<"impossible\n";
		return 0; // this may be put in the end with curr = 0
	}
	sort(ALL(vec));
	ld curr = 1;
	ld rta = 0;
	for(auto [d,p] : vec){
		rta+= d*(curr*p);
		// cout<<setprecision(5)<<fixed<<"debug wiht "<<d<<" "<<curr<<" "<<p<<" "<<((ld) d)*(curr*p)<<"\n";
		curr*=(1-p);
	}
	cout<<setprecision(16)<<fixed<<rta<<"\n";
	return 0;
}