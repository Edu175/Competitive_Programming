#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=105,MAXM=MAXN;
vector<ii> g[MAXN];
ll a[MAXN];

map<ll,ll>mp;
ll vis[MAXN],nono;
void dfs(ll x){
	vis[x]=1;
	mp[a[x]]++;
	for(auto [y,i]:g[x])if(i!=nono&&!vis[y])dfs(y);
}

int main(){
	JET
	ll te; cin>>te;
	while(te--){
		ll n,m; cin>>n>>m;
		fore(i,0,n){
			g[i].clear();
		}
		fore(i,0,n)cin>>a[i];
		fore(i,0,m){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb({v,i});
			g[v].pb({u,i});
		}
		fore(i,0,m){
			nono=i;
			mset(vis,0);
			ll res=0;
			fore(i,0,n)if(!vis[i]){
				mp.clear();
				dfs(i);
				ll mx=0;
				for(auto i:mp)mx=max(mx,i.snd);
				res+=mx;
			}
			cout<<res<<" ";
		}
		cout<<"\n";
	}
	return 0;
}