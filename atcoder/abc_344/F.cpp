#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define forr(i,a,b) for(ll i=b-1,ggdem=a;i>=ggdem;--i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const ll MAXN=82,INF=MAXN*2*(1e9+5);
ll n;
ll a[MAXN][MAXN];
ll R[MAXN][MAXN],D[MAXN][MAXN];
ii dp[MAXN][MAXN][MAXN][MAXN];
/*ii f(ll i, ll j, ll Mi, ll Mj){
	ii res=dp[i][j][Mi][Mj];
	if(res.fst!=-1)return res;
	if(i>n||j>=n)return res={1,INF};
	ii go0=f(i+1,j,Mi,Mj);
	go0.snd+=D[i][j];
	ii go1=f(i,j+1,Mi,Mj);
	go1.snd+=R[i][j];
	res=min(go0,go1);
	if(i==Mi&&j==Mj)res.fst=0;
	if(i==n-1&&j==n-1)return res={res.fst,0};
	return res;
}*/

int main(){FIN;
	cin>>n;
	fore(i,0,n)fore(j,0,n)cin>>a[i][j];
	fore(i,0,n)fore(j,0,n-1)cin>>R[i][j];
	fore(i,0,n-1)fore(j,0,n)cin>>D[i][j];
	fore(Mi,0,n)fore(Mj,0,n)forr(i,0,n+1)forr(j,0,n+1){
		ii &res=dp[i][j][Mi][Mj];
		if(i>=n||j>=n){res={1,INF};continue;}
		ii go0=dp[i+1][j][Mi][Mj];
		go0.snd+=D[i][j];
		ii go1=dp[i][j+1][Mi][Mj];
		go1.snd+=R[i][j];
		res=min(go0,go1);
		if(i==Mi&&j==Mj)res.fst=0;
		if(i==n-1&&j==n-1)res.snd=0;
		//cout<<i<<","<<j<<" "<<Mi<<","<<Mj<<": "<<res.fst<<","<<res.snd<<"\n";
	}
	ll res=INF;
	fore(i,0,n)fore(j,0,n)res=min(res,(dp[0][0][i][j].snd+a[i][j]-1)/a[i][j]);
	res+=2*(n-1);
	cout<<res<<"\n";
	return 0;
}
