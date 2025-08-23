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
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<vv> pos(n);
		vv a(n);
		fore(i,0,n){
			cin>>a[i];
			a[i]--;
			pos[a[i]].pb(i);
		}
		fore(i,0,n)pos[i].pb(n);
		vector<vv> dp(n+3,vv(2));
		for(ll i=n-1;i>=0;i--)fore(vo,0,2){
			auto &res=dp[i][vo];
			res=vo+dp[i+1][1];
			ll prox=*upper_bound(ALL(pos[a[i]]),i);
			if(prox<n){
				res=min(res,dp[prox][0]);
			}
			// cout<<i<<" "<<vo<<": "<<res<<"\n";
		}
		cout<<n-dp[0][1]<<"\n";
	}
	return 0;
}
