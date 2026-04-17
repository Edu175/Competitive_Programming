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
const ll MOD=998244353;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}

int main(){FIN;
	ll n,m,a; cin>>n>>m>>a;
	vector<ll>b(m);
	fore(i,0,m)cin>>b[i];
	reverse(ALL(b));
	vector<vector<ll>>dp(m+1,vector<ll>(2));
	dp[m][0]=dp[m][1]=1;
	//ll sum=1;
	//imp(b);
	//cout<<fpow(1,MOD-2)<<"\n";
	for(ll i=m-1;i>=0;i--)fore(w,0,2){
		ll &res=dp[i][w];
		ll r=fpow(a,(w?b[i]:5*(MOD-1)-b[i]));
		res=add(dp[i+1][w],mul(r,dp[i+1][w^1]));
		//cout<<i<<" "<<w<<": ("<<b[i]<<") "<<r<<" = "<<res<<"\n";;
		//if(!w)sum=add(sum,res);
	}
	ll sum=dp[0][0];
	ll res=mul(fpow(a,n),fpow(fpow(2,m),MOD-2));
	//cout<<res<<"\n";
	res=mul(res,sum);
	//cout<<sum<<" "<<fpow(a,n)<<" = "<<mul(sum,fpow(a,n))<<"\n";
	//cout<<"fijos "<<mul(res,fpow(2,m))<<"\n";
	cout<<res<<"\n";
	return 0;
}

