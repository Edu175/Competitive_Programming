#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (ll)x.size()
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MOD=1e9+7;
ll add(ll a, ll b){a+=b;if(a>=MOD)a-=MOD;return a;}
ll sub(ll a, ll b){a-=b;if(a<0)a+=MOD;return a;}
ll mul(ll a, ll b){return a*b%MOD;}
ll fpow(ll b, ll e){
	ll r=1;
	while(e){
		if(e&1)r=mul(r,b);
		b=mul(b,b),e>>=1;
	}
	return r;
}
int main(){JET
	ll n,k; cin>>n>>k;
	vector<ll>ps,cs;
	ll ni=n;
	for(ll i=2;i*i<=ni;i++){
		ll c=0;
		while(ni%i==0)c++,ni/=i;
		if(c)ps.pb(i),cs.pb(c);
	}
	if(ni>1)ps.pb(ni),cs.pb(1);
	ll res=1;
	fore(i,0,SZ(ps)){
		ll m=cs[i]+1,p=ps[i],v=1;
		vector<ll>dp(m);
		fore(i,0,m)dp[i]=v,v=mul(p,v);
		fore(_,0,k)fore(i,0,m){
			ll inv=fpow(i+1,MOD-2);
			dp[i]=mul(dp[i],inv);
			if(i){
				dp[i]=add(dp[i],mul(sub(1,inv),dp[i-1]));
			}
		}
		res=mul(res,dp[m-1]);
	}
	cout<<res<<"\n";
}