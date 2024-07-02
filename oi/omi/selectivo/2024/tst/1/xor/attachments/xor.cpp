#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,omi=b;i<omi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto dfhj:v)cout<<dfhj<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=2e5+5;

vector<ii> g[MAXN];
ll xp[MAXN],vis[MAXN];

void dfs(ll x){
	vis[x]=1;
	for(auto i:g[x]){
		ll y=i.fst,w=i.snd;
		if(vis[y])continue;
		xp[y]=xp[x]^w;
		dfs(y);
	}
}
const ll B=30;
long long Encuentra_xor(int N, vector<int> u, vector<int> v, vector<int> w) {
	ll n=N;
	fore(i,0,n){
		xp[i]=vis[i]=0;
		g[i].clear();
	}
	fore(i,0,n-1){
		g[u[i]].pb({v[i],w[i]});
		g[v[i]].pb({u[i],w[i]});
	}
	xp[0]=0;
	dfs(0);
	// fore(i,0,n)cout<<xp[i]<<" ";;cout<<"\n";
	vector<ll>c(B);
	fore(x,0,n)fore(j,0,B)if(xp[x]>>j&1)c[j]++;
	ll res=0;
	fore(x,0,n)fore(j,0,B){
		if(xp[x]>>j&1)res+=(n-c[j])<<j;
		else res+=c[j]<<j;
	}
	res/=2;
	// cout<<res<<"\n";
	return res;
}