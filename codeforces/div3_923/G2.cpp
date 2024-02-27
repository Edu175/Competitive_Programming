#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll>a(n);
		fore(i,0,n)cin>>a[i];
		vector<ll>dp(3*n+5);
		for(ll i=n-1;i>=0;i--){
			dp[i]=n+5;
			//cout<<i<<": ";
			ll mx=-1;
			fore(j,i,n){
				if(i+a[i]>j||j-a[j]<i){
					dp[i]=min(dp[i],1+dp[j+1]);
					if(mx!=-1)dp[i]=min(dp[i],2+dp[mx]);
					//cout<<j<<" ";
				}
				mx=max(mx,j+a[j]);
			}
			//cout<<"= "<<dp[i]<<"\n";
		}
		cout<<dp[0]<<"\n";
	}
	return 0;
}
