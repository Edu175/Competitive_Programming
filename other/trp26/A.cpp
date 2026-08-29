#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){FIN;
	ll n,m,k; cin>>n>>m>>k;
	vector<vector<ii>> g(n);
	fore(i,0,m){
		ll u,v,w; cin>>u>>v>>w; u--,v--;
		g[u].pb({v,w});
		g[v].pb({u,w});
	}
	queue<ii> q;
	vector<vv> d(n,vv(k+1,-1));
	d[0][0]=0; q.push({0,0});
	ll res=n+5;
	while(SZ(q)){
		auto [x,c]=q.front(); q.pop();
		if(x==n-1)res=min(res,d[x][c]);
		for(auto [y,w]:g[x]){
			ll pc=c+w;
			if(pc>k)continue;
			if(d[y][pc]==-1)d[y][pc]=d[x][c]+1,q.push({y,pc});
		}
	}
	if(res>=n+5)res=-1;
	cout<<res<<"\n";
	return 0;
}
