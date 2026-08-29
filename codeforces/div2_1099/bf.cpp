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

vector<vv> G;
ll n;
vv all;

void doit(vv v){
	auto g=G;
	ll sz=n;
	queue<ll> q;
	vv deg(n);
	fore(i,0,n){
		deg[i]=SZ(g[i]);
		if(deg[i]<=1)q.push(i);
	}
	vv vis(n);
	while(SZ(q)){
		auto x=q.front(); q.pop();
		vis[x]=1;
		if(count(ALL(v),x))continue;
		sz--;
		for(auto y:g[x])if(!vis[y]&&(--deg[y])<=1)q.push(y);
	}
	all[sz]++;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll k; cin>>n>>k;
		G.clear(); G.resize(n);
		fore(i,0,n-1){
			ll u,v; cin>>u>>v; u--,v--;
			G[u].pb(v);
			G[v].pb(u);
		}
		all.resize(n+5);
		fore(i,0,n)fore(j,i+1,n)fore(k,j+1,n)doit({i,j,k});
		cout<<all[k]<<"\n";
	}
	return 0;
}
