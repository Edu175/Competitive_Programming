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
const ll MOD=1e9+7,MAXF=1e6+5;
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
ll nCr(ll n, ll k){ // must call factos before
	if(n<0||k<0||k>n)return 0;
	return mul(mul(fc[n],fci[k]),fci[n-k]);
}
ll A=26;
// ll A=2;
int main(){FIN;
	factos();
	vv c(A);
	string s; cin>>s;
	for(auto i:s)c[i-'a']++;
	ll n=SZ(s);
	vector<vv> dp(A+1,vv(n+1));
	fore(i,1,n+1)dp[A][i]=1;
	for(ll i=A-1;i>=0;i--)fore(m,0,n+1){
		auto &res=dp[i][m];
		if(!c[i])res=dp[i+1][m];
		fore(k,1,c[i]+1)if(m+k<=n){
			ll q=c[i]-k;
			ll resi=mul(mul(nCr(m+k,k),nCr(c[i]-1,k-1)),dp[i+1][m+k]);
			res=(q&1?sub:add)(res,resi);
			// cout<<"t "<<k<<": "<<resi<<"\n";
		}
		// cout<<i<<" "<<m<<": "<<res<<"\n\n";
	}
	cout<<dp[0][0]<<"\n";
	return 0;
}