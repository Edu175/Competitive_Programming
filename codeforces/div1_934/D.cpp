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
const ll MAXN=405;
ll MOD;
ll dp[MAXN][MAXN];
ll sp[MAXN][MAXN];
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k>>MOD;
		for(ll i=n+1;i>=1;i--){
			fore(l,0,k+1)fore(u,0,k+1){
				ll &res=dp[l][u];
				if(i==n+1){res=(u==0);continue;}
				res=sp[u][max(u-l,(ll)0)];
				//cout<<i<<" "<<l<<" "<<u<<": "<<res<<"\n";
			}
			fore(l,0,k+1){
				sp[l][k]=dp[l][k];
				for(ll u=k-1;u>=0;u--)sp[l][u]=(sp[l][u+1]+dp[l][u])%MOD;
			}
		}
		ll res=sp[0][0];
		cout<<res<<"\n";
	}
	return 0;
}
