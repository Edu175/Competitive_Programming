#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=85,INF=1e6+5;

vector<ii>g[MAXN];
ll n,k;
ll dp[MAXN][MAXN][MAXN];

ll f(ll x, ll e, ll c){
	ll &res=dp[x][e][c];
	if(res!=-1)return res;
	if(c==k)return res=0;
	//cout<<x<<"\n";
	ll l=x,r=e;
	if(l>r)swap(l,r);
	res=INF;
	for(auto i:g[x]){
		ll y=i.fst;
		if(!(l<y&&y<r))continue;
		//cout<<x<<": "<<y<<"\n";
		res=min(res,i.snd+f(y,l,c+1));
		res=min(res,i.snd+f(y,r,c+1));
	}
	//cout<<x<<" "<<e<<" "<<c<<": "<<res<<"\n";
	return res;
}

int main(){FIN;
	cin>>n>>k;
	mset(dp,-1);
	ll m; cin>>m;
	fore(i,0,m){
		ll u,v,w; cin>>u>>v>>w; //1-indexed
		g[u].pb({v,w});
	}
	fore(i,1,n+1)g[0].pb({i,0});
	ll res=f(0,n+1,0);
	if(res>=INF)cout<<"-1\n";
	else cout<<res<<"\n";
	return 0;
}
