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

vv g[MAXN];
#define maxig(a,b) a=max(a,b)
vector<vv> dfs(ll x, ll fa){ // tag, bo
	vector<vector<vv>> got;
	for(auto y:g[x])if(y!=fa)got.pb(dfs(y,x));
	vector<vv> all(2,vv(2));
	ll m=SZ(got);
	fore(i,0,m){
		fore(w,0,2)all[w][0]+=got[i][w][0];
	}
	fore(w,0,2)all[w][1]=-INF;
	fore(w,0,2)fore(i,0,m){
		maxig(all[w][1],all[w][0]+got[i][w][1]-got[i][w][0]);
	}
	vector<vv> ans(2,vv(2));
	fore(bo,0,2){
		ll all0=all[0][bo],all1=all[1][bo];
		ans[0][bo]=max(all0,1+all1);
		ans[1][bo]=all0;
	}
	fore(w,0,2)maxig(ans[w][1],(SZ(g[x])==1)+all[0][0]);
	return ans;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n)g[i].clear();
		fore(i,0,n-1){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		// if(n<=2){
		// 	cout<<n<<"\n";
		// 	continue;
		// }
		auto ans=dfs(0,-1);
		ll res=ans[0][1];
		cout<<res<<"\n"; 
	}
	return 0;
}
