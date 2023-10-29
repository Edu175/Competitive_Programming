#include "fish.h"
#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ioi=b;i<ioi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto sjkg:v)cout<<sjkg<<" ";cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=3e3+5,MAXM=3e5+5;

ll n,m;
ll x[MAXM],y[MAXM],w[MAXM];
ll sp[MAXN][MAXN];
ll h[MAXN][MAXN];
ll get(ll i, ll l, ll r){ //(,]
	l++,r++;
	//[,)
	return sp[i][r]-sp[i][l];
}
ll dp[MAXN][MAXN];
// 	M NO ES DIMENSION
//  M ES CANTIDAD DE PECES
long long max_weights(int N, int M, std::vector<int> X, std::vector<int> Y,
                      std::vector<int> W){
	n=N,m=M;
	fore(i,0,m)x[i]=X[i],y[i]=Y[i],w[i]=W[i];
	//======================done=====================================
	fore(i,0,m)h[x[i]][y[i]]=w[i];
	fore(i,0,n){
		fore(j,1,n+1){
			sp[i][j]=sp[i][j-1]+h[i][j-1];
		}
	}
	//fore(j,0,n)dp[0][i]=0;
	ll ans=0;
	fore(i,1,n)fore(j,0,n){
		ll &res=dp[i][j];
		fore(k,0,n){
			ll resi=0;
			if(k<j)resi=get(i-1,k,j)+dp[i-1][k];
			else resi=get(i,j,k)+dp[i-1][k];
			res=max(res,resi);
		}
		cout<<i<<" "<<j<<": "<<res<<"\n";
		ans=max(res,ans);
	}
	return ans;
}
