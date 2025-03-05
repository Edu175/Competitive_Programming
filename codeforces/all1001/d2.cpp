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
typedef ll node;
const ll MAXN=2e5+5;

vv g[MAXN];
ii a[MAXN];
ll res=0;
void dfs(ll x, ll fa, ll p){
	auto [l,r]=a[x];
	// cout<<x<<" "<<p<<": "<<l<<","<<r<<": ";
	if(l>=p)res+=l-p,p=l;
	else if(r<=p)p=r;
	// cout<<p<<"\n";
	for(auto y:g[x])if(y!=fa)dfs(y,x,p);
}


ll cost(ll x, ll p){
	res=0;
	dfs(x,-1,p);
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n){
			g[i].clear();
		}
		// res=0;
		
		fore(i,0,n)cin>>a[i].fst>>a[i].snd;
		fore(i,0,n-1){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		ll x=0;
		fore(i,0,n)if(a[i].snd<a[x].snd)x=i;
		
		ll l=0,r=a[x].snd;
		ll def=cost(x,r);
		while(l<=r){
			ll m=(l+r)/2;
			if(cost(x,m)==def)r=m-1;
			else l=m+1;
		}
		ll res=def+l;
		dfs(x,-1,a[x].snd);
		cout<<res<<"\n";
	}
	return 0;
}
