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
const ll MAXN=5e5+5;

vv g[MAXN];

ll D[MAXN],fa[MAXN],deg[MAXN]; // para abajo

void dfs(ll x){
	for(auto y:g[x])if(y!=fa[x]){
		// deg[x]++;
		D[y]=D[x]+1;
		fa[y]=x;
		dfs(y);
	}
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n){
			g[i].clear();
			deg[i]=0;
		}
		fore(i,0,n-1){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		D[0]=0; fa[0]=-1;
		dfs(0);
		vector<vv> hist(n);
		fore(i,0,n)hist[D[i]].pb(i);
		ll cant=0,res=0; // max res, then n-res
		
		auto pon=[&](ll x){
			// cout<<"pongo a "<<x<<"\n";
			if(fa[x]!=-1)deg[fa[x]]++;
			cant++;
		};
		auto sac=[&](ll x, auto &&sac)->void { // if
			if(deg[x]==0){
				// cout<<"saco a "<<x<<"\n";
				assert(x);
				deg[fa[x]]--,cant--;
				sac(fa[x],sac);
			}
		};
		fore(d,0,n){
			if(!SZ(hist[d]))break;
			// cout<<"\ndepth "<<d<<"\n";
			for(auto i:hist[d])pon(i);
			if(d){
				for(auto i:hist[d-1])sac(i,sac);
			}
			// cout<<"cant "<<cant<<"\n";
			res=max(res,cant);
		}
		cout<<n-res<<"\n";
	}
	return 0;
}
