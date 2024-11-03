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
const ll MAXN=1e5+5;

vector<ll> g[MAXN];

int main(){FIN;
	ll n,m; cin>>n>>m;
	vv deg(n);
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		g[v].pb(u);
		deg[u]++;
	}
	priority_queue<ll>pq;
	fore(i,0,n)if(!deg[i])pq.push(i);
	vv ord;
	while(SZ(pq)){
		auto x=pq.top(); pq.pop();
		ord.pb(x);
		for(auto y:g[x]){
			deg[y]--;
			if(!deg[y])pq.push(y);
		}
	}
	reverse(ALL(ord));
	for(auto i:ord)cout<<i+1<<" ";;cout<<"\n";
	return 0;
}