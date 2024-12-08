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
typedef long double ld;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=2005,MOD=998244353;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}

vector<ll> g[MAXN];
// ld dp[MAXN][MAXN];
// ll mdp[MAXN][MAXN];
ll fa[MAXN];
vv ord;
void dfs(ll x, ll f=0){
	fa[x]=f;
	for(auto y:g[x])if(y!=f)dfs(y,x);
	ord.pb(x);
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,q; cin>>n>>q;
		fore(i,0,n){
			g[i].clear();
		}
		ord.clear();
		fore(i,0,n-1){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		dfs(0);
		reverse(ALL(ord));
		vector<vector<ld>>dp(n+3,vector<ld>(n+3));
		vector<vv>mdp(n+3,vv(n+3));
		fore(p,0,n+1)for(auto x:ord)if(x){
			auto &res=dp[p][x];
			auto &mres=mdp[p][x];
			
			ll steps=2,sz=SZ(g[x]);
			if(!fa[x])steps=1;
			
			if(p){
				res=dp[p-1][fa[fa[x]]]+steps;
				mres=add(mdp[p-1][fa[fa[x]]],steps);
			}
			
			ld c=0; ll mc=0;
			c=dp[p][fa[fa[x]]]+steps+2*sz-2;
			mc=(mdp[p][fa[fa[x]]]+steps+2*sz-2+MOD)%MOD;
			
			if(!p||c<res)res=c,mres=mc;
			
		}
		while(q--){
			ll v,p; cin>>v>>p; v--;
			cout<<add(mdp[p][fa[v]],1)<<"\n";
		}
	}
	return 0;
}
