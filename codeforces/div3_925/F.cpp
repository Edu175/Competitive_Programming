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
ll flag=1;
ll vis[MAXN];
void dfs(ll x){
	vis[x]=1;
	for(auto y:g[x]){
		if(!vis[y])dfs(y);
		else if(vis[y]==1)flag=0;
	}
	vis[x]=2;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		fore(i,0,n+3)vis[i]=0,g[i].clear();
		fore(i,0,k){
			vector<ll>a(n);
			fore(i,0,n){
				cin>>a[i]; a[i]--;
				if(i>1)g[a[i-1]].pb(a[i]);
			}
		}
		flag=1;
		fore(i,0,n)if(!vis[i])dfs(i);
		if(flag)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
