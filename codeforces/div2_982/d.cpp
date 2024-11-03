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
const ll INF=1e7,MOD=1e9+7;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		vv a(n),b(m);
		fore(i,0,n)cin>>a[i];
		fore(i,0,m)cin>>b[i];
		vv sp(n+1);
		fore(i,1,n+1)sp[i]=sp[i-1]+a[i-1];
		vector<vv>dp(n+5,vv(m+5));
		vector<vv>co(n+5,vv(m+5));
		// imp(sp)
		fore(i,0,m+1)co[n][i]=1;
		fore(i,0,n)dp[i][m]=INF;
		for(ll j=m-1;j>=0;j--){
			vv sum(n+2);
			sum[n]=co[n][j];
			for(ll i=n-1;i>=0;i--){
				ll &res=dp[i][j];
				ll &num=co[i][j];
				ll go0=0,go1=0;
				res=go0=dp[i][j+1];
				ll p=upper_bound(ALL(sp),sp[i]+b[j])-sp.begin();
				p--;
				if(p<=i){res=INF;continue;}
				go1=(p<=i?INF:m-(j+1)+dp[p][j]);
				res=min(res,go1);
				num=0;
				if(res==go0)num=co[i][j+1];
				if(res==go1){ // +=
					ll l=i+1,r=p;
					while(l<=r){
						ll h=(l+r)/2;
						if(dp[h][j]==dp[p][j])r=h-1;
						else l=h+1;
					}
					num=add(num,sub(sum[l],sum[p+1]));
					// cout<<i<<" "<<j<<", "<<l<<" "<<p<<": "<<num<<"\n";
				}
				sum[i]=add(sum[i+1],num);
			}
			
		}
		ll res=dp[0][0];
		if(res>=INF)cout<<"-1\n";
		else cout<<res<<" "<<co[0][0]<<"\n";
	}
	return 0;
}
