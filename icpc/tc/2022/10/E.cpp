#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
#define pres cout<<res<<"\n"
using namespace std;
typedef long long ll;
const ll MAXN=150005;

vector<ll> g[MAXN];
bool vis[MAXN];
ll nodes=0;
ll edges=0;

void dfs(ll v){
	vis[v]=1;
	nodes++;
	for(auto i:g[v]){
		edges++;
		if(!vis[i])dfs(i);
	}
}

int main(){FIN;
	ll n,m; cin>>n>>m;
	set<ll>st;
	fore(i,0,m){
		ll a,b; cin>>a>>b;
		a--,b--;
		st.insert(a);
		st.insert(b);
		g[a].pb(b);
		g[b].pb(a);
	}
	bool flag=1;
	for(auto i:st){
		if(!vis[i]){
			dfs(i);
			//cout<<i<<": "<<nodes<<" "<<edges<<"\n";
			if(nodes*(nodes-1)!=edges)flag=0;
			nodes=0;
			edges=0;
		}
	}
	if(flag)cout<<"YES\n";
	else cout<<"NO\n";
	return 0;
}
