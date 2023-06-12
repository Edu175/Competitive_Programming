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
const ll MOD=998244353,MAXN=105;

ll n;
ll a[MAXN][MAXN],dp[MAXN][MAXN];

ll f(ll j, ll l){
	ll &res=dp[j][l];
	if(res>=0)return res;
	fore(i,0,n){
		if(a[i][j]==2&&i>=l)return res=0;
		if(a[i][j]==1&&i<l)return res=0;
	}
	if(j==n-1)return res=2;
	res=(f(j+1,l)+f(j+1,j+1))%MOD;
	//cout<<j<<" "<<l<<": 1="<<f(j+1,l)<<" 0="<<f(j+1,j+1)<<"| "<<res<<"\n";
	return res;
}

int main(){FIN;
	cin>>n;
	fore(i,0,n)fore(j,i,n)cin>>a[i][j];
	mset(dp,-1);
	cout<<f(0,0)<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
