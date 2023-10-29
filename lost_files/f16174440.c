#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oia=b; i<oia; i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto asd:v)cout<<asd<<" ";cout<<"\n"
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=1e5+5;

vector<ii> g[MAXN];
ll a[MAXN];
vector<ll> b;
ll vol=0;

void dfs(ll x){
	b.pb(vol);
	ll d=0;
	for(auto [di,y]:g[x])vol+=di-d,d+=di-d,dfs(y);
	vol+=a[i]-d;
}

int main(){FIN;
	ll n; cin>>n;
	fore(i,0,n)cin>>a[i];
	fore(i,0,n-1){
		ll u,d,v; cin>>u>>d>>v; u--,v--;
		g[u].pb({a[u]-d,v});
	}
	fore(i,0,n)sort(ALL(g[i]));
	dfs(0);
	ll q; cin>>q;
	while(q--){
		ll k; cin>>k;
		ll res=lower_bound(ALL(b),k)-b.begin();
		cout<<res<<" ";
	}
	cout<<"\n";
	return 0;
}
