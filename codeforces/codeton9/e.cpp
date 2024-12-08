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
const ll MOD=998244353;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
ll fn(ll n){return n*(n+1)/2%MOD;}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		// cout<<n<<"n "<<endl;
		vv dp(n+3);
		ll s=0;
		for(ll i=n;i>=0;i--){
			ll &res=dp[i];
			res=add(mul(s,i),1);
			if(i==n)res=1;
			s=add(s,res);
		}
		// imp(dp);
		if(n==2){
			cout<<"1\n";
			continue;
		}
		ll res=1+n-2;
		fore(i,4,n+1){
			ll c=sub(fn(i-2),1);
			res=add(res,mul(c,dp[i]));
			// cout<<i<<": "<<c<<"\n";
		}
		cout<<res<<"\n";
	}
	return 0;
}
