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
const ll MAXS=1e6+5;

ll dp[MAXS];

int main(){FIN;
	ll n,x; cin>>n>>x;
	vector<ll>a(n);
	fore(i,0,n)cin>>a[i];
	dp[0]=0;
	fore(s,1,x+1){
		dp[s]=x+5;
		fore(i,0,n)if(s>=a[i])dp[s]=min(dp[s],1+dp[s-a[i]]);
	}
	ll res=dp[x];
	if(res>x)cout<<"-1\n";
	else cout<<res<<"\n";
	return 0;
}
