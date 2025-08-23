#include<bits/stdc++.h>
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
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=1e6+5;

vv g[MAXN];

ll vis[MAXN];
void dfs(ll x){
	vis[x]=1;
	for(auto y:g[x])if(!vis[y])dfs(y);
}

int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		fore(i,0,n){
			g[i].clear();
			vis[i]=0;
		}
		fore(i,0,m){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		dfs(0);
		vv wh[2];
		fore(i,0,n)wh[vis[i]].pb(i);
		if(SZ(wh[1])==n)cout<<"No\n";
		else {
			cout<<"Yes\n";
			swap(wh[0],wh[1]);
			cout<<SZ(wh[0])<<" "<<SZ(wh[1])<<"\n";
			for(auto i:wh[0])cout<<i+1<<" ";;cout<<"\n";
			for(auto i:wh[1])cout<<i+1<<" ";;cout<<"\n";
		}
	}
	return 0;
}