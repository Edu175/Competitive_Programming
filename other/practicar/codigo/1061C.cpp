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
typedef ll node;
const ll MAXN=1e6+5,MOD=1e9+7;
vector<ll> divs[MAXN];
void divisores(){
	fore(i,1,MAXN)for(int j=i;j<MAXN;j+=i)divs[j].pb(i);
}
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
int main(){FIN;
	divisores();
	ll n; cin>>n;
	vector<ll>a(n);
	fore(i,0,n)cin>>a[i];
	vector<ll>dp(n+5);
	for(ll i=n-1;i>=0;i--){
		for(auto d:divs[a[i]])if(d<=n){
			dp[d]=add(dp[d],1+dp[d+1]);
		}
		//cout<<i<<": "; imp(dp);
	}
	cout<<dp[1]<<"\n";
	return 0;
}

