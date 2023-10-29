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
const ll maxn=105;
const ll maxv=100005;
ll n; ll w;
ll c[maxn];
ll v[maxn];
ll dp[maxn][maxv];
ll f(ll x, ll sumv){
	if(x==n){
		if(sumv)return dp[x][sumv]=1000000005;
		else return 0;
	}
	if(dp[x][sumv]>=0)return dp[x][sumv];
	if(v[x]>sumv)return f(x+1,sumv);
	return dp[x][sumv]=min(f(x+1,sumv),f(x+1,sumv-v[x])+c[x]);
}

int main(){FIN;
	cin>>n>>w;
	fore(i,0,n)cin>>c[i]>>v[i];
	mset(dp,-1);
	ll maxi=0;
	fore(i,n,1000*n+1)if(f(0,i)<=w)maxi=i;
	cout<<maxi;
	return 0;
}
