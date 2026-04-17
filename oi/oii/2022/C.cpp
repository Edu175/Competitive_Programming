#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oii=b;i<oii;i++)
#define SZ(x) ((int)x.size)
#define ALL(x) x.begin(),x.end
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" ";cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MOD=998244353, MAXF=1e6+5,MAXN=1e6+5;

ll fpow(ll b, ll e){
	ll ret=1;
	while(e){
		if(e&1)ret=(ret*b)%MOD;
		b=b*b%MOD,e>>=1;
	}
	return ret;
}

ll fc[MAXF],fci[MAXF];
void factorials(){
	fc[0]=1;
	fore(i,1,MAXF)fc[i]=fc[i-1]*i%MOD;
	fci[MAXF-1]=fpow(fc[MAXF-1],MOD-2);
	for(ll i=MAXF-2;i>=0;i--)fci[i]=fci[i+1]*(i+1)%MOD;
}
ll nCr(ll n, ll k){
	if(n<0||k>n||k<0)return 0;
	return fc[n]*fci[n-k]%MOD*fci[k]%MOD;
}

ll dp[MAXN];

int main(){FIN;
	factorials();
	ll n,k; cin>>n>>k;
	dp[0]=1;
	ll sum=0;
	fore(m,1,n+1){
		ll &res=dp[m];
		if(m-k>=0)sum=(sum+dp[m-k]*fci[m-k])%MOD;
		res=fc[m-1]*sum%MOD;
	}
	cout<<dp[n]<<"\n";
	return 0;
}
