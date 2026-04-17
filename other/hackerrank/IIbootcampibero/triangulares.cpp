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
const ll MAXN=1e4+5,MOD=1019;
vector<ll>tr;
int main(){FIN;
	tr.pb(1);
	fore(i,2,MAXN){
		ll x=i+tr.back();
		if(x>=MAXN)break;
		tr.pb(x);
	}
	ll n; cin>>n;
	ll dp[MAXN][SZ(tr)];
	fore(x,0,n+1)for(ll i=SZ(tr)-1;i>=0;i--){
		if(x==0){dp[x][i]=1;continue;}
		dp[x][i]=dp[x][i+1];
		if(x-tr[i]>=0)dp[x][i]=(dp[x][i]+dp[x-tr[i]][i])%MOD;
	}
	cout<<dp[n][0]<<"\n";
	return 0;
}
