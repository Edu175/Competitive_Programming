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
const ll MAXN=16,MAXMK=1ll<<16,INF=1e13;

ll a[MAXN][MAXN],n;
ll c[MAXMK];

ll dp[MAXMK];
bool vis[MAXMK];
ll f(ll mk){
	ll &res=dp[mk];
	if(vis[mk])return res;
	vis[mk]=1;
	if(mk==(1ll<<n)-1)return res=0;
	vector<ll>d;
	fore(i,0,n)if((mk&(1ll<<i))==0)d.pb(i);
	ll m=SZ(d);
	res=-INF;
	fore(mki,0,1ll<<m){
		ll r=0;
		fore(i,0,m)if(mki&(1ll<<i))r|=1ll<<d[i];
		res=max(res,f(mk|r)+c[r]);
	}
	return res;
}
int main(){FIN;
	cin>>n;
	fore(i,0,n)fore(j,0,n)cin>>a[i][j];
	fore(mk,0,1ll<<n){
		ll s=0;
		fore(i,0,n)if(mk&(1ll<<i))fore(j,0,n)if(mk&(1ll<<j))s+=a[i][j];
		c[mk]=s/2;
	}
	cout<<f(0)<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
