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
const ll MAXN=2005;
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		vv vals(n),oc(n);
		fore(i,0,n){
			cin>>vals[i];
			vals[i]--;
			oc[vals[i]]++;
		}
		vector<ii> a(m);
		fore(i,0,m){
			ll l,r; cin>>l>>r; l--;
			a[i]={l,r};
		}
		sort(ALL(a));
		ll L=0,R=0;
		vv zs;
		fore(i,0,SZ(a)){
			auto [l,r]=a[i];
			if(R<=l){
				if(R-L)zs.pb(R-L);
				L=l,R=r;
			}
			else R=max(R,r);
		}
		if(R-L)zs.pb(R-L);
		ll sum=accumulate(ALL(zs),0ll);
		fore(i,0,n-sum)zs.pb(1);
		vv dp(n+1);
		dp[0]=1;
		for(auto z:zs)fore(i,1,n+1)if(i-z>=0)dp[i]|=dp[i-z];
		imp(zs)
		imp(dp)
		ll cl=0;
		fore(i,0,n){
			ll m=oc[i];
			ll hay=0;
			fore(i,cl,cl+m+1)hay|=dp[i];
			cout<<hay;
			cl+=m;
		}
		cout<<"\n";
		
	}
	return 0;
}
