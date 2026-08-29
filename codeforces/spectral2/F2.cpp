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
template<class x> ostream & operator<<(ostream & out, vector<x> v){
    out<<"{ ";
    for(auto y : v) out<<y<<" ";
    out<<"}";
    return out;
}
#define ppc __builtin_popcountll

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		vv a(n);
		fore(i,0,n)cin>>a[i];
		sort(ALL(a));
		// reverse(ALL(a));
		ll N=1ll<<n;
		vv sums(N);
		fore(mk,0,N/2)fore(i,0,n-1)if(!(mk>>i&1))sums[mk]+=a[i];
		vector<ii> dp(N/2);
		ll mx=0;
		fore(mk,0,N/2){
			auto now=dp[mk];
			fore(x,0,n-1)if(!(mk>>x&1)){
				ii pr=now; pr.snd+=a[x];
				ll mki=mk|(1ll<<x);
				if(pr.snd*(k-pr.fst-1)>=sums[mki]){
					if(pr.fst==k-1)mx=max(mx,pr.snd);
					else pr.fst++,pr.snd=0;
				}
				dp[mki]=max(dp[mki],pr);
			}
		}
		ll sum=mx;
		ll res=sum+a[n-1];
		cout<<res<<"\n";
	}
	return 0;
}
