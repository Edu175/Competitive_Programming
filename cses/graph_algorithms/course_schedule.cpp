#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,edu=b;i<edu;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long ll;
using namespace std;
const ll MAXN=1e5+5;

vector<ll> g[MAXN];
ll vis[MAXN];
vector<ll> tps;
bool flag=1;

void dfs(ll x){
	for(auto i:g[x]){
		if(!vis[i])vis[i]=1,dfs(i);
		else if(vis[i]==1)flag=0;
	}
	vis[x]=2;
	tps.pb(x);
	//cout<<x<<" ";
}

int main(){FIN;
	ll n,m; cin>>n>>m;
	fore(i,0,m){
		ll a,b; cin>>a>>b;
		a--,b--;
		g[a].pb(b);
	}
	fore(i,0,n){
		if(!vis[i])vis[i]=1,dfs(i);
	}
	//cout<<"\n";
	reverse(ALL(tps));
	if(flag){
		for(auto i:tps)cout<<i+1<<" ";
	}
	else cout<<"IMPOSSIBLE";
	cout<<"\n";
	return 0;
}
