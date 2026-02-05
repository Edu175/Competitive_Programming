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
		ll n,m; cin>>n>>m;
		vector<vv> bad(n,vv(n));
		fore(_,0,m){
			ll i,x; cin>>i>>x; i--,x--;
			bad[i][x]=1;
		}
		vector<vv> mn(n+1,vv(n,n));
		fore(i,0,n)fore(s,0,n){
			auto &res=mn[i][s];
			fore(j,i,n){
				ll k=s+j-i;
				if(k<n&&bad[j][k]){res=j;break;}
			}
		}
		vector<vv> dp(n+1,vv(n+1));
		fore(b,0,n)dp[n][b]=1;
		for(ll i=n-1;i>=0;i--)fore(ban,0,n){
			auto &res=dp[i][ban];
			fore(e,i+1,n+1){
				ll z=e-i;
				fore(s,0,z)if(s!=ban+1){
					ll p=e-s;
					if(mn[i][s]<p||mn[p][0]<e)continue;
					ll cur=dp[e][s==0?z-1:n-1];
					res=add(res,cur);
					// cout<<i<<"("<<s<<") "<<p<<","<<e-1<<"("<<s-1<<") "<<cur<<"\n";
				}
			}
			// if(res)cout<<i<<" "<<ban<<": "<<res<<"\n";
		}
		ll res=dp[0][n-1];
		cout<<res<<"\n";
	}
	return 0;
}
