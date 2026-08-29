#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll) x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(a) {for(auto x:a) cout<<x<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){
    JET
	ll n,m; cin>>n>>m;
	vector<ll> a(m);
	ll N=1ll<<n;
	fore(i,0,m){
		ll k; cin>>k;
		fore(_,0,k){
			ll v; cin>>v;
			a[i]|=1ll<<v;
		}
	}
	// cerr<<"a: "; show(a)
	vv det(N),cnt(N);
	// 1: has asked
	fore(mk,0,N){
		for(auto i:a)cnt[i&mk]++;
		for(auto i:a){
			det[mk]+=cnt[i&mk]==1;
			cnt[i&mk]=0;
		}
		// cerr<<mk<<": "<<det[mk]<<"\n";
	}
	if(det[N-1]<m){
		cout<<"not possible\n";
		return 0;
	}
	vv dp(N); dp[N-1]=0;
	for(ll mk=N-2;mk>=0;mk--){
		auto &res=dp[mk];
		res=1e18;
		fore(j,0,n)if(!(mk>>j&1))res=min(res,dp[mk|(1ll<<j)]);
		res+=m-det[mk];
	}
	ll res=dp[0];
	// cerr<<"res "<<res<<"\n";
	ld ans=ld(res)/m;
	cout<<fixed<<setprecision(15)<<ans<<"\n";
    return 0;
}
