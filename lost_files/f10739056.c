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
const ll MAXN=5e5+5;

ll m;
ll a[MAXN],g[MAXN];
ll dp[5][5][MAXN];

ll f(ll b,ll p,ll i){
	ll &res=dp[b][p][i];
	if(res>=0)return res;
	if(i==m)return res=0;
	ll bi=(a[i]-(i?a[i-1]:0))%2;
	bi^=b;
	res=f(0,0,i+1);
	ll need=0;
	if(p==0)need=(bi?1:2);
	else if(p!=g[i]){
		need=(b?1:2)+(bi?1:2);
	}
	ll dif=a[i]-(i?a[i-1]:0);
	if(dif>=need)res=max(res,1+f(bi,g[i],i+1));
	//cout<<i<<": "<<b<<" "<<p<<": "<<f(0,0,i+1)<<" "<<(dif>=need?to_string(1+f(bi,g[i],i+1)):"-")<<": "<<res<<"\n";
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n>>m;
		fore(i,0,m+5)a[i]=0,g[i]=0;
		fore(i,0,m)cin>>a[i];
		fore(i,0,5)fore(j,0,5)fore(h,0,m+3)dp[i][j][h]=-1;
		fore(i,0,m)cin>>g[i];
		cout<<f(0,0,0)<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
