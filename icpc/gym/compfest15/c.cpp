#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define pb push_back
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=2e5+5,MOD=998244353;
ll add(ll a, ll b){a+=b;if(a>=MOD)a-=MOD;return a;}
ll mul(ll a, ll b){return a*b%MOD;}
vector<ii> g[MAXN];

ll vis[MAXN];
vv dp[MAXN];

vv merge(vv l, vv r){
	l[2]=add(add(l[2],r[2]),mul(l[1],r[0]));
	l[0]=add(l[0],r[0]);
	l[1]=add(l[1],r[1]);
	return l;
}
vector<ll>ord;
void dfs(ll x){
	vis[x]=1;
	for(auto [y,w]:g[x])if(!vis[y])dfs(y);
	ord.pb(x);
}
ll ans=0,unos=0;
void bf(ll x){
	for(auto [y,w]:g[x]){
		if(!w)ans=add(ans,unos);
		else unos=add(unos,1);
		bf(y);
	}
}
// random_device rd;
// mt19937 rng(rd());

// void stress(ll N){
	
// }
int main(){
	JET
	ll n; cin>>n;
	fore(i,0,n){
		ll m; cin>>m;
		fore(j,0,m){
			ll u,w; cin>>u>>w; u--;
			g[i].pb({u,w});
		}
	}
	dfs(0);
	// reverse(ALL(ord));
	for(auto x:ord){
		dp[x]={0,0,0};
		for(auto [y,w]:g[x]){
			vv tmp={0,0,0};
			tmp[w]++;
			vv r=merge(tmp,dp[y]);
			dp[x]=merge(dp[x],r);
		}
	}
	ll res=dp[0][2];
	cout<<res<<"\n";
	
	// //bf
	// bf(0);
	// cout<<ans<<" bf\n";
	return 0;
}