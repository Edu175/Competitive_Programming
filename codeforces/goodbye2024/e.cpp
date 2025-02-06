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

ll c[MAXN],cb[MAXN],fa[MAXN];

void dfs(ll x){
	cb[x]=c[x]==0;
	for(auto y:g[x])if(y!=fa[x]){
		fa[y]=x;
		dfs(y);
		cb[x]+=cb[y];
	}
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n){
			g[i].clear();
			c[i]=0;
			cb[i]=0;
		}
		ll ch=0;
		fore(i,0,n-1){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		fore(x,0,n)if(SZ(g[x])==1){
			c[x]=2; ch++;
			for(auto y:g[x])c[y]=max(c[y],1ll);
		}
		fa[0]=-1;
		dfs(0);
		ll tot=0;
		fore(i,0,n)tot+=c[i]==0;
		// fore(x,0,n)cout<<c[x]<<" ";;cout<<"\n";
		ll res=ch*(n-ch),un=0;
		// cout<<"hoj "<<res<<"\n";
		ll bef=res;
		fore(x,0,n)if(c[x]!=2){
			ll flag=c[x]==0;
			for(auto y:g[x])flag&=c[y]==1;
			un+=flag;
			for(auto y:g[x])if(c[y]==1){
				ll q=y==fa[x]?tot-cb[x]:cb[y];
				res+=q;
			}
		}
		// cout<<"un "<<un<<"\n";
		// cout<<"resto "<<res-bef<<"\n";		
		// res+=un;
		cout<<res<<"\n";
	}
	return 0;
}
