#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=1e4+5,INF=3e18;

ll dp[MAXN];
ll pro=1;
ll query(ll k){
	if(k<MAXN)return dp[k];
	ll q=(k-MAXN)/pro+1;
	ll res=q*dp[pro];
	k-=pro*q;
	assert(0<=k&&k<MAXN);
	return res+dp[k];
}
int main(){FIN;
	ll n,q; cin>>n>>q;
	vv a(n+1); a[0]=0;
	fore(i,1,n+1)cin>>a[i];
	fore(i,1,MAXN){
		dp[i]=INF;
		fore(j,1,min(n,i)+1)dp[i]=min(dp[i],dp[i-j]+a[j]);
		if(dp[i]*pro < dp[pro]*i)pro=i;
	}
	
	vv best(2*n+5,INF);
	fore(i,1,n+1)fore(j,1,n+1)best[i+j]=min(best[i+j],a[i]+a[j]);
	while(q--){
		ll k; cin>>k;
		if(k<=n){cout<<a[k]<<"\n";continue;}
		ll res=INF;
		fore(s,n+1,2*n+1)if(s<=k)res=min(res,best[s]+query(k-s));
		cout<<res<<"\n";
	}
	return 0;
}
