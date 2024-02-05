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
const ll MAXN=1e5+5;

vector<ll> g[MAXN];
ll c[MAXN],d[MAXN],h[MAXN];

void dfs(ll x, ll f){
	if(SZ(g[x])==1&&x!=0)c[x]=1,h[x]=0;
	for(auto y:g[x])if(y!=f){
		d[y]=d[x]+1;
		dfs(y,x);
		c[x]+=c[y];
		h[x]=min(h[x],h[y]);
	}
	h[x]++;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n){
			g[i].clear();
			c[i]=0;
			d[i]=0;
			h[i]=n;
		}
		fore(i,0,n-1){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		dfs(0,-1);
		fore(i,0,n)h[i]--;
		ll res=0;
		fore(i,0,n){
			//cout<<i<<": "<<d[i]<<" "<<h[i]<<" "<<c[i]<<"\n";
			if(h[i]&&h[i]<=d[i])res=max(res,c[i]);
		}
		cout<<res<<"\n";
	}
	return 0;
}
