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

vector<ll> g[MAXN],t[MAXN];
ll val[MAXN],vis[MAXN],is[MAXN];
vector<ll>p;
ll n;
bool dfs(ll x){
	vis[x]=1;
	p.pb(x);
	if(x==n-1)return 1;
	for(auto y:g[x])if(!vis[y]&&dfs(y))return 1;
	p.pop_back();
	return 0;
}
void dfs2(ll x, ll v){
	if(val[x])return;
	val[x]=v;
	if(is[x])return;
	for(auto y:t[x])dfs2(y,v);
}
int main(){FIN;
	ll m; cin>>n>>m;
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		t[v].pb(u);
	}
	dfs(0);
	fore(i,0,SZ(p))is[p[i]]=1;
	for(ll i=SZ(p)-1;i;i--){
		for(auto y:t[p[i]])dfs2(y,i);
	}
	ll r=0;
	vector<ll>res;
	fore(i,0,SZ(p)){
		if(r<=i)res.pb(p[i]);
		r=max(r,val[p[i]]);
	}
	sort(ALL(res));
	cout<<SZ(res)<<"\n";
	for(auto i:res)cout<<i+1<<" ";;cout<<"\n";
	return 0;
}
