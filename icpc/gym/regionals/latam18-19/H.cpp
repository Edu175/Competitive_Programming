#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

const int maxn = 1e4+100;
vector<pair<int,ii>> g[maxn];
ll dist[maxn];
ll put[maxn];
ll rta = 0;
void dijkstra(int x){
	mset(dist,-1);
	priority_queue<pair<ii,int>> q;
	dist[x] = 0; q.push({{0,0},x});
	while(SZ(q)){
		x = q.top().snd;
		auto[l,c] = q.top().fst;
		l = -l; c = -c;
		q.pop();
		if(put[x]){
			// cout<<"ignore node "<<x<<" arista "<<l<<" "<<c<<"\n";
			continue;
		}
		put[x] = 1;
		// cout<<"put node "<<x<<" arista "<<l<<" "<<c<<"\n";
		rta+=c;
		for(auto [y,lc]:g[x]){
			auto[l,c] = lc;
			if(dist[y]<0 || dist[x] + l <= dist[y]) dist[y] = dist[x]+l, q.push({{-dist[y],-c},y});
		}
	}
}

int main(){
	JET
	ll n,m; cin>>n>>m;
	fore(i,0,m){
		ll a,b,l,c; cin>>a>>b>>l>>c;
		a--,b--;
		g[a].pb({b,{l,c}});
		g[b].pb({a,{l,c}});
	}
	dijkstra(0);
	cout<<rta<<"\n";
	return 0;
}