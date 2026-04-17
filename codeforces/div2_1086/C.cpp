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
typedef long double ld;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv c(n);
		vector<ld>p(n);
		fore(i,0,n){
			cin>>c[i]>>p[i];
			p[i]=1-ld(p[i])/100;
		}
		vector<ld> dp(n+1);
		for(ll i=n-1;i>=0;i--){
			auto &res=dp[i];
			auto prox=dp[i+1];
			res=max(prox,c[i]+p[i]*prox);
		}
		cout<<fixed<<setprecision(15);
		cout<<dp[0]<<"\n";
	}
	return 0;
}
