#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,boi=b;i<boi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto skdauf:v)cout<<skdauf<<" ";cout<<"\n"
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll b,p,d,n; cin>>b>>p>>d>>n;
	vector<ll>a={0};
	fore(i,0,n){
		ll x; cin>>x; a.pb(x);
	}
	n++;
	a.pb(b);
	vector<vector<ll>>dp(n+5,vector<ll>(p+5));
	//imp(a);
	for(ll i=n-1;i>=0;i--){
		ll x=a[i+1]-a[i],q=(x+p-1)/p-1,add=q*d+x;
		//cout<<i<<": "<<x<<" "<<q<<" "<<add<<"\n";
		fore(r,0,p){
			dp[i][r]=dp[i+1][(r+x)%p]+add+(r>p-x%p)*d;
			if(r)dp[i][r]=min(dp[i][r],dp[i][0]+p-r);
			//cout<<"  "<<r<<": "<<dp[i][r]<<"\n";
		}
	}
	cout<<dp[0][0]<<"\n";
	return 0;
}
