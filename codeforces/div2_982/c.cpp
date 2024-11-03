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
const ll MAXN=3e5+5;

map<ll,vector<ll>> g;
ll res=0;
set<ll>st;
void dfs(ll x){
	st.insert(x);
	res=max(res,x);
	for(auto y:g[x])if(!st.count(y))dfs(y);
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		// fore(i,0,n){
		// 	vis[i]=0;
		// 	g[i].clear();
		// }
		st.clear();
		g.clear();
		vv a(n);
		fore(i,0,n){
			cin>>a[i]; a[i]--;
			ll u=a[i]+1+i,v=u+i;
			g[u].pb(v);
		}
		res=0;
		dfs(n);
		cout<<res<<"\n";
		
	}
	return 0;
}
