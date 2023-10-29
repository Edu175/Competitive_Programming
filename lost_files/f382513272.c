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
const ll MOD=1e9+7,MAXN=1e5+5;

ll n;
vector<ll>g[MAXN];
ll p[MAXN];
void dfs(ll x){
	for(auto i:g[x]){
		if(i!=p[x]){
			p[i]=x;
			dfs(i);
		}
	}
}
ll dp[MAXN][5];
ll f(ll x, ll b){
	ll &res=dp[x][b];
	if(res>=0)return res;
	res=0;
	fore(c,0,2){
		ll resi=1;
		if(b+c==2)continue;
		for(auto i:g[x]){
			if(i==p[x])continue;
			resi=(resi*f(i,c))%MOD;
		}
		res=(res+resi)%MOD;
	}
	return res;
}
int main(){FIN;
	cin>>n;
	fore(i,0,n-1){
		ll a,b; cin>>a>>b; a--,b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	p[0]=-1;
	dfs(0);
	mset(dp,-1);
	ll res=f(0,0);
	cout<<res<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
