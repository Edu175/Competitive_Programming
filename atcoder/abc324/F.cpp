#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> ii;
const ll MAXN=2e5+5;

vector<pair<ll,ii>> g[MAXN];

ii maxi(ii a, ii b){
	if(a.fst*b.snd>b.fst*a.snd)return a;
	return b;
}

ii dp[MAXN];
ll n;

ii f(ll x){
	ii &res=dp[x];
	if(res.fst!=-1)return res;
	res={0,0};
	if(x==n-1)return res;
	for(auto i:g[x]){
		ll y=i.fst,b=i.snd.fst,c=i.snd.snd;
		ii nx=f(y);
		res=maxi(res,{nx.fst+b,nx.snd+c});
	}
	cout<<x<<": "<<res.fst<<"/"<<res.snd<<" = "<<ld(res.fst)/ld(res.snd)<<"\n";
	return res;
}

int main(){FIN;
	cin>>n;
	ll m; cin>>m;
	fore(i,0,m){
		ll u,v,b,c; cin>>u>>v>>b>>c; u--,v--;
		g[u].pb({v,{b,c}});
	}
	fore(i,0,n+2)dp[i]={-1,-1};
	ii res=f(0);
	ld ans=ld(res.fst)/ld(res.snd);
	cout<<fixed<<setprecision(15)<<ans<<"\n";
	return 0;
}
