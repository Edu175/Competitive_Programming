#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef int ll;
typedef long long LL;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
LL mod;
int addm(int a, int b){
	a+=b;
	if(a>mod) a%=mod;
	return a;
}
int mulm(LL a, LL b){
	a*=b; if(a>mod) a%=mod;
	return a;
}
int main(){
	JET
	ll n,m; cin>>n>>m>>mod;
	ll c[n]; mset(c,0);
	fore(i,0,m)fore(j,0,n){
		char b; cin>>b;
		c[j]+=(b=='1');
	}
	ll k1=0,k2=0;
	fore(i,0,n) {
		k1+=c[i]==1;
		k2+=!c[i];
	}
	ll dp[n+1][2]; mset(dp,0); dp[0][0]=1;
	#define pos (i&1)
	// cout<<k1<<" "<<k2<<"\n";
	fore(i,0,n-m){
		fore(u,0,n+1) dp[u][!pos]=0;
		// fore(u,0,n+1){
		// 	cout<<dp[u][pos]<<" ";;cout<<"\n";
		// }
		// cout<<"\n";
		//2*u + d = i
		ll u=2*i, d=0;
		while(u>=0 && d<=n){
			if(u<=n){
				ll &r=dp[u][pos];
				// cout<<u<<endl;
				if(u<n-1){
					// cout<<"desde "<<u<<","<<d<<" veo a "<<u+2<<","<<d<<endl;
					dp[u+2][!pos]=addm(dp[u+2][!pos],mulm((u+2)*(u+1)/2,r));
				}
				if(d<n-1 && u>=2){
					dp[u-2][!pos]=addm(dp[u-2][!pos],mulm((d+2)*(d+1)/2,r));
				}
				if(d<n && u){
					dp[u][!pos]=addm(dp[u][!pos],mulm((d+1)*(u),r));
				}
			}
			u-=2; d+=1;
		}
	}
	cout<<dp[k1][((n-m)&1)]<<"\n";
	return 0;
}
// 3 1 1000
// 011
// 0 1
// 0
