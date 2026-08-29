#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MOD=(119<<23)+1;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
#define addig(a,b) a=add(a,b)

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<vv> g(n);
		fore(i,0,n-1){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		vv deg(n);
		ll sum=0,mx=0;
		vv dp(n);
		priority_queue<ll,vv,greater<ll>> pq;
		fore(x,0,n){
			deg[x]=SZ(g[x]);
			if(deg[x]==1){
				mx=max(mx,x);
				pq.push(x);
			}
		}
		dp[mx]=1;
		vv vis(n);
		while(SZ(pq)){
			auto x=pq.top(); pq.pop();
			mx=max(mx,x);
			vis[x]=1;
			addig(dp[x],sum);
			if(x<mx)assert(dp[x]==0);
			addig(sum,dp[x]);
			for(auto y:g[x])if(!vis[y]){
				--deg[y];
				if(deg[y]==1){
					dp[y]=sub(dp[y],sum);
					pq.push(y);
				}
			}
		}
		ll res=dp[n-1];
		// fore(i,0,n)addig(res,dp[i]);
		cout<<res<<"\n";
	}
	return 0;
}
