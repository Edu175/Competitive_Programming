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
typedef __int128 xl;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

xl Gcd(xl a, xl b){
	return !b?a:Gcd(b,a%b);
}
xl Lcm(xl a, xl b){
	return a*b/Gcd(a,b);
}

int main(){FIN;
	ll n,m,y; cin>>n>>m>>y;
	vv a(n);
	fore(i,0,n)cin>>a[i];
	auto val=[&](ll mk)->ll {
		xl num=1;
		fore(i,0,n)if(mk>>i&1){
			num=Lcm(num,a[i]);
			if(num>y)return 0;
		}
		return y/num;
	};
	ll N=1ll<<n;
	vector<ll> dp(N); // SOSupersets
	fore(mk,0,N){
		ll c=__builtin_popcountll(mk);
		dp[mk]=(c&1?-1:1)*val(mk);
	}
	fore(j,0,n)for(ll mk=N-1;mk>=0;mk--){
		if(!(mk>>j&1))dp[mk]+=dp[mk|(1ll<<j)];
	}
	ll res=0;
	fore(mk,0,N){
		ll c=__builtin_popcountll(mk);
		if(c!=m)continue;
		ll cur=dp[mk];
		if(c&1)cur=-cur;
		assert(cur>=0);
		res+=cur;
	}
	cout<<res<<"\n";
	return 0;
}
