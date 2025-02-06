#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b; i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=1e5+5,INF=1e17; // 1e12

vector<ii> g[MAXN];
ll cost[MAXN];
ll a[MAXN];
ll res=-INF, best=INF;
void dfs(ll x, ll fa, ll d, ll can){
	ll resi=d+a[x];
	if(can&&(resi>res||(res==resi&&x<best)))res=resi,best=x;
	for(auto [y,i]:g[x])if(y!=fa){
		dfs(y,x,d-cost[i],1);
	}
}

int main(){
	JET
	ll n,q; cin>>n>>q;
	assert(n>1);
	map<ii,ll>ed;
	fore(i,0,n)cin>>a[i];
	fore(i,0,n-1){
		ll u,v,w; cin>>u>>v>>w; u--,v--;
		g[u].pb({v,i});
		g[v].pb({u,i});
		if(u>v)swap(u,v);
		ed[{u,v}]=i;
		cost[i]=w;
	}
	ll now=0;
	while(q--){
		ll ty; cin>>ty;
		if(ty==1){
			ll x,w; cin>>x>>w; x--;
			a[x]=w;
		}
		else {
			ll x,y,w; cin>>x>>y>>w; x--,y--;
			if(x>y)swap(x,y);
			cost[ed[{x,y}]]=w;
		}
		res=-INF; best=INF;
		dfs(now,-1,0,0);
		now=best;
		cout<<now+1<<" ";
	}
	cout<<"\n";
	return 0;
}