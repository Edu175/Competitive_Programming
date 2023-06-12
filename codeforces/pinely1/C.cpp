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
const ll MAXN=1005;

vector<ll>g[MAXN];
ll vis[MAXN];
bool esDAG=1;
vector<ll>ord;
void dfs(ll x){
	for(auto i:g[x]){
		if(!vis[i]){
			if(vis[i]==1)esDAG=0;
			else vis[i]=1,dfs(i);
		}
	}
	vis[x]=2;
	ord.pb(x);
}


int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		char a[n][n];
		fore(i,0,n){
			fore(j,0,n){
				cin>>a[i][j];
				if(a[i][j]-'0')g[i].pb(j);
			}
		}
		fore(i,0,n)if(!vis[i])dfs(i);
		reverse(ALL(ord));
		//imp(ord);
		set<ll>res[n];
		fore(i,0,n)res[i].insert(i);
		for(auto i:ord){
			for(auto j:g[i]){
				for(auto k:res[i])res[j].insert(k);
			}
		}
		fore(i,0,n){
			cout<<SZ(res[i])<<" ";
			for(auto j:res[i])cout<<j+1<<" ";
			cout<<"\n";
		}
		//cout<<"\n";
		fore(i,0,n)g[i].clear(),vis[i]=0;
		ord.clear();
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
