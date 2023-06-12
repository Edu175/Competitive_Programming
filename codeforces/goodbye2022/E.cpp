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
const ll MOD=998244353,MAXN=3e5+5;

ll fpow(ll b, ll e){
	if(e<0)return 0;
	ll ret=1;
	while(e){
		if(e&1)ret=ret*b%MOD;
		b=b*b%MOD,e>>=1;
	}
	return ret;
}

vector<ll>g[MAXN];
ll d[MAXN],c[MAXN],p[MAXN];
bool vis[MAXN],b[MAXN];

void dfs(ll x){
	vis[x]=1;
	c[x]=b[x];
	for(auto i:g[x]){
		if(vis[i])continue;
		d[i]=d[x]+1;
		dfs(i);
		c[x]+=c[i];
	}
}

int main(){FIN;
	ll n,k; cin>>n>>k;
	fore(i,0,k){
		ll x; cin>>x; x--;
		b[x]=1;
		p[x]=1;
	}
	vector<pair<ll,ll>>e;
	fore(i,0,n-1){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
		e.pb({u,v});
	}
	d[0]=0;
	dfs(0);
	/*fore(i,0,n){
		cout<<i<<": "<<c[i]<<" "<<d[i]<<" "<<b[i]<<"\n";
	}*/
	ll res=0;
	for(auto i:e){
		ll u=i.fst,v=i.snd;
		if(d[u]>d[v])swap(u,v);
		ll a=p[u]*(1-p[v]+MOD)%MOD*fpow(2,MOD-2)%MOD;
		ll b=p[v]*(1-p[u]+MOD)%MOD*fpow(2,MOD-2)%MOD;
		ll z=(1-(a+b)+MOD)%MOD;
		//cout<<u<<" "<<v<<": "<<k-c[v]<<" "<<c[v]<<": ";
		//cout<<a<<"("<<fpow(a,MOD-2)<<") "<<b<<"("<<fpow(b,MOD-2)<<") "<<z<<"("<<fpow(z,MOD-2)<<") "<<"\n";
		//ll pre=res;
		res=(res+a*(c[v]+1)%MOD*(k-c[v]-1))%MOD;
		//cout<<res-pre<<" ";pre=res;
		res=(res+b*(c[v]-1)%MOD*(k-c[v]+1))%MOD;
		//cout<<res-pre<<" ";pre=res;
		res=(res+z*c[v]%MOD*(k-c[v]))%MOD;
		//cout<<res-pre<<"\n";
		//cout<<p[u]<<" --> ";
		p[u]=(p[u]-a+b+MOD)%MOD;
		//cout<<p[u]<<"\n"<<p[v]<<" --> ";
		p[v]=(p[v]+a-b+MOD)%MOD;
		//cout<<p[v]<<"\n\n";
	}
	res=res*fpow(k*(k-1)/2%MOD,MOD-2)%MOD;
	res=(res+MOD)%MOD;
	cout<<res<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
