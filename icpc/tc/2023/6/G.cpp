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

int main(){FIN;
	ll n,m; cin>>n>>m;
	vv deg(n);
	vector<vv> vis(n,vv(n));
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		deg[u]++; deg[v]++;
		vis[u][v]=vis[v][u]=1;
	}
	fore(i,0,n)vis[i][i]=1;
	vv mx(n);
	auto recalc=[&](ll x){
		mx[x]=-n-5;
		fore(y,0,n)if(!vis[x][y]){
			mx[x]=max(mx[x],deg[y]);
			mx[y]=max(mx[y],deg[x]);
		}
	};
	auto agr=[&](ll x, ll y){
		vis[x][y]=vis[y][x]=1;
		deg[x]++;
		deg[y]++;
		recalc(x);
		recalc(y);
	};
	auto get=[&]()->ii {
		ll cur=0;
		fore(x,0,n)cur=max(cur,deg[x]+mx[x]);
		assert(cur>=0);
		fore(x,0,n)if(deg[x]+mx[x]==cur){
			fore(y,0,n)if(!vis[x][y]&&deg[y]==mx[x])return {x,y};
			assert(0);
		}
		assert(0);
	};
	fore(i,0,n)recalc(i);
	ll cnt=m;
	ll k=n*n+5;
	while(cnt<n*(n-1)/2){
		auto [x,y]=get();
		// cout<<x<<" "<<y<<endl;
		k=min(k,deg[x]+deg[y]);
		cnt++;
		agr(x,y);
	}
	cout<<k<<"\n";
	return 0;
}
