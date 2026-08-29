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

vector<vv> g;

ll n;
vv bfs(ll s){
	vv d(n,-1);
	queue<ll> q;
	d[s]=0; q.push(s);
	while(SZ(q)){
		auto x=q.front(); q.pop();
		for(auto y:g[x])if(d[y]==-1){
			d[y]=d[x]+1;
			q.push(y);
		}
	}
	return d;
}

int main(){FIN;
	ll m; cin>>n>>m;
	g.resize(n);
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	ll s=0,t=n-1;
	vv ds=bfs(s);
	vv dt=bfs(t);
	ll good=0;
	ll dist=ds[t]; assert(dt[s]==dist);
	// cerr<<"dist "<<dist<<"\n";
	fore(x,0,n)for(auto y:g[x]){
		ll cur=ds[x]+1+dt[y];
		if(ds[x]!=-1&&dt[y]!=-1&&cur==dist+1)good=1;
		// cerr<<x<<" "<<y<<": "<<cur<<"\n";
	}
	if(good)cout<<"possible\n";
	else cout<<"impossible\n";
	return 0;
}
