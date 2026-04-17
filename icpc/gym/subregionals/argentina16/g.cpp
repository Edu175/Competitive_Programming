#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=1e5+5;

ll xs[MAXN];
vector<ii>g[MAXN];

void dfs(ll x, ll fa=-1){
	for(auto [y,w]:g[x])if(y!=fa){
		xs[y]=xs[x]^w;
		dfs(y,x);
	}
}

int main(){JET
	ll n; cin>>n;
	fore(i,0,n-1){
		ll u,v,w; cin>>u>>v>>w; u--,v--;
		g[u].pb({v,w});
		g[v].pb({u,w});
	}
	dfs(0);
	vector<ll>a(n);
	fore(i,0,n)a[i]=xs[i];
	sort(ALL(a));
	// fore(i,0,n)cout<<xs[i]<<" ";;cout<<"\n";
	fore(i,0,n){
		ll x=0;
		for(ll j=31;j>=0;j--){
			ll busco=!(xs[i]>>j&1),key=x+(busco<<j);
			ll hay=lower_bound(ALL(a),key+(1ll<<j))-
			 	   lower_bound(ALL(a),key);
			if(hay)x|=busco<<j;
			else x|=(!busco)<<j;
			// cout<<j<<" "<<x<<": "<<busco<<" "<<hay<<"\n";
		}
		cout<<(x^xs[i])<<"\n";
		
		//debug
		// ll mx=0;
		// fore(j,0,n)mx=max(mx,xs[j]^xs[i]);
		// cout<<mx<<"\n\n";
		
	}
	return 0;
}