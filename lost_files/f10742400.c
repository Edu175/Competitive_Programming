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

ll dp[22][22][65];
ll a[22][22];
ll n;
ll f(ll i,ll j,ll x){
	ll &res=dp[i][j][x];
	if(res>=0)return res;
	if(i==n-1&&j==n-1)return res=(x==0);
	res=0;
	if(i<n-1)res+=f(i+1,j,x^a[i+1][j]);
	if(j<n-1)res+=f(i,j+1,x^a[i][j+1]);
	return res;
}

int main(){FIN;
	mset(dp,-1);
	cin>>n;
	fore(i,0,n){
		fore(j,0,n)cin>>a[i][j];
	}
	cout<<f(0,0,a[0][0])<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
