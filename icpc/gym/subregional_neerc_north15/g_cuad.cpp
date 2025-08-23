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

vv g[MAXN];
bitset<MAXN> vis,reach[MAXN];
void dfs(ll x){
	vis[x]=1;
	reach[x][x]=1;
	for(auto y:g[x]){
		if(!vis[y])dfs(y);
		reach[x]|=reach[y];
	}
}

int main(){FIN;
	ll n,m,k; cin>>n>>m>>k;
	priority_queue<ll>pq;
	vv ind(n);
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		ind[v]++;
	}
	fore(i,0,n)if(!ind[i])pq.push(-i);
	vv ord;
	while(SZ(pq)){
		auto x=pq.top(); pq.pop(); x=-x;
		ord.pb(x);
		for(auto y:g[x]){
			ind[y]--;
			if(!ind[y])pq.push(-y);
		}
	}
	auto reachability=[&](){
		vis.reset();
		fore(x,0,n)if(!vis[x])dfs(x);
	};
	vv pos(n);
	fore(x,0,n){
		if(!vis[x])dfs(x);
		for(auto y:g[x])ind[y]++;
	}
	fore(x,0,n){
		pos[ord[x]]=x;
		if(!ind[x])pq.push(-x);
	}
	vector<ii>res;
	bitset<MAXN>sac;
	vv ans;
	vector<ii>ed;
	// fore(i,0,n){
	// 	cout<<i<<": ";
	// 	fore(j,0,n)if(reach[i][j])cout<<j<<" ";;cout<<"\n";
	// }
	while(SZ(pq)){
		auto x=pq.top(); pq.pop(); x=-x;
		ll p=-1;
		fore(i,0,n)if(!sac[i]&&!reach[x][i]){
			if(p==-1||pos[p]<pos[i])p=i;
		}
		cout<<x<<":\n";
		if(k&&p!=-1){
			cout<<"encontro "<<p<<"\n";
			k--;
			ed.pb({p,x});
			g[p].pb(x);
			// reach[p]|=reach[x];
			reachability();
			ind[x]++;
		}
		else {// lo saco
			ans.pb(x); sac[x]=1;
			for(auto y:g[x])if(!--ind[y])pq.push(-y);
		}
	}
	for(auto i:ans)cout<<i+1<<" ";;cout<<"\n";
	return 0;
}
