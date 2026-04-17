#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=6,n=6;

ll g[MAXN][MAXN];
ll vis[MAXN];

void dfs(ll x){
	vis[x]=1;
	fore(y,0,n)if(g[x][y]&&!vis[y])dfs(y);
}

bool good(vector<ii> ed){
	vv deg(n),us(n);
	mset(vis,0);
	mset(g,0);
	for(auto [x,y]:ed){
		g[x][y]=g[y][x]=1;
		us[x]=us[y]=1;
		deg[x]++; deg[y]++;
	}
	if(!SZ(ed))return 0;
	ll cnt=0;
	fore(x,0,n)cnt+=deg[x]&1;
	assert(cnt%2==0);
	if(cnt>2)return 0;
	fore(x,0,n)if(us[x]){
		dfs(x);
		break;
	}
	ll fg=1;
	fore(x,0,n)if(us[x])fg&=vis[x];
	return fg; // que sea conexo
}

int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll m; cin>>m;
		vector<ii> a;
		fore(i,0,m){
			ll u,v; cin>>u>>v; u--,v--;
			a.pb({u,v});
		}
		ll res=0;
		fore(mk,0,1ll<<m){
			vector<ii> ed;
			fore(i,0,m)if(mk>>i&1)ed.pb(a[i]);
			res+=good(ed);
		}
		cout<<res<<"\n";
	}
	return 0;
}