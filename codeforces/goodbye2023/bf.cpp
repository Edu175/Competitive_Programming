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
const ll MAXN=3e5+5;

vector<ll> g[MAXN];
ll c[MAXN],d[MAXN],fa[MAXN];
void dfs(ll x){
	for(auto y:g[x]){
		d[y]=d[x]+1;
		fa[y]=x;
		dfs(y);
	}
}

ll query(ll x, ll y){
	if(d[x]>d[y])swap(x,y);
	set<ll>sx,sy;
	while(d[y]>d[x])sy.insert(c[y]),y=fa[y];
	while(x!=y){
		sx.insert(c[x]),x=fa[x];
		sy.insert(c[y]),y=fa[y];
	}
	sx.insert(c[x]);
	sy.insert(c[y]);
	return SZ(sx)*SZ(sy);
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n){
			g[i].clear();
		}
		fore(i,1,n){
			ll p; cin>>p; p--;
			g[p].pb(i);
		}
		fore(i,0,n)cin>>c[i],c[i]--;
		dfs(0);
		//vector<ll>h;
		//fore(i,0,n)if(SZ(g[i])==0)h.pb(i);
		ll res=0;
		fore(i,0,n)fore(j,i,n){
			res=max(res,query(i,j));
		}
		cout<<res<<"\n";
	}
	return 0;
}
