#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

int main(){
	JET
	ll n,m; cin>>n>>m;
	vv g[n];
	ll res=0;
	fore(i,0,m){
		ll u,v; cin>>u>>v;
		if(u%2==v%2)res++;
		g[u].pb(v);
		g[v].pb(u);
	}
	vv a(n); fore(i,0,n)a[i]=i&1;
	ll ans=res,mx=0;
	
	fore(x,0,n){
		for(auto y:g[x])if(a[y]==a[x])res--;
		a[x]^=1;
		for(auto y:g[x])if(a[y]==a[x])res++;
		ans=min(ans,res);
		if(ans==res)mx=x;
	}
	fore(i,0,mx+1)a[i]^=1;
	// cerr<<mx<<"\n";
	cout<<(ans+(n&1))<<"\n";
	fore(i,0,n)cout<<a[i]<<" ";;cout<<"\n";
	return 0;
}