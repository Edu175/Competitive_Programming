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
const ll INF=1e15;
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n),c(n,-1);
		fore(i,0,n){
			cin>>a[i],a[i]--;
			if(a[i]!=-1)c[a[i]]=i&1;
		}
		// imp(c)
		ll fij=0;
		fore(i,0,n)fij+=(i+1)*(n-i);
		vector<vv>dp(n+3,vv(n+3,-INF));
		dp[n][(n+1)/2]=0;
		for(ll i=n-1;i>=0;i--)fore(q,0,n){
			auto &res=dp[i][q];
			ll m=(n+1)/2;
			ll go0=(i+1)*(q-(m-1-q))+dp[i+1][q+1];
			ll qp=i-q,mp=n/2;
			ll go1=(i+1)*(qp-(mp-1-qp))+dp[i+1][q];
			if(c[i]!=-1)res=(c[i]?go1:go0);
			else res=max(go0,go1);
			// cout<<i<<" "<<q<<": "<<go0<<" "<<go1<<": "<<res<<"\n";
		}
		ll res=fij+dp[0][0];
		// cerr<<fij<<": ";
		cout<<res<<"\n";
	}
	return 0;
}
