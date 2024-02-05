#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

const int MAXN=61, MOD=1e9+7;
int dp[MAXN][MAXN][MAXN][MAXN][2];

int add(int x, int y){x+=y; if(x>=MOD)x-=MOD;return x;}
int sub(int x, int y){x-=y; if(x<0)x+=MOD;return x;}
int mul(ll x, ll y){return x*y%MOD;}

// vi mas chicos que el minimo de i

int solve(int v1, int v2, int v3, int v4, int did){
	if(!v1&&!v2&&!v3&&!v4) return did;
	
	int &r=dp[v1][v2][v3][v4][did];
	if(r>=0)return r;
	r=0;
	
	//1 a 2
	fore(i,0,v1) r=add(r, solve(i, v2+(v1-i-1), v3, v4, did));
	
	//2 a 3
	fore(i,0,v2) r=add(r, solve(v1, i, v3+(v2-i-1), v4, did));
	
	//3 a 4
	fore(i,0,v3) r=add(r, solve(v1, v2, i, v4+(v3-i-1), 1));
	
	//4 decreciente
	if(v4) r=add(r, solve(v1,v2,v3,v4-1,1));
	
	//cout<<"done "<<v1<<" "<<v2<<" "<<v3<<" "<<v4<<" con did "<<did<<": "<<r<<"\n";
	
	return r;
}

int main(){FIN;
	memset(dp,-1,sizeof(dp));
	
	int n; cin>>n;
	
	int bad=solve(n,0,0,0,0);
	
	//cout<<"bad "<<bad<<"!\n";
	
	int all=1;
	fore(i,1,n+1) all=mul(all,i);
	
	cout<<sub(all,bad)<<"\n";
}
