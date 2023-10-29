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

const ll maxn=100005;

ll a[maxn];
ll dp[maxn];
ll n;
ll k;
ll jump(ll j){
	if(j==n-1)return 0;
	if(dp[j]>=0)return dp[j];
	ll mini=9e18;
	fore(i,1,min(k+1,n-j))mini=min(abs(a[j]-a[j+i])+jump(j+i),mini);
	return dp[j]=mini;
}

int main(){FIN;
	cin>>n>>k;
	fore(i,0,n)cin>>a[i];
	mset(dp,-1);
	cout<<jump(0);
	return 0;
}
