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
const ll MAXN=1e4+5,MOD=1e9+7;

string k;
ll n,d;
ll dp[MAXN][105][2];
ll f(ll i, ll s, ll b){
	ll &res=dp[i][s][b];
	if(res>=0)return res;
	if(i==n)return res=(s==0);
	res=0;
	if(!b){
		fore(j,0,10)res=(res+f(i+1,(s+j)%d,0))%MOD;
	}
	else{
		fore(j,0,k[i]-'0')res=(res+f(i+1,(s+j)%d,0))%MOD;
		res=(res+f(i+1,(s+k[i]-'0')%d,1))%MOD;
	}
	//cout<<i<<" "<<s<<" "<<b<<": "<<res<<"\n";
	return res;
}

int main(){FIN;
	mset(dp,-1);
	cin>>k>>d;
	n=SZ(k);
	cout<<(f(0,0,1)-1+MOD)%MOD<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
