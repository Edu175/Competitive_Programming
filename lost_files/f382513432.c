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
const ll MAXN=1e5+5;
ll MOD=1e9+5;

vector<ll>g[MAXN];
ll f[MAXN],h[MAXN],ch[MAXN];
vector<ll>pre[MAXN],suf[MAXN];
void dfs(ll x){
	h[x]=1;
	fore(i,0,SZ(g[x])){
		ll y=g[x][i];
		if(y==f[x])continue;
		f[y]=x;
		dfs(y);
		h[x]=h[x]*(h[y]+1)%MOD;
	}
	//cout<<x<<": "<<h[x]<<"\n";
}
void cnt(ll x){
	fore(i,0,SZ(g[x])){
		ll y=g[x][i];
		if(y==f[x])continue;
		ch[y]=(pre[x][i]*suf[x][i+1]%MOD*ch[x]+1)%MOD;
		cnt(y);
	}
	//cout<<x<<": "<<ch[x]<<"\n";
}
int main(){FIN;
	ll n; cin>>n>>MOD;
	fore(i,0,n-1){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(0);
	//cout<<"\n";
	fore(x,0,n){
		pre[x].resize(SZ(g[x])+1,1);//	[0,i)
		suf[x].resize(SZ(g[x])+1,1);//	[i,n)
		fore(i,1,SZ(g[x])+1){
			if(g[x][i-1]==f[x])pre[x][i]=pre[x][i-1];
			else pre[x][i]=pre[x][i-1]*(h[g[x][i-1]]+1)%MOD;
		}
		for(int i=SZ(g[x])-1;i>=0;i--){
			if(g[x][i]==f[x])suf[x][i]=suf[x][i+1];
			else suf[x][i]=suf[x][i+1]*(h[g[x][i]]+1)%MOD;
		}
		//cout<<x<<":\n"; imp(pre[x]); imp(suf[x]);
	}
	//cout<<"\n";
	ch[0]=1;
	cnt(0);
	fore(x,0,n)cout<<h[x]*ch[x]%MOD<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
