#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet;i++)
#define pb push_back
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MOD=1e9+7;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
const ll MAXN=8005,B=90;

vector<ll> g[MAXN];
vv coef[MAXN];
ll vis[MAXN],val[MAXN],dp[MAXN];
ll n;
void dfs(ll x){
	vis[x]=1;
	coef[x][x]=1;
	for(auto y:g[x]){
		if(!vis[y])dfs(y);
		fore(i,0,n)coef[x][i]=add(coef[x][i],coef[y][i]);
	}
}

void dfs2(ll x){
	vis[x]=1;
	dp[x]=val[x];
	for(auto y:g[x]){
		if(!vis[y])dfs2(y);
		dp[x]=add(dp[x],dp[y]);
	}
}
void dodp(){ // given val
	mset(vis,0);
	fore(i,0,n)if(!vis[i])dfs2(i);
}
int main(){
	JET
	cin>>n;
	fore(i,0,n)cin>>val[i];
	ll m; cin>>m;
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
	}
	fore(i,0,n)coef[i]=vv(n);
	fore(i,0,n)if(!vis[i])dfs(i);
	vector<ii>bag;
	vv ans;
	ll q; cin>>q;
	fore(_,0,q){
		if(_%B==0){
			dodp();
			bag.clear();
		}
		char ty; cin>>ty;
		if(ty=='U'){
			ll x,v; cin>>x>>v; x--;
			v=sub(v,val[x]);
			val[x]=add(val[x],v);
			bag.pb({x,v});
		}
		else{
			ll x; cin>>x; x--;
			ll resi=dp[x];
			for(auto [y,v]:bag)resi=add(resi,mul(coef[x][y],v));
			ans.pb(resi);
		}
	}
	ll res=0;
	fore(i,0,SZ(ans))res=add(res,mul(i+1,ans[i]));
	cout<<res<<"\n";
	return 0;
}