#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first 
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll) x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MOD=(119<<23)+1;
ll add(ll a, ll b){a+=b;if(a>=MOD)a-=MOD;return a;}
ll sub(ll a, ll b){a-=b;if(a<0)a+=MOD;return a;}
ll mul(ll a, ll b){return a*b%MOD;}
ll fpow(ll b, ll e){
	if(e<0)return 0;
	ll res=1;
	for(;e;e>>=1,b=mul(b,b))if(e&1)res=mul(res,b);
	return res;
}
ll inv(ll a){return fpow(a,MOD-2);}
int main(){
	JET
	ll n,k; cin>>n>>k;
	vv a(n);
	fore(i,0,n){
		cin>>a[i];
		ll den; cin>>den;
		a[i]=mul(a[i],inv(den));
	}
	ll sum=0,ma=0,prod=1;
	fore(i,0,k)prod=mul(prod,a[i]);
	vv dp(n);
	ll res=0;
	fore(i,k-1,n){
		if(i-k>=0){
			prod=mul(prod,inv(a[i-k]));
			prod=mul(prod,a[i]);
			ma=add(ma,dp[i-1]);
			ma=mul(ma,a[i]);
			ma=sub(ma,mul(dp[i-k],prod));
			sum=add(sum,dp[i-k]);
		}
		auto &cur=dp[i];
		cur=prod;
		ll sac=add(mul(sum,prod),ma);
		cur=sub(cur,sac);
		res=add(res,cur);
	}
	cout<<res<<"\n";
	return 0;
}