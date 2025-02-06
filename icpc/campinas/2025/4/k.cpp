#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define pb push_back
#define ALL(x) x.begin(),x.end();
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=3e5+5,INF=MAXN*3;

vv g[MAXN];
ll is[MAXN],m,res=0,k;

ii dfs(ll x, ll fa){
	ll best=INF,nec=-INF;
	for(auto y:g[x])if(y!=fa){
		auto [b,n]=dfs(y,x);
		best=min(best,b);
		nec=max(nec,n);
	}
	best++,nec++;
	if(best+nec<=m)nec=-INF;
	if(best>m&&is[x])nec=max(nec,0ll);
	if(nec==m)res++,best=0,nec=-INF;
	return {best,nec};
}

bool can(ll _m){
	m=_m; res=0;
	auto [best,nec]=dfs(0,-1);
	if(nec>=0)res++;
	return res<=k;
}

int main(){
	JET
	ll n; cin>>n>>k;
	fore(i,0,n)cin>>is[i];
	fore(i,0,n-1){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	ll l=0,r=n-1;
	while(l<=r){
		ll m=(l+r)/2;
		if(can(m))r=m-1;
		else l=m+1;
	}
	cout<<l<<"\n";
	return 0;
}