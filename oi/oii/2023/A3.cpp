#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oii=b;i<oii;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto dfkg:v)cout<<dfkg<<" ";cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=2e5+5;

vector<ll>g[MAXN];
ll val[MAXN];
ll bfs(ll s, ll n){
	priority_queue<ii>pq;
	vector<ll>vis(n);
	vis[s]=1;
	ll sum=val[s];
	for(auto y:g[s])if(!vis[y]){
		pq.push({-val[y],y});
		vis[y]=1;
	}
	while(SZ(pq)&&sum>-pq.top().fst){
		auto x=pq.top().snd; pq.pop();
		sum+=val[x];
		for(auto y:g[x])if(!vis[y]){
			pq.push({-val[y],y});
			vis[y]=1;
		}
	}
	return sum;
}
int main(){FIN;
	ll n; cin>>n;
	fore(i,0,n-1){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	fore(i,0,n)cin>>val[i];
	fore(i,0,n){
		cout<<bfs(i,n)<<"\n";
	}
	// cout<<"\n";
	return 0;
}
