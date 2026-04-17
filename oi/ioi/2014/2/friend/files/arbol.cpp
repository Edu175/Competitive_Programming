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
ll n,c[MAXN];

ll dp[MAXN][2];
ll f(ll x, ll b){
	ll &res=dp[x][b];
	if(res!=-1)return res;
	res=0;
	ll go0=0,go1=0;
	for(auto y:g[x])go0+=f(y,0),go1+=f(y,1);
	res=go0;
	if(!b)res=max(res,go1+c[x]);
	return res;
}

int findSample(int N,int CS[],int p[],int t[]){
	n=N;
	fore(i,0,n)c[i]=CS[i];
	fore(i,1,n){
		g[p[i]].pb(i);
	}
	mset(dp,-1);
	return f(0,0);
}
