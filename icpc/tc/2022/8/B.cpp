#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
#define pres cout<<res<<"\n"
using namespace std;
typedef long long ll;
const ll MOD=1000000007, MAXN=104;

ll fact[MAXN];
void factorial(ll x){
	fact[0]=1;
	fore(i,1,x)fact[i]=fact[i-1]*i%MOD;
}

ll bin_pow(ll a, ll e){
	ll res=1;
	if(e%2){
		res=a;
	}
	if(e>1){
		ll ab=bin_pow(a,e/2);
		res=res*ab%MOD*ab%MOD;
	}
	res%=MOD;
	return res;
}

ll inv(ll a){
	return bin_pow(a,MOD-2);
}

ll n,m,k;

bool visc[MAXN*MAXN][MAXN];
ll cuenta[MAXN*MAXN][MAXN];
ll c(ll x, ll i){
	ll &res=cuenta[x][i];
	if(visc[x][i])return res;
	visc[x][i]=1;
	ll g=m/n;
	g+=(m%n>i);
	ll div=fact[x]*fact[n-x]%MOD;
	ll ret=fact[n]*inv(div)%MOD;
	return res=bin_pow(ret,g)%MOD;
}

ll dp[MAXN][MAXN*MAXN];
bool vis[MAXN][MAXN*MAXN];

ll f(ll i, ll p){
	ll &res=dp[i][p];
	if(vis[i][p])return res;
	vis[i][p]=1;
	if(p==k)return res=1;
	if(i==n)return res=(p==k);
	fore(j,0,min(n+1,k-p+1)){
		res+=c(j,i)*(f(i+1,p+j)%MOD);
		res%=MOD;
	}
	return res%MOD;
}

int main(){FIN;
	cin>>n>>m>>k;
	factorial(104);
	cout<<f(0,0)%MOD;
	return 0;
}
