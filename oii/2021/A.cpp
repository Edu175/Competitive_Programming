#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oii=b;i<oii;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto dkjgh:v)cout<<dkjgh<<" ";cout<<"\n";}
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef int ll;
typedef pair<ll,ll> ii;
const ll MAXN=35;
ll n;
ll a[MAXN][MAXN];
unordered_map<ll,ll>dp;
ll f(ll mk){
	if(dp.count(mk))return dp[mk];
	ll &res=dp[mk];
	if(mk==0)return res=0;
	ll x=__builtin_ctz(mk);
	fore(y,x+1,n)if(mk>>y&1){
		res=max(res,a[x][y]+f(mk^(1<<x)^(1<<y)));
	}
	return res;
}

int main(){FIN;
	cin>>n;
	fore(i,0,n)fore(j,0,n)cin>>a[i][j];
	
	cout<<f((1<<n)-1)<<"\n";
	return 0;
}
