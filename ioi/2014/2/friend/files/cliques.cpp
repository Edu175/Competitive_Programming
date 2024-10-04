#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ioi=b;i<ioi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto fdgkj:v)cout<<fdgkj<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=1e5+5;
vector<ll> g[MAXN];
ll n;
ll vis[MAXN],c[MAXN];
ll mx;
void dfs(ll x){
	vis[x]=1;
	mx=max(mx,c[x]);
	for(auto y:g[x])if(!vis[y])dfs(y);
}

int findSample(int N,int CS[],int p[],int t[]){
	n=N;
	fore(i,0,n)c[i]=CS[i];
	fore(i,1,n){
		g[p[i]].pb(i);
		g[i].pb(p[i]);
	}
	ll res=0;
	fore(i,0,n)if(!vis[i]){
		mx=0;
		dfs(i);
		res+=mx;
	}
	return res;
}
