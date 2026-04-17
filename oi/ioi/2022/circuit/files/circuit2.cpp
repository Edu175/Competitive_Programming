#include "circuit.h"
#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ioi=b;i<ioi;i++)
#define dfore(i,a,b) for(ll i=b-1,ioi=a;i>=ioi;i--)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto djfhg:v)cout<<djfhg<<" ";cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=2e5+5,MOD=1000002022;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}

ll n,m;
vector<ll>g[MAXN];
ll a[MAXN],tot[MAXN],dp[MAXN];
vector<ll> pre[MAXN], suf[MAXN];
void init(int N, int M, std::vector<int> P, std::vector<int> A){
	n=N,m=M;
	fore(i,0,SZ(P)){
		if(P[i]!=-1)g[P[i]].pb(i);
	}
	fore(i,0,m)a[i+n]=A[i];
	fore(i,0,m)tot[n+i]=1;
	dfore(x,0,n){
		ll k=SZ(g[x]);
		tot[x]=k;
		for(auto y:g[x])tot[x]=mul(tot[x],tot[y]);
		pre[x].resize(k+1,1),suf[x].resize(k+1,1);
		fore(i,1,k+1)pre[x][i]=mul(pre[x][i-1],tot[g[x][i-1]]);
		dfore(i,0,k)suf[x][i]=mul(suf[x][i+1],tot[g[x][i]]);
	}
}

int count_ways(int L, int R){
	fore(i,L,R+1)a[i]^=1;
	//fore(i,n,n+m)cout<<a[i];;cout<<"\n";
	dfore(x,0,n+m){
		dp[x]=0;
		if(x>=n)dp[x]=a[x];
		else {
			fore(i,0,SZ(g[x])){
				auto y=g[x][i];
				dp[x]=add(dp[x],mul(dp[y],mul(pre[x][i],suf[x][i+1])));
			}
		}
		//cout<<x<<": "<<dp[x]<<"\n";
	}
	return dp[0];
}
