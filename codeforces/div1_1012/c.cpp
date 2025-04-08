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
int fpow(int a, ll b){
	if(b<0)return 0;
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,l,k; cin>>n>>l>>k;
		// vector<vector<vv>> dp(n+1,vector<vv>(n+1,vv(l+1)));
		vv ans(n);
		vv inv(l+5+k);
		fore(i,0,SZ(inv))inv[i]=fpow(i,MOD-2);
		vv prob(n); prob[0]=1;
		for(ll t=l;t>0;t--){
			vv prox(n);
			fore(i,0,n){
				vv now(n);
				fore(j,0,n){
					ll good=(j-i+n)%n<(t+k)%n;
					now[j]=mul((good+(t+k)/n),inv[t+k]);
					// cout<<j<<": "<<good<<","<<t/n<<" "<<(good+t/n)<<"\n";
				}
				fore(j,0,n)
					now[j]=mul(now[j],prob[i]),
					ans[j]=add(ans[j],now[j]),
					prox[j]=add(prox[j],now[j]);
				// cout<<t<<" "<<i<<": "; imp(now)
			}
			fore(i,0,n)prob[(i+1)%n]=prox[i];
		}
		imp(ans)
	}
	return 0;
}
