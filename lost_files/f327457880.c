#include "longesttrip.h"
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
typedef int ll;
typedef pair<ll,ll> ii;
#define ask are_connected
const ll MAXN=300;

vector<ll>g[MAXN];
ll n,d;

vector<ll>res;
vector<ll>p;
ll vis[MAXN];
void dfs(ll x){
	vis[x]=1;
	p.pb(x);
	if(SZ(p)>SZ(res))res=p;
	for(auto y:g[x])if(!vis[y])dfs(y);
	p.pop_back();
}

vector<int> longest_trip(int N, int D){
	n=N,d=D;
	fore(i,0,n){
		g[i].clear();
	}
	res.clear();
	fore(i,0,n)fore(j,i+1,n){
		if(ask({i},{j}))g[i].pb(j),g[j].pb(i);
	}
	fore(x,0,n){
		fore(i,0,n)vis[i]=0;
		p.clear();
		dfs(x);
	}
	return res;
}

