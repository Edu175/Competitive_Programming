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
const ll MAXN=2e5+5,MOD=998244353;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	if(b<0)return 0;
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
ll dp[MAXN][2];
ll a[MAXN];
ll n;
ll f(ll i, ll fg){
	auto &res=dp[i][fg];
	if(res!=-1)return res;
	if(i==n)return res=1;
	if(!fg){ // anterior es true
		res=f(i+1,1); // im liar
		ll bad=a[i]!=(i?a[i-1]:0);
		if(!bad)res=add(res,f(i+1,0));
	}
	else {
		// im true
		ll bad=a[i]!=(i>=2?a[i-2]+1:1);
		if(bad)return res=0;
		res=f(i+1,0);
	}
	return res;
}


int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		fore(i,0,n+3)fore(j,0,2)dp[i][j]=-1;
		fore(i,0,n)cin>>a[i];
		
		cout<<f(0,0)<<"\n";
		
		
	}
	return 0;
}
