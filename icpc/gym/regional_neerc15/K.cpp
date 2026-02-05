#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a, jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

const ll MAXN=2e5+5;

void fail(){
	if(1){
		cout<<"There is no route, Karl!\n";
		exit(0);
	}
}

vv g[MAXN];

ll vis[MAXN],bad[MAXN];

vv path;
void dfs0(ll x){
	vis[x]=1; path.pb(x);
	for(auto y:g[x])if(!vis[y])dfs0(y);
}

ll u;
vv cad;
void dfs1(ll x){
	cad.pb(x);
	if(bad[x])fail();
	if(SZ(g[x])>1)return;
	bad[x]=1; u=x;
	for(auto y:g[x])dfs1(y);
}

ll good[MAXN];

int main(){
	JET
	#ifdef ONLINE_JUDGE
	freopen("king.in","r",stdin);
	freopen("king.out","w",stdout);
	#endif
	ll n,m; cin>>n>>m;
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		// in[v]++;
	}
	vv hay(n);
	fore(x,0,n)if(SZ(g[x])==1)for(auto y:g[x])hay[y]=1;
	
	
	dfs0(0);
	fore(i,0,n){
		if(!vis[i]||!SZ(g[i]))fail();
		vis[i]=0;
	}
	
	vector<vv> ten(n);
	
	fore(x,0,n)if(!hay[x]&&SZ(g[x])==1){
		cad.clear();
		dfs1(x);
		ten[x]=cad;
		g[x]=g[u];
		good[x]=1;
	}
	
	fore(x,0,n)if(!bad[x]&&SZ(g[x])==1){
		for(auto i:path)cout<<i+1<<" ";
		cout<<"1\n";
		return 0;
	}
	
	
	vv nod,nl(n);
	
	fore(x,0,n){
		if(good[x])bad[x]=0;
		if(!bad[x]){
			nl[x]=SZ(nod);
			nod.pb(x);
		}
	}
	
	ll z=SZ(nod);
	assert(z<=21);
	vector<vv> gn(n);
	
	fore(x,0,n)if(!bad[x])for(auto y:g[x])if(!bad[y]){
		gn[nl[x]].pb(nl[y]);
	}
	
	ll Z=1ll<<z;
	
	vector<vv> dp(Z,vv(z));
	
	fore(x,0,z){
		ll esta=0;
		for(auto y:gn[x])esta|=!y;
		dp[Z-1][x]=esta;
	}
	
	for(ll mk=Z-1;mk>=0;mk--)fore(x,0,z)if(mk>>x&1){
		auto &res=dp[mk][x];
		for(auto y:gn[x])if(!(mk>>y&1)){
			res|=dp[mk|(1ll<<y)][y];
		}
	}
	
	ll s=-1;
	fore(x,0,z)if(dp[1ll<<x][x])s=x;
	if(s==-1)fail();
	
	vv ans;
	ll mk=1ll<<s,x=s;
	while(mk!=Z-1){
		for(auto i:ten[nod[x]])ans.pb(i);
		auto res=dp[mk][x];
		assert(res);
		ll prox=-1;
		for(auto y:gn[x])if(!(mk>>y&1)){
			if(dp[mk|(1ll<<y)][y])prox=y;
		}
		assert(prox!=-1);
		ll y=prox;
		mk|=(1ll<<y);
		x=y;
	}
	assert(SZ(ans)<=n);
	if(SZ(ans)<n)fail();
	ll p=-1;
	fore(i,0,n)if(ans[i]==0)p=i;
	assert(p!=-1);
	rotate(ans.begin(),ans.begin()+p,ans.end());
	for(auto i:ans)cout<<i+1<<" ";
	cout<<"1\n";
	return 0;
}