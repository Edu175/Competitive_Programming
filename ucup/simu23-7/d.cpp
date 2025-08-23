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
vector<ii> g[MAXN];
// vv fu[MAXN];

ll is[MAXN],vis[MAXN];

void dfs(ll x, ll c){
	if(vis[x]||!is[x])return;
	vis[x]=1;
	for(auto [y,w]:g[x])if(w==c)dfs(y,c);
}

bool good(vv s){
	for(auto i:s)is[i]=1;
	ll fg=1;
	fore(c,0,2){
		dfs(s[0],c);
		for(auto i:s)fg&=vis[i],vis[i]=0;
	}
	for(auto i:s)is[i]=0;
	return fg;
}
// ll res=0;
vv s;
set<vv> st;
vv so(vv s){
	sort(ALL(s));
	return s;
}
void go(ll x){
	if(count(ALL(s),x))return;
	s.pb(x);
	if(good(s))st.insert(so(s));
	if(SZ(s)<4){
		for(auto [y,dslf]:g[x])go(y);
	}
	s.pop_back();
}

int main(){FIN;
	// ll t; cin>>t;
	// while(t--){
		ll n,m; cin>>n>>m;
		fore(i,0,n){
			g[i].clear();
		}
		fore(i,0,m){
			ll u,v,w; cin>>u>>v>>w; u--,v--;
			g[u].pb({v,w});
			g[v].pb({u,w});
		}
		st.clear();
		fore(x,0,n){
			go(x);
		}
		cout<<SZ(st)<<"\n";
	// }
	return 0;
}
