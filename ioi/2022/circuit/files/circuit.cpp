#include "circuit.h"
#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ioi=b;i<ioi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto djfhg:v)cout<<djfhg<<" ";cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=5005,MOD=1000002022;

ll n,m;
vector<ll>g[MAXN];
ll a[MAXN];

ii dp[2*MAXN]; //ways of 1, ways of 0
vector<ll>v;
ii f(ll x){
	ii &res=dp[x];
	if(res.fst!=-1)return res;
	res={0,0};
	if(x>=n){
		if(a[x-n])res.fst=1;
		else res.snd=1;
		//cout<<x<<": "<<res.fst<<","<<res.snd<<"\n\n";
		return res;
	}
	ll sz=SZ(g[x]);
	vector<vector<ll>> dp2(sz+3,vector<ll>(sz+3));
	/*for(auto y:g[x])f(y);//res.snd=(res.snd*f(y).snd)%MOD; debugging
	cout<<x<<":\n";*/
	for(ll i=sz;i>=0;i--)fore(k,0,sz+2){
		ll &res2=dp2[i][k];
		if(i==sz){
			if(k==0)res2=1;
			else res2=0;
			continue;
		}
		ll y=g[x][i];
		ll ch=f(y).fst,no=f(y).snd;
		res2=(res2+dp2[i+1][k]*no)%MOD;
		if(k)res2=(res2+dp2[i+1][k-1]*ch)%MOD;
		//cout<<i<<"("<<y<<") "<<k<<": "<<res2<<"\n";
	}
	fore(k,0,sz+2){
		//cout<<dp2[0][k]<<"*"<<k<<": "<<dp2[0][k]*k<<"\n";
		res.fst=(res.fst+dp2[0][k]*k)%MOD;
		res.snd=(res.snd+dp2[0][k]*(sz-k))%MOD;
	}
	//cout<<res.fst<<","<<res.snd<<"\n\n";
	return res;
}

void init(int N, int M, std::vector<int> P, std::vector<int> A){
	n=N,m=M;
	fore(i,0,SZ(P)){
		if(P[i]!=-1)g[P[i]].pb(i);
	}
	fore(i,0,m)a[i]=A[i];
}

int count_ways(int L, int R){
	fore(i,L,R+1)a[i-n]^=1;
	fore(i,0,n+m+5)dp[i]={-1,-1};
	//cout<<"\n\nQUERY\n";
	return f(0).fst;
}
