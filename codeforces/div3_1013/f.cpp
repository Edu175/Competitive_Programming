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
ll fqrt(ll x){ //if ceil change to r*r<x and return r
	ll r=sqrt(x)-3;
	for(;r<0||r*r<=x;r++)if(r<0)continue;
	return r-1;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m,d; cin>>n>>m>>d;
		vector<string> a(n);
		fore(i,0,n)cin>>a[i];
		ll dv=fqrt(d*d-1);
		vv sp(m+1);
		fore(i,1,m+1)sp[i]=add(sp[i-1],1);
		// cout<<d<<" "<<dv<<"\n";
		fore(i,0,n){
			vv dp(m+1),spi(m+1);
			fore(b,0,2){
				fore(j,0,m)if(a[i][j]=='X'){
					ll l=max(0ll,j-dv),r=min(m-1,j+dv)+1;
					// cout<<l<<","<<r<<"\n";
					ll go=sub(sp[r],sp[l]); // salto
					if(i==0)go=1;
					l=max(0ll,j-d),r=min(m-1,j+d)+1;
					ll stay=sub(spi[r],spi[l]);
					stay=sub(stay,dp[j]);
					dp[j]=add(go,stay);
					// cout<<i<<" "<<j<<" "<<b<<": "<<go<<" "<<stay<<": "<<dp[j]<<"\n";
				}
				fore(j,1,m+1)spi[j]=add(spi[j-1],dp[j-1]);
			}
			sp=spi;
		}
		cout<<sp.back()<<"\n";
	}
	return 0;
}
