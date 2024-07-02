#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll INF=1e15,MAXN=50*50+6;
vector<ii> g[MAXN];
ll n,m;
ll cv(ii i){return m*i.fst+i.snd;}
ii cv(ll x){return {x/m,x%m};}
int main(){FIN;
	ll k; cin>>n>>m>>k;
	ii s; cin>>s.fst>>s.snd; s.fst--,s.snd--;
	ll a[n][m];
	// ll mx=-1;
	fore(i,0,n)fore(j,0,m)cin>>a[i][j];
	fore(x,0,n*m){
		auto [i,j]=cv(x);
		g[x].pb({x,a[i][j]});
		if(i)g[x].pb({cv({i-1,j}),a[i-1][j]});
		if(j)g[x].pb({cv({i,j-1}),a[i][j-1]});
		if(i<n-1)g[x].pb({cv({i+1,j}),a[i+1][j]});
		if(j<m-1)g[x].pb({cv({i,j+1}),a[i][j+1]});
	}
	ll p=min(k,6000ll);
	vector<ll>dp(n*m,-INF); dp[cv(s)]=0;
	fore(i,0,p){
		vector<ll>dpi(n*m,-INF);
		fore(x,0,n*m){
			for(auto [y,w]:g[x])dpi[y]=max(dpi[y],w+dp[x]);
		}
		dp=dpi;
	}
	// imp(dp);
	ll res=-INF;
	fore(i,0,n)fore(j,0,m)
		res=max(res,max(k-p,0ll)*a[i][j]+dp[cv({i,j})]);
	// if(p<k)res+=(k-p)*mx;
	cout<<res<<"\n";
	return 0;
}
