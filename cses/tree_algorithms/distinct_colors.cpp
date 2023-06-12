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
const ll MAXN=2e5+5;

vector<ll>g[MAXN];
ll c[MAXN],res[MAXN];

vector<ll> comp[MAXN]; ll id[MAXN];
set<ll>col[MAXN];
void uf_init(ll n){fore(i,0,n)comp[i]={i},id[i]=i,col[i]={c[i]};}
bool uf_join(ll a, ll b){
	a=id[a], b=id[b];
	if(a==b)return 0;
	if(SZ(comp[a])>SZ(comp[b]))swap(a,b);
	for(auto i:comp[a])comp[b].pb(i), col[b].insert(c[i]),id[i]=b;
	/*comp[a].clear();
	col[a].clear();*/
	return 1;
}
void dfs(ll x, ll f){
	for(auto y:g[x])if(y!=f){
		dfs(y,x);
		uf_join(x,y);
	}
	res[x]=SZ(col[id[x]]);
	//cout<<x<<": ";imp(col[id[x]]);
}
int main(){FIN;
	ll n; cin>>n;
	//map<ll,ll>mp;
	fore(i,0,n)cin>>c[i];//,mp[c[i]]=-1;
	/*ll j=0;
	for(auto &i:mp)i.snd=j++;
	fore(i,0,n)c[i]=mp[c[i]];*/
	uf_init(n);
	fore(i,0,n-1){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(0,-1);
	fore(i,0,n)cout<<res[i]<<" ";
	cout<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
