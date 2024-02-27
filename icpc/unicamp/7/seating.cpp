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

vector<ll> g[MAXN];
ll vis[MAXN];
vector<vector<ll>>ans;
ll dfs(ll x){
	vis[x]=1;
	vector<ll>v;
	for(auto y:g[x])if(!vis[y]){
		if(dfs(y))v.pb(y);
	}
	for(ll i=1;i<SZ(v);i+=2)ans.pb({v[i-1],v[i],x});
	if(SZ(v)&1){
		ans.pb({v.back(),x,-1});
		return 0;
	}
	return 1;
}

int main(){FIN;
	ll n,m; cin>>n>>m;
	fore(i,0,m){
		ll u,v; cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	ll flag=1;
	fore(i,0,2*n)if(!vis[i]){
		flag&=!dfs(i);
	}
	if(flag){
		cout<<"POSSIBLE\n";
		for(auto i:ans){
			cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<"\n";
		}
	}
	else {
		cout<<"IMPOSSIBLE\n";
	}
	return 0;
}
