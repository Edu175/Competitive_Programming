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
typedef pair<ll,ll> ii;
const ll MAXN=1e6+5,MOD=1e9+7;

ll dp[MAXN][2];

ll f(ll i, ll b){
	ll &res=dp[i][b];
	if(res!=-1)return res;
	if(i==0){
		return res=1;
	}
	if(b==0){
		return res=(2*f(i-1,0)+f(i-1,1))%MOD;
	}
	else {
		return res=(4*f(i-1,1)+f(i-1,0))%MOD;
	}
}

int main(){FIN;
	mset(dp,-1);
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		cout<<(f(n-1,0)+f(n-1,1))%MOD<<"\n";
	}
	return 0;
}

