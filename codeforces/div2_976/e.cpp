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
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
const ll B=10,den=fpow(10000,MOD-2);
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;;
		vv a(n),p(n);
		fore(i,0,n)cin>>a[i];
		fore(i,0,n)cin>>p[i];
		ll res=0;
		fore(i,0,B)fore(j,0,B){
			vv dp(4); dp[0]=1;
			fore(k,0,n){
				ll mk=(a[k]>>i&1)*2+(a[k]>>j&1);
				ll camb=mul(p[k],den);
				ll qued=sub(1,camb);
				vv dpi(4);
				fore(w,0,4){
					dpi[w]=add(mul(dp[w],qued),
						   mul(dp[w^mk],camb));
				}
				swap(dp,dpi);
			}
			res=add(res,mul(dp[3],fpow(2,i+j)));
		}
		cout<<res<<"\n";
	}
	return 0;
}
