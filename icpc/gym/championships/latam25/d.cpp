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
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=3e5+5;

ll lazy[MAXN],val[MAXN],id[MAXN];
vv comp[MAXN];

void uf_join(ll a, ll b){
	a=id[a],b=id[b];
	if(a==b)return;
	if(SZ(comp[a])<SZ(comp[b]))swap(a,b);
	// lazy[a]+=SZ(comp[b])*w;
	// lazy[b]+=SZ(comp[a])*w;
	for(auto i:comp[b]){
		id[i]=a;
		val[i]+=lazy[b]-lazy[a];
		comp[a].pb(i);
	}
	comp[b].clear();
}
ll sz(ll x){return SZ(comp[id[x]]);}
vv g[MAXN];
int main(){
	JET
	ll n,m; cin>>n>>m;
	fore(i,0,n)id[i]=i,comp[i]={i};
	vv a(n);
	vector<ii> sa;
	fore(i,0,n)cin>>a[i],sa.pb({a[i],i});
	sort(ALL(sa));
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	vv vis(n);
	for(auto [v,x]:sa){
		assert(id[x]==x);
		ll tot=1;
		set<ll>st;
		for(auto y:g[x])if(vis[y])st.insert(id[y]);
		for(auto y:st)tot+=sz(y);
		for(auto y:st)lazy[y]+=(tot-sz(y))*v;
		val[x]+=tot*v; // o lazy ahora
		for(auto y:st)uf_join(x,y);
		vis[x]=1;
	}
	fore(i,0,n)val[i]+=lazy[id[i]];
	fore(i,0,n)cout<<val[i]<<" ";;cout<<"\n";
	return 0;
}