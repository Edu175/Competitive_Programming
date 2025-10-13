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

#define maxig(a,b) a=max(a,b)

int main(){
    JET
    ll n; cin>>n;
	vv a(n);
	vector<ii> sa;
	fore(i,0,n)cin>>a[i],sa.pb({a[i],i});
	vv r(n),l(n);
	fore(i,0,n)
		for(l[i]=i-1;l[i]!=-1&&a[l[i]]<=a[i];l[i]=l[l[i]]);
	for(ll i=n-1;i>=0;i--)
		for(r[i]=i+1;r[i]!=n &&a[r[i]]<=a[i];r[i]=r[r[i]]);
	vv dp(n);
	sort(ALL(sa));
	ll ans=0;
	for(auto [v,i]:sa){
		maxig(ans,++dp[i]);
		if(l[i]!=-1)maxig(dp[l[i]],dp[i]);
		if(r[i]!=n) maxig(dp[r[i]],dp[i]);
	}
	cout<<ans<<"\n";
	return 0;
}