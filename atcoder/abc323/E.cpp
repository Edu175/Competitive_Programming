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
const ll MAXV=1e4+5,MOD=998244353;

ll fpow(ll b, ll e){
	if(e<0)return 0;
	ll ret=1;
	while(e){
		if(e&1)ret=ret*b%MOD;
		b=b*b%MOD,e>>=1;
	}
	return ret;
}

ll dp[MAXV];

int main(){FIN;
	ll n,x; cin>>n>>x;
	ll inv=fpow(n,MOD-2);
	ll a[n];
	fore(i,0,n)cin>>a[i];
	dp[0]=1;
	ll res=0;
	fore(i,0,MAXV){
		if(x-a[0]<i&&i<=x)res=(res+dp[i]*inv)%MOD;
		fore(j,0,n)if(i+a[j]<MAXV)dp[i+a[j]]=(dp[i+a[j]]+dp[i]*inv)%MOD;
	}
	cout<<res<<"\n";
	return 0;
}
