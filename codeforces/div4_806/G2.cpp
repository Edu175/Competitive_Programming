#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
#define pres cout<<res<<"\n"
using namespace std;
typedef long long ll;
const ll MAXN=100005, MINRES=-100000000000005;
ll a[MAXN];
ll n,k;
ll dp[MAXN][35];
ll comp=0;

ll solve(ll i, ll j){
	if(j>=35)j=34;
	if(dp[i][j]>MINRES)return dp[i][j];
	comp++;
	if(i>=n)return dp[i][j]=0;
	dp[i][j]=max(a[i]/(1ll<<j)-k+solve(i+1,j),a[i]/(1ll<<(j+1))+solve(i+1,j+1));
	//cout<<i<<","<<j<<": "<<dp[i][j]<<"\n";
	return dp[i][j];
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n>>k;
		fore(i,0,n)cin>>a[i];
		//mset(dp,MINRES);
		fore(i,0,n+1){
			fore(j,0,35)dp[i][j]=MINRES;
		}
		cout<<solve(0,0)<<"\n";
	}
	/*cout<<"comp:"<<comp;
	if(comp<300010000)cout<<" ok\n";
	else cout<<" tle\n";*/
	return 0;
}
