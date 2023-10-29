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
const ll MAXN=2e5+5;

vector<ll>g[MAXN];
ll n;

ll a[MAXN];
ll h[MAXN],ch[MAXN]; //hijos, complement hijos
ll f[MAXN],c[MAXN];

void dfs1(ll x){
	c[x]=1;
	for(auto y:g[x])if(y!=f[x]){
		f[y]=x;
		dfs1(y);
		c[x]+=c[y];
		h[x]=h[x]+h[y]+(a[x]^a[y])*c[y];
	}
}

void dfs2(ll x){
	for(auto y:g[x])if(y!=f[x]){
		ch[y]=ch[x]+(a[x]^a[y])*(n-c[y])+h[x]-(h[y]+(a[x]^a[y])*c[y]);
		dfs2(y);
	}
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		fore(i,0,n){
			g[i].clear();
			h[i]=0;
		}
		fore(i,0,n)cin>>a[i];
		fore(i,0,n-1){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		ch[0]=0; f[0]=-1;
		dfs1(0);
		dfs2(0);
		fore(i,0,n){
			//cout<<"\n"<<i<<": "<<c[i]<<" : "<<h[i]<<"+"<<ch[i]<<" = ";
			cout<<h[i]+ch[i]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
