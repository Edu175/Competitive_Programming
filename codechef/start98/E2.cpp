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
typedef pair<ll,ll> ii;
const ll MAXN=2e2+5,INF=2e12;

ll dp[MAXN][MAXN];
ll a[MAXN];
ll h[MAXN][MAXN];

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m,x; cin>>n>>m>>x;
		fore(i,0,n)cin>>a[i],a[i]--;
		fore(i,0,n)fore(j,0,m)cin>>h[i][j];
		fore(i,0,n+1)fore(j,0,m)dp[i][j]=-INF;
		dp[n][0]=0;
		for(ll i=n-1;i>=0;i--)fore(s,0,m){
			ll &res=dp[i][s];
			//for(ll j=0;!j||(j*x)%m!=0;j++)
			fore(j,0,lcm(x,m)/x+2)
				res=max(res,h[i][(a[i]+j*x)%m]+dp[i+1][(s+j*x)%m]);
		}
		cout<<dp[0][0]<<"\n";
	}
	return 0;
}
