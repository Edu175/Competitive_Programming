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
typedef pair<ll,ll> ii;
const ll MOD=998244353,MAXN=2005;

ll n,m;
ll a[MAXN][MAXN]; 
ll dp[MAXN][MAXN];
int main(){FIN;
	cin>>n>>m;
	char b[n][m];
	fore(i,0,n)fore(j,0,m){
		cin>>b[i][j];
		a[m-1-j][i]=(b[i][j]=='#'); //giro tablero 90
	}
	swap(n,m);
	ll fl[n]={};
	m++; //elijo borde
	fore(i,0,n)fore(j,0,m){
		ll &res=dp[i][j];
		if(j)res=dp[i][j-1];
		ll arr=1;
		if(i)arr=dp[i-1][min(j+1,m-1)];
		if(!fl[i])res=(res+arr)%MOD;
		if(a[i][j])fl[i]=1;
	}
	ll res=dp[n-1][m-1];
	cout<<res<<"\n";
	return 0;
}
