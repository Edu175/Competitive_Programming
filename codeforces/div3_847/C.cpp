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
const ll MAXN=105;

vector<ll>g[MAXN];
bool vis[MAXN];
vector<ll>ans;
void dfs(ll x){
	vis[x]=1;
	ans.pb(x);
	for(auto i:g[x])if(!vis[i])dfs(i);
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n)vis[i]=0,g[i].clear();
		ans.clear();
		ll a[n][n-1];
		vector<ll>oc[n-1];
		fore(i,0,n){
			fore(j,0,n-1){
				cin>>a[i][j]; a[i][j]--;
				if((SZ(oc[j])==1&&oc[j][0]!=a[i][j])||SZ(oc[j])==0)
					oc[j].pb(a[i][j]);
			}
		}
		fore(i,0,n-1){
			ll u=oc[i][0],v=oc[i][1];
			g[u].pb(v);
			g[v].pb(u);
		}
		ll s=oc[0][0];
		ll c=0;
		fore(i,0,n)c+=(a[i][0]==s);
		if(c==1)s=oc[0][1];
		dfs(s);
		for(auto i:ans)cout<<i+1<<" ";
		cout<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
