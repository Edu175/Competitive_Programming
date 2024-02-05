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
typedef long double ld;
typedef pair<ll,ll> ii;
const ll MAXN=5005;

ld dp[2][2*MAXN];

int main(){FIN;
	ll n,k; cin>>n>>k;
	vector<ld>a(n);
	fore(i,0,n)cin>>a[i];
	fore(i,k,n+3)dp[n&1][i+n]=1;//,cout<<i<<" ";;cout<<"\n";
	sort(ALL(a));
	cout<<fixed<<setprecision(15);
	ld ans=dp[n&1][n];
	for(ll i=n-1;i>=0;i--)fore(s,0,2*n+1){
		ll x=i&1;
		ld &res=dp[x][s];
		res=-5*n;
		if(abs(s-n)<=i)res=a[i]*dp[x^1][s+1]+(1.0-a[i])*dp[x^1][s-1];
		//cout<<i<<" "<<s-n<<": "<<res<<"\n";
		//if(s==2*n)cout<<"\n";
		if(s-n==0)ans=max(ans,res);
	}
	cout<<ans<<"\n";
	return 0;
}
