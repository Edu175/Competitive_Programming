#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(a) {for(auto x:a)cout<<x<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
const ll MAXN=1e5+5;

vv g[MAXN];
ll cnt;
ll nl[MAXN];

void dfs(ll x, ll fa){
	auto ptr=find(ALL(g[x]),fa);
	if(ptr!=g[x].end())g[x].erase(ptr);
	for(auto y:g[x])dfs(y,x);
	nl[x]=cnt++;
}
ll n;
ll greedy(ll k){
	vector<ii> dp(n);
	fore(x,0,n){
		ll res=0;
		ll mx1=-1,mx2=-1;
		for(auto y:g[x]){
			auto &[cur,di]=dp[y];
			res+=cur;
			if(di>mx1)mx2=mx1,mx1=di;
			else if(di>mx2)mx2=di;
		}
		mx1++,mx2++;
		if(mx1+mx2>=k)res++,mx1=-1;
		dp[x]={res,mx1};
	}
	return dp[n-1].fst;
}
// const ll B=0;
const ll B=1300;

int main(){
	JET
	cin>>n;
	fore(i,0,n-1){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(0,-1);
	vector<vv> _g(n); fore(i,0,n)_g[i]=g[i],g[i].clear();
	fore(x,0,n)for(auto y:_g[x])g[nl[x]].pb(nl[y]);
	fore(x,0,n)for(auto y:g[x])assert(y<x);
	vv ans(n);
	ll u=n+5,p=-1;
	fore(k,0,min(B,n))u=ans[k]=greedy(k),p=k;
	while(u){
		ll l=p,r=n;
		while(r-l>1){
			ll m=(l+r)/2;
			if(greedy(m)==u)l=m;
			else r=m;
		}
		p=r;
		if(p)ans[p-1]=greedy(p-1);
		if(p>=n)break;
		u=ans[p]=greedy(p);
	}
	for(ll i=n-2;i>=0;i--)ans[i]=max(ans[i],ans[i+1]);
	fore(i,0,n)cout<<ans[i]<<"\n";
	return 0;
}
