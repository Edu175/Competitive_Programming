#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b;i<jet;i++)
#define pb push_back
#define snd second
#define fst first
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

int main(){
	JET
	ll n,k; cin>>n>>k;
	vv a(n);
	fore(i,0,n){
		cin>>a[i];
		a[i]--;
	}
	ll m; cin>>m;
	set<ii>st;
	fore(i,0,m){
		ll a,b; cin>>a>>b; a--,b--;
		st.insert({a,b});
		assert(a<k&&b<k);
	}
	vv dp(n+3);
	dp[n]=0;
	for(ll i=n-1;i>=0;i--){
		auto &res=dp[i];
		// if(i==n-1){res=1;continue;}
		res=0;
		if(i+1>=n||st.count({a[i],a[i+1]})){
			res=max(res,1+dp[i+1]);
		}
		if(i+2>=n||st.count({a[i],a[i+2]})){
			res=max(res,1+dp[i+2]);
		}
	}
	ll res=0;
	if(a[0]<k)res=max(res,dp[0]);
	if(a[1]<k)res=max(res,dp[1]);
	cout<<res<<"\n";
	return 0;
}