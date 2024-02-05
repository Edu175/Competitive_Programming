#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=25005;

vector<ll> g[MAXN];
ll cmp[MAXN];
ll qcmp=0;
void dfs(ll x){
	cmp[x]=qcmp;
	for(auto y:g[x])if(cmp[y]==-1)dfs(y);
}

int main(){FIN;
	ll n;
	while(cin>>n){
		ll m; cin>>m;
		fore(i,0,n){
			g[i].clear();
			cmp[i]=-1;
		}
		fore(i,0,m){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		qcmp=0;
		fore(i,0,n)if(cmp[i]==-1){
			dfs(i);
			qcmp++;
		}
		ll k; cin>>k;
		vector<ll> res(qcmp,-1);
		fore(i,0,k){
			ll x,c; cin>>x>>c; x--;
			if(res[cmp[x]]==-1||c<res[cmp[x]])res[cmp[x]]=c;
		}
		ll q; cin>>q;
		while(q--){
			ll x; cin>>x; x--;
			ll ans=res[cmp[x]];
			if(ans==-1)cout<<"MENUDO MARRON\n";
			else cout<<ans<<"\n";
		}
		cout<<"---\n";
	}
	return 0;
}
