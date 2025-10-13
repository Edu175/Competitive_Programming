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
ll dp[MAXN][MAXN][2];

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
ll vis[MAXN][MAXN][2];

vector<vv> f(ll x, ll k, ll b){
	assert(k<=sz[x]);
	auto &res=dp[x][k][b];
	if(vis[x][k][b])return res;
	vis[x][k][b]=1;
	// no lo pago
	vv conv={0};
	for(auto y:g[x]){
		vv vec;
		fore(i,0,sz[y]+1)vec.pb(f(y,i,0));
		conv=convolve(conv,vec);
	}
	ll no=k?-wf[x]*b+conv[k-1]:INF;
	
	// si lo pago
	conv={0};
	for(auto y:g[x]){
		vv vec;
		fore(i,0,sz[y]+1)vec.pb(f(y,i,1));
		conv=convolve(conv,vec);
	}
	ll si=cost[x]+conv[min(k,SZ(conv)-1)];
	cout<<x<<": "<<
	return res=min(si,no);
}

int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n){
			g[i].clear();
			fore(j,0,n)fore(k,0,2)vis[i][j][k]=0;
		}
		wf[0]=0;
		fa[0]=-1;
		fore(i,1,n){
			cin>>fa[i]; fa[i]--;
			g[fa[i]].pb(i);
		}
		fore(i,0,n)cin>>hp[i];
		dfs0(0);
		vv res(n+1);
		fore(k,0,n+1){
			res[k]=f(0,k,0);
			if(k)assert(res[k]<=res[k-1]);
		}
		for(auto i:res)cout<<i<<" ";;cout<<"\n";
	}
	return 0;
}