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
const ll MAXN=105,MAXK=35;
ll MOD;
ll n,k;
ll dp[MAXN][MAXN][MAXK];
ll f(ll i, ll g, ll s){
	ll &res=dp[i][g][s];
	if(res!=-1)return res;
	if(i==n)return (s==0);
	res=0;
	fore(j,0,k){
		ll si=s;
		if(i==g)si=(s-j+k)%k;
		else si=(s+j)%k;
		res=(res+f(i+1,g,si))%MOD;
	}
	return res;
}
int main(){FIN;
	cin>>n>>k>>MOD;
	mset(dp,-1);
	ll res=0;
	fore(i,0,n)res=(res+f(0,i,0))%MOD;
	cout<<res<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
