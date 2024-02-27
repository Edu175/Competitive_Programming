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

vector<ll>g[MAXN];
vector<pair<ii,ll>>ed;
vector<ll>p,cyc;
ll vis[MAXN];
void doit(ll x){
	ll did=0;
	for(auto i:p){
		if(i==x)did=1;
		if(did)cyc.pb(i);
	}
}
void dfs(ll x){
	vis[x]=1;
	p.pb(x);
	for(auto y:g[x]){
		if(!vis[y])dfs(y);
		else if(vis[y]==1&&SZ(cyc)==0)doit(y);
	}
	vis[x]=2;
	p.pop_back();
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		
	}
	return 0;
}
