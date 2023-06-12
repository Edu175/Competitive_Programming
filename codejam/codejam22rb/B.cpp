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
const ll maxn=1005;
ll alr[maxn][2];
ll dp[maxn][2];
ll n;
ll f(ll x,ll y){
	if(dp[x][y]>=0)return dp[x][y];
	if(x==n)return dp[x][y]=0;
	ll dis=alr[x][1]-alr[x][0];
	return dp[x][y]=min(abs(alr[x][1]-alr[x-1][y])+dis+f(x+1,0),abs(alr[x][0]-alr[x-1][y])+dis+f(x+1,1));
}

int main(){FIN;
	ll t; cin>>t;
	ll te=t;
	while(t--){
		cout<<"Case #"<<te-t<<": ";
		ll p;
		cin>>n>>p;
		ll a[n][p];
		fore(i,0,n){
			alr[i][0]=10e9+5;
			alr[i][1]=0;
			fore(j,0,p){
				cin>>a[i][j];
				alr[i][0]=min(alr[i][0],a[i][j]);
				alr[i][1]=max(alr[i][1],a[i][j]);
			}
		}
		mset(dp,-1);
		cout<<alr[0][1]+f(1,1)<<"\n";
	}
	return 0;
}
