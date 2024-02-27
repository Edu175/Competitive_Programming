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
const ll MAXN=1e5+5;

vector<ll> g[MAXN];
ll ind[MAXN];

int main(){FIN;
	ll n,m; cin>>n>>m;
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		ind[v]++;
	}
	priority_queue<ll>pq;
	vector<ll>ord;
	fore(i,0,n)if(!ind[i])pq.push(-i);
	while(SZ(pq)){
		auto x=pq.top(); pq.pop(); x=-x;
		ord.pb(x);
		for(auto y:g[x]){
			ind[y]--;
			if(!ind[y])pq.push(-y);
		}
	}
	for(auto i:ord)cout<<i+1<<" ";
	cout<<"\n";
	return 0;
}
