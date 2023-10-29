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
const ll MOD=1e9+7,MAXN=22;

ll n;
ll g[MAXN][MAXN];
ll dp[MAXN][1ll<<MAXN];

ll f(ll i,ll bm){
	ll &res=dp[i][bm];
	if(res>=0)return res;
	if(i==n)return res=1;
	res=0;
	fore(j,0,n){
		if(g[i][j]&&(bm&(1ll<<j))==0)res=(res+f(i+1,bm|(1ll<<j)))%MOD;
	}
	return res;
}

int main(){FIN;
	cin>>n;
	mset(dp,-1);
	fore(i,0,n){
		fore(j,0,n)cin>>g[i][j];
	}
	cout<<f(0,0)<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
