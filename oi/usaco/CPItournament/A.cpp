#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef __int128 bint;
typedef pair<ll,ll> ii;
const ll MAXN=1e5+5,D=50;
bint dp[MAXN][D];
ll a[MAXN],b[MAXN];
ll n;
bint f(ll i, ll d){
	bint &res=dp[i][d];
	if(res!=-1)return res;
	if(i==n)return res=0;
	res=(bint(b[i])<<d)+f(i+1,d);
	if(d<D-1)res=min(res,(bint(a[i])<<d)+f(i+1,d+1));
	return res;
}

int main(){FIN;
	mset(dp,-1);
	fore(i,0,MAXN)fore(j,0,D)dp[i][j]=-1;
	cin>>n;
	fore(i,0,n)cin>>a[i];
	fore(i,0,n)cin>>b[i];
	/*fore(d,0,D)dp[n][i]=0;
	for(ll i=n-1;i>=0;i--)fore(d,0,D){
		dp[i][d]=(b[i]<<d)+dp[i+1][d];
		if(d<D-1)
			dp[i][d]=min(dp[i][d],(a[i]<<d)+dp[i+1][d+1]);
	}*/
	cout<<(ll)f(0,0)<<"\n";
	return 0;
}
