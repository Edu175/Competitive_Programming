#include <bits/stdc++.h>
#include "train.h"
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ioi=b;i<ioi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto dfhg:v)cout<<dfhg<<" ";cout<<endl;}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=5005;

vector<ll>g[MAXN],tra[MAXN];
ll ch[MAXN],w[MAXN];
ll n;
vector<ll>ord;
ll vis[MAXN];
void dfs1(ll x){
	vis[x]=1;
	for(auto y:g[x])if(!vis[y])dfs1(y);
	ord.pb(x);
}
ll qcmp=0,cmp[MAXN];
void dfs2(ll x){
	vis[x]=1;
	cmp[x]=qcmp;
	for(auto y:tra[x])if(!vis[y])dfs2(y);
}

void scc(){
	fore(x,0,n)for(auto y:g[x])tra[y].pb(x);
	fore(x,0,n)if(!vis[x])dfs1(x);
	mset(vis,0);
	reverse(ALL(ord));
	for(auto x:ord)if(!vis[x]){
		dfs2(x);
		qcmp++;
	}
}

vector<ll>g2[MAXN];
ll dp[MAXN],is[MAXN],cyc[MAXN];
void f(ll x){
	vis[x]=1;
	dp[x]=is[x]&&cyc[x];
	for(auto y:g2[x]){
		if(!vis[y])f(y);
		// cout<<x<<","<<y<<"\n";
		dp[x]|=dp[y];
	}
}
std::vector<int> who_wins(std::vector<int> A, std::vector<int> R, std::vector<int> U, std::vector<int> V){
	fore(i,0,SZ(U))g[U[i]].pb(V[i]);
	n=SZ(A);
	fore(i,0,n)w[i]=A[i],ch[i]=R[i];
	
	scc();
	ll n2=qcmp;
	// fore(i,0,n)cout<<cmp[i]<<" ";;cout<<"\n";
	fore(x,0,n)for(auto y:g[x]){
		auto u=cmp[x],v=cmp[y];
		if(u==v)cyc[u]=1;
		g2[u].pb(v);
	}
	
	fore(x,0,n)is[cmp[x]]|=ch[x];
	if(!w[0]){
		fore(i,0,n)is[i]^=1;
	}
	
	mset(vis,0);
	fore(x,0,n2)if(!vis[x])f(x);
	
	vector<int>res(n);
	fore(i,0,n)res[i]=dp[cmp[i]];
	if(!w[0]){
		fore(i,0,n)res[i]^=1;
	}
	return res;
}
