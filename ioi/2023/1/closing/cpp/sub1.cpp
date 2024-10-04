#include "closing.h"
#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=2e5+5;

vector<ll> d[2];
ll b[MAXN][2];
ll n,k;
vector<ii> g[MAXN];
void dfs(ll x, vector<ll> &d){
	for(auto [y,w]:g[x])if(d[y]==-1){
		d[y]=d[x]+w;
		dfs(y,d);
	}
}
ll disjoint(){
	vector<ll>v;
	fore(i,0,n)v.pb(b[i][0]);
	sort(ALL(v));
	ll ki=0,res=0;
	// imp(v);
	fore(i,0,SZ(v)){
		if(ki+v[i]<=k)res++,ki+=v[i];
	}
	return res;
}
int max_score(int N, int x, int y, long long K,
              std::vector<int> U, std::vector<int> V, std::vector<int> W)
{
	n=N,k=K;
	fore(i,0,n)g[i].clear();
	fore(i,0,n-1){
		g[U[i]].pb({V[i],W[i]});
		g[V[i]].pb({U[i],W[i]});
	}
	d[0]=d[1]=vector<ll>(n,-1);
	d[0][x]=0; dfs(x,d[0]);
	d[1][y]=0; dfs(y,d[1]);
	fore(i,0,n){
		auto &x=b[i][0],&y=b[i][1];
		x=d[0][i];
		y=d[1][i];
		if(x>y)swap(x,y);
		y-=x;
	}
	ll res=disjoint();
	return res;
}
