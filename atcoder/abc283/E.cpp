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
const ll MAXN=1e3+5,INF=5*MAXN;

ll n,m;
ll a[MAXN][MAXN];
ll dp[MAXN][5][5];

ll f(ll i,ll p,ll b){
	ll &res=dp[i][p][b];
	if(res>=0)return res;
	if(i==n)return res=0;
	res=INF;
	fore(s,0,2){
		ll flag=1;
		fore(j,0,m){
			if(j&&a[i][j]==a[i][j-1])continue;
			if(j<m-1&&a[i][j]==a[i][j+1])continue;
			if(((!i)||(a[i-1][j]^p^a[i][j]^b))&&
			((i==n-1)||(a[i][j]^b^a[i+1][j]^s)))flag=0;
		}
		if(flag)res=min(res,s+f(i+1,b,s));
	}
	//cout<<i<<" "<<p<<" "<<b<<": "<<res<<"\n";
	return res;
}

int main(){FIN;
	cin>>n>>m;
	fore(i,0,n){
		fore(j,0,m)cin>>a[i][j];
	}
	mset(dp,-1);
	ll res=min(f(0,0,0),1+f(0,0,1));
	if(res==INF)cout<<"-1\n";
	else cout<<res<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
