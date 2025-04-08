#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MOD=998244353,MAXF=1e6+5;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	if(b<0)return 0;
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
ll fc[MAXF],fci[MAXF];
void factos(){
	fc[0]=1;
	fore(i,1,MAXF)fc[i]=mul(fc[i-1],i);
	fci[MAXF-1]=fpow(fc[MAXF-1],MOD-2);
	for(ll i=MAXF-2;i>=0;i--)fci[i]=mul(fci[i+1],(i+1));
}

int main(){FIN;
	factos();
	ll t; cin>>t;
	while(t--){
		ll sum=0;
		vv c(26);
		fore(i,0,26)cin>>c[i],sum+=c[i];
		vector<vv> dp(27,vv(sum+1));
		dp[26][(sum+1)/2]=1;
		for(ll i=25;i>=0;i--)fore(s,0,sum+1){
			auto &res=dp[i][s];
			res=dp[i+1][s];
			ll oc=c[i];
			if(oc&&s+oc<=sum)res=add(res,dp[i+1][s+oc]);
			// cout<<i<<" "<<s<<": "<<res<<"\n";
		}
		ll res=dp[0][0];
		res=mul(res,mul(fc[(sum+1)/2],fc[sum/2]));
		fore(i,0,26)res=mul(res,fci[c[i]]);
		cout<<res<<"\n";
	}
	return 0;
}
