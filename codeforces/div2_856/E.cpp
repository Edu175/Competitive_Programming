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

#define bint __int128
bint MOD=212345678987654321LL,P=1777771;
const ll MAXN=2e5+5;
vector<ll>g[MAXN]; ll n;
ll h[MAXN],r[MAXN],p[MAXN],f[MAXN];

void dfs(ll x){
	h[x]=1;
	for(auto y:g[x]){
		if(y==f[x])continue;
		f[y]=x;
		dfs(y);
		h[x]=(h[x]+h[y]*P)%MOD;
	}
	//cout<<x<<": "<<f[x]<<" "<<h[x]<<" "<<r[x]<<"\n";
}
void cnt(ll x){
	r[x]=(r[x]+h[x])%MOD;
	for(auto y:g[x]){
		if(y==f[x])continue;
		r[y]=(r[x]-h[y]*P%MOD+MOD)*P%MOD;
		cnt(y);
	}
}
int main(){FIN;
	cin>>n;
	ll a[n];
	fore(i,0,n-1)cin>>a[i];
	fore(i,0,n-1){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v),g[v].pb(u);
	}
	p[0]=1;
	fore(i,1,n)p[i]=p[i-1]*P%MOD;
	f[0]=-1;
	dfs(0);
	cnt(0);
	ll k=0;
	fore(i,0,n-1)k=(k+p[a[i]])%MOD;
	set<ll>st;
	fore(i,0,n)st.insert((k+p[i])%MOD);
	vector<ll>res;
	fore(x,0,n)if(st.count(r[x]))res.pb(x);
	sort(ALL(res));
	cout<<SZ(res)<<"\n";
	for(auto i:res)cout<<i+1<<" ";
	cout<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
