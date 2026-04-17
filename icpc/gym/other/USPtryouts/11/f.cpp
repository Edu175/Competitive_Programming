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
const ll MAXN=1e5+5,MAXQ=2e5+5;
ll id[MAXN];
vv comp[MAXN];
set<ll> qs[MAXN];
ll ans[MAXQ];
void uf_init(ll n){
	fore(i,0,n){
		comp[i]={i};
		id[i]=i;
	}
}
void uf_join(ll a, ll b, ll w){
	a=id[a], b=id[b];
	if(a==b)return;
	if(SZ(comp[a])<SZ(comp[b]))swap(a,b);
	for(auto i:comp[b])comp[a].pb(i),id[i]=a;
	if(SZ(qs[a])<SZ(qs[b]))swap(qs[a],qs[b]);
	for(auto i:qs[b]){
		if(qs[a].count(i))ans[i]=w,qs[a].erase(i);
		else qs[a].insert(i);
	}
	qs[b].clear();
	comp[b].clear();
}
int main(){FIN;
	ll n,m; cin>>n>>m;
	vector<array<ll,3>> ed(m);
	fore(i,0,m){
		ll u,v,w; cin>>u>>v>>w; u--,v--;
		ed[i]={w,u,v};
	}
	ll q; cin>>q;
	fore(i,0,q){
		ll x,y; cin>>x>>y; x--,y--;
		qs[x].insert(i);
		qs[y].insert(i);
	}
	sort(ALL(ed));
	uf_init(n);
	for(auto [w,u,v]:ed)uf_join(u,v,w);
	fore(i,0,q)cout<<ans[i]<<"\n";
	return 0;
}
