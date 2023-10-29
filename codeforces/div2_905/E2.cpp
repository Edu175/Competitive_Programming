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

map<ll,vector<ll>> g[MAXN]; //g[t][x]
ll vis[MAXN];
vector<ll> in[MAXN];
vector<ll> go[MAXN];

void add(ll x){
	for(auto t:in[x])go[t].pb(x);
}

int main(){FIN;
	ll n,t; cin>>n>>t;
	fore(i,0,t){
		ll m; cin>>m;
		fore(j,0,m){
			ll u,v; cin>>u>>v; u--,v--;
			g[i][u].pb(v);
			g[i][v].pb(u);
			if(!SZ(in[u])||in[u].back()!=i)in[u].pb(i);
			if(!SZ(in[v])||in[v].back()!=i)in[v].pb(i);
		}
	}
	ll q; cin>>q;
	vector<ll>a(q);
	fore(i,0,q)cin>>a[i],a[i]--;
	add(0);
	vis[0]=1;
	ll res=-1;
	fore(i,0,q){
		//cout<<i<<" "<<a[i]<<": ";
		//fore(i,0,n)if(vis[i])cout<<i<<" ";;cout<<"\n";
		vector<ll>upd;
		for(auto x:go[a[i]])for(auto y:g[a[i]][x])if(!vis[y]){
			vis[y]=1;
			upd.pb(y);
		}
		go[a[i]].clear();
		for(auto x:upd)add(x);
		if(vis[n-1]){
			res=i+1;
			break;
		}
	}
	cout<<res<<"\n";
	return 0;
}
