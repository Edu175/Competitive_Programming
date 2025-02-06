#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MOD=1e9+7;

ll add(ll a, ll b){a+=b;if(a>=MOD)a-=MOD;return a;}
ll sub(ll a, ll b){a-=b;if(a<0)a+=MOD;return a;}
ll mul(ll a, ll b){return a*b%MOD;}
ll fpow(ll b, ll e){
	ll ret=1;
	while(e){
		if(e&1)ret=mul(ret,b);
		e>>=1,b=mul(b,b);
	}
	return ret;
}
int main(){
	JET
	ll n,k; cin>>n>>k;
	vv fc(2*n+5);
	fc[0]=1; fore(i,1,SZ(fc))fc[i]=mul(i,fc[i-1]);
	vv dp(n+1);
	fore(i,0,k+1)dp[i]=1;
	//dp[i]=mul(fc[i],fpow(,))
	ll sum=k;
	fore(i,k+1,n+1){
		ll &res=dp[i];
		res=mul(sum,fc[i-1]);
		res=mul(res,fpow(fc[i],MOD-2));
		sum=sub(sum,dp[i-k]);
		sum=add(sum,res);
	}
	ll res=dp[n];
	res=mul(res,fc[n]);
	cout<<res<<"\n";
	return 0;
}