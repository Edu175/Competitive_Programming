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
const ll MOD=1e9+7,MAXF=2e5+5,MAXC=28;
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
	vv fib(MAXC); fib[1]=1;
	fore(i,2,MAXC)fib[i]=fib[i-1]+fib[i-2];
	ll n; cin>>n;
	ll dp[MAXC][n+5];
	mset(dp,0);
	fore(s,0,n+1)dp[0][s]=1;
	fore(c,1,MAXC)fore(s,0,n+1){
		auto &res=dp[c][s];
		if(s==n){ // resto go2
			fore(coef,1,n+1){
				ll si=s-coef*fib[c];
				if(si>=0&&c>=2){ // prox coef = 0
					ll go2=dp[c-2][si];
					go2=mul(go2,(MOD+1)/2);
					res=sub(res,go2);
				}
			}
		}
		else res=dp[c-1][s]; // skip only if already started
		if(s>=fib[c])res=add(res,dp[c][s-fib[c]]);
		// cout<<c<<" "<<s<<": "<<res<<"\n";
	}
	factos();
	ll res=0,tot=0;
	fore(c,1,n+1)tot=add(tot,fpow(n,c));
	fore(c,1,min(MAXC,n+1)){
		ll cur=dp[c][n];
		// cerr<<c<<": "<<cur<<": ";
		cur=mul(cur,fc[c]);
		// cout<<cur<<" final\n";
		res=add(res,cur);
	}
	// cerr<<res<<" "<<tot<<": ";
	res=sub(tot,res);
	cout<<res<<"\n";
	return 0;
}
