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
ll jump(ll j){
	if(j==n-1)return 0;
	if(dp[j]>=0)return dp[j];
	if(j==n-2)dp[j]=abs(a[j]-a[j+1]);
	else dp[j]=min(abs(a[j]-a[j+1])+jump(j+1),abs(a[j]-a[j+2])+jump(j+2));
	return dp[j];
}

int main(){FIN;
	cin>>n;
	fore(i,0,n)cin>>a[i];
	mset(dp,-1);
	cout<<jump(0);
	return 0;
}
