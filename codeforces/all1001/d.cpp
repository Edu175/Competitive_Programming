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
ll dfs(ll x, ll fa){
	auto [l,r]=a[x];
	// cout<<x<<" "<<p<<": "<<l<<","<<r<<": ";
	
	vv opt;
	for(auto y:g[x])if(y!=fa)opt.pb(dfs(y,x));
	
	if(!SZ(opt))return l;
	
	sort(ALL(opt));
	ll p=opt.back();
	if(p>r)p=r;
	if(p<l)p=l;
	
	for(auto i:opt)res+=max(0ll,i-p);
	return p;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n){
			g[i].clear();
		}
		res=0;
		
		fore(i,0,n)cin>>a[i].fst>>a[i].snd;
		fore(i,0,n-1){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		res+=dfs(0,-1);
		cout<<res<<"\n";
	}
	return 0;
}
