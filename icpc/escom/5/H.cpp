#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

ii norm(ii u){if(u.fst>u.snd)swap(u.fst,u.snd);return u;}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		ll N=n;
		n*=3;
		vector<vv> g(n);
		map<ii,ll> idx;
		set<ii> st;
		fore(i,0,m){
			ll u,v; cin>>u>>v; u--,v--;
			st.insert(norm({u,v}));
			idx[norm({u,v})]=i;
			g[u].pb(v);
			g[v].pb(u);
		}
		vv vis(n);
		vv mat;
		while(SZ(mat)<N&&SZ(st)){
			auto [u,v]=*st.begin(); st.erase(st.begin());
			assert(!vis[u]&&!vis[v]);
			mat.pb(idx[{u,v}]);
			vis[u]=vis[v]=1;
			for(auto i:g[u])st.erase(norm({u,i}));
			for(auto i:g[v])st.erase(norm({v,i}));
		}
		vv inde;
		fore(i,0,n)if(!vis[i]&&SZ(inde)<N)inde.pb(i);
		assert(SZ(mat)==N||SZ(inde)==N);
		if(SZ(mat)==N){
			cout<<"Matching\n";
			for(auto i:mat)cout<<i+1<<" ";;cout<<"\n";
		}
		else if(SZ(inde)==N){
			cout<<"IndSet\n";
			for(auto i:inde)cout<<i+1<<" ";;cout<<"\n";
		}
	}
	return 0;
}
