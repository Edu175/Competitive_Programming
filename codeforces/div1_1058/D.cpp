#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n);
		fore(i,0,n)cin>>a[i];
		vv b;
		ll mn=2e18;
		for(ll i=n-1;i>=0;i--){
			if(a[i]<mn){
				mn=a[i];
				b.pb(a[i]);
			}
		}
		reverse(ALL(b));
		a=b;
		n=SZ(a);
		vv dp(n+1);
		for(ll i=n-1;i>=0;i--){
			auto &res=dp[i];
			res=n+5;
			fore(m,1,10){ // [2,3] is okay
				ll p=upper_bound(ALL(a),a[i]*m)-a.begin();
				res=min(res,m+dp[p]);
			}
		}
		cout<<dp[0]<<"\n";
	}
	return 0;
}
