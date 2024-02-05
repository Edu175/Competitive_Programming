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
const ll MAXS=1e5+5,MAXN=105;

ll dp[2][MAXS];

int main(){FIN;
	ll n,x; cin>>n>>x;
	vector<ll>a(n),b(n);
	fore(i,0,n)cin>>a[i];
	fore(i,0,n)cin>>b[i];
	fore(s,0,x+1)dp[n&1][s]=0;
	for(ll i=n-1;i>=0;i--)fore(s,0,x+1){
		ll &res=dp[i&1][s];
		res=dp[(i+1)&1][s];
		if(s>=a[i])res=max(res,b[i]+dp[(i+1)&1][s-a[i]]);
	}
	cout<<dp[0][x]<<"\n";
	return 0;
}

