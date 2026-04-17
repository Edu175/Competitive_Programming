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
const ll MAXN=5005,INF=1e18;
vector<ii> g[MAXN]; // u->[(v,cost)]
ll dist[MAXN];
bool bford(int src, int n){ // O(nm)
	fill(dist,dist+n,INF);dist[src]=0;
	fore(_,0,n)fore(x,0,n)if(dist[x]!=INF)for(auto [y,w]:g[x]){
		dist[y]=min(dist[y],dist[x]+w);
	}
	// fore(x,0,n)cout<<dist[x]<<" ";;cout<<"\n";
	fore(x,0,n)if(dist[x]!=INF)for(auto [y,w]:g[x]){
		if(dist[y]>dist[x]+w) {
			// cerr<<"bad "<<x<<" "<<y<<": "<<dist[x]<<" "<<dist[y]<<" "<<w<<"\n";
			return 0;
		}
	}
	return 1;
}

int main(){FIN;
	vv vals;
	ll n; cin>>n;
	vector<ii> a(n);
	fore(i,0,n){
		cin>>a[i].fst>>a[i].snd; a[i].snd++;
		vals.pb(a[i].fst);
		vals.pb(a[i].snd);
	}
	sort(ALL(vals)); vals.resize(unique(ALL(vals))-vals.begin());
	for(auto &[l,r]:a){
		l=lower_bound(ALL(vals),l)-vals.begin();
		r=lower_bound(ALL(vals),r)-vals.begin();
	}
	ll m=SZ(vals)+1;
	auto can=[&](ll k){
		// cerr<<k<<"\n";
		fore(i,0,m)g[i].clear();
		for(auto [l,r]:a){
			g[l].pb({r,k});
			g[r].pb({l,-1});
		}
		fore(i,0,m-1)g[i+1].pb({i,0});
		return bford(m-1,m);
	};
	ll l=0,r=n+5;
	while(r-l>1){
		ll m=(l+r)/2;
		if(can(m))r=m;
		else l=m;
	}
	ll k=r;
	// cerr<<k<<" k\n";
	can(k);
	vv res;
	fore(i,0,m-1)if(dist[i+1]-dist[i])res.pb(vals[i]);
	cout<<SZ(res)<<"\n";
	imp(res);
	return 0;
}