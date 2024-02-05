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
const ll MAXN=17;

ll g[MAXN][MAXN];
ll can[1ll<<MAXN];
ll dp[1ll<<MAXN];
int main(){FIN;
	ll p,b,n,m; cin>>p>>b>>n>>m;
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--;
		g[u][v]=g[v][u]=1;
	}
	n++;
	fore(mk,0,1ll<<n){
		can[mk]=1;
		fore(i,0,n)if((mk>>i)&1)fore(j,i+1,n)if((mk>>j)&1){
			if(g[i][j])can[mk]=0;
		}
	}
	dp[0]=0;
	fore(mk,1,1ll<<n){
		dp[mk]=2*n+5;
		for(ll sb=mk;sb;sb=(sb-1)&mk)if(can[sb])
			dp[mk]=min(dp[mk],1+dp[mk^sb]);
	}
	if(dp[(1ll<<n)-1]<=p)cout<<"Yes\n";
	else cout<<"No\n";
	return 0;
}
