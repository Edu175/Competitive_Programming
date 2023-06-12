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
const ll MAXN=400005,MOD=1000000007;

vector<ll> g[MAXN];
bool vis[MAXN];

void dfs(ll v){
	vis[v]=1;
	//cout<<v+1<<" ";
	for(auto i:g[v]){
		if(!vis[i])dfs(i);
	}
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll a[2][n];
		fore(i,0,2){
			fore(j,0,n)cin>>a[i][j];
		}
		fore(i,0,n){
			ll c=a[0][i],b=a[1][i];
			c--,b--;
			g[c].pb(b);
			g[b].pb(c);
		}
		ll comps=0;
		fore(i,0,n){
			if(!vis[i]){
				dfs(i);
				//cout<<"\n";
				comps++;
			}
		}
		ll res=1;
		fore(i,0,comps){
			res*=2;
			res%=MOD;
		}
		//cout<<comps<<" ";
		pres;
		fore(i,0,n)vis[i]=0,g[i].clear();
	}
	return 0;
}
