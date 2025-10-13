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
	vv pos;
	ll m=SZ(s);
	fore(l,1,m){
		ll fg=1;
		fore(i,0,m-l)if(s[i]!=s[i+l]){
			fg=0;
			break;
		}
		if(fg){
			pos.pb(l);
		}
	}
	// imp(pos)
	// cerr<<d<<" "<<m<<"\n";
	vector<vv> dp(2*n+3,vv(2));
	dp[n][0]=1;
	for(ll i=n-1;i>=0;i--)for(auto b:{1,0}){
		auto &res=dp[i][b];
		if(b){
			res=dp[i+m][0];
			for(auto d:pos){
				res=sub(res,dp[i+d][1]);
			}
		}
		else {
			res=mul(k,dp[i+1][0]);
			res=sub(res,dp[i][1]);
		}
		// cout<<i<<" "<<b<<": "<<res<<"\n";
	}
	ll tot=1;
	fore(i,0,n)tot=mul(tot,k);
	ll res=sub(tot,dp[0][0]);
	cout<<res<<"\n";
	return 0;
}
