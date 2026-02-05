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
const ll MAXN=1005;

vv g[MAXN];
ll vis[MAXN][MAXN];

ll n,s;
vector<ii> p,sol;
void dfs(ll x, ll u){
	if(vis[x][u])return;
	if((x>=n&&x!=s)||x==u-n)return; // invalid
	p.pb({x,u});
	vis[x][u]=1;
	if(x<u-n)for(auto y:g[x])dfs(y,u);
	else for(auto v:g[u])dfs(x,v);
	if(x==s&&u==2*n-1)sol=p;
	p.pop_back();
}

void doit(ll _s){
	s=_s;
	mset(vis,0);
	dfs(0,s);
}

int main(){FIN;
	ll m; cin>>n>>m;
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
	}
	fore(s,n,2*n-1)doit(s);
	set<ll> st;
	for(auto [a,b]:sol)st.insert(a),st.insert(b);
	if(!SZ(st))cout<<"*\n";
	else {
		cout<<SZ(st)<<"\n";
		for(auto i:st)cout<<i+1<<" ";;cout<<"\n";
	}
	return 0;
}