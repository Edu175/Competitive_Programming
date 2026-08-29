#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll INF=1e18;

// lpmmmm lei techo la concha del pato

ll n,m;
ll k;
vv a; // sorted, only relevant (remove upper half)
vv cost;

bool can(ll h){
	vv dp(m+1,INF);
	fore(i,0,min(h,m)+1)dp[i]=0;
	fore(i,h,m+1){
		fore(v,2,m+1){
			ll j=min((i+1)*v-1,m);
			dp[j]=min(dp[j],dp[i]+cost[v]);
			if(j==m)break; // this makes it nlogn here
		}
	}
	for(ll i=m-1;i>=0;i--)dp[i]=min(dp[i],dp[i+1]);
	ll cur=0;
	fore(i,0,n){
		cur+=dp[a[i]];
		if(cur>k)return 0;
	}
	return 1;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n>>m>>k;
		a=vv(n),cost=vv(m+1);
		fore(i,0,n)cin>>a[i];
		sort(ALL(a));
		n=(n+1)/2;
		a.resize(n);
		fore(i,1,m+1)cin>>cost[i];
		for(ll i=m-1;i>=1;i--)cost[i]=min(cost[i],cost[i+1]);
		ll l=-1,r=a.back()+1;
		while(r-l>1){
			ll h=(l+r)/2;
			if(can(h))r=h;
			else l=h;
		}
		// cerr<<"can 0 "<<can(0)<<"\n";
		ll res=r;
		cout<<res<<"\n";
	}
	return 0;
}
