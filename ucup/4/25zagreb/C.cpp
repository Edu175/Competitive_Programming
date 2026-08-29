#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define snd second
#define fst first
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define show(x) {for(auto y:x)cout<<y<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
vector<vector<ii>> g;
vv col;
ll good;
void dfs(ll x){
	for(auto [y,w]:g[x]){
		ll nxt=(col[x]+w+3)%3;
		if(col[y]==-1){
			col[y]=nxt;
			dfs(y);
		}
		else good&=col[y]==nxt;
	}
}
int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ii> all;
		vector<pair<ii,ii>> ed;
		fore(i,0,n){
			vv a(3); fore(j,0,3)cin>>a[j];
			sort(ALL(a));
			do{
				ii u={a[0],a[1]};
				ii v={a[1],a[2]};
				all.pb(u);
				all.pb(v);
				ed.pb({u,v});
			}while(next_permutation(ALL(a)));
		}
		sort(ALL(all)); all.resize(unique(ALL(all))-all.begin());
		auto get_idx=[&](ii a)->ll {
			return lower_bound(ALL(all),a)-all.begin();
		};
		ll m=SZ(all);
		g.clear();
		g.resize(m);
		for(auto [_u,_v]:ed){
			ll u=get_idx(_u);
			ll v=get_idx(_v);
			g[u].pb({v,1});
			g[v].pb({u,-1});
		}
		col=vv(m,-1);
		good=1;
		fore(x,0,m)if(col[x]==-1){
			col[x]=0;
			dfs(x);
		}
		if(good)cout<<"no\n";
		else cout<<"yes\n";
	}
	return 0;
}