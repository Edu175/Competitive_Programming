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
const ll MAXN=505,INF=MAXN*MAXN*MAXN;

ll dp[MAXN][MAXN];

ll f(ll n, ll m){
	ll &res=dp[n][m];
	if(res!=-1)return res;
	if(n==m)return res=0;
	res=INF;
	fore(x,1,n)res=min(res,1+f(x,m)+f(n-x,m));
	fore(x,1,m)res=min(res,1+f(n,x)+f(n,m-x));
	return res;
}

int main(){FIN;
	ll n,m; cin>>n>>m;
	mset(dp,-1);
	cout<<f(n,m)<<"\n";
	return 0;
}
