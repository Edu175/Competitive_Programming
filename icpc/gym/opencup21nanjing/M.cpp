#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b; i<jet; i++)
#define snd second
#define fst first
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=2005,INF=1e18;
// ll dp[MAXN][MAXN][2];

vv g[MAXN];
ll sz[MAXN],cost[MAXN],fa[MAXN],wf[MAXN],hp[MAXN];
void dfs0(ll x){
	cost[x]=hp[x];
	sz[x]=1;
	for(auto y:g[x]){
		cost[x]+=hp[y];
		wf[y]=hp[x];
		dfs0(y);
		sz[x]+=sz[y];
	}
}

vv convolve(vv a, vv b){
	vv c(SZ(a)+SZ(b)-1,INF);
	fore(i,0,SZ(a))fore(j,0,SZ(b))c[i+j]=min(c[i+j],a[i]+b[j]);
	return c;
}
// ll vis[MAXN][MAXN][2];

vector<vv> f(ll x){
	// no lo pago
	vector<vv> conv(2,{0});
	for(auto y:g[x]){
		vector<vv> vec(2);
		auto v=f(y);
		fore(b,0,2){
			fore(i,0,sz[y]+1)vec[b].pb(v[b][i]);
			conv[b]=convolve(conv[b],vec[b]);
		}
	}
	vector<vv> ans(2,vv(sz[x]+1));
	fore(b,0,2)fore(k,0,SZ(ans[b])){
		ll no=k?-hp[x]*b+conv[0][k-1]:INF;
		ll si=k==sz[x]?INF:cost[x]+conv[1][k]; // no lo pagues si tenes todos
		ans[b][k]=min(no,si);
		// cout<<x<<" "<<b<<" "<<k<<": "<<ans[b][k]<<"\n";
	}
	return ans;
}

int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n){
			g[i].clear();
		}
		wf[0]=0;
		fa[0]=-1;
		fore(i,1,n){
			cin>>fa[i]; fa[i]--;
			g[fa[i]].pb(i);
		}
		fore(i,0,n)cin>>hp[i];
		dfs0(0);
		// fore(x,0,n){
		// 	cout<<x<<": "<<
		// }
		auto v=f(0);
		vv res(n+1);
		fore(k,0,n+1){
			res[k]=v[0][k];
			// if(k)assert(res[k]<=res[k-1]);
		}
		for(auto i:res)cout<<i<<" ";;cout<<"\n";
	}
	return 0;
}