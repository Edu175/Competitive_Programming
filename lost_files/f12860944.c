#include "biscuits.h"
#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ioi=b;i<ioi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto dfh:v)cout<<dfh<<" ";cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef __int128 bint;

vector<ll>a; ll n;
ll x;
vector<vector<bint>> dp;

long long count_tastiness(long long X, vector<long long> A){
	x=X; n=0;
	bint sum=0;
	fore(i,0,SZ(A)){
		sum+=bint(A[i])*bint(1ll<<i);
	}
	//cout<<(ll)sum<<" ";
	while(sum)n++,sum/=2;
	//cout<<n<<"\n";
	n+=3;
	a.clear();
	a.resize(n,0);
	fore(i,0,n)if(i<SZ(A))a[i]=A[i];
	fore(i,0,n-1){
		if(a[i]-x<0)continue;
		ll q=(a[i]-x)/2;
		a[i+1]+=q;
		a[i]-=2*q;
	}
	ll MAXN=n+3,MAXQ=3*x+5;
	dp.clear();
	dp.resize(MAXN,vector<bint>(MAXQ,0));
	//fore(i,1,x+5)dp[n][i]=0;
	//imp(a);
	dp[n][0]=1;
	for(ll i=n-1;i>=0;i--)fore(q,0,MAXQ){
		bint &res=dp[i][q];
		res=0;
		res+=dp[i+1][(a[i]+q)/2];
		if(a[i]+q>=x)res+=dp[i+1][(a[i]+q-x)/2];
		/*cout<<i<<" "<<q<<": ["<<(a[i]+q)/2<<"] ["<<(a[i]+q-x)/2<<"]: "<<dp[i+1][(a[i]+q)/2]<<" ";
		if(a[i]+q>=x)cout<<dp[i+1][(a[i]+q-x)/2];
		else cout<<0;
		cout<<": "<<res<<"\n";*/
	}
	ll res=dp[0][0];
	return res;
}

