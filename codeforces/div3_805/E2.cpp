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
#define ft gr[g[v][0]]
#define sd gr[g[v][1]]
using namespace std;
typedef long long ll;

const int MAXN=200005;

vector<int> g[MAXN];
bool flag=1;
bool vis[MAXN];
ll cont;

void dfs(ll v){
	//cout<<v<<"\n";
	if(vis[v]==0){
		vis[v]=1;
		if(SZ(g[v])>2)flag=0;
		for(auto i:g[v]){
			if(!vis[i])dfs(i);
		}
		cont++;
	}
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n){
			ll a,b; cin>>a>>b;
			a--,b--;
			g[a].pb(b);
			g[b].pb(a);
			if(a==b)flag=0;
		}
		fore(i,0,n){
			if(!vis[i]){
				if(cont%2)flag=0;
				cont=0;
				dfs(i);
			}
		}
		if(cont%2)flag=0;
		cont=0;
		/*fore(i,0,n){
			cout<<i<<": ";
			for(auto j:g[i])cout<<j<<" ";
			cout<<"\n";
		}*/
		if(flag)cout<<"YES\n";
		else cout<<"NO\n";
		flag=1;
		fore(i,0,n)vis[i]=0,g[i].clear();
	}
	return 0;
}
