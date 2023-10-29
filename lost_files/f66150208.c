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
const ll MAXS=1e5+5;

ll n,x;
vector<ll>a;
vector<vector<ll>>dp;
ll f(ll i, ll q){
	ll &res=dp[i][q];
	if(res!=-1)return res;
	if(i==n)return res=1;
	res=0;
	res=f(i+1,(a[i]+q)/2);
	if(a[i]+q>=x)res+=f(i+1,(a[i]+q-x)/2);
	return res;
}

long long count_tastiness(long long X, vector<long long> A){
	x=X; n=0;
	//fore(i,0,SZ(A))if(A[i])n=i+1;
	n=66-__builtin_clzll(MAXS);
	a.clear();
	dp.clear();
	a.resize(n,0);
	fore(i,0,n)if(i<SZ(A))a[i]=A[i];
	dp.resize(n+3,vector<ll>(MAXS,-1));
	return f(0,0);
}

