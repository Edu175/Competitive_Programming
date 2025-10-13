#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=5005;

vv g[MAXN];

ll D[MAXN];

void dfs(ll x, ll fa){
	for(auto y:g[x])if(y!=fa){
		D[y]=D[x]+1;
		dfs(y,x);
	}
}

int main(){FIN;
	ll n; cin>>n;
	fore(i,0,n-1){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	vector<ll> ans(n+1);
	fore(x,0,n){
		D[x]=0;
		dfs(x,-1);
		vv ds(n);
		fore(x,0,n)ds[x]=D[x];
		sort(ALL(ds));
		vv sp(n+1);
		fore(i,1,n+1)sp[i]=sp[i-1]+ds[i-1];
		// imp(sp);
		fore(k,0,n+1){
			ll cur=(n-1)*k-2*sp[k];
			// cout<<k<<","<<cur<<" ";;
			ans[k]=max(ans[k],cur);
		}
		// cout<<"\n";
	}
	fore(k,0,n+1)cout<<ans[k]<<" ";;cout<<"\n";
	return 0;
}
