#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=5005;

vector<ll> g[MAXN];
ll val[MAXN];

int main(){FIN;
	ll n,m; cin>>n>>m;
	vector<ii>ed;
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		ed.pb({u,v});
	}
	vector<ll>w(n),a(n);
	vector<ii>b(n);
	fore(i,0,n)cin>>w[i],b[i]={w[i],i};
	fore(i,0,n)cin>>a[i];
	for(auto [u,v]:ed){
		if(w[u]==w[v])continue;
		if(w[u]<w[v])swap(u,v);
		g[u].pb(v);
	}
	sort(ALL(b)); // reverse(ALL(b));
	for(auto [wi,x]:b){
		ll m=SZ(g[x]);
		vector<vector<ll>>dp(m+5,vector<ll>(wi+5));
		for(ll i=m-1;i>=0;i--)fore(s,0,wi+3){
			dp[i][s]=dp[i+1][s];
			ll y=g[x][i];
			if(s+w[y]<wi)dp[i][s]=max(dp[i][s],val[y]+dp[i+1][s+w[y]]);
		}
		val[x]=1+dp[0][0];
	}
	ll res=0;
	fore(i,0,n)res+=a[i]*val[i];
	cout<<res<<"\n";
	return 0;
}
