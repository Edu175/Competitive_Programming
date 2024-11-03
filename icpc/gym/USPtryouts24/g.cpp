#include <bits/stdc++.h>
#define fore(i,a,b) for(int i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

const int maxn=1005;
ll dp[maxn][maxn];
vv a;
int n;
ll f(int x, int tp){
	if(x==n+1) return 0;
	if(dp[x][tp]!=-1) return dp[x][tp];
	dp[x][tp]=min(abs(a[x-1]-a[x])+f(x+1,tp),abs(a[tp]-a[x])+f(x+1,x-1));
	return dp[x][tp];
}

int main(){
	JET
	cin>>n;
	a.resize(n+1);
	fore(i,1,n+1) cin>>a[i];
	a[0]=0;
	mset(dp,-1);
	cout<<f(1,0)<<"\n";
	return 0;
}