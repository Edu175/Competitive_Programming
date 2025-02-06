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
typedef pair<ll,ll> ii;
const ll MOD=1e9+7,MAXF=1e5+5;
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
	fore(i,1,MAXF)fc[i]=fc[i-1]*i%MOD;
	fci[MAXF-1]=fpow(fc[MAXF-1],MOD-2);
	for(ll i=MAXF-2;i>=0;i--)fci[i]=fci[i+1]*(i+1)%MOD;
}
ll nCr(ll n, ll k){ //must call factorials before
	if(n<0||k<0||k>n)return 0;
	return fc[n]*fci[k]%MOD*fci[n-k]%MOD;
}

int main(){FIN;
	factorials();
	ll n; cin>>n;
	vector<ll>to(n),c(n+1),vis(n);
	fore(i,0,n)cin>>to[i];
	fore(i,0,n)if(!vis[i]){
		ll q=0;
		for(ll x=i;!vis[x];x=to[x]){
			vis[x]=1;
			q++;
		}
		c[q]++;
	}
	vector<ll>dp[n+1];
	ll res=1;
	fore(i,0,n+1){
		dp[i].resize(c[i]+5,0);
		dp[i][0]=1;
		fore(s,1,c[i]+1){
			ll &res=dp[i][s];
			if(s>=4)res=mul(nCr(s-1,3),mul(fc[3],mul(fpow(i,3),dp[i][s-4])));
			if(s>=2&&(i&1))res=add(res,mul((s-1),mul(i,dp[i][s-2])));
			if(i&1)res=add(res,dp[i][s-1]);
			//cout<<i<<" "<<s<<": "<<dp[i][s-1]<<" "<<(s>=2?mul((s-1),mul(i,dp[i][s-2])):0)<<" "<<(s>=4?mul(nCr(s-1,3),mul(fc[3],mul(fpow(i,3),dp[i][s-4]))):0)<<" = "<<res<<"\n";
		}
		res=mul(res,dp[i][c[i]]);
	}
	cout<<res<<"\n";
	return 0;
}
