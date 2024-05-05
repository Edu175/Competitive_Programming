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
		a.pb(0);
		sort(ALL(a));
		vector<ll>b;
		fore(i,0,n){
			b.pb(a[i+1]-a[i]);
			if(b.back()==0)b.pop_back();
		}
		n=SZ(b);
		vector<ll>dp(n+5);
		dp[n]=0;
		for(ll i=n-1;i>=0;i--){
			if(b[i]==1)dp[i]=dp[i+1]^1;
			else dp[i]=1;
		}
		if(dp[0])cout<<"Alice\n";
		else cout<<"Bob\n";
	}
	return 0;
}
