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
const ll MAXN=2e5+5;

vv g[MAXN];
ii par[MAXN];
ll a[MAXN];
set<ll> st;
void dfs1(ll x, ll fa){
	st.erase(a[x]);
	auto it=st.begin();
	par[x]={*it,*(++it)};
	for(auto y:g[x])if(y!=fa)dfs1(y,x);
	st.insert(a[x]);
}

ll res=0;
pair<map<ll,ll>,multiset<ll>> dfs2(ll x, ll fa){
	map<ll,ll> mp;
	multiset<ll> ms;
	ll del=par[x].snd-par[x].fst;
	mp[par[x].fst]=del;
	ms.insert(del);
	
	for(auto y:g[x])if(y!=fa){
		auto got=dfs2(y,x);
		if(SZ(got.fst)+SZ(got.snd)>SZ(mp)+SZ(ms)){
			swap(mp,got.fst);
			swap(ms,got.snd);
		}
		for(auto [a,b]:got.fst){
			if(mp[a])ms.erase(ms.find(mp[a]));
			mp[a]+=b;
			ms.insert(mp[a]);
		}
	}
	while(SZ(mp)&&mp.begin().fst<)
	cout<<x<<": ";
	for(auto i:mp)cout<<i.fst<<","<<i.snd<<" ";
	cout<<"\n";
	if(SZ(ms))res=max(res,*ms.rbegin());
	return {mp,ms};
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n){
			g[i].clear();
			
		}
		st.clear();
		fore(i,0,n+2)st.insert(i);
		
		fore(i,0,n)cin>>a[i];
		fore(i,0,n-1){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		
		dfs1(0,-1);
		ll fij=0;
		fore(x,0,n)fij+=par[x].fst;
		res=0;
		dfs2(0,-1);
		cout<<fij+res<<"\n";
	}
	return 0;
}
