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
const ll MAXN=3005,MOD=998244353;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
#define addig(a,b) a=add(a,b)

int main(){FIN;
	vector<vv> divs(MAXN);
	fore(n,1,MAXN)fore(d,1,n+1)if(n%d==0)divs[n].pb(d);
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		vv a(n);
		fore(i,0,n)cin>>a[i];
		vector<vv> dp(n,vv(m+1));
		dp[0][1]=1;
		ll res=0;
		fore(i,0,n)fore(u,1,m+1){
			ll now=dp[i][u];
			if(a[i]&&a[i]!=u)continue;
			if(i==n-1){
				addig(res,now);
				continue;
			}
			for(auto d:divs[u]){
				ll v=u+d;
				if(v<=m)addig(dp[i+1][v],now);
			}
		}
		cout<<res<<"\n";
	}
	return 0;
}
