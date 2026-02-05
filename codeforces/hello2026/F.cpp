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
const ll MAXN=5005,MOD=998244353;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
#define addig(a,b) a=add(a,b)

vv g[MAXN];

void dfs(ll x, ll fa){
	ll p=-1;
	fore(i,0,SZ(g[x])){
		ll y=g[x][i];
		if(y!=fa)dfs(y,x);
		else p=i;
	}
	if(p!=-1)g[x].erase(g[x].begin()+p);
	else assert(fa==-1);
}
char a[MAXN];
ll dp[MAXN][MAXN][2];

ll f(ll x, ll u, ll t){
	auto &res=dp[x][u][t];
	if(res!=-1)return res;
	res=0;
	if(t==0){
		res=f(x,u,t^1); // freno x
		for(auto y:g[x])addig(res,f(y,u,t)); // sigo x
	}
	else {
		res=0;
		if(a[x]==a[u]){ // freno u => uso (x,u) y bajo ambos 
			for(auto y:g[x])for(auto v:g[u])addig(res,f(y,v,t^1));
			addig(res,1); // a[x]+""
		}
		for(auto v:g[u])addig(res,f(x,v,t)); // sigo u
	}
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n)cin>>a[i];
		fore(i,0,n){
			g[i].clear();
			fore(j,0,n)fore(k,0,2)dp[i][j][k]=-1;
		}
		fore(i,0,n-1){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		dfs(0,-1);
		fore(x,0,n)cout<<f(x,x,0)<<" ";;cout<<"\n";
	}
	return 0;
}
