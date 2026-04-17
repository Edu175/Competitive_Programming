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

int findSample(int n,int c[],int ps[],int ts[]){
	vector<vector<ll>>dp(n,vector<ll>(2));
	for(ll x=n-1;x>=0;x--){
		ll p=ps[x],t=ts[x];
		// cerr<<"cero "<<dp[0][0]<<" "<<dp[0][1]<<"\n";
		dp[x][1]+=c[x];
		// cerr<<x<<": "<<dp[x][0]<<" "<<dp[x][1]<<"\n";
		if(!x)break;
		if(!t){
			dp[p][0]+=max(dp[x][1],dp[x][0]);
			dp[p][1]+=dp[x][0];
		}
		else {
			if(t==1){
				dp[p][1]=max(max(dp[p][1],dp[p][0]-c[p])+dp[x][1],
							dp[p][1]+dp[x][0]);
			}
			else {
				dp[p][1]=max(dp[p][0]-c[p]+dp[x][1],
							dp[p][1]+dp[x][0]);
			}
			dp[p][0]+=dp[x][0];
		}
	}
	ll res=max(dp[0][0],dp[0][1]);
	return res;
}
