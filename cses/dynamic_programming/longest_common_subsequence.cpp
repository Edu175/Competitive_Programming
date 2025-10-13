#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a, jet = b; i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {for(auto i:v)cout<<i<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

int main(){
    JET
	ll n,m; cin>>n>>m;
	vv a(n),b(m);
	fore(i,0,n)cin>>a[i];
	fore(i,0,m)cin>>b[i];
	vector<vv> dp(n+3,vv(m+3));
	for(ll i=n-1;i>=0;i--)for(ll j=m-1;j>=0;j--){
		auto &res=dp[i][j];
		res=dp[i+1][j];
		res=max(res,dp[i][j+1]);
		if(a[i]==b[j]){
			res=max(res,1+dp[i+1][j+1]);
		}
	}
	vv ans;
	ll i=0,j=0;
	while(i<n&&j<m){
		auto &res=dp[i][j];
		if(res==dp[i+1][j])i++;
		else if(res==dp[i][j+1])j++;
		else {
			assert(a[i]==b[j]);
			ans.pb(a[i]);
			i++,j++;
		}
	}
	cout<<dp[0][0]<<"\n";
	imp(ans)
    return 0;
}