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
const ll MAXN=2e5+5,INF=1e18;
map<ll,ll> all;
vector<ll> comp[MAXN]; ll id[MAXN];
map<ll,ll> cnt[MAXN];
ll mex[MAXN];
vv vals;
ll get_prev(ll x){
	auto ptr=lower_bound(ALL(vals),x);
	if(ptr==vals.begin())return -1;
	return *(--ptr);
}
void uf_init(ll n){ // given vals
	fore(i,0,n){
		comp[i]={i};
		id[i]=i;
		cnt[i].clear();
		mex[i]=vals.back();
	}
}
bool uf_join(ll x, ll y, ll w){
	x=id[x], y=id[y];
	if(x==y)return 0;
	if(SZ(comp[x])<SZ(comp[y]))swap(x,y);
	for(auto i:comp[y])comp[x].pb(i), id[i]=x;
	for(auto i:cnt[y])cnt[x][i.fst]+=i.snd;
	auto &e=mex[x];
	e=min(e,mex[y]);
	while(cnt[x][e]==all[e])e=get_prev(e);
	comp[y].clear(); cnt[y].clear();
	return 1;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		uf_init(n);
		vector<array<ll,3>> ed;
		fore(i,0,m){
			ll u,v,w; cin>>u>>v>>w; u--,v--;
			ed.pb({w,u,v});
		}
		sort(ALL(ed));
		ll sum=0,tree=1;
		fore(i,0,n-1)sum+=ed[i][0],tree&=uf_join(ed[i][1],ed[i][2]);
		if(!tree){
			cout<<sum<<"\n";
			continue;
		}
		ll res=INF;
		if(m>=n+1)res=sum-ed[n-3][0]-ed[n-2][0]+ed[n-1][0]+ed[n][0];
		
	}
	return 0;
}
