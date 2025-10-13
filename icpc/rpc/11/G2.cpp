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
const ll MOD=1e9+7;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}

int main(){FIN;
	ll n,k; string s; cin>>n>>k>>s;
	ll m=SZ(s),d=m;
	fore(l,1,m+1){
		ll fg=1;
		fore(i,0,m-l)if(s[i]!=s[i+l]){
			fg=0;
			break;
		}
		if(fg){
			d=l;
			break;
		}
	}
	cout<<d<<" "<<m<<"\n";
	vector<ll> dp(n+3);
	dp[n]=1;
	for(ll i=n-1;i>=0;i--){
		auto &res=dp[i];
		res=mul(k,dp[i+1]);
		cout<<i<<" inicial "<<res<<"\n";
		ll p=i+m,sig=1;
		while(p<=n){
			res=(sig?sub:add)(res,dp[p]);
			cout<<p<<": "<<(sig?"-=":"+=")<<" "<<dp[p]<<"\n";
			p+=d,sig^=1;
		}
		cout<<i<<": "<<dp[i]<<" final\n\n";
	}
	ll tot=1;
	fore(i,0,n)tot=mul(tot,k);
	ll res=sub(tot,dp[0]);
	cout<<res<<"\n";
	return 0;
}
