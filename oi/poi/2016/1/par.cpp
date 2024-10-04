#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,skopul=b;i<skopul;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=2e5+5;

ll dp[MAXN];
ll res=0;

vector<ll>g[MAXN];

void dfs(ll x, ll fa=-1){
	vector<ll>p;
	for(auto y:g[x])if(y!=fa){
		dfs(y,x);
		p.pb(dp[y]);
	}
	ll sz=SZ(g[x]);
	if(SZ(p)) {
		sort(ALL(p)); reverse(ALL(p));
		dp[x]=p[0]+sz-2;
		res=max(res,dp[x]);
		if(SZ(p)>=2)res=max(res,p[0]+p[1]-4+sz);
	}
	dp[x]=max(dp[x],sz);
}

int main(){FIN;
	ll n; cin>>n;
	fore(i,0,n-1){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(0);
	cout<<res<<"\n";
	return 0;
}