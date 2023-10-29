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
const ll MOD=1e9+7, MAXN=505;

ll dp[MAXN][125000];
ll n,sum;
ll f(ll i, ll s){
	ll &res=dp[i][s];
	if(res>=0)return res;
	if(i==n+1)return res=(s*2==sum);
	return res=(f(i+1,s+i)+f(i+1,s))%MOD;
}

int main(){FIN;
	cin>>n;
	sum=(n*(n+1))/2;
	mset(dp,-1);
	cout<<f(1,0)*500000004%MOD<<"\n";
	return 0;
}
