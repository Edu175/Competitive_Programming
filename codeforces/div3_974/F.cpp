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
const ll MAXN=2e5+5;

vector<ll> g[MAXN];
ll a[MAXN];
ll dp[MAXN][2];
bool vis[MAXN][2];
ll k;
ll f(ll x, ll fg, ll fa=-1){
	ll &res=dp[x][fg];
	if(vis[x][fg])return res;
	vis[x][fg]=1;
	ll go0=0,go1=a[x];
	if(fg)go1-=2*k;
	for(auto y:g[x])if(y!=fa){
		go0+=f(y,0,x);
		go1+=f(y,1,x);
	}
	return res=max(go0,go1);
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n>>k;
		fore(i,0,n)cin>>a[i];
		fore(i,0,n){
			fore(j,0,2)vis[i][j]=0;
			g[i].clear();
		}
		fore(i,0,n-1){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		ll res=f(0,0);
		cout<<res<<"\n";
	}
	return 0;
}
