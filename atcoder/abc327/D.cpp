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
ll c[MAXN];
ll flag=1;

void dfs(ll x, ll b){
	c[x]=b;
	for(auto y:g[x]){
		if(c[y]){
			if(c[y]==b)flag=0;
		}
		else {
			dfs(y,3-b);
		}
	}
}

int main(){FIN;
	ll n,m; cin>>n>>m;
	vector<ll>u(m),v(m);
	fore(i,0,m)cin>>u[i],u[i]--;
	fore(i,0,m)cin>>v[i],v[i]--;
	fore(i,0,m){
		g[u[i]].pb(v[i]);
		g[v[i]].pb(u[i]);
	}
	fore(i,0,n)if(!c[i])dfs(i,1);
	if(flag)cout<<"Yes\n";
	else cout<<"No\n";
	return 0;
}
