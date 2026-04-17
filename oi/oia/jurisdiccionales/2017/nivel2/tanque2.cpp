#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;

const ll MAXN=1000005;
vector<pair<ll,ll>> g[MAXN];
bool vis[MAXN];
vector<ll> ord;

void dfs(ll v){
	vis[v]=1;
	for(auto i:g[v]){
		if(!vis[i.snd])dfs(i.snd);
	}
	ord.pb(v);
}

int main(){
	ll n; cin>>n;
	fore(i,0,n-1){
		ll t1,a,t2; cin>>t1>>a>>t2;
		g[t1].pb({a,t2});
	}
	ll k; cin>>k;
	fore(i,1,n+1)sort(ALL(g[i])), reverse(ALL(g[i]));
	dfs(1);
	ll res1=ord[k-1];
	cout<<res1<<" "<<1<<"\n";
	return 0;
}
