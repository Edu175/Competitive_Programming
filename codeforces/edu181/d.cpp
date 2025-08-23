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
int inv(int a){return fpow(a,MOD-2);}
int main(){FIN;
		ll n,m; cin>>n>>m;
		vector<array<ll,3>> a(n);
		vector<vv> h(m);
		vv pp(m+1,1); // product actually
		fore(i,0,n){
			ll l,r,p,q; cin>>l>>r>>p>>q; l--;
			p=mul(p,inv(q));
			a[i]={l,r,p};
			h[l].pb(i);
			pp[l+1]=mul(pp[l+1],sub(1,p));
		}
		fore(i,0,m)pp[i+1]=mul(pp[i+1],pp[i]);
		vv dp(m+5,1);
		for(ll i=m-1;i>=0;i--){
			auto &res=dp[i];
			res=0;
			for(auto idx:h[i]){
				auto [l,r,p]=a[idx];
				ll cur=mul(p,inv(sub(1,p)));
				ll ran=mul(pp[r],inv(pp[l]));
				ll prox=dp[r];
				// cout<<cur<<" "<<ran<<" c r\n";
				// cout<<i<<"-> "<<idx<<": "<<l<<" "<<r<<": "<<mul(cur,ran)<<" "<<prox<<": ";
				cur=mul(mul(cur,ran),prox);
				// cout<<cur<<"\n";
				res=add(res,cur);
			}
			// cout<<i<<": "<<res<<"\n";
		}
		cout<<dp[0]<<"\n";
	return 0;
}
