#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
const ll maxn=101;
ll n;
ll c[maxn];
ll v[maxn];
ll dp[maxn][100001];
ll knack(ll x, ll w){
	if(x==n)return 0;
	if(dp[x][w]>=0)return dp[x][w];
	if(c[x]>w)return knack(x+1,w);
	return dp[x][w]=max(knack(x+1,w),knack(x+1,w-c[x])+v[x]);
}

int main(){FIN;
	ll w;
	cin>>n>>w;
	fore(i,0,n)cin>>c[i]>>v[i];
	mset(dp,-1);
	cout<<knack(0,w);
	return 0;
}
