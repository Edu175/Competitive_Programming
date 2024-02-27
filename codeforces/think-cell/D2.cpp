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
		string s; cin>>s;
		vector<ll>dp(n+6);
		ll lo=n,res=0;
		for(ll i=n-1;i>=0;i--){
			if(s[i]=='0')dp[i]=dp[lo];
			else {
				dp[i]=n-i+dp[i+3];
				lo=i;
			}
			res+=dp[i];
		}
		cout<<res<<"\n";
	}
	return 0;
}
