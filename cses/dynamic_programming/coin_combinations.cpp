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
const ll MAXS=1e6+5,MOD=1e9+7;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}

ll dp[MAXS];

int main(){FIN;
	ll n,x; cin>>n>>x;
	vector<ll>a(n);
	fore(i,0,n)cin>>a[i];
	dp[0]=1;
	fore(s,1,x+1){
		dp[s]=0;
		fore(i,0,n)if(s>=a[i])dp[s]=add(dp[s],dp[s-a[i]]);
	}
	ll res=dp[x];
	cout<<res<<"\n";
	return 0;
}
