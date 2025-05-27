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
const ll MAXN=ll(1e12)+5,MAXM=1414214+5;
// ans <= 8
vv tr;
int main(){FIN;
	tr.pb(1);
	fore(i,2,MAXN){
		if(tr.back()>MAXN)break;
		tr.pb(tr.back()+i);
	}
	vv dp(MAXM);
	ll mx=0;
	auto inner=[&](ll n){
		ll res=n+5;
		ll p=upper_bound(ALL(tr),n)-tr.begin();
		for(ll i=p-1;i>=0;i--){
			ll v=tr[i],q=n/v;
			if(q>=res)break;
			ll to=n-q*v;
			mx=max(mx,to);
			// assert(to<MAXM);
			if(to<MAXM)res=min(res,q+dp[to]);
			// cerr<<n<<" "<<++steps<<"\n";
		}
		return res;
	};
	fore(n,1,MAXM)dp[n]=inner(n);
	fore(i,0,10)cout<<dp[i]<<" ";;cout<<"\n";
	cerr<<"fin dp\n";
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		cout<<inner(n)<<"\n";
	}
	cerr<<"max "<<mx<<"\n";
	return 0;
}