#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define forr(i,a,b) for(ll i=b-1,jet=a;i>=jet;--i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MOD=998244353,MAXN=1005,MAXS=55005,MAXX=12,FB=24;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}

ll N,M,x;
ll dp[2][MAXS][MAXX];

int main(){FIN;
	vector<ll>fib={1,1};
	while(fib.back()<=55000)fib.pb(fib.back()+fib.end()[-2]);
	fib.pop_back();
	// imp(fib);
	// cout<<SZ(fib)<<"\n";;
	// cout<<fib[9]<<"\n";
	cin>>N>>x>>M;
	if(M>11){
		cout<<"0\n";
		return 0;
	}
	
	ll S=N*fib[x-1]+3;
	vector<ll>dp2(S); dp2[0]=0;
	fore(i,1,S){
		dp2[i]=i+1;
		for(auto v:fib)if(i>=v)dp2[i]=min(dp2[i],dp2[i-v]+1);
	}
	
	fore(i,0,x)fore(s,0,S)dp[0][s][i]=dp2[s]==M;
	fore(n,1,N+1)forr(s,0,S)forr(i,0,x){
		ll w=n&1;
		ll &res=dp[w][s][i];
		res=0;
		if(i+1<x)res=dp[w][s][i+1];
		if(s+fib[i]<S)res=add(res,dp[w^1][s+fib[i]][i]);
	}
	
	ll res=dp[N&1][0][0];
	cout<<res<<"\n";
	return 0;
}