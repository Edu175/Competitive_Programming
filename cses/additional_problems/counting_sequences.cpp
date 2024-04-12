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
const ll MOD=1e9+7,MAXF=1e6+5;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
ll fc[MAXF],fci[MAXF];
void factorials(){
	fc[0]=1;
	fore(i,1,MAXF)fc[i]=mul(fc[i-1],i);
	fci[MAXF-1]=fpow(fc[MAXF-1],MOD-2);
	for(ll i=MAXF-2;i>=0;i--)fci[i]=mul(fci[i+1],(i+1));
}
ll nCr(ll n, ll k){ //must call factorials before
	if(n<0||k<0||k>n)return 0;
	return fc[n]*fci[k]%MOD*fci[n-k]%MOD;
}

ll bf(ll n, ll k){
	vector<ll>dp(k+1);
	dp[1]=1;
	fore(x,2,k+1){
		fore(i,1,x)dp[x]=add(dp[x],mul(dp[i],nCr(x,i)));
		dp[x]=sub(fpow(x,n),dp[x]);
	}
	return dp[k];
}
int main(){FIN;
	factorials();
	ll n,k; cin>>n>>k;
	cout<<"(answer) "<<bf(n,k)<<"\n";
	ll res=0,s=0;
	fore(i,1,k){
		res=add(res,mul(fpow(k-i,n),sub(nCr(k,i),nCr(k,i-1))));
		//cout<<i<<": "<<res
		s=add(s,nCr(k,i));
	}
	cout<<res<<"\n";
	res=sub(fpow(n,k),res);
	cout<<res<<"\n";
	return 0;
}
