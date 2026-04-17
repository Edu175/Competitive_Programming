#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oii=b;i<oii;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" ";cout<<"\n"
using namespace std;
typedef int ll;
typedef pair<ll,ll> ii;
const ll MAXN=1005,MAXS=1e5+5;

ll n;
ll g[MAXN][MAXN];
ll a[MAXN];
ll vis[MAXN];

vector<ll>cmp[MAXN]; ll id[MAXN], val[MAXN];
void uf_init(){fore(i,0,MAXN)cmp[i]={i},id[i]=i,val[i]=a[i];}
bool uf_join(ll a, ll b){
	a=id[a],b=id[b];
	if(a==b)return 0;
	if(SZ(cmp[a])>SZ(cmp[b]))swap(a,b);
	for(auto i:cmp[a])cmp[b].pb(i),id[i]=b;
	val[b]+=val[a];
	cmp[a].clear(); val[a]=0;
	return 1;
}
vector<vector<ll>> dp;
vector<ll>comps;
vector<ll>ans;
void build(ll i, ll s){
	if(i==SZ(comps))return;
	ll x=comps[i];
	if(s+val[x]>=MAXS||dp[i+1][s]<dp[i+1][s+val[x]])build(i+1,s);
	else ans.pb(x),build(i+1,s+val[x]);
}
int main(){FIN;
	ll m; cin>>n>>m;
	fore(i,0,n)fore(j,0,n)g[i][j]=1;
	ll sum=0;
	fore(i,0,n)cin>>a[i],sum+=a[i];
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		g[u][v]=0;
		g[v][u]=0;
	}
	uf_init();
	fore(i,0,n)fore(j,0,n)if(g[i][j])uf_join(i,j);
	vector<ll> h[MAXS];
	fore(i,0,n){
		if(SZ(cmp[i]))h[val[i]].pb(i);
	}
	fore(i,0,MAXS){ //compress sqrt decomp ( k = O(sqrt(n)) )
		if(!SZ(h[i]))continue;
		vector<ll> hi={h[i][0]};
		ll l=1;
		if(SZ(h[i])%2==0)hi.pb(h[i][1]),l++;
		for(ll j=l;j<SZ(h[i]);j+=2){
			ll x=cmp[h[i][j]][0];
			uf_join(h[i][j],h[i][j+1]);
			h[val[id[x]]].pb(id[x]); //2*i
		}
		h[i]=hi;
	}
	fore(i,0,n)if(SZ(cmp[i]))comps.pb(i);
	//imp(comps);
	//ll dp[SZ(comps)+5][MAXS];
	ll k=SZ(comps);
	dp.resize(k+5,vector<ll>(MAXS));
	for(ll i=k;i>=0;i--)fore(s,0,MAXS){
		ll &res=dp[i][s];
		if(i==k){res=abs(s-(sum-s));continue;}
		res=dp[i+1][s];
		ll x=comps[i];
		if(s+val[x]<MAXS)res=min(res,dp[i+1][s+val[x]]);
	}
	cout<<dp[0][0]<<"\n";
	//build
	build(0,0);
	for(auto i:ans)for(auto j:cmp[i])cout<<j+1<<" ";
	cout<<"\n";
	return 0;
}
