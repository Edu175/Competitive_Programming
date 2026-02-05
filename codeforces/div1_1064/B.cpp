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
		// reverse(ALL(hist));
		// while(!hist.back())hist.pop_back();
		// reverse(ALL(hist));
		ll m=SZ(hist);
		vv dp(n+1); dp[0]=1;
		fore(x,0,m){
			// cerr<<hist[x]<<"\n";
			auto prox=dp;
			fore(s,0,n+1)if(dp[s]){
				ll now=mul(dp[s],hist[x]);
				ll pos=s+hist[x];
				// if(now)cout<<"entra "<<x<<" "<<s<<": "<<pos<<" "<<now<<"\n";
				assert(pos<=n);
				prox[pos]=add(prox[pos],now);
			}
			// imp(dp)
			// imp(prox)
			swap(prox,dp);
		}
		// imp(dp)
		ll bad=0;
		fore(s,0,hist[m-1])bad=add(bad,dp[s]);
		// cerr<<bad<<" bad\n";
		
		ll all=1;
		for(auto i:hist)all=mul(all,i+1);
		
		ll res=sub(all,bad);
		cout<<res<<"\n";
	}
	return 0;
}
