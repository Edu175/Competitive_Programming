#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MOD=1e9+7;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}

int main(){FIN;
	ll n,l,r; cin>>n>>l>>r; r++;
	vector<ll>c(3);
	c[0]=c[1]=c[2]=(r-l)/3;
	while(l%3!=r%3)c[l%3]++,l++;
	vector<vector<ll>>dp(n+5,vector<ll>(3));
	//imp(c);
	dp[n][0]=1;
	for(ll i=n-1;i>=0;i--)fore(s,0,3){
		ll &res=dp[i][s];
		fore(j,0,3)res=add(res,mul(c[j],dp[i+1][(s+j)%3]));
	}
	cout<<dp[0][0]<<"\n";
	return 0;
}

