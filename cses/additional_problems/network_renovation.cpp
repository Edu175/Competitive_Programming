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
const ll MAXN=1e5+5;

vector<ll> g[MAXN];
ll vis[MAXN];
vector<ll>h;
ll rt=0;
void dfs(ll x){
	vis[x]=1;
	if(SZ(g[x])==1&&x!=rt)h.pb(x);
	for(auto y:g[x])if(!vis[y])dfs(y);
}

int main(){FIN;
	ll n; cin>>n;
	/*if(n==2){
		cout<<"1\n1 2\n";
		return 0;
	}*/
	fore(i,0,n-1){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	fore(i,0,n)if(SZ(g[i])==1){
		rt=i;
		break;
	}
	dfs(rt);
	vector<ii>ed;
	fore(i,0,SZ(h)/2)ed.pb({h[i],h[SZ(h)-1-i]});
	/*if(SZ(h)&1)*/ed.pb({rt,h[SZ(h)/2]});
	cout<<SZ(ed)<<"\n";
	for(auto [u,v]:ed)cout<<u+1<<" "<<v+1<<"\n";
	return 0;
}
