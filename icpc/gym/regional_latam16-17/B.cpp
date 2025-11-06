#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a, jet = b; i<jet; i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define JET  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

int main(){
    JET
	ll n,m,a,b; cin>>n>>m>>a>>b;
	vv deg(n);
	vector<vv> g(n);
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
		deg[u]++;
		deg[v]++;
	}
	vv vis(n);
	ll k=n;
	priority_queue<ii> big,small;
	auto agr=[&](ll x, ll w){
		auto &pq=w?big:small;
		ll val=deg[x];
		if(!w)val=-val;
		pq.push({val,x});
	};
	auto saca=[&](ll x){
		k--;
		vis[x]=1;
		for(auto y:g[x])if(!vis[y]){
			deg[y]--;
			fore(w,0,2)agr(y,w);
		}
	};
	fore(x,0,n)fore(w,0,2)agr(x,w);
	while(k>0){
		ll x=small.top().snd;
		if(vis[x]){small.pop(); continue;}
		if(deg[x]<a)small.pop(),saca(x);
		else {
			x=big.top().snd;
			if(vis[x]){big.pop(); continue;}
			if(deg[x]>k-1-b)big.pop(),saca(x);
			else break;
		}
	}
	cout<<k<<"\n";
    return 0;
}