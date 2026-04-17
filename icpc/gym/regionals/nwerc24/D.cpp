#include <bits/stdc++.h> 
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define snd second 
#define fst first
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll) x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){
	JET
	ll n; cin>>n;
	ll tot=0;
	vv a(n);
	fore(i,0,n)cin>>a[i],tot+=a[i];
	vv dp(tot+1); dp[0]=1;
	sort(ALL(a));
	reverse(ALL(a));
	ll res=0;
	for(auto x:a){
		fore(s,0,tot+1){
			ll sum=s+x;
			if(sum>tot/2&&sum-x<=tot/2)res+=dp[s];
		}
		for(ll i=tot;i>=0;i--)if(dp[i])dp[i+x]+=dp[i];
	}
	cout<<res<<"\n";
	return 0;
}