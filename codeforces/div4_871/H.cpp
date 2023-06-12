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
const ll MAXN=2e5+5,MAXV=130,MOD=1e9+7;

ll dp[MAXN][MAXV];
ll a[MAXN];
ll n,k;
ll f(ll i, ll x){
	ll &res=dp[i][x];
	if(res!=-1)return res;
	if(i==n)return res=(x>=64?0:(__builtin_popcountll(x)==k));
	res=(f(i+1,x)+f(i+1,x&a[i]))%MOD;
	//cout<<i<<" "<<x<<": "<<f(i+1,x)<<" "<<f(i+1,x&a[i])<<": "<<res<<"\n";
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n>>k;
		fore(i,0,n+3){
			fore(j,0,MAXV)dp[i][j]=-1;
		}
		fore(i,0,n)cin>>a[i];
		ll res=f(0,127);
		cout<<res<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home

