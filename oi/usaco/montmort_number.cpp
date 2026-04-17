#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
const ll MAXN=1e6+5;
ll MOD;

ll dp[MAXN][2];
ll f(ll n, ll c){
	ll &res=dp[n][c];
	if(res!=-1)return res;
	if(n==1)return res=c;
	if(c)return res=(f(n-1,0)+(n-1)*f(n-1,1))%MOD;
	return res=(n-1)*f(n-1,1)%MOD;
}

int main(){FIN;
	ll n; cin>>n>>MOD;
	mset(dp,-1);
	fore(i,1,n+1){
		cout<<f(i,0)<<" ";
	}
	cout<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
