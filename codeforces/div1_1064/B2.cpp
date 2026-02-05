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
const ll MOD=99824435;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	if(b<0)return 0;
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv hist(n);
		fore(i,0,n){
			ll x; cin>>x; x--;
			hist[x]++;
		}
		sort(ALL(hist));
		reverse(ALL(hist));
		while(!hist.back())hist.pop_back();
		reverse(ALL(hist));
		ll m=SZ(hist);
		vv pr(m+1,1),sum(m+1,0);
		for(ll i=m-1;i>=0;i--){
			pr[i]=mul(pr[i+1],hist[i]);
			sum[i]=sum[i+1]+hist[i];
		}
		// imp(hist)
		ll res=0;
		vv dp(n+1); dp[0]=1;
		fore(x,0,m){
			ll cur=0,ex=sum[x+1];
			fore(s,0,n+1)if(s+ex>=hist[x])cur=add(cur,dp[s]);
			cur=mul(cur,pr[x+1]);
			// cout<<x<<": "<<cur<<"\n";
			res=add(res,cur);
			for(ll s=n;s>=0;s--)if(dp[s]){
				ll now=mul(dp[x],hist[x]);
				ll pos=s+hist[x];
				dp[pos]=add(dp[pos],now);
			}
		}
		res=add(res,pr[0]); // all
		// cerr<<pr[0]<<"\n";
		cout<<res<<"\n";
	}
	return 0;
}
