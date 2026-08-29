#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a, jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(x)  for(auto [a,i]:x){cout<<a<<" ";}cout<<"\n";
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll>  ii;

const int MAXN = 1e5+100, MAXM = 2e5+100;
vector<ii> g[MAXN];
ll ord[MAXN];
ll vis[MAXN], res[MAXM];
ll INF  = 1e8+100;
vv v;


void dfs(int x){
	v.pb(x);
	vis[x] = 1;
	for(auto [y,i]:g[x]) if(!vis[y]){
		res[i] = INF--;
		dfs(y);
	}
}

int main(){
	JET
	ll n,m; cin>>n>>m;
	fore(i,0,m){
		ll x,y; cin>>x>>y;x--,y--;
		g[x].pb({y,i});
		g[y].pb({x,i});
		res[i] = 1;
	}
	vv final;
	ll ini = -1;
	fore(i,0,n){	
		ll x; cin>>x; x--;
		if(ini < 0) ini = x;
		ord[x] = i;
		final.pb(x);	
	}
	if(ini != 0){
		cout<<"impossible\n";
		return 0;
	}
	fore(i,0,n) sort(ALL(g[i]),[&](ii a, ii b){return ord[a.fst]<ord[b.fst];});
	dfs(ini);
	if(v != final) cout<<"impossible";
	else fore(i,0,m)cout<<res[i]<<" ";
	cout<<"\n";
	return 0;
}