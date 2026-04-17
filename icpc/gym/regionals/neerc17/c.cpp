#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=1e5+5,MAXM=MAXN;

ll vis[MAXN];

vector<ii>no;
vv g[MAXN];
ll cnt=0;
void dfs(ll x){
	vis[x]=++cnt;
	vv cand;
	for(auto y:g[x]){
		if(!vis[y])dfs(y);//,cerr<<"tree "<<x<<","<<y<<"\n";
		else {
			cand.pb(y);
			// else cerr<<"back good "<<x<<","<<y<<"\n";
		}
	}
	sort(ALL(cand),[&](ll x, ll y){return vis[x]<vis[y];});
	fore(i,1,SZ(cand))no.pb({x,cand[i]});
}

int main(){
    JET
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		fore(i,0,n)g[i].clear(),vis[i]=0;
		cnt=0;
		no.clear();
		fore(i,0,m){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
		}
		dfs(0);
		ll des=m-2*n; //cerr<<"des "<<des<<"\n";
		no.resize(des);
		for(auto [x,y]:no)cout<<x+1<<" "<<y+1<<"\n";
	}
    return 0;
}