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
const ll MOD=998244353,MAXN=305,MAXA=300*300*2+10;

ll m=MAXA/2;
ll n,a[MAXN];
ll dp[MAXN][MAXA];
ll f(ll i, ll c){
	ll &res=dp[i][c+m];
	if(res!=-1)return res;
	if(i==n-1)return res=1;
	if(c==0)return res=f(i+1,a[i+1]);
	return res=(f(i+1,a[i+1]+c)+f(i+1,a[i+1]-c))%MOD;
}


int main(){FIN;
	mset(dp,-1);
	cin>>n;
	fore(i,0,n)cin>>a[i];
	cout<<f(1,a[1])<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home

