#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef int ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=5005;

ll vis[MAXN][MAXN];
vector<pair<ll,char>> to[MAXN],ba[MAXN];
ll cnt=0;
void dfs(ll x, ll u){
	cnt++;
	vis[x][u]=1;
	for(auto [y,c]:ba[x])for(auto [v,d]:to[u])if(c==d&&!vis[y][v])dfs(y,v);
}

int main(){
	JET
	ll n,m; cin>>n>>m;
	fore(i,0,m){
		ll u,v; char c; cin>>u>>v>>c; u--,v--;
		to[u].pb({v,c});
		ba[v].pb({u,c});
	}
	fore(i,0,n)if(!vis[i][i])dfs(i,i);
	fore(x,0,n){
		for(auto [y,dkjfhg]:to[x]){
			if(!vis[x][y])dfs(x,y);
		}
	}
	cnt-=n;
	cout<<cnt<<"\n";
	return 0;
}