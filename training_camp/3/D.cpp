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
const ll MAXN=2e5+5;

vector<ll>g[MAXN];
ll c[MAXN],q[2],ch[MAXN];
bool vis[MAXN];
ll n,sum=0;

void dfs(ll x){
	vis[x]=1;
	ch[x]=1;
	q[c[x]]++;
	for(auto i:g[x]){
		if(vis[i])continue;
		c[i]=c[x]^1;
		dfs(i);
		ch[x]+=ch[i];
		sum+=ch[i]*(n-ch[i]);
	}
	//cout<<x<<": "<<c[x]<<" "<<ch[x]<<"\n";
}
int main(){FIN;
	cin>>n;
	fore(i,0,n-1){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	c[0]=0;
	dfs(0);
	//cout<<q[0]<<" "<<q[1]<<"\n";
	sum=(sum+q[0]*q[1])/2;
	cout<<sum<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
