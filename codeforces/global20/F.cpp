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
const ll MAXN=2e5+5;

vv g[MAXN];
ll vis[MAXN];
ll hay=0;
void dfs(ll x){
	vis[x]=1;
	for(auto y:g[x]){
		if(vis[y]==1)hay=1;
		if(!vis[y])dfs(y);
	}
	vis[x]=2;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n){
			g[i].clear();
			vis[i]=0;
		}
		hay=0;
		vv a(n),b(n);
		vv oc(n);
		fore(i,0,n)cin>>a[i],a[i]--,oc[a[i]]++;
		fore(i,0,n)cin>>b[i],b[i]--;
		ll mx=max_element(ALL(oc))-oc.begin();
		fore(i,0,n){
			ll u=a[i],v=b[i];
			if(u!=mx&&v!=mx)g[u].pb(v);
		}
		fore(i,0,n)if(!vis[i])dfs(i);
		if(hay)cout<<"WA\n";
		else cout<<"AC\n";
	}
	return 0;
}
