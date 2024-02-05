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
	ll n,k; cin>>n>>k;
	vector<ll>dp(n*n);
	dp[0]=1;
	fore(m,0,n){
		vector<ll>sp(SZ(dp)+1);
		fore(i,1,SZ(sp))sp[i]=add(sp[i-1],dp[i-1]);
		fore(i,0,SZ(dp)){
			dp[i]=sub(sp[i+1],sp[max(i-m,(ll)0)]);
		}
	}
	cout<<dp[k]<<"\n";
	return 0;
}
