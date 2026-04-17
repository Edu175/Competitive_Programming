#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oia=b;i<oia;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto messi:v)cout<<messi<<" ";cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll>ii;
const ll MAXN=1e5+5;

vector<ii>g[MAXN];
ll t;
ll c[MAXN];
vector<ll>ans;
void dfs(ll x, ll f){//f = index arista padre
	c[x]=1;
	for(auto i:g[x])if(i.snd!=f){
		ll y=i.fst;
		dfs(y,i.snd);
		c[x]+=c[y];
	}
	if(c[x]%t==0)ans.pb(f);
}

int cortarbol(vector<int> &a, vector<int> &b, int T, vector<int> &lineas) {
	ll n=SZ(a)+1;
	t=T;
	fore(i,0,n-1){
		a[i]--,b[i]--;
		ll u=a[i],v=b[i];
		g[u].pb({v,i});
		g[v].pb({u,i});
	}
	assert(n%t==0);
	dfs(0,-1);
	lineas.clear();
	for(auto i:ans)if(i!=-1)lineas.pb(i);
	return SZ(ans);
}
