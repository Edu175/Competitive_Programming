#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll n; cin>>n;
	ll cop[n][n];
	fore(i,0,n)fore(j,0,n)cin>>cop[i][j];
	vector<ll>a(n);
	fore(i,0,n)cin>>a[i];
	ll val[n][n][n];
	fore(i,0,n)fore(j,0,n)fore(k,0,n){
		ll &res=val[i][j][k];
		res=max({a[i],a[j],a[k]});
		fore(mk,0,8){
			ll p=mk&1,q=mk&2,r=mk&4;
			ll resi=1;
			if(p&&q)resi*=cop[i][j];
			if(p&&r)resi*=cop[i][k];
			if(r&&q)resi*=cop[k][j];
			res=max(res,resi);
		}
	}
	vector<ll>dp(1<<n);
	fore(mk,1,1<<n){
		ll &res=dp[mk];
		ll i=__builtin_ctzll(mk);
		fore(j,i+1,n)if((mk>>j)&1)fore(k,j+1,n)if((mk>>k)&1){
			res=max(res,dp[mk^(1ll<<i)^(1ll<<j)^(1ll<<k)]+val[i][j][k]);
		}
	}
	cout<<dp[(1<<n)-1]<<"\n";
	return 0;
}
