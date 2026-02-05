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
#define addig(a,b) a=add(a,b)

int main(){FIN;
	ll n,k; cin>>n>>k;
	vv dp(k+1,1); dp[0]=0;
	fore(d,2,min(n+1,k+3)){
		vv prox(k+1);
		fore(i,1,k+1){
			ll c=i*(d-1);
			for(ll j=d-c%d;j<=k;j+=d)addig(prox[(c+j)/d],dp[i]);
		}
		swap(prox,dp);
	}
	ll res=0;
	fore(i,1,k+1)addig(res,dp[i]);
	cout<<res<<"\n";
	return 0;
}