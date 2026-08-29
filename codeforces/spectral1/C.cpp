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
		auto sa=a; sort(ALL(sa));
		ll med=sa[n/2];
		vv dp(n+1);
		for(ll i=n-1;i>=0;i--){
			auto &res=dp[i];
			res=-1e9;
			ll le=0,eq=0,bi=0;
			fore(j,i+1,n+1){
				ll v=a[j-1];
				if(v<med)le++;
				if(v==med)eq++;
				if(v>med)bi++;
				ll z=j-i;
				if(z%2==0||!eq)continue;
				if(le<=z/2&&bi<=z/2)res=max(res,dp[j]+1);
			}
		}
		cout<<dp[0]<<"\n";
	}
	return 0;
}
