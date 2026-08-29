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
const ll MAXN=2e5+5;

vv g[MAXN],gt[MAXN],ord;
ll vis[MAXN],cmp[MAXN],truth[MAXN],qcmp=0,n;
void dfsk(ll x, ll t){
	vis[x]=1; if(t)cmp[x]=qcmp;
	for(auto y:t?gt[x]:g[x])if(!vis[y])dfsk(y,t);
	if(!t)ord.pb(x);
}
void scc(ll n){
	qcmp=0; ord.clear(); fore(i,0,n)vis[i]=0;
	fore(i,0,n)if(!vis[i])dfsk(i,0);
	reverse(ALL(ord)); fore(i,0,n)vis[i]=0;
	for(auto x:ord)if(!vis[x])dfsk(x,1),qcmp++;
}

int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		fore(i,0,n){
			g[i].clear();
			gt[i].clear();
		}
		fore(i,0,m){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
			gt[v].pb(u);
		}
		scc(n);
		if(qcmp==1)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}